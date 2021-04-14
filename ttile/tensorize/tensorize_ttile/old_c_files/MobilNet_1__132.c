#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c636_p_0, cp_1, c636, h, hp_0, w, wp_0, x, xp_0, x848_p_0, x849_p_0, xp_1, x848_p_1, xp_2, x848, x849, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y424 = 0;
IND_TYPE x850 = 0;
IND_TYPE h404 = 0;
IND_TYPE w424 = 0;
IND_TYPE c637 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7636 ,mem_vec_7637 ,mem_vec_7638 ,mem_vec_7639 ,mem_vec_7640 ,mem_vec_7641 ,mem_vec_7642 ,mem_vec_7643 ,mem_vec_7644 ,mem_vec_7645 ,mem_vec_7646 ,mem_vec_7647 ,mem_vec_7648 ,mem_vec_7649 ,mem_vec_7650 ,mem_vec_7651 ,mem_vec_7652 ,mem_vec_7653 ,mem_vec_7654 ,mem_vec_7655 ,mem_vec_7656 ,mem_vec_7657 ,mem_vec_7658 ,mem_vec_7659 ,mem_vec_7660 ,mem_vec_7661 ,mem_vec_7662 ,mem_vec_7663 ,mem_vec_7664 ,mem_vec_7665 ,mem_vec_7666 ,mem_vec_7667 ,mem_vec_7668 ,mem_vec_7669 ,mem_vec_7670 ,mem_vec_7671 ,mem_vec_7672 ,mem_vec_7673 ,mem_vec_7674 ,mem_vec_7675 ,mem_vec_7676 ,mem_vec_7677 ,mem_vec_7678 ,mem_vec_7679 ,mem_vec_7680 ,mem_vec_7681 ,mem_vec_7682 ,mem_vec_7683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x849 = x850, x849_p_0 = 0;
	x849 < x850 + 112;
	x849 += 16, x849_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c636 = c637, c636_p_0 = 0;
		c636 < c637 + 32;
		c636 += 16, c636_p_0 += 16){
			for (y = y424, yp_0 = 0;
				y < y424 + 99;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 16, h = 3, w = 3, c = 16, f = 32
				// T (x, 4) (16 / 4)
				for (x848 = x849, x848_p_1 = x849_p_0, x848_p_0 = 0;
					x848 < x849 + 16;
					x848 += 4, x848_p_1 += 4, x848_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h404, hp_0 = 0;
						h < h404 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w424, wp_0 = 0;
							w < w424 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x848, xp_2 = x848_p_1, xp_1 = x848_p_0, xp_0 = 0;
								x < x848 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7636 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7637 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
											c < c636 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7636);
											mem_vec_7636 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7637);
											mem_vec_7637 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7638);
											mem_vec_7638 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7639);
											mem_vec_7639 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7640);
											mem_vec_7640 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7641);
											mem_vec_7641 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7642);
											mem_vec_7642 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7643);
											mem_vec_7643 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7644);
											mem_vec_7644 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7645);
											mem_vec_7645 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7646);
											mem_vec_7646 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7647);
											mem_vec_7647 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7648);
											mem_vec_7648 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7649);
											mem_vec_7649 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7650);
											mem_vec_7650 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7651);
											mem_vec_7651 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7652);
											mem_vec_7652 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7653);
											mem_vec_7653 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7654);
											mem_vec_7654 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7655);
											mem_vec_7655 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7656);
											mem_vec_7656 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7657);
											mem_vec_7657 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7657);
							}
						}
					}
				}
			}
			for (y = y424 + 99, yp_0 = 0;
				y < y424 + 99 + 13;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 16, h = 3, w = 3, c = 16, f = 32
				// T (x, 4) (16 / 4)
				for (x848 = x849, x848_p_1 = x849_p_0, x848_p_0 = 0;
					x848 < x849 + 16;
					x848 += 4, x848_p_1 += 4, x848_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h404, hp_0 = 0;
						h < h404 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w424, wp_0 = 0;
							w < w424 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x848, xp_2 = x848_p_1, xp_1 = x848_p_0, xp_0 = 0;
								x < x848 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_7680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_7681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_7682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_7683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
											c < c636 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7658);
											mem_vec_7658 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7659);
											mem_vec_7659 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7660);
											mem_vec_7660 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7661);
											mem_vec_7661 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7662);
											mem_vec_7662 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7663);
											mem_vec_7663 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7664);
											mem_vec_7664 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7665);
											mem_vec_7665 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7666);
											mem_vec_7666 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7667);
											mem_vec_7667 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7668);
											mem_vec_7668 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7669);
											mem_vec_7669 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7670);
											mem_vec_7670 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7671);
											mem_vec_7671 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7672);
											mem_vec_7672 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7673);
											mem_vec_7673 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7674);
											mem_vec_7674 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7675);
											mem_vec_7675 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7676);
											mem_vec_7676 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7677);
											mem_vec_7677 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7678);
											mem_vec_7678 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7679);
											mem_vec_7679 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7680);
											mem_vec_7680 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7681);
											mem_vec_7681 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7682);
											mem_vec_7682 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7683);
											mem_vec_7683 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7671);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7672);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7673);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7674);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7675);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7676);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7677);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7678);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7679);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7680);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7681);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7682);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7683);
							}
						}
					}
				}
			}
	}
}


}