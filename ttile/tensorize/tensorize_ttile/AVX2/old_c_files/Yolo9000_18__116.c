#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (8, c); T (4, f); T (4, f)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, f648_p_0, f649_p_0, fp_1, f648_p_1, fp_2, f648, f649, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y384 = 0;
IND_TYPE x354 = 0;
IND_TYPE h = 0;
IND_TYPE w315 = 0;
IND_TYPE c592 = 0;
IND_TYPE f650 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6964 ,mem_vec_6965 ,mem_vec_6966 ,mem_vec_6967 ,mem_vec_6968 ,mem_vec_6969 ,mem_vec_6970 ,mem_vec_6971 ,mem_vec_6972 ,mem_vec_6973 ,mem_vec_6974 ,mem_vec_6975 ,mem_vec_6976 ,mem_vec_6977 ,mem_vec_6978 ,mem_vec_6979 ,mem_vec_6980 ,mem_vec_6981 ,mem_vec_6982 ,mem_vec_6983 ,mem_vec_6984 ,mem_vec_6985 ,mem_vec_6986 ,mem_vec_6987 ,mem_vec_6988 ,mem_vec_6989 ,mem_vec_6990 ,mem_vec_6991 ,mem_vec_6992 ,mem_vec_6993 ,mem_vec_6994 ,mem_vec_6995 ,mem_vec_6996 ,mem_vec_6997 ,mem_vec_6998 ,mem_vec_6999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f649 = f650, f649_p_0 = 0;
	f649 < f650 + 1024;
	f649 += 256, f649_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 4) (256 / 64)
	for (f648 = f649, f648_p_1 = f649_p_0, f648_p_0 = 0;
		f648 < f649 + 256;
		f648 += 64, f648_p_1 += 64, f648_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
		// T (c, 8) (512 / 64)
		for (c591 = c592, c591_p_0 = 0;
			c591 < c592 + 512;
			c591 += 64, c591_p_0 += 64){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f648, fp_2 = f648_p_1, fp_1 = f648_p_0, fp_0 = 0;
				f < f648 + 64;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y384, yp_0 = 0;
						y < y384 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x354, xp_0 = 0;
							x < x354 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w315, wp_0 = 0;
								w < w315 + 3;
								w += 1, wp_0 += 1){
										mem_vec_6964 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6965 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6966 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6967 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
											c < c591 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6964);
											mem_vec_6964 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6965);
											mem_vec_6965 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6966);
											mem_vec_6966 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6967);
											mem_vec_6967 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6968);
											mem_vec_6968 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6969);
											mem_vec_6969 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6970);
											mem_vec_6970 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6971);
											mem_vec_6971 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6972);
											mem_vec_6972 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6973);
											mem_vec_6973 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6974);
											mem_vec_6974 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6975);
											mem_vec_6975 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6976);
											mem_vec_6976 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6977);
											mem_vec_6977 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6978);
											mem_vec_6978 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6979);
											mem_vec_6979 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6964);
											mem_vec_6964 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6965);
											mem_vec_6965 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6966);
											mem_vec_6966 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6967);
											mem_vec_6967 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6968);
											mem_vec_6968 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6969);
											mem_vec_6969 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6970);
											mem_vec_6970 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6971);
											mem_vec_6971 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6972);
											mem_vec_6972 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6973);
											mem_vec_6973 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6974);
											mem_vec_6974 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6975);
											mem_vec_6975 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6976);
											mem_vec_6976 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6977);
											mem_vec_6977 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6978);
											mem_vec_6978 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6979);
											mem_vec_6979 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6964);
											mem_vec_6964 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6965);
											mem_vec_6965 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6966);
											mem_vec_6966 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6967);
											mem_vec_6967 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6968);
											mem_vec_6968 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6969);
											mem_vec_6969 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6970);
											mem_vec_6970 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6971);
											mem_vec_6971 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6972);
											mem_vec_6972 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6973);
											mem_vec_6973 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6974);
											mem_vec_6974 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6975);
											mem_vec_6975 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6976);
											mem_vec_6976 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6977);
											mem_vec_6977 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6978);
											mem_vec_6978 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6979);
											mem_vec_6979 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6964);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6965);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6966);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6967);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6968);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6969);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6970);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6971);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6972);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6973);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6974);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6975);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6976);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6977);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6978);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6979);
							}
						}
					}
					for (y = y384 + 12, yp_0 = 0;
						y < y384 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x354, xp_0 = 0;
							x < x354 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w315, wp_0 = 0;
								w < w315 + 3;
								w += 1, wp_0 += 1){
										mem_vec_6980 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6981 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6982 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6983 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
											c < c591 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6980);
											mem_vec_6980 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6981);
											mem_vec_6981 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6982);
											mem_vec_6982 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6983);
											mem_vec_6983 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6984);
											mem_vec_6984 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6985);
											mem_vec_6985 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6986);
											mem_vec_6986 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6987);
											mem_vec_6987 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6988);
											mem_vec_6988 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6989);
											mem_vec_6989 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6990);
											mem_vec_6990 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6991);
											mem_vec_6991 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6992);
											mem_vec_6992 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6993);
											mem_vec_6993 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6994);
											mem_vec_6994 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6995);
											mem_vec_6995 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6996);
											mem_vec_6996 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6997);
											mem_vec_6997 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6998);
											mem_vec_6998 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6999);
											mem_vec_6999 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6980);
											mem_vec_6980 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6981);
											mem_vec_6981 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_6982);
											mem_vec_6982 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_6983);
											mem_vec_6983 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_6984);
											mem_vec_6984 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_6985);
											mem_vec_6985 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_6986);
											mem_vec_6986 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_6987);
											mem_vec_6987 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6988);
											mem_vec_6988 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6989);
											mem_vec_6989 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_6990);
											mem_vec_6990 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_6991);
											mem_vec_6991 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_6992);
											mem_vec_6992 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_6993);
											mem_vec_6993 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_6994);
											mem_vec_6994 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_6995);
											mem_vec_6995 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_6996);
											mem_vec_6996 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_6997);
											mem_vec_6997 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_6998);
											mem_vec_6998 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_6999);
											mem_vec_6999 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6980);
											mem_vec_6980 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6981);
											mem_vec_6981 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_6982);
											mem_vec_6982 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_6983);
											mem_vec_6983 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_6984);
											mem_vec_6984 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_6985);
											mem_vec_6985 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_6986);
											mem_vec_6986 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_6987);
											mem_vec_6987 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6988);
											mem_vec_6988 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6989);
											mem_vec_6989 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_6990);
											mem_vec_6990 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6991);
											mem_vec_6991 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_6992);
											mem_vec_6992 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_6993);
											mem_vec_6993 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_6994);
											mem_vec_6994 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_6995);
											mem_vec_6995 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_6996);
											mem_vec_6996 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_6997);
											mem_vec_6997 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_6998);
											mem_vec_6998 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_6999);
											mem_vec_6999 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6980);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6981);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6982);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6983);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6984);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6985);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6986);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6987);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6988);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6989);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6990);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6991);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6992);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6993);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6994);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6995);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6996);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6997);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6998);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6999);
							}
						}
					}
			}
		}
	}
}


}