#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (68, x);
  T (3, w); T (4, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 2), (Arg 3))]; T (17, y)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, w, wp_0, x, xp_0, x752_p_0, xp_1, x752, y, yp_0, y423_p_0, yp_1, y423;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y424 = 0;
IND_TYPE x753 = 0;
IND_TYPE h = 0;
IND_TYPE w278 = 0;
IND_TYPE c592 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7847 ,mem_vec_7848 ,mem_vec_7849 ,mem_vec_7850 ,mem_vec_7851 ,mem_vec_7852 ,mem_vec_7853 ,mem_vec_7854 ,mem_vec_7855 ,mem_vec_7856 ,mem_vec_7857 ,mem_vec_7858 ,mem_vec_7859 ,mem_vec_7860 ,mem_vec_7861 ,mem_vec_7862 ,mem_vec_7863 ,mem_vec_7864 ,mem_vec_7865 ,mem_vec_7866 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (y, 17) (136 / 8)
for (y423 = y424, y423_p_0 = 0;
	y423 < y424 + 136;
	y423 += 8, y423_p_0 += 8){
		for (y = y423, yp_1 = y423_p_0, yp_0 = 0;
			y < y423 + 2;
			y += 2, yp_1 += 2, yp_0 += 2){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (136 / 68)
			for (x752 = x753, x752_p_0 = 0;
				x752 < x753 + 136;
				x752 += 68, x752_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f394, fp_0 = 0;
					f < f394 + 128;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c591 = c592, c591_p_0 = 0;
						c591 < c592 + 64;
						c591 += 16, c591_p_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w278, wp_0 = 0;
							w < w278 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 68, h = 3, w = 1, c = 16, f = 64
							// T (x, 68) (68 / 1)
							for (x = x752, xp_1 = x752_p_0, xp_0 = 0;
								x < x752 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7847 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
											c < c591 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7847);
											mem_vec_7847 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7848);
											mem_vec_7848 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7849);
											mem_vec_7849 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7850);
											mem_vec_7850 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7851);
											mem_vec_7851 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7852);
											mem_vec_7852 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7853);
											mem_vec_7853 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7854);
											mem_vec_7854 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_7847);
											mem_vec_7847 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_7848);
											mem_vec_7848 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_7849);
											mem_vec_7849 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_7850);
											mem_vec_7850 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_7851);
											mem_vec_7851 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_7852);
											mem_vec_7852 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_7853);
											mem_vec_7853 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_7854);
											mem_vec_7854 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_7847);
											mem_vec_7847 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_7848);
											mem_vec_7848 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_7849);
											mem_vec_7849 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_7850);
											mem_vec_7850 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_7851);
											mem_vec_7851 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_7852);
											mem_vec_7852 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_7853);
											mem_vec_7853 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_7854);
											mem_vec_7854 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7854);
							}
						}
					}
				}
			}
		}
		for (y = y423 + 2, yp_1 = y423_p_0, yp_0 = 0;
			y < y423 + 2 + 6;
			y += 3, yp_1 += 3, yp_0 += 3){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (136 / 68)
			for (x752 = x753, x752_p_0 = 0;
				x752 < x753 + 136;
				x752 += 68, x752_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f394, fp_0 = 0;
					f < f394 + 128;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c591 = c592, c591_p_0 = 0;
						c591 < c592 + 64;
						c591 += 16, c591_p_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w278, wp_0 = 0;
							w < w278 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 68, h = 3, w = 1, c = 16, f = 64
							// T (x, 68) (68 / 1)
							for (x = x752, xp_1 = x752_p_0, xp_0 = 0;
								x < x752 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7856 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7857 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7858 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
											c < c591 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7855);
											mem_vec_7855 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7856);
											mem_vec_7856 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7857);
											mem_vec_7857 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7858);
											mem_vec_7858 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7859);
											mem_vec_7859 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7860);
											mem_vec_7860 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7861);
											mem_vec_7861 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7862);
											mem_vec_7862 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7863);
											mem_vec_7863 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7864);
											mem_vec_7864 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7865);
											mem_vec_7865 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7866);
											mem_vec_7866 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_7855);
											mem_vec_7855 = vec_19;

											vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_7856);
											mem_vec_7856 = vec_22;

											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_7857);
											mem_vec_7857 = vec_24;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_7858);
											mem_vec_7858 = vec_26;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_4);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_7859);
											mem_vec_7859 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_7860);
											mem_vec_7860 = vec_30;



											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_7861);
											mem_vec_7861 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_7862);
											mem_vec_7862 = vec_32;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_7863);
											mem_vec_7863 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_7864);
											mem_vec_7864 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_7865);
											mem_vec_7865 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_7866);
											mem_vec_7866 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_7855);
											mem_vec_7855 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_7856);
											mem_vec_7856 = vec_41;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_7857);
											mem_vec_7857 = vec_43;

											vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_7858);
											mem_vec_7858 = vec_45;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_7);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_7859);
											mem_vec_7859 = vec_47;



											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_7860);
											mem_vec_7860 = vec_49;



											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_7861);
											mem_vec_7861 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_7862);
											mem_vec_7862 = vec_51;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_8);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_7863);
											mem_vec_7863 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_7864);
											mem_vec_7864 = vec_54;



											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_7865);
											mem_vec_7865 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_7866);
											mem_vec_7866 = vec_56;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7866);
							}
						}
					}
				}
			}
		}
}


}