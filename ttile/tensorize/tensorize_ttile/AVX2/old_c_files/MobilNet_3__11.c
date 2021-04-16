#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (2, c); T (8, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]]
*/
IND_TYPE c, cp_0, c784_p_0, c785_p_0, cp_1, c784_p_1, cp_2, c784, c785, f, fp_0, w, wp_0, x, xp_0, x588_p_0, xp_1, x588, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y392 = 0;
IND_TYPE x589 = 0;
IND_TYPE h = 0;
IND_TYPE w310 = 0;
IND_TYPE c786 = 0;
IND_TYPE f568 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8956 ,mem_vec_8957 ,mem_vec_8958 ,mem_vec_8959 ,mem_vec_8960 ,mem_vec_8961 ,mem_vec_8962 ,mem_vec_8963 ,mem_vec_8964 ,mem_vec_8965 ,mem_vec_8966 ,mem_vec_8967 ,mem_vec_8968 ,mem_vec_8969 ,mem_vec_8970 ,mem_vec_8971 ,mem_vec_8972 ,mem_vec_8973 ,mem_vec_8974 ,mem_vec_8975 ,mem_vec_8976 ,mem_vec_8977 ,mem_vec_8978 ,mem_vec_8979 ,mem_vec_8980 ,mem_vec_8981 ,mem_vec_8982 ,mem_vec_8983 ,mem_vec_8984 ,mem_vec_8985 ,mem_vec_8986 ,mem_vec_8987 ,mem_vec_8988 ,mem_vec_8989 ,mem_vec_8990 ,mem_vec_8991 ,mem_vec_8992 ,mem_vec_8993 ,mem_vec_8994 ,mem_vec_8995 ,mem_vec_8996 ,mem_vec_8997 ,mem_vec_8998 ,mem_vec_8999 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y = y392, yp_0 = 0;
		y < y392 + 20;
		y += 10, yp_0 += 10){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x588 = x589, x588_p_0 = 0;
			x588 < x589 + 56;
			x588 += 28, x588_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (c, 4) (128 / 32)
			for (c785 = c786, c785_p_0 = 0;
				c785 < c786 + 128;
				c785 += 32, c785_p_0 += 32){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 128
				// T (f, 8) (128 / 16)
				for (f = f568, fp_0 = 0;
					f < f568 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (c, 2) (32 / 16)
					for (c784 = c785, c784_p_1 = c785_p_0, c784_p_0 = 0;
						c784 < c785 + 32;
						c784 += 16, c784_p_1 += 16, c784_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 16
						// T (x, 28) (28 / 1)
						for (x = x588, xp_1 = x588_p_0, xp_0 = 0;
							x < x588 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w310, wp_0 = 0;
								w < w310 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8956 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8957 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c784, cp_2 = c784_p_1, cp_1 = c784_p_0, cp_0 = 0;
											c < c784 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8956);
											mem_vec_8956 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8957);
											mem_vec_8957 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8958);
											mem_vec_8958 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8959);
											mem_vec_8959 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8960);
											mem_vec_8960 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8961);
											mem_vec_8961 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8962);
											mem_vec_8962 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8963);
											mem_vec_8963 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8964);
											mem_vec_8964 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8965);
											mem_vec_8965 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8966);
											mem_vec_8966 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8967);
											mem_vec_8967 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8968);
											mem_vec_8968 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8969);
											mem_vec_8969 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8970);
											mem_vec_8970 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8971);
											mem_vec_8971 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8972);
											mem_vec_8972 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8973);
											mem_vec_8973 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8974);
											mem_vec_8974 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8975);
											mem_vec_8975 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_8956);
											mem_vec_8956 = vec_32;

											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_8957);
											mem_vec_8957 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_8958);
											mem_vec_8958 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_8959);
											mem_vec_8959 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_8960);
											mem_vec_8960 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_8961);
											mem_vec_8961 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_8962);
											mem_vec_8962 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8963);
											mem_vec_8963 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_8964);
											mem_vec_8964 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_8965);
											mem_vec_8965 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_8966);
											mem_vec_8966 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_8967);
											mem_vec_8967 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_8968);
											mem_vec_8968 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_8969);
											mem_vec_8969 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_8970);
											mem_vec_8970 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_8971);
											mem_vec_8971 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_8972);
											mem_vec_8972 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8973);
											mem_vec_8973 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_8974);
											mem_vec_8974 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_8975);
											mem_vec_8975 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_8956);
											mem_vec_8956 = vec_64;

											vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_8957);
											mem_vec_8957 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_8958);
											mem_vec_8958 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_8959);
											mem_vec_8959 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8960);
											mem_vec_8960 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_8961);
											mem_vec_8961 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_8962);
											mem_vec_8962 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_8963);
											mem_vec_8963 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_8964);
											mem_vec_8964 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_8965);
											mem_vec_8965 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_8966);
											mem_vec_8966 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_8967);
											mem_vec_8967 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_8968);
											mem_vec_8968 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_8969);
											mem_vec_8969 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_8970);
											mem_vec_8970 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_8971);
											mem_vec_8971 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_8972);
											mem_vec_8972 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_8973);
											mem_vec_8973 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_8974);
											mem_vec_8974 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_8975);
											mem_vec_8975 = vec_95;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8956);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8957);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8958);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8959);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8960);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8961);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8962);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8963);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8964);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8965);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8966);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8967);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8968);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8969);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8970);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8971);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8972);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8973);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8974);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8975);
							}
						}
					}
				}
			}
		}
	}
	for (y = y392 + 20, yp_0 = 0;
		y < y392 + 20 + 36;
		y += 12, yp_0 += 12){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x588 = x589, x588_p_0 = 0;
			x588 < x589 + 56;
			x588 += 28, x588_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (c, 4) (128 / 32)
			for (c785 = c786, c785_p_0 = 0;
				c785 < c786 + 128;
				c785 += 32, c785_p_0 += 32){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 128
				// T (f, 8) (128 / 16)
				for (f = f568, fp_0 = 0;
					f < f568 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (c, 2) (32 / 16)
					for (c784 = c785, c784_p_1 = c785_p_0, c784_p_0 = 0;
						c784 < c785 + 32;
						c784 += 16, c784_p_1 += 16, c784_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 16
						// T (x, 28) (28 / 1)
						for (x = x588, xp_1 = x588_p_0, xp_0 = 0;
							x < x588 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w310, wp_0 = 0;
								w < w310 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8976 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8977 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_8996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_8998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c784, cp_2 = c784_p_1, cp_1 = c784_p_0, cp_0 = 0;
											c < c784 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8976);
											mem_vec_8976 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8977);
											mem_vec_8977 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8978);
											mem_vec_8978 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8979);
											mem_vec_8979 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8980);
											mem_vec_8980 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8981);
											mem_vec_8981 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8982);
											mem_vec_8982 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8983);
											mem_vec_8983 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8984);
											mem_vec_8984 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8985);
											mem_vec_8985 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8986);
											mem_vec_8986 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8987);
											mem_vec_8987 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8988);
											mem_vec_8988 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8989);
											mem_vec_8989 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8990);
											mem_vec_8990 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8991);
											mem_vec_8991 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8992);
											mem_vec_8992 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8993);
											mem_vec_8993 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8994);
											mem_vec_8994 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8995);
											mem_vec_8995 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8996);
											mem_vec_8996 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8997);
											mem_vec_8997 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_8998);
											mem_vec_8998 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_8999);
											mem_vec_8999 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_8976);
											mem_vec_8976 = vec_38;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_8977);
											mem_vec_8977 = vec_41;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8978);
											mem_vec_8978 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8979);
											mem_vec_8979 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_8980);
											mem_vec_8980 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_8981);
											mem_vec_8981 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_8982);
											mem_vec_8982 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_8983);
											mem_vec_8983 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_8984);
											mem_vec_8984 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_8985);
											mem_vec_8985 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_8986);
											mem_vec_8986 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_8987);
											mem_vec_8987 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8988);
											mem_vec_8988 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8989);
											mem_vec_8989 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_8990);
											mem_vec_8990 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_8991);
											mem_vec_8991 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_8992);
											mem_vec_8992 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_8993);
											mem_vec_8993 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_8994);
											mem_vec_8994 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_8995);
											mem_vec_8995 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_8996);
											mem_vec_8996 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_8997);
											mem_vec_8997 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_8998);
											mem_vec_8998 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_8999);
											mem_vec_8999 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_77 = _mm256_set1_ps(scal_24);
											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_8976);
											mem_vec_8976 = vec_76;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_8977);
											mem_vec_8977 = vec_79;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_8978);
											mem_vec_8978 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_8979);
											mem_vec_8979 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_8980);
											mem_vec_8980 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_8981);
											mem_vec_8981 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_8982);
											mem_vec_8982 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8983);
											mem_vec_8983 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_8984);
											mem_vec_8984 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_8985);
											mem_vec_8985 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_8986);
											mem_vec_8986 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_8987);
											mem_vec_8987 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_8988);
											mem_vec_8988 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_8989);
											mem_vec_8989 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_8990);
											mem_vec_8990 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_8991);
											mem_vec_8991 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_8992);
											mem_vec_8992 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_8993);
											mem_vec_8993 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_8994);
											mem_vec_8994 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_8995);
											mem_vec_8995 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_8996);
											mem_vec_8996 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_8997);
											mem_vec_8997 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_8998);
											mem_vec_8998 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_8999);
											mem_vec_8999 = vec_113;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8976);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8977);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8978);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8979);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8980);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8981);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8982);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8983);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8984);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8985);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8986);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8987);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8988);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8989);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8990);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8991);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8992);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8993);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8994);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8995);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8996);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8997);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8998);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_8999);
							}
						}
					}
				}
			}
		}
	}


}