#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (16, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, h, hp_0, w, wp_0, x, xp_0, x936_p_0, x937_p_0, xp_1, x936_p_1, xp_2, x936, x937, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y468 = 0;
IND_TYPE x938 = 0;
IND_TYPE h448 = 0;
IND_TYPE w468 = 0;
IND_TYPE c703 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8712 ,mem_vec_8713 ,mem_vec_8714 ,mem_vec_8715 ,mem_vec_8716 ,mem_vec_8717 ,mem_vec_8718 ,mem_vec_8719 ,mem_vec_8720 ,mem_vec_8721 ,mem_vec_8722 ,mem_vec_8723 ,mem_vec_8724 ,mem_vec_8725 ,mem_vec_8726 ,mem_vec_8727 ,mem_vec_8728 ,mem_vec_8729 ,mem_vec_8730 ,mem_vec_8731 ,mem_vec_8732 ,mem_vec_8733 ,mem_vec_8734 ,mem_vec_8735 ,mem_vec_8736 ,mem_vec_8737 ,mem_vec_8738 ,mem_vec_8739 ,mem_vec_8740 ,mem_vec_8741 ,mem_vec_8742 ,mem_vec_8743 ,mem_vec_8744 ,mem_vec_8745 ,mem_vec_8746 ,mem_vec_8747 ,mem_vec_8748 ,mem_vec_8749 ,mem_vec_8750 ,mem_vec_8751 ,mem_vec_8752 ,mem_vec_8753 ,mem_vec_8754 ,mem_vec_8755 ,mem_vec_8756 ,mem_vec_8757 ,mem_vec_8758 ,mem_vec_8759 ,mem_vec_8760 ,mem_vec_8761 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
for (x937 = x938, x937_p_0 = 0;
	x937 < x938 + 112;
	x937 += 56, x937_p_0 += 56){
	// y = 112, x = 56, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c702 = c703, c702_p_0 = 0;
		c702 < c703 + 32;
		c702 += 2, c702_p_0 += 2){
			for (y = y468, yp_0 = 0;
				y < y468 + 60;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 56, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (56 / 28)
				for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
					x936 < x937 + 56;
					x936 += 28, x936_p_1 += 28, x936_p_0 += 28){
					// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h448, hp_0 = 0;
						h < h448 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w468, wp_0 = 0;
							w < w468 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 1, c = 2, f = 32
							// T (x, 28) (28 / 1)
							for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
								x < x936 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8712 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8713 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
											c < c702 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8712);
											mem_vec_8712 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8713);
											mem_vec_8713 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8714);
											mem_vec_8714 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8715);
											mem_vec_8715 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8716);
											mem_vec_8716 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8717);
											mem_vec_8717 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8718);
											mem_vec_8718 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8719);
											mem_vec_8719 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8720);
											mem_vec_8720 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8721);
											mem_vec_8721 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8722);
											mem_vec_8722 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8723);
											mem_vec_8723 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8724);
											mem_vec_8724 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8725);
											mem_vec_8725 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8726);
											mem_vec_8726 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8727);
											mem_vec_8727 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8728);
											mem_vec_8728 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8729);
											mem_vec_8729 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8730);
											mem_vec_8730 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8731);
											mem_vec_8731 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8732);
											mem_vec_8732 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8733);
											mem_vec_8733 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8734);
											mem_vec_8734 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8735);
											mem_vec_8735 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8712);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8713);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8714);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8715);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8716);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8717);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8718);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8719);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8725);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8735);
							}
						}
					}
				}
			}
			for (y = y468 + 60, yp_0 = 0;
				y < y468 + 60 + 52;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 56, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (56 / 28)
				for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
					x936 < x937 + 56;
					x936 += 28, x936_p_1 += 28, x936_p_0 += 28){
					// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h448, hp_0 = 0;
						h < h448 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w468, wp_0 = 0;
							w < w468 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 1, c = 2, f = 32
							// T (x, 28) (28 / 1)
							for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
								x < x936 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8736 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8737 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_8760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
											c < c702 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8736);
											mem_vec_8736 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8737);
											mem_vec_8737 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8738);
											mem_vec_8738 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8739);
											mem_vec_8739 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8740);
											mem_vec_8740 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8741);
											mem_vec_8741 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8742);
											mem_vec_8742 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8743);
											mem_vec_8743 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8744);
											mem_vec_8744 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8745);
											mem_vec_8745 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8746);
											mem_vec_8746 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8747);
											mem_vec_8747 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8748);
											mem_vec_8748 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8749);
											mem_vec_8749 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8750);
											mem_vec_8750 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8751);
											mem_vec_8751 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8752);
											mem_vec_8752 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8753);
											mem_vec_8753 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8754);
											mem_vec_8754 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8755);
											mem_vec_8755 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8756);
											mem_vec_8756 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8757);
											mem_vec_8757 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8758);
											mem_vec_8758 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8759);
											mem_vec_8759 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8760);
											mem_vec_8760 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8761);
											mem_vec_8761 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8755);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8761);
							}
						}
					}
				}
			}
	}
}


}