#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, c); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c676_p_0, c677_p_0, cp_1, c676_p_1, cp_2, c676, c677, h, hp_0, w, wp_0, x, xp_0, x752_p_0, xp_1, x752, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y408 = 0;
IND_TYPE x753 = 0;
IND_TYPE h372 = 0;
IND_TYPE w384 = 0;
IND_TYPE c678 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_6732 ,mem_vec_6733 ,mem_vec_6734 ,mem_vec_6735 ,mem_vec_6736 ,mem_vec_6737 ,mem_vec_6738 ,mem_vec_6739 ,mem_vec_6740 ,mem_vec_6741 ,mem_vec_6742 ,mem_vec_6743 ,mem_vec_6744 ,mem_vec_6745 ,mem_vec_6746 ,mem_vec_6747 ,mem_vec_6748 ,mem_vec_6749 ,mem_vec_6750 ,mem_vec_6751 ,mem_vec_6752 ,mem_vec_6753 ,mem_vec_6754 ,mem_vec_6755 ,mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c677 = c678, c677_p_0 = 0;
	c677 < c678 + 64;
	c677 += 8, c677_p_0 += 8){
		for (y = y408, yp_0 = 0;
			y < y408 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 4) (56 / 14)
			for (x752 = x753, x752_p_0 = 0;
				x752 < x753 + 56;
				x752 += 14, x752_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c676 = c677, c676_p_1 = c677_p_0, c676_p_0 = 0;
					c676 < c677 + 8;
					c676 += 4, c676_p_1 += 4, c676_p_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h372, hp_0 = 0;
						h < h372 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w384, wp_0 = 0;
							w < w384 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 4, f = 64
							// T (x, 14) (14 / 1)
							for (x = x752, xp_1 = x752_p_0, xp_0 = 0;
								x < x752 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6732 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6733 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6734 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6735 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c676, cp_2 = c676_p_1, cp_1 = c676_p_0, cp_0 = 0;
											c < c676 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6732);
											mem_vec_6732 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6733);
											mem_vec_6733 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6734);
											mem_vec_6734 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6735);
											mem_vec_6735 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6736);
											mem_vec_6736 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6737);
											mem_vec_6737 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6738);
											mem_vec_6738 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6739);
											mem_vec_6739 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6740);
											mem_vec_6740 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6741);
											mem_vec_6741 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6742);
											mem_vec_6742 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6743);
											mem_vec_6743 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6744);
											mem_vec_6744 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6745);
											mem_vec_6745 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6746);
											mem_vec_6746 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6747);
											mem_vec_6747 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6748);
											mem_vec_6748 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6749);
											mem_vec_6749 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6750);
											mem_vec_6750 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6751);
											mem_vec_6751 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6752);
											mem_vec_6752 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6753);
											mem_vec_6753 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6754);
											mem_vec_6754 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6755);
											mem_vec_6755 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6755);
							}
						}
					}
				}
			}
		}
		for (y = y408 + 42, yp_0 = 0;
			y < y408 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 4) (56 / 14)
			for (x752 = x753, x752_p_0 = 0;
				x752 < x753 + 56;
				x752 += 14, x752_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c676 = c677, c676_p_1 = c677_p_0, c676_p_0 = 0;
					c676 < c677 + 8;
					c676 += 4, c676_p_1 += 4, c676_p_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h372, hp_0 = 0;
						h < h372 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w384, wp_0 = 0;
							w < w384 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 4, f = 64
							// T (x, 14) (14 / 1)
							for (x = x752, xp_1 = x752_p_0, xp_0 = 0;
								x < x752 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6758 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6759 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_6780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_6783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c676, cp_2 = c676_p_1, cp_1 = c676_p_0, cp_0 = 0;
											c < c676 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6756);
											mem_vec_6756 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6757);
											mem_vec_6757 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6758);
											mem_vec_6758 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6759);
											mem_vec_6759 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6760);
											mem_vec_6760 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6761);
											mem_vec_6761 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6762);
											mem_vec_6762 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6763);
											mem_vec_6763 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6764);
											mem_vec_6764 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6765);
											mem_vec_6765 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6766);
											mem_vec_6766 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6767);
											mem_vec_6767 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6768);
											mem_vec_6768 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6769);
											mem_vec_6769 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6770);
											mem_vec_6770 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6771);
											mem_vec_6771 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6772);
											mem_vec_6772 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6773);
											mem_vec_6773 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6774);
											mem_vec_6774 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6775);
											mem_vec_6775 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6776);
											mem_vec_6776 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6777);
											mem_vec_6777 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6778);
											mem_vec_6778 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6779);
											mem_vec_6779 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_6780);
											mem_vec_6780 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_6781);
											mem_vec_6781 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_6782);
											mem_vec_6782 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_6783);
											mem_vec_6783 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_6782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_6783);
							}
						}
					}
				}
			}
		}
}


}