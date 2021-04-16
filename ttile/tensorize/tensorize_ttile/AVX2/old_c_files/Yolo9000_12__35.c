#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (8, c); T (8, f)]
*/
IND_TYPE c, cp_0, c355_p_0, c356_p_0, cp_1, c355_p_1, cp_2, c355, c356, f, fp_0, f289_p_0, fp_1, f289, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y209 = 0;
IND_TYPE x184 = 0;
IND_TYPE h = 0;
IND_TYPE w160 = 0;
IND_TYPE c357 = 0;
IND_TYPE f290 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,mem_vec_3976 ,mem_vec_3977 ,mem_vec_3978 ,mem_vec_3979 ,mem_vec_3980 ,mem_vec_3981 ,mem_vec_3982 ,mem_vec_3983 ,mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,mem_vec_3988 ,mem_vec_3989 ,mem_vec_3990 ,mem_vec_3991 ,mem_vec_3992 ,mem_vec_3993 ,mem_vec_3994 ,mem_vec_3995 ,mem_vec_3996 ,mem_vec_3997 ,mem_vec_3998 ,mem_vec_3999 ,mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,mem_vec_4008 ,mem_vec_4009 ,mem_vec_4010 ,mem_vec_4011 ,mem_vec_4012 ,mem_vec_4013 ,mem_vec_4014 ,mem_vec_4015 ,mem_vec_4016 ,mem_vec_4017 ,mem_vec_4018 ,mem_vec_4019 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f289 = f290, f289_p_0 = 0;
	f289 < f290 + 512;
	f289 += 64, f289_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (c, 8) (256 / 32)
	for (c356 = c357, c356_p_0 = 0;
		c356 < c357 + 256;
		c356 += 32, c356_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (f, 2) (64 / 32)
		for (f = f289, fp_1 = f289_p_0, fp_0 = 0;
			f < f289 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y209, yp_0 = 0;
					y < y209 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c355 = c356, c355_p_1 = c356_p_0, c355_p_0 = 0;
						c355 < c356 + 32;
						c355 += 16, c355_p_1 += 16, c355_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x184, xp_0 = 0;
							x < x184 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w160, wp_0 = 0;
								w < w160 + 3;
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
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c355, cp_2 = c355_p_1, cp_1 = c355_p_0, cp_0 = 0;
											c < c355 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
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
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_3968);
											mem_vec_3968 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_3969);
											mem_vec_3969 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_3970);
											mem_vec_3970 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_3971);
											mem_vec_3971 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_3972);
											mem_vec_3972 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_3973);
											mem_vec_3973 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_3974);
											mem_vec_3974 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_3975);
											mem_vec_3975 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_3976);
											mem_vec_3976 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_3977);
											mem_vec_3977 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_3978);
											mem_vec_3978 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_3979);
											mem_vec_3979 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_3980);
											mem_vec_3980 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_3981);
											mem_vec_3981 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_3982);
											mem_vec_3982 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_3983);
											mem_vec_3983 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_3984);
											mem_vec_3984 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_3985);
											mem_vec_3985 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_3986);
											mem_vec_3986 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_3987);
											mem_vec_3987 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_3988);
											mem_vec_3988 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_3989);
											mem_vec_3989 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_3990);
											mem_vec_3990 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_3991);
											mem_vec_3991 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_3968);
											mem_vec_3968 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_3969);
											mem_vec_3969 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_3970);
											mem_vec_3970 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_3971);
											mem_vec_3971 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_3972);
											mem_vec_3972 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_3973);
											mem_vec_3973 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_3974);
											mem_vec_3974 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_3975);
											mem_vec_3975 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_3976);
											mem_vec_3976 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_3977);
											mem_vec_3977 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_3978);
											mem_vec_3978 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_3979);
											mem_vec_3979 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_3980);
											mem_vec_3980 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_3981);
											mem_vec_3981 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_3982);
											mem_vec_3982 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_3983);
											mem_vec_3983 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_3984);
											mem_vec_3984 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_3985);
											mem_vec_3985 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_3986);
											mem_vec_3986 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_3987);
											mem_vec_3987 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_3988);
											mem_vec_3988 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_3989);
											mem_vec_3989 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_3990);
											mem_vec_3990 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_3991);
											mem_vec_3991 = vec_101;
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
							}
						}
					}
				}
				for (y = y209 + 6, yp_0 = 0;
					y < y209 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c355 = c356, c355_p_1 = c356_p_0, c355_p_0 = 0;
						c355 < c356 + 32;
						c355 += 16, c355_p_1 += 16, c355_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x184, xp_0 = 0;
							x < x184 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w160, wp_0 = 0;
								w < w160 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3992 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3993 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3994 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3995 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4000 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4001 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4002 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4003 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4004 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4005 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4006 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4007 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_4008 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4009 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_4010 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4011 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_4012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_4014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_4016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_4018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c355, cp_2 = c355_p_1, cp_1 = c355_p_0, cp_0 = 0;
											c < c355 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3992);
											mem_vec_3992 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3993);
											mem_vec_3993 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3994);
											mem_vec_3994 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3995);
											mem_vec_3995 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3996);
											mem_vec_3996 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3997);
											mem_vec_3997 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3998);
											mem_vec_3998 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3999);
											mem_vec_3999 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4000);
											mem_vec_4000 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4001);
											mem_vec_4001 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4002);
											mem_vec_4002 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4003);
											mem_vec_4003 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4004);
											mem_vec_4004 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4005);
											mem_vec_4005 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4006);
											mem_vec_4006 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4007);
											mem_vec_4007 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4008);
											mem_vec_4008 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4009);
											mem_vec_4009 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4010);
											mem_vec_4010 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4011);
											mem_vec_4011 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4012);
											mem_vec_4012 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4013);
											mem_vec_4013 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_4014);
											mem_vec_4014 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_4015);
											mem_vec_4015 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_4016);
											mem_vec_4016 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_4017);
											mem_vec_4017 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_4018);
											mem_vec_4018 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_4019);
											mem_vec_4019 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_3992);
											mem_vec_3992 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_3993);
											mem_vec_3993 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_3994);
											mem_vec_3994 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_3995);
											mem_vec_3995 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_3996);
											mem_vec_3996 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_3997);
											mem_vec_3997 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_3998);
											mem_vec_3998 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_3999);
											mem_vec_3999 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_4000);
											mem_vec_4000 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_4001);
											mem_vec_4001 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_4002);
											mem_vec_4002 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_4003);
											mem_vec_4003 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_4004);
											mem_vec_4004 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_4005);
											mem_vec_4005 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_4006);
											mem_vec_4006 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_4007);
											mem_vec_4007 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_4008);
											mem_vec_4008 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_4009);
											mem_vec_4009 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_4010);
											mem_vec_4010 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_4011);
											mem_vec_4011 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_4012);
											mem_vec_4012 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_4013);
											mem_vec_4013 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_4014);
											mem_vec_4014 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_4015);
											mem_vec_4015 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_4016);
											mem_vec_4016 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_4017);
											mem_vec_4017 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_4018);
											mem_vec_4018 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_4019);
											mem_vec_4019 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_3992);
											mem_vec_3992 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_3993);
											mem_vec_3993 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_3994);
											mem_vec_3994 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_3995);
											mem_vec_3995 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3996);
											mem_vec_3996 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_3997);
											mem_vec_3997 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3998);
											mem_vec_3998 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3999);
											mem_vec_3999 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_4000);
											mem_vec_4000 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_4001);
											mem_vec_4001 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_4002);
											mem_vec_4002 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_4003);
											mem_vec_4003 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_4004);
											mem_vec_4004 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_4005);
											mem_vec_4005 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_4006);
											mem_vec_4006 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_4007);
											mem_vec_4007 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_4008);
											mem_vec_4008 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_4009);
											mem_vec_4009 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_4010);
											mem_vec_4010 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_4011);
											mem_vec_4011 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_4012);
											mem_vec_4012 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_4013);
											mem_vec_4013 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_4014);
											mem_vec_4014 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_4015);
											mem_vec_4015 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_4016);
											mem_vec_4016 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_4017);
											mem_vec_4017 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_4018);
											mem_vec_4018 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_4019);
											mem_vec_4019 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3992);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3993);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3994);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3995);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3996);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3997);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3998);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3999);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4000);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4001);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4002);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4003);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4004);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4005);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4006);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4007);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4008);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4009);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4010);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4011);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4012);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_4013);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4014);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_4015);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4016);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_4017);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4018);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_4019);
							}
						}
					}
				}
		}
	}
}


}