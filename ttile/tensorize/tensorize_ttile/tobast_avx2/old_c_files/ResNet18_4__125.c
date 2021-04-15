#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (16, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (2, x)]
*/
IND_TYPE c, cp_0, c1112_p_0, cp_1, c1112, f, fp_0, w, wp_0, x, xp_0, x1310_p_0, x1311_p_0, xp_1, x1310_p_1, xp_2, x1310, x1311, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y692 = 0;
IND_TYPE x1312 = 0;
IND_TYPE h = 0;
IND_TYPE w556 = 0;
IND_TYPE c1113 = 0;
IND_TYPE f766 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10084 ,mem_vec_10085 ,mem_vec_10086 ,mem_vec_10087 ,mem_vec_10088 ,mem_vec_10089 ,mem_vec_10090 ,mem_vec_10091 ,mem_vec_10092 ,mem_vec_10093 ,mem_vec_10094 ,mem_vec_10095 ,mem_vec_10096 ,mem_vec_10097 ,mem_vec_10098 ,mem_vec_10099 ,mem_vec_10100 ,mem_vec_10101 ,mem_vec_10102 ,mem_vec_10103 ,mem_vec_10104 ,mem_vec_10105 ,mem_vec_10106 ,mem_vec_10107 ,mem_vec_10108 ,mem_vec_10109 ,mem_vec_10110 ,mem_vec_10111 ,mem_vec_10112 ,mem_vec_10113 ,mem_vec_10114 ,mem_vec_10115 ,mem_vec_10116 ,mem_vec_10117 ,mem_vec_10118 ,mem_vec_10119 ,mem_vec_10120 ,mem_vec_10121 ,mem_vec_10122 ,mem_vec_10123 ,mem_vec_10124 ,mem_vec_10125 ,mem_vec_10126 ,mem_vec_10127 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (28 / 14)
for (x1311 = x1312, x1311_p_0 = 0;
	x1311 < x1312 + 28;
	x1311 += 14, x1311_p_0 += 14){
	// y = 28, x = 14, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f766, fp_0 = 0;
		f < f766 + 128;
		f += 32, fp_0 += 32){
			for (y = y692, yp_0 = 0;
				y < y692 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
				// T (x, 2) (14 / 7)
				for (x1310 = x1311, x1310_p_1 = x1311_p_0, x1310_p_0 = 0;
					x1310 < x1311 + 14;
					x1310 += 7, x1310_p_1 += 7, x1310_p_0 += 7){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
					// T (c, 16) (64 / 4)
					for (c1112 = c1113, c1112_p_0 = 0;
						c1112 < c1113 + 64;
						c1112 += 4, c1112_p_0 += 4){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w556, wp_0 = 0;
							w < w556 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 32
							// T (x, 7) (7 / 1)
							for (x = x1310, xp_2 = x1310_p_1, xp_1 = x1310_p_0, xp_0 = 0;
								x < x1310 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10084 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10085 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10086 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10087 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c1112, cp_1 = c1112_p_0, cp_0 = 0;
											c < c1112 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10084);
											mem_vec_10084 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10085);
											mem_vec_10085 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10086);
											mem_vec_10086 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10087);
											mem_vec_10087 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10088);
											mem_vec_10088 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10089);
											mem_vec_10089 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10090);
											mem_vec_10090 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10091);
											mem_vec_10091 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10092);
											mem_vec_10092 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10093);
											mem_vec_10093 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10094);
											mem_vec_10094 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10095);
											mem_vec_10095 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10096);
											mem_vec_10096 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10097);
											mem_vec_10097 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10098);
											mem_vec_10098 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10099);
											mem_vec_10099 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10100);
											mem_vec_10100 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10101);
											mem_vec_10101 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10102);
											mem_vec_10102 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10103);
											mem_vec_10103 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10084);
											mem_vec_10084 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10085);
											mem_vec_10085 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10086);
											mem_vec_10086 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10087);
											mem_vec_10087 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10088);
											mem_vec_10088 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10089);
											mem_vec_10089 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10090);
											mem_vec_10090 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10091);
											mem_vec_10091 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10092);
											mem_vec_10092 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10093);
											mem_vec_10093 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10094);
											mem_vec_10094 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10095);
											mem_vec_10095 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10096);
											mem_vec_10096 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10097);
											mem_vec_10097 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10098);
											mem_vec_10098 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10099);
											mem_vec_10099 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10100);
											mem_vec_10100 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10101);
											mem_vec_10101 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10102);
											mem_vec_10102 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10103);
											mem_vec_10103 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10084);
											mem_vec_10084 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10085);
											mem_vec_10085 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10086);
											mem_vec_10086 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10087);
											mem_vec_10087 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10088);
											mem_vec_10088 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10089);
											mem_vec_10089 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10090);
											mem_vec_10090 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10091);
											mem_vec_10091 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10092);
											mem_vec_10092 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10093);
											mem_vec_10093 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10094);
											mem_vec_10094 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10095);
											mem_vec_10095 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10096);
											mem_vec_10096 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10097);
											mem_vec_10097 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10098);
											mem_vec_10098 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10099);
											mem_vec_10099 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10100);
											mem_vec_10100 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10101);
											mem_vec_10101 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10102);
											mem_vec_10102 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10103);
											mem_vec_10103 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10084);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10085);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10086);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10087);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10088);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10089);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10090);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10091);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10092);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10093);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10094);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10095);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10096);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10097);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10098);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10099);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10100);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10101);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10102);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10103);
							}
						}
					}
				}
			}
			for (y = y692 + 10, yp_0 = 0;
				y < y692 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
				// T (x, 2) (14 / 7)
				for (x1310 = x1311, x1310_p_1 = x1311_p_0, x1310_p_0 = 0;
					x1310 < x1311 + 14;
					x1310 += 7, x1310_p_1 += 7, x1310_p_0 += 7){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
					// T (c, 16) (64 / 4)
					for (c1112 = c1113, c1112_p_0 = 0;
						c1112 < c1113 + 64;
						c1112 += 4, c1112_p_0 += 4){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w556, wp_0 = 0;
							w < w556 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 32
							// T (x, 7) (7 / 1)
							for (x = x1310, xp_2 = x1310_p_1, xp_1 = x1310_p_0, xp_0 = 0;
								x < x1310 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10104 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10105 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10106 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10107 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10112 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10113 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10114 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10115 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_10124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_10126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c1112, cp_1 = c1112_p_0, cp_0 = 0;
											c < c1112 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10104);
											mem_vec_10104 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10105);
											mem_vec_10105 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10106);
											mem_vec_10106 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10107);
											mem_vec_10107 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10108);
											mem_vec_10108 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10109);
											mem_vec_10109 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10110);
											mem_vec_10110 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10111);
											mem_vec_10111 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10112);
											mem_vec_10112 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10113);
											mem_vec_10113 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10114);
											mem_vec_10114 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10115);
											mem_vec_10115 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10116);
											mem_vec_10116 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10117);
											mem_vec_10117 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10118);
											mem_vec_10118 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10119);
											mem_vec_10119 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10120);
											mem_vec_10120 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10121);
											mem_vec_10121 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10122);
											mem_vec_10122 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10123);
											mem_vec_10123 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10124);
											mem_vec_10124 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10125);
											mem_vec_10125 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10126);
											mem_vec_10126 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10127);
											mem_vec_10127 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10104);
											mem_vec_10104 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10105);
											mem_vec_10105 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10106);
											mem_vec_10106 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10107);
											mem_vec_10107 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10108);
											mem_vec_10108 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10109);
											mem_vec_10109 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10110);
											mem_vec_10110 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10111);
											mem_vec_10111 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10112);
											mem_vec_10112 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10113);
											mem_vec_10113 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10114);
											mem_vec_10114 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10115);
											mem_vec_10115 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10116);
											mem_vec_10116 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10117);
											mem_vec_10117 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10118);
											mem_vec_10118 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10119);
											mem_vec_10119 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10120);
											mem_vec_10120 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10121);
											mem_vec_10121 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10122);
											mem_vec_10122 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10123);
											mem_vec_10123 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10124);
											mem_vec_10124 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10125);
											mem_vec_10125 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10126);
											mem_vec_10126 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10127);
											mem_vec_10127 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10104);
											mem_vec_10104 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10105);
											mem_vec_10105 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10106);
											mem_vec_10106 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10107);
											mem_vec_10107 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10108);
											mem_vec_10108 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10109);
											mem_vec_10109 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10110);
											mem_vec_10110 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10111);
											mem_vec_10111 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10112);
											mem_vec_10112 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10113);
											mem_vec_10113 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10114);
											mem_vec_10114 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10115);
											mem_vec_10115 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10116);
											mem_vec_10116 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10117);
											mem_vec_10117 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10118);
											mem_vec_10118 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10119);
											mem_vec_10119 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10120);
											mem_vec_10120 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10121);
											mem_vec_10121 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10122);
											mem_vec_10122 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10123);
											mem_vec_10123 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10124);
											mem_vec_10124 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10125);
											mem_vec_10125 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10126);
											mem_vec_10126 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10127);
											mem_vec_10127 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10104);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10105);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10106);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10107);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10108);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10109);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10110);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10111);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10112);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10113);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10114);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10115);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10116);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10117);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10118);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10119);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10120);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10121);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10122);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10123);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10124);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10125);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10126);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10127);
							}
						}
					}
				}
			}
	}
}


}