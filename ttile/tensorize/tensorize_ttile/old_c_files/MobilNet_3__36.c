#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (2, f);
  T (32, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1050_p_0, cp_1, c1050, f, fp_0, w, wp_0, x, xp_0, x1228_p_0, x1229_p_0, xp_1, x1228_p_1, xp_2, x1228, x1229, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y700 = 0;
IND_TYPE x1230 = 0;
IND_TYPE h = 0;
IND_TYPE w670 = 0;
IND_TYPE c1051 = 0;
IND_TYPE f1044 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9936 ,mem_vec_9937 ,mem_vec_9938 ,mem_vec_9939 ,mem_vec_9940 ,mem_vec_9941 ,mem_vec_9942 ,mem_vec_9943 ,mem_vec_9944 ,mem_vec_9945 ,mem_vec_9946 ,mem_vec_9947 ,mem_vec_9948 ,mem_vec_9949 ,mem_vec_9950 ,mem_vec_9951 ,mem_vec_9952 ,mem_vec_9953 ,mem_vec_9954 ,mem_vec_9955 ,mem_vec_9956 ,mem_vec_9957 ,mem_vec_9958 ,mem_vec_9959 ,mem_vec_9960 ,mem_vec_9961 ,mem_vec_9962 ,mem_vec_9963 ,mem_vec_9964 ,mem_vec_9965 ,mem_vec_9966 ,mem_vec_9967 ,mem_vec_9968 ,mem_vec_9969 ,mem_vec_9970 ,mem_vec_9971 ,mem_vec_9972 ,mem_vec_9973 ,mem_vec_9974 ,mem_vec_9975 ,mem_vec_9976 ,mem_vec_9977 ,mem_vec_9978 ,mem_vec_9979 ,mem_vec_9980 ,mem_vec_9981 ,mem_vec_9982 ,mem_vec_9983 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (56 / 56)
for (x1229 = x1230, x1229_p_0 = 0;
	x1229 < x1230 + 56;
	x1229 += 56, x1229_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (c, 32) (128 / 4)
	for (c1050 = c1051, c1050_p_0 = 0;
		c1050 < c1051 + 128;
		c1050 += 4, c1050_p_0 += 4){
		// y = 56, x = 56, h = 3, w = 3, c = 4, f = 128
		// T (f, 2) (128 / 64)
		for (f = f1044, fp_0 = 0;
			f < f1044 + 128;
			f += 64, fp_0 += 64){
				for (y = y700, yp_0 = 0;
					y < y700 + 35;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 64
					// T (x, 7) (56 / 8)
					for (x1228 = x1229, x1228_p_1 = x1229_p_0, x1228_p_0 = 0;
						x1228 < x1229 + 56;
						x1228 += 8, x1228_p_1 += 8, x1228_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w670, wp_0 = 0;
							w < w670 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 3, w = 1, c = 4, f = 64
							// T (x, 8) (8 / 1)
							for (x = x1228, xp_2 = x1228_p_1, xp_1 = x1228_p_0, xp_0 = 0;
								x < x1228 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9936 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9937 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9938 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9939 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_9952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_9955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
											c < c1050 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9936);
											mem_vec_9936 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9937);
											mem_vec_9937 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9938);
											mem_vec_9938 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9939);
											mem_vec_9939 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9940);
											mem_vec_9940 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9941);
											mem_vec_9941 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9942);
											mem_vec_9942 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9943);
											mem_vec_9943 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9944);
											mem_vec_9944 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9945);
											mem_vec_9945 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9946);
											mem_vec_9946 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9947);
											mem_vec_9947 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9948);
											mem_vec_9948 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9949);
											mem_vec_9949 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9950);
											mem_vec_9950 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9951);
											mem_vec_9951 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9952);
											mem_vec_9952 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9953);
											mem_vec_9953 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9954);
											mem_vec_9954 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9955);
											mem_vec_9955 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_9936);
											mem_vec_9936 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_9937);
											mem_vec_9937 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_9938);
											mem_vec_9938 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_9939);
											mem_vec_9939 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_9940);
											mem_vec_9940 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_9941);
											mem_vec_9941 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_9942);
											mem_vec_9942 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_9943);
											mem_vec_9943 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_9944);
											mem_vec_9944 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_9945);
											mem_vec_9945 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_9946);
											mem_vec_9946 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_9947);
											mem_vec_9947 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_9948);
											mem_vec_9948 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_9949);
											mem_vec_9949 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_9950);
											mem_vec_9950 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_9951);
											mem_vec_9951 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_9952);
											mem_vec_9952 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_9953);
											mem_vec_9953 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_9954);
											mem_vec_9954 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_9955);
											mem_vec_9955 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_9936);
											mem_vec_9936 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_9937);
											mem_vec_9937 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_9938);
											mem_vec_9938 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_9939);
											mem_vec_9939 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_9940);
											mem_vec_9940 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_9941);
											mem_vec_9941 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_9942);
											mem_vec_9942 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_9943);
											mem_vec_9943 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_9944);
											mem_vec_9944 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_9945);
											mem_vec_9945 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_9946);
											mem_vec_9946 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_9947);
											mem_vec_9947 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_9948);
											mem_vec_9948 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_9949);
											mem_vec_9949 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_9950);
											mem_vec_9950 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_9951);
											mem_vec_9951 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_9952);
											mem_vec_9952 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_9953);
											mem_vec_9953 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_9954);
											mem_vec_9954 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_9955);
											mem_vec_9955 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9939);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9945);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9946);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9947);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9948);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9949);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9951);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9952);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9953);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9954);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9955);
							}
						}
					}
				}
				for (y = y700 + 35, yp_0 = 0;
					y < y700 + 35 + 21;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 64
					// T (x, 7) (56 / 8)
					for (x1228 = x1229, x1228_p_1 = x1229_p_0, x1228_p_0 = 0;
						x1228 < x1229 + 56;
						x1228 += 8, x1228_p_1 += 8, x1228_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w670, wp_0 = 0;
							w < w670 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 3, w = 1, c = 4, f = 64
							// T (x, 8) (8 / 1)
							for (x = x1228, xp_2 = x1228_p_1, xp_1 = x1228_p_0, xp_0 = 0;
								x < x1228 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9956 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9957 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9958 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9959 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_9972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_9975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_9976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_9979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_9980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_9983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
											c < c1050 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9956);
											mem_vec_9956 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9957);
											mem_vec_9957 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9958);
											mem_vec_9958 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9959);
											mem_vec_9959 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9960);
											mem_vec_9960 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9961);
											mem_vec_9961 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9962);
											mem_vec_9962 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9963);
											mem_vec_9963 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9964);
											mem_vec_9964 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9965);
											mem_vec_9965 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9966);
											mem_vec_9966 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9967);
											mem_vec_9967 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9968);
											mem_vec_9968 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9969);
											mem_vec_9969 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9970);
											mem_vec_9970 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9971);
											mem_vec_9971 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9972);
											mem_vec_9972 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9973);
											mem_vec_9973 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9974);
											mem_vec_9974 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9975);
											mem_vec_9975 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9976);
											mem_vec_9976 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9977);
											mem_vec_9977 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_9978);
											mem_vec_9978 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_9979);
											mem_vec_9979 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_9980);
											mem_vec_9980 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_9981);
											mem_vec_9981 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_9982);
											mem_vec_9982 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_9983);
											mem_vec_9983 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_9956);
											mem_vec_9956 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_9957);
											mem_vec_9957 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_9958);
											mem_vec_9958 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_9959);
											mem_vec_9959 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_9960);
											mem_vec_9960 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_9961);
											mem_vec_9961 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_9962);
											mem_vec_9962 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_9963);
											mem_vec_9963 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_9964);
											mem_vec_9964 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_9965);
											mem_vec_9965 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_9966);
											mem_vec_9966 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_9967);
											mem_vec_9967 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_9968);
											mem_vec_9968 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_9969);
											mem_vec_9969 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_9970);
											mem_vec_9970 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_9971);
											mem_vec_9971 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_9972);
											mem_vec_9972 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_9973);
											mem_vec_9973 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_9974);
											mem_vec_9974 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_9975);
											mem_vec_9975 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_9976);
											mem_vec_9976 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_9977);
											mem_vec_9977 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_9978);
											mem_vec_9978 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_9979);
											mem_vec_9979 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_9980);
											mem_vec_9980 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_9981);
											mem_vec_9981 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_9982);
											mem_vec_9982 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_9983);
											mem_vec_9983 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_9956);
											mem_vec_9956 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_9957);
											mem_vec_9957 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_9958);
											mem_vec_9958 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_9959);
											mem_vec_9959 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_9960);
											mem_vec_9960 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_9961);
											mem_vec_9961 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_9962);
											mem_vec_9962 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_9963);
											mem_vec_9963 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_9964);
											mem_vec_9964 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_9965);
											mem_vec_9965 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_9966);
											mem_vec_9966 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_9967);
											mem_vec_9967 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_9968);
											mem_vec_9968 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_9969);
											mem_vec_9969 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_9970);
											mem_vec_9970 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_9971);
											mem_vec_9971 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_9972);
											mem_vec_9972 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_9973);
											mem_vec_9973 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_9974);
											mem_vec_9974 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_9975);
											mem_vec_9975 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_9976);
											mem_vec_9976 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_9977);
											mem_vec_9977 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_9978);
											mem_vec_9978 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_9979);
											mem_vec_9979 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_9980);
											mem_vec_9980 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_9981);
											mem_vec_9981 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_9982);
											mem_vec_9982 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_9983);
											mem_vec_9983 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9956);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9957);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9959);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_9978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_9979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_9982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_9983);
							}
						}
					}
				}
		}
	}
}


}