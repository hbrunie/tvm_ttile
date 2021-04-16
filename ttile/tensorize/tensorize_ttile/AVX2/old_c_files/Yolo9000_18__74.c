#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))];
  T (4, f); T (16, c); T (1, f); T (8, f)]
*/
IND_TYPE c, cp_0, c343_p_0, cp_1, c343, f, fp_0, f364_p_0, f365_p_0, fp_1, f364_p_1, fp_2, f364, f365, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y222 = 0;
IND_TYPE x202 = 0;
IND_TYPE h = 0;
IND_TYPE w180 = 0;
IND_TYPE c344 = 0;
IND_TYPE f366 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3948 ,mem_vec_3949 ,mem_vec_3950 ,mem_vec_3951 ,mem_vec_3952 ,mem_vec_3953 ,mem_vec_3954 ,mem_vec_3955 ,mem_vec_3956 ,mem_vec_3957 ,mem_vec_3958 ,mem_vec_3959 ,mem_vec_3960 ,mem_vec_3961 ,mem_vec_3962 ,mem_vec_3963 ,mem_vec_3964 ,mem_vec_3965 ,mem_vec_3966 ,mem_vec_3967 ,mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,mem_vec_3976 ,mem_vec_3977 ,mem_vec_3978 ,mem_vec_3979 ,mem_vec_3980 ,mem_vec_3981 ,mem_vec_3982 ,mem_vec_3983 ,mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,mem_vec_3988 ,mem_vec_3989 ,mem_vec_3990 ,mem_vec_3991 ,mem_vec_3992 ,mem_vec_3993 ,mem_vec_3994 ,mem_vec_3995 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f365 = f366, f365_p_0 = 0;
	f365 < f366 + 1024;
	f365 += 128, f365_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (f, 1) (128 / 128)
	for (f364 = f365, f364_p_1 = f365_p_0, f364_p_0 = 0;
		f364 < f365 + 128;
		f364 += 128, f364_p_1 += 128, f364_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
		// T (c, 16) (512 / 32)
		for (c343 = c344, c343_p_0 = 0;
			c343 < c344 + 512;
			c343 += 32, c343_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 128
			// T (f, 4) (128 / 32)
			for (f = f364, fp_2 = f364_p_1, fp_1 = f364_p_0, fp_0 = 0;
				f < f364 + 128;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y222, yp_0 = 0;
						y < y222 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x202, xp_0 = 0;
							x < x202 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w180, wp_0 = 0;
								w < w180 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3948 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3949 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3950 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3951 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c343, cp_1 = c343_p_0, cp_0 = 0;
											c < c343 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3948);
											mem_vec_3948 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3949);
											mem_vec_3949 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3950);
											mem_vec_3950 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3951);
											mem_vec_3951 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3952);
											mem_vec_3952 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3953);
											mem_vec_3953 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3954);
											mem_vec_3954 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3955);
											mem_vec_3955 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3956);
											mem_vec_3956 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3957);
											mem_vec_3957 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3958);
											mem_vec_3958 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3959);
											mem_vec_3959 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3960);
											mem_vec_3960 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3961);
											mem_vec_3961 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3962);
											mem_vec_3962 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3963);
											mem_vec_3963 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3964);
											mem_vec_3964 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3965);
											mem_vec_3965 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3966);
											mem_vec_3966 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3967);
											mem_vec_3967 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_3948);
											mem_vec_3948 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_3949);
											mem_vec_3949 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_3950);
											mem_vec_3950 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_3951);
											mem_vec_3951 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_3952);
											mem_vec_3952 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_3953);
											mem_vec_3953 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_3954);
											mem_vec_3954 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_3955);
											mem_vec_3955 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_3956);
											mem_vec_3956 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_3957);
											mem_vec_3957 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_3958);
											mem_vec_3958 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_3959);
											mem_vec_3959 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_3960);
											mem_vec_3960 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_3961);
											mem_vec_3961 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_3962);
											mem_vec_3962 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_3963);
											mem_vec_3963 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_3964);
											mem_vec_3964 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_3965);
											mem_vec_3965 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_3966);
											mem_vec_3966 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_3967);
											mem_vec_3967 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_3948);
											mem_vec_3948 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_3949);
											mem_vec_3949 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_3950);
											mem_vec_3950 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_3951);
											mem_vec_3951 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_3952);
											mem_vec_3952 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_3953);
											mem_vec_3953 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_3954);
											mem_vec_3954 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_3955);
											mem_vec_3955 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_3956);
											mem_vec_3956 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_3957);
											mem_vec_3957 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_3958);
											mem_vec_3958 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_3959);
											mem_vec_3959 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_3960);
											mem_vec_3960 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_3961);
											mem_vec_3961 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_3962);
											mem_vec_3962 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_3963);
											mem_vec_3963 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_3964);
											mem_vec_3964 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_3965);
											mem_vec_3965 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_3966);
											mem_vec_3966 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_3967);
											mem_vec_3967 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3948);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3949);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3950);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3951);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3952);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3953);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3954);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3955);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3956);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3957);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3958);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3959);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3960);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3961);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3962);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3963);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3964);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3965);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3966);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3967);
							}
						}
					}
					for (y = y222 + 10, yp_0 = 0;
						y < y222 + 10 + 7;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x202, xp_0 = 0;
							x < x202 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w180, wp_0 = 0;
								w < w180 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3968 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3969 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3970 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3971 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_3988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_3992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c343, cp_1 = c343_p_0, cp_0 = 0;
											c < c343 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3968);
											mem_vec_3968 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3969);
											mem_vec_3969 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3970);
											mem_vec_3970 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3971);
											mem_vec_3971 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3972);
											mem_vec_3972 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3973);
											mem_vec_3973 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3974);
											mem_vec_3974 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3975);
											mem_vec_3975 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3976);
											mem_vec_3976 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3977);
											mem_vec_3977 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3978);
											mem_vec_3978 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3979);
											mem_vec_3979 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3980);
											mem_vec_3980 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3981);
											mem_vec_3981 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3982);
											mem_vec_3982 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3983);
											mem_vec_3983 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3984);
											mem_vec_3984 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3985);
											mem_vec_3985 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3986);
											mem_vec_3986 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3987);
											mem_vec_3987 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3988);
											mem_vec_3988 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3989);
											mem_vec_3989 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3990);
											mem_vec_3990 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3991);
											mem_vec_3991 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_3992);
											mem_vec_3992 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_3993);
											mem_vec_3993 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_3994);
											mem_vec_3994 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_3995);
											mem_vec_3995 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_3968);
											mem_vec_3968 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_3969);
											mem_vec_3969 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_3970);
											mem_vec_3970 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_3971);
											mem_vec_3971 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_3972);
											mem_vec_3972 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_3973);
											mem_vec_3973 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_3974);
											mem_vec_3974 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_3975);
											mem_vec_3975 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_3976);
											mem_vec_3976 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_3977);
											mem_vec_3977 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_3978);
											mem_vec_3978 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_3979);
											mem_vec_3979 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_3980);
											mem_vec_3980 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_3981);
											mem_vec_3981 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_3982);
											mem_vec_3982 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_3983);
											mem_vec_3983 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_3984);
											mem_vec_3984 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_3985);
											mem_vec_3985 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_3986);
											mem_vec_3986 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_3987);
											mem_vec_3987 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_3988);
											mem_vec_3988 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_3989);
											mem_vec_3989 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_3990);
											mem_vec_3990 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_3991);
											mem_vec_3991 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_3992);
											mem_vec_3992 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_3993);
											mem_vec_3993 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_3994);
											mem_vec_3994 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_3995);
											mem_vec_3995 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_3968);
											mem_vec_3968 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_3969);
											mem_vec_3969 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_3970);
											mem_vec_3970 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_3971);
											mem_vec_3971 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3972);
											mem_vec_3972 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_3973);
											mem_vec_3973 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3974);
											mem_vec_3974 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3975);
											mem_vec_3975 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_3976);
											mem_vec_3976 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_3977);
											mem_vec_3977 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_3978);
											mem_vec_3978 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_3979);
											mem_vec_3979 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_3980);
											mem_vec_3980 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_3981);
											mem_vec_3981 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_3982);
											mem_vec_3982 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_3983);
											mem_vec_3983 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_3984);
											mem_vec_3984 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_3985);
											mem_vec_3985 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_3986);
											mem_vec_3986 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_3987);
											mem_vec_3987 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_3988);
											mem_vec_3988 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_3989);
											mem_vec_3989 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_3990);
											mem_vec_3990 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_3991);
											mem_vec_3991 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_3992);
											mem_vec_3992 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_3993);
											mem_vec_3993 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_3994);
											mem_vec_3994 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_3995);
											mem_vec_3995 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3968);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3969);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3970);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3971);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3972);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3973);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3974);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3975);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3976);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3977);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3978);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3979);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3980);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3981);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3982);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3983);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3984);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3985);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3986);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3987);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3988);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3989);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3990);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3991);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3992);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3993);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3994);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_3995);
							}
						}
					}
			}
		}
	}
}


}