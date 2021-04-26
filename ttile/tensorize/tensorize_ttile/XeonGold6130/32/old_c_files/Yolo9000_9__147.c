#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (4, f); T (17, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]]
*/
IND_TYPE c, cp_0, c222_p_0, cp_1, c222, f, fp_0, x, xp_0, x296_p_0, x297_p_0, xp_1, x296_p_1, xp_2, x296, x297, y, yp_0, y222_p_0, yp_1, y222;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y223 = 0;
IND_TYPE x298 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c223 = 0;
IND_TYPE f148 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3728 ,mem_vec_3729 ,mem_vec_3730 ,mem_vec_3731 ,mem_vec_3732 ,mem_vec_3733 ,mem_vec_3734 ,mem_vec_3735 ,mem_vec_3736 ,mem_vec_3737 ,mem_vec_3738 ,mem_vec_3739 ,mem_vec_3740 ,mem_vec_3741 ,mem_vec_3742 ,mem_vec_3743 ,mem_vec_3744 ,mem_vec_3745 ,mem_vec_3746 ,mem_vec_3747 ,mem_vec_3748 ,mem_vec_3749 ,mem_vec_3750 ,mem_vec_3751 ,mem_vec_3752 ,mem_vec_3753 ,mem_vec_3754 ,mem_vec_3755 ,mem_vec_3756 ,mem_vec_3757 ,mem_vec_3758 ,mem_vec_3759 ,mem_vec_3760 ,mem_vec_3761 ,mem_vec_3762 ,mem_vec_3763 ,mem_vec_3764 ,mem_vec_3765 ,mem_vec_3766 ,mem_vec_3767 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y222 = y223, y222_p_0 = 0;
		y222 < y223 + 8;
		y222 += 8, y222_p_0 += 8){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x297 = x298, x297_p_0 = 0;
			x297 < x298 + 68;
			x297 += 68, x297_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y222, yp_1 = y222_p_0, yp_0 = 0;
				y < y222 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x296 = x297, x296_p_1 = x297_p_0, x296_p_0 = 0;
					x296 < x297 + 68;
					x296 += 4, x296_p_1 += 4, x296_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f148, fp_0 = 0;
						f < f148 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c222 = c223, c222_p_0 = 0;
							c222 < c223 + 256;
							c222 += 256, c222_p_0 += 256){
							// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
							// T (x, 4) (4 / 1)
							for (x = x296, xp_2 = x296_p_1, xp_1 = x296_p_0, xp_0 = 0;
								x < x296 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
											c < c222 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3728);
											mem_vec_3728 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3729);
											mem_vec_3729 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3730);
											mem_vec_3730 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3731);
											mem_vec_3731 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3732);
											mem_vec_3732 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3733);
											mem_vec_3733 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3734);
											mem_vec_3734 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3735);
											mem_vec_3735 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3736);
											mem_vec_3736 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3737);
											mem_vec_3737 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3738);
											mem_vec_3738 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3739);
											mem_vec_3739 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3740);
											mem_vec_3740 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3741);
											mem_vec_3741 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3742);
											mem_vec_3742 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3743);
											mem_vec_3743 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3743);
							}
						}
					}
				}
			}
		}
	}
	for (y222 = y223 + 8, y222_p_0 = 0;
		y222 < y223 + 8 + 60;
		y222 += 12, y222_p_0 += 12){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x297 = x298, x297_p_0 = 0;
			x297 < x298 + 68;
			x297 += 68, x297_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y222, yp_1 = y222_p_0, yp_0 = 0;
				y < y222 + 12;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x296 = x297, x296_p_1 = x297_p_0, x296_p_0 = 0;
					x296 < x297 + 68;
					x296 += 4, x296_p_1 += 4, x296_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f148, fp_0 = 0;
						f < f148 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c222 = c223, c222_p_0 = 0;
							c222 < c223 + 256;
							c222 += 256, c222_p_0 += 256){
							// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
							// T (x, 4) (4 / 1)
							for (x = x296, xp_2 = x296_p_1, xp_1 = x296_p_0, xp_0 = 0;
								x < x296 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3744 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3745 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
											c < c222 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3744);
											mem_vec_3744 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3745);
											mem_vec_3745 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3746);
											mem_vec_3746 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3747);
											mem_vec_3747 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3748);
											mem_vec_3748 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3749);
											mem_vec_3749 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3750);
											mem_vec_3750 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3751);
											mem_vec_3751 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3752);
											mem_vec_3752 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3753);
											mem_vec_3753 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3754);
											mem_vec_3754 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3755);
											mem_vec_3755 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3756);
											mem_vec_3756 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3757);
											mem_vec_3757 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3758);
											mem_vec_3758 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3759);
											mem_vec_3759 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3760);
											mem_vec_3760 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3761);
											mem_vec_3761 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3762);
											mem_vec_3762 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3763);
											mem_vec_3763 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3764);
											mem_vec_3764 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3765);
											mem_vec_3765 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3766);
											mem_vec_3766 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3767);
											mem_vec_3767 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3755);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3767);
							}
						}
					}
				}
			}
		}
	}


}