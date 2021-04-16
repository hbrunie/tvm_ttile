#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (28, x);
  T (3, w); T (4, c); T (4, f); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (1, x)]
*/
IND_TYPE c, cp_0, c129_p_0, cp_1, c129, f, fp_0, w, wp_0, x, xp_0, x144_p_0, x145_p_0, xp_1, x144_p_1, xp_2, x144, x145, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y86 = 0;
IND_TYPE x146 = 0;
IND_TYPE h = 0;
IND_TYPE w82 = 0;
IND_TYPE c130 = 0;
IND_TYPE f130 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,mem_vec_988 ,mem_vec_989 ,mem_vec_990 ,mem_vec_991 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (56 / 56)
for (x145 = x146, x145_p_0 = 0;
	x145 < x146 + 56;
	x145 += 56, x145_p_0 += 56){
		for (y = y86, yp_0 = 0;
			y < y86 + 45;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (56 / 28)
			for (x144 = x145, x144_p_1 = x145_p_0, x144_p_0 = 0;
				x144 < x145 + 56;
				x144 += 28, x144_p_1 += 28, x144_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f130, fp_0 = 0;
					f < f130 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c129 = c130, c129_p_0 = 0;
						c129 < c130 + 128;
						c129 += 32, c129_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w82, wp_0 = 0;
							w < w82 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x144, xp_2 = x144_p_1, xp_1 = x144_p_0, xp_0 = 0;
								x < x144 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c129, cp_1 = c129_p_0, cp_0 = 0;
											c < c129 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_956);
											mem_vec_956 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_957);
											mem_vec_957 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_958);
											mem_vec_958 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_959);
											mem_vec_959 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_960);
											mem_vec_960 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_961);
											mem_vec_961 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_962);
											mem_vec_962 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_963);
											mem_vec_963 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_964);
											mem_vec_964 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_965);
											mem_vec_965 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_966);
											mem_vec_966 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_967);
											mem_vec_967 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_968);
											mem_vec_968 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_969);
											mem_vec_969 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_970);
											mem_vec_970 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_971);
											mem_vec_971 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_972);
											mem_vec_972 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_973);
											mem_vec_973 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_956);
											mem_vec_956 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_957);
											mem_vec_957 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_958);
											mem_vec_958 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_959);
											mem_vec_959 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_960);
											mem_vec_960 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_961);
											mem_vec_961 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_962);
											mem_vec_962 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_963);
											mem_vec_963 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_964);
											mem_vec_964 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_965);
											mem_vec_965 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_966);
											mem_vec_966 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_967);
											mem_vec_967 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_968);
											mem_vec_968 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_969);
											mem_vec_969 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_970);
											mem_vec_970 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_971);
											mem_vec_971 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_972);
											mem_vec_972 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_973);
											mem_vec_973 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_956);
											mem_vec_956 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_957);
											mem_vec_957 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_958);
											mem_vec_958 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_959);
											mem_vec_959 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_960);
											mem_vec_960 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_961);
											mem_vec_961 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_962);
											mem_vec_962 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_963);
											mem_vec_963 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_964);
											mem_vec_964 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_965);
											mem_vec_965 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_966);
											mem_vec_966 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_967);
											mem_vec_967 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_968);
											mem_vec_968 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_969);
											mem_vec_969 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_970);
											mem_vec_970 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_971);
											mem_vec_971 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_972);
											mem_vec_972 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_973);
											mem_vec_973 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_956);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_957);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_959);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_973);
							}
						}
					}
				}
			}
		}
		for (y = y86 + 45, yp_0 = 0;
			y < y86 + 45 + 11;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (56 / 28)
			for (x144 = x145, x144_p_1 = x145_p_0, x144_p_0 = 0;
				x144 < x145 + 56;
				x144 += 28, x144_p_1 += 28, x144_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f130, fp_0 = 0;
					f < f130 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c129 = c130, c129_p_0 = 0;
						c129 < c130 + 128;
						c129 += 32, c129_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w82, wp_0 = 0;
							w < w82 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x144, xp_2 = x144_p_1, xp_1 = x144_p_0, xp_0 = 0;
								x < x144 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c129, cp_1 = c129_p_0, cp_0 = 0;
											c < c129 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_974);
											mem_vec_974 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_975);
											mem_vec_975 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_976);
											mem_vec_976 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_977);
											mem_vec_977 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_978);
											mem_vec_978 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_979);
											mem_vec_979 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_980);
											mem_vec_980 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_981);
											mem_vec_981 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_982);
											mem_vec_982 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_983);
											mem_vec_983 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_984);
											mem_vec_984 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_985);
											mem_vec_985 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_986);
											mem_vec_986 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_987);
											mem_vec_987 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_988);
											mem_vec_988 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_989);
											mem_vec_989 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_990);
											mem_vec_990 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_991);
											mem_vec_991 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_992);
											mem_vec_992 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_993);
											mem_vec_993 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_994);
											mem_vec_994 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_995);
											mem_vec_995 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_974);
											mem_vec_974 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_975);
											mem_vec_975 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_976);
											mem_vec_976 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_977);
											mem_vec_977 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_978);
											mem_vec_978 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_979);
											mem_vec_979 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_980);
											mem_vec_980 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_981);
											mem_vec_981 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_982);
											mem_vec_982 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_983);
											mem_vec_983 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_984);
											mem_vec_984 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_985);
											mem_vec_985 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_986);
											mem_vec_986 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_987);
											mem_vec_987 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_988);
											mem_vec_988 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_989);
											mem_vec_989 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_990);
											mem_vec_990 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_991);
											mem_vec_991 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_992);
											mem_vec_992 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_993);
											mem_vec_993 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_994);
											mem_vec_994 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_995);
											mem_vec_995 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_974);
											mem_vec_974 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_975);
											mem_vec_975 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_976);
											mem_vec_976 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_977);
											mem_vec_977 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_978);
											mem_vec_978 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_979);
											mem_vec_979 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_980);
											mem_vec_980 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_981);
											mem_vec_981 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_982);
											mem_vec_982 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_983);
											mem_vec_983 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_984);
											mem_vec_984 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_985);
											mem_vec_985 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_986);
											mem_vec_986 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_987);
											mem_vec_987 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_988);
											mem_vec_988 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_989);
											mem_vec_989 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_990);
											mem_vec_990 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_991);
											mem_vec_991 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_992);
											mem_vec_992 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_993);
											mem_vec_993 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_994);
											mem_vec_994 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_995);
											mem_vec_995 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_994);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_995);
							}
						}
					}
				}
			}
		}
}


}