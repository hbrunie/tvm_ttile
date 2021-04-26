#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (4, c); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c429_p_0, cp_1, c429, f, fp_0, f429_p_0, fp_1, f429, h, hp_0, x, xp_0, x399_p_0, xp_1, x399, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y286 = 0;
IND_TYPE x400 = 0;
IND_TYPE h240 = 0;
IND_TYPE w = 0;
IND_TYPE c430 = 0;
IND_TYPE f430 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3950 ,mem_vec_3951 ,mem_vec_3952 ,mem_vec_3953 ,mem_vec_3954 ,mem_vec_3955 ,mem_vec_3956 ,mem_vec_3957 ,mem_vec_3958 ,mem_vec_3959 ,mem_vec_3960 ,mem_vec_3961 ,mem_vec_3962 ,mem_vec_3963 ,mem_vec_3964 ,mem_vec_3965 ,mem_vec_3966 ,mem_vec_3967 ,mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,mem_vec_3976 ,mem_vec_3977 ,mem_vec_3978 ,mem_vec_3979 ,mem_vec_3980 ,mem_vec_3981 ,mem_vec_3982 ,mem_vec_3983 ,mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,mem_vec_3988 ,mem_vec_3989 ,mem_vec_3990 ,mem_vec_3991 ,mem_vec_3992 ,mem_vec_3993 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f429 = f430, f429_p_0 = 0;
	f429 < f430 + 256;
	f429 += 128, f429_p_0 += 128){
		for (y = y286, yp_0 = 0;
			y < y286 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x399 = x400, x399_p_0 = 0;
				x399 < x400 + 28;
				x399 += 28, x399_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f429, fp_1 = f429_p_0, fp_0 = 0;
					f < f429 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c429 = c430, c429_p_0 = 0;
						c429 < c430 + 128;
						c429 += 32, c429_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h240, hp_0 = 0;
							h < h240 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x399, xp_1 = x399_p_0, xp_0 = 0;
								x < x399 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3950 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3951 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3952 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3953 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_3954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_3957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_3958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_3961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_3962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_3965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_3966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c429, cp_1 = c429_p_0, cp_0 = 0;
											c < c429 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3950);
											mem_vec_3950 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3951);
											mem_vec_3951 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3952);
											mem_vec_3952 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3953);
											mem_vec_3953 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3954);
											mem_vec_3954 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3955);
											mem_vec_3955 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3956);
											mem_vec_3956 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3957);
											mem_vec_3957 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3958);
											mem_vec_3958 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3959);
											mem_vec_3959 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3960);
											mem_vec_3960 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3961);
											mem_vec_3961 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3962);
											mem_vec_3962 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3963);
											mem_vec_3963 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3964);
											mem_vec_3964 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3965);
											mem_vec_3965 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3966);
											mem_vec_3966 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3967);
											mem_vec_3967 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3968);
											mem_vec_3968 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3969);
											mem_vec_3969 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_3950);
											mem_vec_3950 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_3951);
											mem_vec_3951 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_3952);
											mem_vec_3952 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_3953);
											mem_vec_3953 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_3954);
											mem_vec_3954 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_3955);
											mem_vec_3955 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_3956);
											mem_vec_3956 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_3957);
											mem_vec_3957 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_3958);
											mem_vec_3958 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_3959);
											mem_vec_3959 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_3960);
											mem_vec_3960 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_3961);
											mem_vec_3961 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_3962);
											mem_vec_3962 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_3963);
											mem_vec_3963 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_3964);
											mem_vec_3964 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_3965);
											mem_vec_3965 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_3966);
											mem_vec_3966 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_3967);
											mem_vec_3967 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_3968);
											mem_vec_3968 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_3969);
											mem_vec_3969 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_3950);
											mem_vec_3950 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_3951);
											mem_vec_3951 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_3952);
											mem_vec_3952 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_3953);
											mem_vec_3953 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_3954);
											mem_vec_3954 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_3955);
											mem_vec_3955 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_3956);
											mem_vec_3956 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_3957);
											mem_vec_3957 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_3958);
											mem_vec_3958 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_3959);
											mem_vec_3959 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_3960);
											mem_vec_3960 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_3961);
											mem_vec_3961 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_3962);
											mem_vec_3962 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_3963);
											mem_vec_3963 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_3964);
											mem_vec_3964 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_3965);
											mem_vec_3965 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_3966);
											mem_vec_3966 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_3967);
											mem_vec_3967 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_3968);
											mem_vec_3968 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_3969);
											mem_vec_3969 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3951);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3952);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3953);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3954);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3955);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3956);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3957);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3959);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3969);
							}
						}
					}
				}
			}
		}
		for (y = y286 + 10, yp_0 = 0;
			y < y286 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x399 = x400, x399_p_0 = 0;
				x399 < x400 + 28;
				x399 += 28, x399_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f429, fp_1 = f429_p_0, fp_0 = 0;
					f < f429 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c429 = c430, c429_p_0 = 0;
						c429 < c430 + 128;
						c429 += 32, c429_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h240, hp_0 = 0;
							h < h240 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x399, xp_1 = x399_p_0, xp_0 = 0;
								x < x399 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3970 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3971 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3972 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3973 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_3974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_3977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_3978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_3981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_3982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_3985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_3986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_3990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_3993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c429, cp_1 = c429_p_0, cp_0 = 0;
											c < c429 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3970);
											mem_vec_3970 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3971);
											mem_vec_3971 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3972);
											mem_vec_3972 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3973);
											mem_vec_3973 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3974);
											mem_vec_3974 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3975);
											mem_vec_3975 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3976);
											mem_vec_3976 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3977);
											mem_vec_3977 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3978);
											mem_vec_3978 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3979);
											mem_vec_3979 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3980);
											mem_vec_3980 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3981);
											mem_vec_3981 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3982);
											mem_vec_3982 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3983);
											mem_vec_3983 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3984);
											mem_vec_3984 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3985);
											mem_vec_3985 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3986);
											mem_vec_3986 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3987);
											mem_vec_3987 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3988);
											mem_vec_3988 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3989);
											mem_vec_3989 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3990);
											mem_vec_3990 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3991);
											mem_vec_3991 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3992);
											mem_vec_3992 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3993);
											mem_vec_3993 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_3970);
											mem_vec_3970 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_3971);
											mem_vec_3971 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_3972);
											mem_vec_3972 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_3973);
											mem_vec_3973 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_3974);
											mem_vec_3974 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_3975);
											mem_vec_3975 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_3976);
											mem_vec_3976 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_3977);
											mem_vec_3977 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_3978);
											mem_vec_3978 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_3979);
											mem_vec_3979 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_3980);
											mem_vec_3980 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3981);
											mem_vec_3981 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_3982);
											mem_vec_3982 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_3983);
											mem_vec_3983 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_3984);
											mem_vec_3984 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_3985);
											mem_vec_3985 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_3986);
											mem_vec_3986 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_3987);
											mem_vec_3987 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_3988);
											mem_vec_3988 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_3989);
											mem_vec_3989 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_3990);
											mem_vec_3990 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_3991);
											mem_vec_3991 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_3992);
											mem_vec_3992 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_3993);
											mem_vec_3993 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_3970);
											mem_vec_3970 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_3971);
											mem_vec_3971 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_3972);
											mem_vec_3972 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_3973);
											mem_vec_3973 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_3974);
											mem_vec_3974 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_3975);
											mem_vec_3975 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_3976);
											mem_vec_3976 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_3977);
											mem_vec_3977 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_3978);
											mem_vec_3978 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_3979);
											mem_vec_3979 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_3980);
											mem_vec_3980 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_3981);
											mem_vec_3981 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_3982);
											mem_vec_3982 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_3983);
											mem_vec_3983 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_3984);
											mem_vec_3984 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_3985);
											mem_vec_3985 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_3986);
											mem_vec_3986 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_3987);
											mem_vec_3987 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_3988);
											mem_vec_3988 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_3989);
											mem_vec_3989 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_3990);
											mem_vec_3990 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_3991);
											mem_vec_3991 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_3992);
											mem_vec_3992 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_3993);
											mem_vec_3993 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3993);
							}
						}
					}
				}
			}
		}
}


}