#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 2), (Arg 14))]; T (16, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, h, hp_0, w, wp_0, x, xp_0, x1016_p_0, x1017_p_0, xp_1, x1016_p_1, xp_2, x1016, x1017, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y508 = 0;
IND_TYPE x1018 = 0;
IND_TYPE h488 = 0;
IND_TYPE w508 = 0;
IND_TYPE c763 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9732 ,mem_vec_9733 ,mem_vec_9734 ,mem_vec_9735 ,mem_vec_9736 ,mem_vec_9737 ,mem_vec_9738 ,mem_vec_9739 ,mem_vec_9740 ,mem_vec_9741 ,mem_vec_9742 ,mem_vec_9743 ,mem_vec_9744 ,mem_vec_9745 ,mem_vec_9746 ,mem_vec_9747 ,mem_vec_9748 ,mem_vec_9749 ,mem_vec_9750 ,mem_vec_9751 ,mem_vec_9752 ,mem_vec_9753 ,mem_vec_9754 ,mem_vec_9755 ,mem_vec_9756 ,mem_vec_9757 ,mem_vec_9758 ,mem_vec_9759 ,mem_vec_9760 ,mem_vec_9761 ,mem_vec_9762 ,mem_vec_9763 ,mem_vec_9764 ,mem_vec_9765 ,mem_vec_9766 ,mem_vec_9767 ,mem_vec_9768 ,mem_vec_9769 ,mem_vec_9770 ,mem_vec_9771 ,mem_vec_9772 ,mem_vec_9773 ,mem_vec_9774 ,mem_vec_9775 ,mem_vec_9776 ,mem_vec_9777 ,mem_vec_9778 ,mem_vec_9779 ,mem_vec_9780 ,mem_vec_9781 ,mem_vec_9782 ,mem_vec_9783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x1017 = x1018, x1017_p_0 = 0;
	x1017 < x1018 + 112;
	x1017 += 16, x1017_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c762 = c763, c762_p_0 = 0;
		c762 < c763 + 32;
		c762 += 2, c762_p_0 += 2){
			for (y = y508, yp_0 = 0;
				y < y508 + 84;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (16 / 8)
				for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
					x1016 < x1017 + 16;
					x1016 += 8, x1016_p_1 += 8, x1016_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h488, hp_0 = 0;
						h < h488 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w508, wp_0 = 0;
							w < w508 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 2, f = 32
							// T (x, 8) (8 / 1)
							for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
								x < x1016 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9732 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9733 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
											c < c762 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9732);
											mem_vec_9732 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9733);
											mem_vec_9733 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9734);
											mem_vec_9734 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9735);
											mem_vec_9735 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9736);
											mem_vec_9736 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9737);
											mem_vec_9737 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9738);
											mem_vec_9738 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9739);
											mem_vec_9739 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9740);
											mem_vec_9740 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9741);
											mem_vec_9741 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9742);
											mem_vec_9742 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9743);
											mem_vec_9743 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9744);
											mem_vec_9744 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9745);
											mem_vec_9745 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9746);
											mem_vec_9746 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9747);
											mem_vec_9747 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9748);
											mem_vec_9748 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9749);
											mem_vec_9749 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9750);
											mem_vec_9750 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9751);
											mem_vec_9751 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9752);
											mem_vec_9752 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9753);
											mem_vec_9753 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9754);
											mem_vec_9754 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9755);
											mem_vec_9755 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9755);
							}
						}
					}
				}
			}
			for (y = y508 + 84, yp_0 = 0;
				y < y508 + 84 + 28;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (16 / 8)
				for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
					x1016 < x1017 + 16;
					x1016 += 8, x1016_p_1 += 8, x1016_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h488, hp_0 = 0;
						h < h488 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w508, wp_0 = 0;
							w < w508 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 2, f = 32
							// T (x, 8) (8 / 1)
							for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
								x < x1016 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_9780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_9781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_9782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_9783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
											c < c762 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9756);
											mem_vec_9756 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9757);
											mem_vec_9757 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9758);
											mem_vec_9758 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9759);
											mem_vec_9759 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9760);
											mem_vec_9760 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9761);
											mem_vec_9761 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9762);
											mem_vec_9762 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9763);
											mem_vec_9763 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9764);
											mem_vec_9764 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9765);
											mem_vec_9765 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9766);
											mem_vec_9766 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9767);
											mem_vec_9767 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9768);
											mem_vec_9768 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9769);
											mem_vec_9769 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9770);
											mem_vec_9770 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9771);
											mem_vec_9771 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9772);
											mem_vec_9772 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9773);
											mem_vec_9773 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9774);
											mem_vec_9774 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9775);
											mem_vec_9775 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9776);
											mem_vec_9776 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9777);
											mem_vec_9777 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9778);
											mem_vec_9778 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9779);
											mem_vec_9779 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9780);
											mem_vec_9780 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9781);
											mem_vec_9781 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9782);
											mem_vec_9782 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9783);
											mem_vec_9783 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9783);
							}
						}
					}
				}
			}
	}
}


}