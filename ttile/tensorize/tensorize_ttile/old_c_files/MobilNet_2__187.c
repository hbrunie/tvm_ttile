#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (4, f);
  T (1, c); T (28, x)]
*/
IND_TYPE c, cp_0, c788_p_0, cp_1, c788, f, fp_0, w, wp_0, x, xp_0, x864_p_0, x865_p_0, xp_1, x864_p_1, xp_2, x864, x865, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y472 = 0;
IND_TYPE x866 = 0;
IND_TYPE h = 0;
IND_TYPE w448 = 0;
IND_TYPE c789 = 0;
IND_TYPE f392 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7884 ,mem_vec_7885 ,mem_vec_7886 ,mem_vec_7887 ,mem_vec_7888 ,mem_vec_7889 ,mem_vec_7890 ,mem_vec_7891 ,mem_vec_7892 ,mem_vec_7893 ,mem_vec_7894 ,mem_vec_7895 ,mem_vec_7896 ,mem_vec_7897 ,mem_vec_7898 ,mem_vec_7899 ,mem_vec_7900 ,mem_vec_7901 ,mem_vec_7902 ,mem_vec_7903 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
for (x865 = x866, x865_p_0 = 0;
	x865 < x866 + 56;
	x865 += 2, x865_p_0 += 2){
	// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
	// T (c, 1) (64 / 64)
	for (c788 = c789, c788_p_0 = 0;
		c788 < c789 + 64;
		c788 += 64, c788_p_0 += 64){
		// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
		// T (f, 4) (64 / 16)
		for (f = f392, fp_0 = 0;
			f < f392 + 64;
			f += 16, fp_0 += 16){
				for (y = y472, yp_0 = 0;
					y < y472 + 45;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 16
					// T (x, 2) (2 / 1)
					for (x864 = x865, x864_p_1 = x865_p_0, x864_p_0 = 0;
						x864 < x865 + 2;
						x864 += 1, x864_p_1 += 1, x864_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w448, wp_0 = 0;
							w < w448 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
							// T (x, 1) (1 / 1)
							for (x = x864, xp_2 = x864_p_1, xp_1 = x864_p_0, xp_0 = 0;
								x < x864 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
										// T (c, 64) (64 / 1)
										for (c = c788, cp_1 = c788_p_0, cp_0 = 0;
											c < c788 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7884);
											mem_vec_7884 = vec_0;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7885);
											mem_vec_7885 = vec_3;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7886);
											mem_vec_7886 = vec_5;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7887);
											mem_vec_7887 = vec_7;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7888);
											mem_vec_7888 = vec_9;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7889);
											mem_vec_7889 = vec_11;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_7890);
											mem_vec_7890 = vec_13;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_7891);
											mem_vec_7891 = vec_15;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7892);
											mem_vec_7892 = vec_17;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_7884);
											mem_vec_7884 = vec_19;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_7885);
											mem_vec_7885 = vec_22;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_7886);
											mem_vec_7886 = vec_24;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_7887);
											mem_vec_7887 = vec_26;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_7888);
											mem_vec_7888 = vec_28;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_7889);
											mem_vec_7889 = vec_30;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_7890);
											mem_vec_7890 = vec_32;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_7891);
											mem_vec_7891 = vec_34;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_7892);
											mem_vec_7892 = vec_36;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_7884);
											mem_vec_7884 = vec_38;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_7885);
											mem_vec_7885 = vec_41;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7886);
											mem_vec_7886 = vec_43;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_7887);
											mem_vec_7887 = vec_45;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_7888);
											mem_vec_7888 = vec_47;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_7889);
											mem_vec_7889 = vec_49;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_7890);
											mem_vec_7890 = vec_51;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_7891);
											mem_vec_7891 = vec_53;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_7892);
											mem_vec_7892 = vec_55;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7887);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7888);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7889);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7890);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7891);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7892);
							}
						}
					}
				}
				for (y = y472 + 45, yp_0 = 0;
					y < y472 + 45 + 11;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 16
					// T (x, 2) (2 / 1)
					for (x864 = x865, x864_p_1 = x865_p_0, x864_p_0 = 0;
						x864 < x865 + 2;
						x864 += 1, x864_p_1 += 1, x864_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w448, wp_0 = 0;
							w < w448 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
							// T (x, 1) (1 / 1)
							for (x = x864, xp_2 = x864_p_1, xp_1 = x864_p_0, xp_0 = 0;
								x < x864 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7893 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
										// T (c, 64) (64 / 1)
										for (c = c788, cp_1 = c788_p_0, cp_0 = 0;
											c < c788 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7893);
											mem_vec_7893 = vec_0;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7894);
											mem_vec_7894 = vec_3;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7895);
											mem_vec_7895 = vec_5;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7896);
											mem_vec_7896 = vec_7;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7897);
											mem_vec_7897 = vec_9;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7898);
											mem_vec_7898 = vec_11;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_7899);
											mem_vec_7899 = vec_13;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_7900);
											mem_vec_7900 = vec_15;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7901);
											mem_vec_7901 = vec_17;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7902);
											mem_vec_7902 = vec_19;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_7903);
											mem_vec_7903 = vec_21;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_7893);
											mem_vec_7893 = vec_23;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_7894);
											mem_vec_7894 = vec_26;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_7895);
											mem_vec_7895 = vec_28;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_7896);
											mem_vec_7896 = vec_30;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_7897);
											mem_vec_7897 = vec_32;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_7898);
											mem_vec_7898 = vec_34;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_7899);
											mem_vec_7899 = vec_36;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_7900);
											mem_vec_7900 = vec_38;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_7901);
											mem_vec_7901 = vec_40;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_7902);
											mem_vec_7902 = vec_42;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_7903);
											mem_vec_7903 = vec_44;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_7893);
											mem_vec_7893 = vec_46;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_7894);
											mem_vec_7894 = vec_49;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_7895);
											mem_vec_7895 = vec_51;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_7896);
											mem_vec_7896 = vec_53;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_7897);
											mem_vec_7897 = vec_55;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_7898);
											mem_vec_7898 = vec_57;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_7899);
											mem_vec_7899 = vec_59;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_7900);
											mem_vec_7900 = vec_61;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_7901);
											mem_vec_7901 = vec_63;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_7902);
											mem_vec_7902 = vec_65;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_7903);
											mem_vec_7903 = vec_67;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7893);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7894);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7895);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7896);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7897);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7898);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7899);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7900);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7901);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7902);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7903);
							}
						}
					}
				}
		}
	}
}


}