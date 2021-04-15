#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (2, f);
  T (512, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, f1592_p_0, f1593_p_0, fp_1, f1592_p_1, fp_2, f1592, f1593, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y796 = 0;
IND_TYPE x796 = 0;
IND_TYPE h648 = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f1594 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13944 ,mem_vec_13945 ,mem_vec_13946 ,mem_vec_13947 ,mem_vec_13948 ,mem_vec_13949 ,mem_vec_13950 ,mem_vec_13951 ,mem_vec_13952 ,mem_vec_13953 ,mem_vec_13954 ,mem_vec_13955 ,mem_vec_13956 ,mem_vec_13957 ,mem_vec_13958 ,mem_vec_13959 ,mem_vec_13960 ,mem_vec_13961 ,mem_vec_13962 ,mem_vec_13963 ,mem_vec_13964 ,mem_vec_13965 ,mem_vec_13966 ,mem_vec_13967 ,mem_vec_13968 ,mem_vec_13969 ,mem_vec_13970 ,mem_vec_13971 ,mem_vec_13972 ,mem_vec_13973 ,mem_vec_13974 ,mem_vec_13975 ,mem_vec_13976 ,mem_vec_13977 ,mem_vec_13978 ,mem_vec_13979 ,mem_vec_13980 ,mem_vec_13981 ,mem_vec_13982 ,mem_vec_13983 ,mem_vec_13984 ,mem_vec_13985 ,mem_vec_13986 ,mem_vec_13987 ,mem_vec_13988 ,mem_vec_13989 ,mem_vec_13990 ,mem_vec_13991 ,mem_vec_13992 ,mem_vec_13993 ,mem_vec_13994 ,mem_vec_13995 ,mem_vec_13996 ,mem_vec_13997 ,mem_vec_13998 ,mem_vec_13999 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f1593 = f1594, f1593_p_0 = 0;
	f1593 < f1594 + 512;
	f1593 += 128, f1593_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 128
	// T (c, 512) (512 / 1)
	for (c1194 = c1195, c1194_p_0 = 0;
		c1194 < c1195 + 512;
		c1194 += 1, c1194_p_0 += 1){
		// y = 7, x = 7, h = 3, w = 3, c = 1, f = 128
		// T (f, 2) (128 / 64)
		for (f1592 = f1593, f1592_p_1 = f1593_p_0, f1592_p_0 = 0;
			f1592 < f1593 + 128;
			f1592 += 64, f1592_p_1 += 64, f1592_p_0 += 64){
				for (y = y796, yp_0 = 0;
					y < y796 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
						f < f1592 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
						// T (h, 3) (3 / 1)
						for (h = h648, hp_0 = 0;
							h < h648 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
							// T (x, 7) (7 / 1)
							for (x = x796, xp_0 = 0;
								x < x796 + 7;
								x += 1, xp_0 += 1){
										mem_vec_13944 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13945 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_13946 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13947 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_13948 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_13949 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_13950 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_13951 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_13952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_13954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_13956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_13957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_13958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_13959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_13960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_13962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_13964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_13965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_13966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_13967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
										// T (c, 1) (1 / 1)
										for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
											c < c1194 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13944);
											mem_vec_13944 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13945);
											mem_vec_13945 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13946);
											mem_vec_13946 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13947);
											mem_vec_13947 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_13948);
											mem_vec_13948 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_13949);
											mem_vec_13949 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_13950);
											mem_vec_13950 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_13951);
											mem_vec_13951 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_13952);
											mem_vec_13952 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_13953);
											mem_vec_13953 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_13954);
											mem_vec_13954 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_13955);
											mem_vec_13955 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_13956);
											mem_vec_13956 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_13957);
											mem_vec_13957 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_13958);
											mem_vec_13958 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_13959);
											mem_vec_13959 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_13960);
											mem_vec_13960 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_13961);
											mem_vec_13961 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_13962);
											mem_vec_13962 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_13963);
											mem_vec_13963 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_13964);
											mem_vec_13964 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_13965);
											mem_vec_13965 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_13966);
											mem_vec_13966 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_13967);
											mem_vec_13967 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_13944);
											mem_vec_13944 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_13945);
											mem_vec_13945 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_13946);
											mem_vec_13946 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_13947);
											mem_vec_13947 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_13948);
											mem_vec_13948 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_13949);
											mem_vec_13949 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_13950);
											mem_vec_13950 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_13951);
											mem_vec_13951 = vec_50;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_13952);
											mem_vec_13952 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_13953);
											mem_vec_13953 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_13954);
											mem_vec_13954 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_13955);
											mem_vec_13955 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_13956);
											mem_vec_13956 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_13957);
											mem_vec_13957 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_13958);
											mem_vec_13958 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_13959);
											mem_vec_13959 = vec_60;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_13960);
											mem_vec_13960 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_13961);
											mem_vec_13961 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_13962);
											mem_vec_13962 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_13963);
											mem_vec_13963 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_13964);
											mem_vec_13964 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_13965);
											mem_vec_13965 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_13966);
											mem_vec_13966 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_13967);
											mem_vec_13967 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_13944);
											mem_vec_13944 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_13945);
											mem_vec_13945 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_13946);
											mem_vec_13946 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_13947);
											mem_vec_13947 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_13948);
											mem_vec_13948 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_13949);
											mem_vec_13949 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_13950);
											mem_vec_13950 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_13951);
											mem_vec_13951 = vec_85;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13952);
											mem_vec_13952 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13953);
											mem_vec_13953 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13954);
											mem_vec_13954 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_13955);
											mem_vec_13955 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_13956);
											mem_vec_13956 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_13957);
											mem_vec_13957 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_13958);
											mem_vec_13958 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_13959);
											mem_vec_13959 = vec_95;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_13960);
											mem_vec_13960 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_13961);
											mem_vec_13961 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_13962);
											mem_vec_13962 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_13963);
											mem_vec_13963 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_13964);
											mem_vec_13964 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_13965);
											mem_vec_13965 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_13966);
											mem_vec_13966 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_13967);
											mem_vec_13967 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13944);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13945);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13946);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13947);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13948);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_13949);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13950);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_13951);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13952);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13953);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13954);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13955);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13956);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_13957);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13958);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_13959);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13960);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13961);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13962);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13963);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13964);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_13965);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13966);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_13967);
							}
						}
					}
				}
				for (y = y796 + 3, yp_0 = 0;
					y < y796 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
						f < f1592 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
						// T (h, 3) (3 / 1)
						for (h = h648, hp_0 = 0;
							h < h648 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
							// T (x, 7) (7 / 1)
							for (x = x796, xp_0 = 0;
								x < x796 + 7;
								x += 1, xp_0 += 1){
										mem_vec_13968 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13969 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_13970 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13971 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_13972 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_13973 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_13974 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_13975 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_13976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_13978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_13980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_13981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_13982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_13983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_13984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_13986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_13988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_13989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_13990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_13991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_13992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_13993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_13994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_13995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_13996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_13997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_13998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_13999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
										// T (c, 1) (1 / 1)
										for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
											c < c1194 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13968);
											mem_vec_13968 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13969);
											mem_vec_13969 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13970);
											mem_vec_13970 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13971);
											mem_vec_13971 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_13972);
											mem_vec_13972 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_13973);
											mem_vec_13973 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_13974);
											mem_vec_13974 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_13975);
											mem_vec_13975 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_13976);
											mem_vec_13976 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_13977);
											mem_vec_13977 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_13978);
											mem_vec_13978 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_13979);
											mem_vec_13979 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_13980);
											mem_vec_13980 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_13981);
											mem_vec_13981 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_13982);
											mem_vec_13982 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_13983);
											mem_vec_13983 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_13984);
											mem_vec_13984 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_13985);
											mem_vec_13985 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_13986);
											mem_vec_13986 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_13987);
											mem_vec_13987 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_13988);
											mem_vec_13988 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_13989);
											mem_vec_13989 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_13990);
											mem_vec_13990 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_13991);
											mem_vec_13991 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_13992);
											mem_vec_13992 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_13993);
											mem_vec_13993 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_13994);
											mem_vec_13994 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_13995);
											mem_vec_13995 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_13996);
											mem_vec_13996 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_13997);
											mem_vec_13997 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_13998);
											mem_vec_13998 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_13999);
											mem_vec_13999 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_13968);
											mem_vec_13968 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_13969);
											mem_vec_13969 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_13970);
											mem_vec_13970 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_13971);
											mem_vec_13971 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_13972);
											mem_vec_13972 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_13973);
											mem_vec_13973 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_13974);
											mem_vec_13974 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_13975);
											mem_vec_13975 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_13976);
											mem_vec_13976 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_13977);
											mem_vec_13977 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_13978);
											mem_vec_13978 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_13979);
											mem_vec_13979 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_13980);
											mem_vec_13980 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_13981);
											mem_vec_13981 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_13982);
											mem_vec_13982 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_13983);
											mem_vec_13983 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_13984);
											mem_vec_13984 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_13985);
											mem_vec_13985 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_13986);
											mem_vec_13986 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_13987);
											mem_vec_13987 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_13988);
											mem_vec_13988 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_13989);
											mem_vec_13989 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_13990);
											mem_vec_13990 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_13991);
											mem_vec_13991 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_13992);
											mem_vec_13992 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_13993);
											mem_vec_13993 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_13994);
											mem_vec_13994 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_13995);
											mem_vec_13995 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_13996);
											mem_vec_13996 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_13997);
											mem_vec_13997 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_13998);
											mem_vec_13998 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_13999);
											mem_vec_13999 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_13968);
											mem_vec_13968 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_13969);
											mem_vec_13969 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_13970);
											mem_vec_13970 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_13971);
											mem_vec_13971 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_13972);
											mem_vec_13972 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_13973);
											mem_vec_13973 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_13974);
											mem_vec_13974 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_13975);
											mem_vec_13975 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_13976);
											mem_vec_13976 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_13977);
											mem_vec_13977 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_13978);
											mem_vec_13978 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_13979);
											mem_vec_13979 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_13980);
											mem_vec_13980 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_13981);
											mem_vec_13981 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_13982);
											mem_vec_13982 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_13983);
											mem_vec_13983 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_13984);
											mem_vec_13984 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_13985);
											mem_vec_13985 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_13986);
											mem_vec_13986 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_13987);
											mem_vec_13987 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_13988);
											mem_vec_13988 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_13989);
											mem_vec_13989 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_13990);
											mem_vec_13990 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_13991);
											mem_vec_13991 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_13992);
											mem_vec_13992 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_13993);
											mem_vec_13993 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_13994);
											mem_vec_13994 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_13995);
											mem_vec_13995 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_13996);
											mem_vec_13996 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_13997);
											mem_vec_13997 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_13998);
											mem_vec_13998 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_13999);
											mem_vec_13999 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13968);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13969);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13970);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13971);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13972);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_13973);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13974);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_13975);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13976);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13977);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13978);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13979);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13980);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_13981);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13982);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_13983);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13984);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13985);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13986);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13987);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13988);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_13989);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13990);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_13991);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13992);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13993);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13994);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13995);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13996);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_13997);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13998);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_13999);
							}
						}
					}
				}
		}
	}
}


}