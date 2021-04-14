#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (4, f);
  T (64, c); T (28, x)]
*/
IND_TYPE c, cp_0, c782_p_0, cp_1, c782, f, fp_0, w, wp_0, x, xp_0, x856_p_0, x857_p_0, xp_1, x856_p_1, xp_2, x856, x857, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y468 = 0;
IND_TYPE x858 = 0;
IND_TYPE h = 0;
IND_TYPE w444 = 0;
IND_TYPE c783 = 0;
IND_TYPE f388 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7844 ,mem_vec_7845 ,mem_vec_7846 ,mem_vec_7847 ,mem_vec_7848 ,mem_vec_7849 ,mem_vec_7850 ,mem_vec_7851 ,mem_vec_7852 ,mem_vec_7853 ,mem_vec_7854 ,mem_vec_7855 ,mem_vec_7856 ,mem_vec_7857 ,mem_vec_7858 ,mem_vec_7859 ,mem_vec_7860 ,mem_vec_7861 ,mem_vec_7862 ,mem_vec_7863 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
for (x857 = x858, x857_p_0 = 0;
	x857 < x858 + 56;
	x857 += 2, x857_p_0 += 2){
	// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
	// T (c, 64) (64 / 1)
	for (c782 = c783, c782_p_0 = 0;
		c782 < c783 + 64;
		c782 += 1, c782_p_0 += 1){
		// y = 56, x = 2, h = 3, w = 3, c = 1, f = 64
		// T (f, 4) (64 / 16)
		for (f = f388, fp_0 = 0;
			f < f388 + 64;
			f += 16, fp_0 += 16){
				for (y = y468, yp_0 = 0;
					y < y468 + 45;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
					// T (x, 1) (2 / 2)
					for (x856 = x857, x856_p_1 = x857_p_0, x856_p_0 = 0;
						x856 < x857 + 2;
						x856 += 2, x856_p_1 += 2, x856_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
						// T (w, 3) (3 / 1)
						for (w = w444, wp_0 = 0;
							w < w444 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 16
							// T (x, 2) (2 / 1)
							for (x = x856, xp_2 = x856_p_1, xp_1 = x856_p_0, xp_0 = 0;
								x < x856 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
										// T (c, 1) (1 / 1)
										for (c = c782, cp_1 = c782_p_0, cp_0 = 0;
											c < c782 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7844);
											mem_vec_7844 = vec_0;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7845);
											mem_vec_7845 = vec_3;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7846);
											mem_vec_7846 = vec_5;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7847);
											mem_vec_7847 = vec_7;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7848);
											mem_vec_7848 = vec_9;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7849);
											mem_vec_7849 = vec_11;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_7850);
											mem_vec_7850 = vec_13;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_7851);
											mem_vec_7851 = vec_15;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7852);
											mem_vec_7852 = vec_17;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_7844);
											mem_vec_7844 = vec_19;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_7845);
											mem_vec_7845 = vec_22;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_7846);
											mem_vec_7846 = vec_24;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_7847);
											mem_vec_7847 = vec_26;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_7848);
											mem_vec_7848 = vec_28;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_7849);
											mem_vec_7849 = vec_30;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_7850);
											mem_vec_7850 = vec_32;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_7851);
											mem_vec_7851 = vec_34;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_7852);
											mem_vec_7852 = vec_36;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_7844);
											mem_vec_7844 = vec_38;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_7845);
											mem_vec_7845 = vec_41;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7846);
											mem_vec_7846 = vec_43;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_7847);
											mem_vec_7847 = vec_45;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_7848);
											mem_vec_7848 = vec_47;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_7849);
											mem_vec_7849 = vec_49;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_7850);
											mem_vec_7850 = vec_51;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_7851);
											mem_vec_7851 = vec_53;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_7852);
											mem_vec_7852 = vec_55;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7852);
							}
						}
					}
				}
				for (y = y468 + 45, yp_0 = 0;
					y < y468 + 45 + 11;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
					// T (x, 1) (2 / 2)
					for (x856 = x857, x856_p_1 = x857_p_0, x856_p_0 = 0;
						x856 < x857 + 2;
						x856 += 2, x856_p_1 += 2, x856_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
						// T (w, 3) (3 / 1)
						for (w = w444, wp_0 = 0;
							w < w444 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 16
							// T (x, 2) (2 / 1)
							for (x = x856, xp_2 = x856_p_1, xp_1 = x856_p_0, xp_0 = 0;
								x < x856 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
										// T (c, 1) (1 / 1)
										for (c = c782, cp_1 = c782_p_0, cp_0 = 0;
											c < c782 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7853);
											mem_vec_7853 = vec_0;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7854);
											mem_vec_7854 = vec_3;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7855);
											mem_vec_7855 = vec_5;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7856);
											mem_vec_7856 = vec_7;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7857);
											mem_vec_7857 = vec_9;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7858);
											mem_vec_7858 = vec_11;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_7859);
											mem_vec_7859 = vec_13;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_7860);
											mem_vec_7860 = vec_15;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7861);
											mem_vec_7861 = vec_17;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7862);
											mem_vec_7862 = vec_19;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_7863);
											mem_vec_7863 = vec_21;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_7853);
											mem_vec_7853 = vec_23;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_7854);
											mem_vec_7854 = vec_26;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_7855);
											mem_vec_7855 = vec_28;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_7856);
											mem_vec_7856 = vec_30;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_7857);
											mem_vec_7857 = vec_32;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_7858);
											mem_vec_7858 = vec_34;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_7859);
											mem_vec_7859 = vec_36;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_7860);
											mem_vec_7860 = vec_38;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_7861);
											mem_vec_7861 = vec_40;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_7862);
											mem_vec_7862 = vec_42;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_7863);
											mem_vec_7863 = vec_44;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_7853);
											mem_vec_7853 = vec_46;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_7854);
											mem_vec_7854 = vec_49;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_7855);
											mem_vec_7855 = vec_51;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_7856);
											mem_vec_7856 = vec_53;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_7857);
											mem_vec_7857 = vec_55;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_7858);
											mem_vec_7858 = vec_57;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_7859);
											mem_vec_7859 = vec_59;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_7860);
											mem_vec_7860 = vec_61;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_7861);
											mem_vec_7861 = vec_63;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_7862);
											mem_vec_7862 = vec_65;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_7863);
											mem_vec_7863 = vec_67;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7863);
							}
						}
					}
				}
		}
	}
}


}