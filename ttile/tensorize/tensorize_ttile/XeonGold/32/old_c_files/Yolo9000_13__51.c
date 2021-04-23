#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (17, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, x, xp_0, x60_p_0, x61_p_0, xp_1, x60_p_1, xp_2, x60, x61, y, yp_0, y37_p_0, yp_1, y37;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y38 = 0;
IND_TYPE x62 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y37 = y38, y37_p_0 = 0;
		y37 < y38 + 8;
		y37 += 8, y37_p_0 += 8){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 34;
			x61 += 34, x61_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f30, fp_0 = 0;
				f < f30 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y37, yp_1 = y37_p_0, yp_0 = 0;
					y < y37 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
						x60 < x61 + 34;
						x60 += 2, x60_p_1 += 2, x60_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 2) (512 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 512;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
							// T (x, 2) (2 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
											c < c45 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_710);
											mem_vec_710 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_711);
											mem_vec_711 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_712);
											mem_vec_712 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_713);
											mem_vec_713 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_714);
											mem_vec_714 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_715);
											mem_vec_715 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_716);
											mem_vec_716 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_717);
											mem_vec_717 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_718);
											mem_vec_718 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_719);
											mem_vec_719 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_720);
											mem_vec_720 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_721);
											mem_vec_721 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_722);
											mem_vec_722 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_723);
											mem_vec_723 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_724);
											mem_vec_724 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_725);
											mem_vec_725 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_710);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_711);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_712);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_713);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_714);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_715);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_716);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_717);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_718);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_719);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_725);
							}
						}
					}
				}
			}
		}
	}
	for (y37 = y38 + 8, y37_p_0 = 0;
		y37 < y38 + 8 + 26;
		y37 += 13, y37_p_0 += 13){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 34;
			x61 += 34, x61_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f30, fp_0 = 0;
				f < f30 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y37, yp_1 = y37_p_0, yp_0 = 0;
					y < y37 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
						x60 < x61 + 34;
						x60 += 2, x60_p_1 += 2, x60_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 2) (512 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 512;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
							// T (x, 2) (2 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
											c < c45 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_726);
											mem_vec_726 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_727);
											mem_vec_727 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_728);
											mem_vec_728 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_729);
											mem_vec_729 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_730);
											mem_vec_730 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_731);
											mem_vec_731 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_732);
											mem_vec_732 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_733);
											mem_vec_733 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_734);
											mem_vec_734 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_735);
											mem_vec_735 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_736);
											mem_vec_736 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_737);
											mem_vec_737 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_738);
											mem_vec_738 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_739);
											mem_vec_739 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_740);
											mem_vec_740 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_741);
											mem_vec_741 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_742);
											mem_vec_742 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_743);
											mem_vec_743 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_744);
											mem_vec_744 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_745);
											mem_vec_745 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_746);
											mem_vec_746 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_747);
											mem_vec_747 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_748);
											mem_vec_748 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_749);
											mem_vec_749 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_750);
											mem_vec_750 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_751);
											mem_vec_751 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_751);
							}
						}
					}
				}
			}
		}
	}


}