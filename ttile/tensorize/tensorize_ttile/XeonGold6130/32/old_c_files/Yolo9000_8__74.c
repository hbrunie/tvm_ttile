#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (16, f);
  T (4, x); T (1, y)]
*/
IND_TYPE c, cp_0, c561_p_0, cp_1, c561, f, fp_0, w, wp_0, x, xp_0, x561_p_0, xp_1, x561, y, yp_0, y391_p_0, yp_1, y391;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y392 = 0;
IND_TYPE x562 = 0;
IND_TYPE h = 0;
IND_TYPE w344 = 0;
IND_TYPE c562 = 0;
IND_TYPE f714 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6882 ,mem_vec_6883 ,mem_vec_6884 ,mem_vec_6885 ,mem_vec_6886 ,mem_vec_6887 ,mem_vec_6888 ,mem_vec_6889 ,mem_vec_6890 ,mem_vec_6891 ,mem_vec_6892 ,mem_vec_6893 ,mem_vec_6894 ,mem_vec_6895 ,mem_vec_6896 ,mem_vec_6897 ,mem_vec_6898 ,mem_vec_6899 ,mem_vec_6900 ,mem_vec_6901 ,mem_vec_6902 ,mem_vec_6903 ,mem_vec_6904 ,mem_vec_6905 ,mem_vec_6906 ,mem_vec_6907 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (y, 1) (68 / 68)
for (y391 = y392, y391_p_0 = 0;
	y391 < y392 + 68;
	y391 += 68, y391_p_0 += 68){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 4) (68 / 17)
	for (x561 = x562, x561_p_0 = 0;
		x561 < x562 + 68;
		x561 += 17, x561_p_0 += 17){
		// y = 68, x = 17, h = 3, w = 3, c = 128, f = 256
		// T (f, 16) (256 / 16)
		for (f = f714, fp_0 = 0;
			f < f714 + 256;
			f += 16, fp_0 += 16){
				for (y = y391, yp_1 = y391_p_0, yp_0 = 0;
					y < y391 + 12;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
					// T (c, 4) (128 / 32)
					for (c561 = c562, c561_p_0 = 0;
						c561 < c562 + 128;
						c561 += 32, c561_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w344, wp_0 = 0;
							w < w344 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x561, xp_1 = x561_p_0, xp_0 = 0;
								x < x561 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6882 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c561, cp_1 = c561_p_0, cp_0 = 0;
											c < c561 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6882);
											mem_vec_6882 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6883);
											mem_vec_6883 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6884);
											mem_vec_6884 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6885);
											mem_vec_6885 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6886);
											mem_vec_6886 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6887);
											mem_vec_6887 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_6888);
											mem_vec_6888 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6889);
											mem_vec_6889 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6890);
											mem_vec_6890 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6891);
											mem_vec_6891 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_6892);
											mem_vec_6892 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6893);
											mem_vec_6893 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_6882);
											mem_vec_6882 = vec_25;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6883);
											mem_vec_6883 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_6884);
											mem_vec_6884 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_6885);
											mem_vec_6885 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6886);
											mem_vec_6886 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_6887);
											mem_vec_6887 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_6888);
											mem_vec_6888 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6889);
											mem_vec_6889 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_6890);
											mem_vec_6890 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_6891);
											mem_vec_6891 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_6892);
											mem_vec_6892 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_6893);
											mem_vec_6893 = vec_48;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_6882);
											mem_vec_6882 = vec_50;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_6883);
											mem_vec_6883 = vec_53;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_6884);
											mem_vec_6884 = vec_55;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_6885);
											mem_vec_6885 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_6886);
											mem_vec_6886 = vec_59;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_6887);
											mem_vec_6887 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_6888);
											mem_vec_6888 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_6889);
											mem_vec_6889 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_6890);
											mem_vec_6890 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_6891);
											mem_vec_6891 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_6892);
											mem_vec_6892 = vec_71;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_6893);
											mem_vec_6893 = vec_73;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6882);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6883);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6887);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6888);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6889);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6890);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6891);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6892);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6893);
							}
						}
					}
				}
				for (y = y391 + 12, yp_1 = y391_p_0, yp_0 = 0;
					y < y391 + 12 + 56;
					y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
					// T (c, 4) (128 / 32)
					for (c561 = c562, c561_p_0 = 0;
						c561 < c562 + 128;
						c561 += 32, c561_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w344, wp_0 = 0;
							w < w344 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x561, xp_1 = x561_p_0, xp_0 = 0;
								x < x561 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6894 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_6906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_6907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c561, cp_1 = c561_p_0, cp_0 = 0;
											c < c561 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6894);
											mem_vec_6894 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6895);
											mem_vec_6895 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6896);
											mem_vec_6896 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6897);
											mem_vec_6897 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6898);
											mem_vec_6898 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6899);
											mem_vec_6899 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_6900);
											mem_vec_6900 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6901);
											mem_vec_6901 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6902);
											mem_vec_6902 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6903);
											mem_vec_6903 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_6904);
											mem_vec_6904 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6905);
											mem_vec_6905 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_26 = _mm512_set1_ps(scal_12);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_6906);
											mem_vec_6906 = vec_25;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_28 = _mm512_set1_ps(scal_13);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_6907);
											mem_vec_6907 = vec_27;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_14);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6894);
											mem_vec_6894 = vec_29;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_31, mem_vec_6895);
											mem_vec_6895 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_6896);
											mem_vec_6896 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_31, mem_vec_6897);
											mem_vec_6897 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6898);
											mem_vec_6898 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_6899);
											mem_vec_6899 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_31, mem_vec_6900);
											mem_vec_6900 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_31, mem_vec_6901);
											mem_vec_6901 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_6902);
											mem_vec_6902 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6903);
											mem_vec_6903 = vec_48;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_51 = _mm512_set1_ps(scal_24);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_31, mem_vec_6904);
											mem_vec_6904 = vec_50;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_25);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_6905);
											mem_vec_6905 = vec_52;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_55 = _mm512_set1_ps(scal_26);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_31, mem_vec_6906);
											mem_vec_6906 = vec_54;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
											vec_57 = _mm512_set1_ps(scal_27);


											vec_56 = _mm512_fmadd_ps(vec_57, vec_31, mem_vec_6907);
											mem_vec_6907 = vec_56;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_28);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6894);
											mem_vec_6894 = vec_58;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_60, mem_vec_6895);
											mem_vec_6895 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_6896);
											mem_vec_6896 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_60, mem_vec_6897);
											mem_vec_6897 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6898);
											mem_vec_6898 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_6899);
											mem_vec_6899 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_60, mem_vec_6900);
											mem_vec_6900 = vec_71;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_60, mem_vec_6901);
											mem_vec_6901 = vec_73;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_36);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_6902);
											mem_vec_6902 = vec_75;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_37);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6903);
											mem_vec_6903 = vec_77;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_38);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_60, mem_vec_6904);
											mem_vec_6904 = vec_79;
											scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_39);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_6905);
											mem_vec_6905 = vec_81;
											scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_84 = _mm512_set1_ps(scal_40);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_60, mem_vec_6906);
											mem_vec_6906 = vec_83;
											scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
											vec_86 = _mm512_set1_ps(scal_41);


											vec_85 = _mm512_fmadd_ps(vec_86, vec_60, mem_vec_6907);
											mem_vec_6907 = vec_85;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6894);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6895);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6896);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6897);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6898);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6899);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6900);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6901);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6902);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6903);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6904);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6905);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6906);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6907);
							}
						}
					}
				}
		}
	}
}


}