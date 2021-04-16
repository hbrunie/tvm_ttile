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
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c796_p_0, c797_p_0, cp_1, c796_p_1, cp_2, c796, c797, f, fp_0, w, wp_0, x, xp_0, x597_p_0, xp_1, x597, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y398 = 0;
IND_TYPE x598 = 0;
IND_TYPE h = 0;
IND_TYPE w316 = 0;
IND_TYPE c798 = 0;
IND_TYPE f574 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9090 ,mem_vec_9091 ,mem_vec_9092 ,mem_vec_9093 ,mem_vec_9094 ,mem_vec_9095 ,mem_vec_9096 ,mem_vec_9097 ,mem_vec_9098 ,mem_vec_9099 ,mem_vec_9100 ,mem_vec_9101 ,mem_vec_9102 ,mem_vec_9103 ,mem_vec_9104 ,mem_vec_9105 ,mem_vec_9106 ,mem_vec_9107 ,mem_vec_9108 ,mem_vec_9109 ,mem_vec_9110 ,mem_vec_9111 ,mem_vec_9112 ,mem_vec_9113 ,mem_vec_9114 ,mem_vec_9115 ,mem_vec_9116 ,mem_vec_9117 ,mem_vec_9118 ,mem_vec_9119 ,mem_vec_9120 ,mem_vec_9121 ,mem_vec_9122 ,mem_vec_9123 ,mem_vec_9124 ,mem_vec_9125 ,mem_vec_9126 ,mem_vec_9127 ,mem_vec_9128 ,mem_vec_9129 ,mem_vec_9130 ,mem_vec_9131 ,mem_vec_9132 ,mem_vec_9133 ,mem_vec_9134 ,mem_vec_9135 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y = y398, yp_0 = 0;
		y < y398 + 30;
		y += 10, yp_0 += 10){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x597 = x598, x597_p_0 = 0;
			x597 < x598 + 56;
			x597 += 28, x597_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (c, 4) (128 / 32)
			for (c797 = c798, c797_p_0 = 0;
				c797 < c798 + 128;
				c797 += 32, c797_p_0 += 32){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 128
				// T (f, 8) (128 / 16)
				for (f = f574, fp_0 = 0;
					f < f574 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (c, 2) (32 / 16)
					for (c796 = c797, c796_p_1 = c797_p_0, c796_p_0 = 0;
						c796 < c797 + 32;
						c796 += 16, c796_p_1 += 16, c796_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 16
						// T (x, 28) (28 / 1)
						for (x = x597, xp_1 = x597_p_0, xp_0 = 0;
							x < x597 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w316, wp_0 = 0;
								w < w316 + 3;
								w += 1, wp_0 += 1){
										mem_vec_9090 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9091 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_9092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_9094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_9096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_9098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_9100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_9102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_9104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_9106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_9108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c796, cp_2 = c796_p_1, cp_1 = c796_p_0, cp_0 = 0;
											c < c796 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9090);
											mem_vec_9090 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9091);
											mem_vec_9091 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9092);
											mem_vec_9092 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9093);
											mem_vec_9093 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9094);
											mem_vec_9094 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9095);
											mem_vec_9095 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9096);
											mem_vec_9096 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9097);
											mem_vec_9097 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9098);
											mem_vec_9098 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9099);
											mem_vec_9099 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9100);
											mem_vec_9100 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9101);
											mem_vec_9101 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9102);
											mem_vec_9102 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9103);
											mem_vec_9103 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9104);
											mem_vec_9104 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9105);
											mem_vec_9105 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9106);
											mem_vec_9106 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9107);
											mem_vec_9107 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9108);
											mem_vec_9108 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9109);
											mem_vec_9109 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_9090);
											mem_vec_9090 = vec_32;

											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_9091);
											mem_vec_9091 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_9092);
											mem_vec_9092 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_9093);
											mem_vec_9093 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_9094);
											mem_vec_9094 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_9095);
											mem_vec_9095 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_9096);
											mem_vec_9096 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9097);
											mem_vec_9097 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_9098);
											mem_vec_9098 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_9099);
											mem_vec_9099 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_9100);
											mem_vec_9100 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_9101);
											mem_vec_9101 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_9102);
											mem_vec_9102 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_9103);
											mem_vec_9103 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_9104);
											mem_vec_9104 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_9105);
											mem_vec_9105 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_9106);
											mem_vec_9106 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9107);
											mem_vec_9107 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_9108);
											mem_vec_9108 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_9109);
											mem_vec_9109 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_9090);
											mem_vec_9090 = vec_64;

											vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_9091);
											mem_vec_9091 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_9092);
											mem_vec_9092 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_9093);
											mem_vec_9093 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9094);
											mem_vec_9094 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_9095);
											mem_vec_9095 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_9096);
											mem_vec_9096 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_9097);
											mem_vec_9097 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_9098);
											mem_vec_9098 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_9099);
											mem_vec_9099 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_9100);
											mem_vec_9100 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_9101);
											mem_vec_9101 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_9102);
											mem_vec_9102 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_9103);
											mem_vec_9103 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_9104);
											mem_vec_9104 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_9105);
											mem_vec_9105 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_9106);
											mem_vec_9106 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_9107);
											mem_vec_9107 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_9108);
											mem_vec_9108 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_9109);
											mem_vec_9109 = vec_95;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9090);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9091);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9092);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9093);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9094);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9095);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9096);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9097);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9098);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9099);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9100);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9101);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9102);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9103);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9104);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9105);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9106);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9107);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9108);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_9109);
							}
						}
					}
				}
			}
		}
	}
	for (y = y398 + 30, yp_0 = 0;
		y < y398 + 30 + 26;
		y += 13, yp_0 += 13){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x597 = x598, x597_p_0 = 0;
			x597 < x598 + 56;
			x597 += 28, x597_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (c, 4) (128 / 32)
			for (c797 = c798, c797_p_0 = 0;
				c797 < c798 + 128;
				c797 += 32, c797_p_0 += 32){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 128
				// T (f, 8) (128 / 16)
				for (f = f574, fp_0 = 0;
					f < f574 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (c, 2) (32 / 16)
					for (c796 = c797, c796_p_1 = c797_p_0, c796_p_0 = 0;
						c796 < c797 + 32;
						c796 += 16, c796_p_1 += 16, c796_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 16
						// T (x, 28) (28 / 1)
						for (x = x597, xp_1 = x597_p_0, xp_0 = 0;
							x < x597 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w316, wp_0 = 0;
								w < w316 + 3;
								w += 1, wp_0 += 1){
										mem_vec_9110 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9111 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_9112 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9113 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_9114 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9115 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_9116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_9118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_9120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_9122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_9124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_9126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_9128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_9130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_9132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										mem_vec_9134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_9135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c796, cp_2 = c796_p_1, cp_1 = c796_p_0, cp_0 = 0;
											c < c796 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9110);
											mem_vec_9110 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9111);
											mem_vec_9111 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9112);
											mem_vec_9112 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9113);
											mem_vec_9113 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9114);
											mem_vec_9114 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9115);
											mem_vec_9115 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9116);
											mem_vec_9116 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9117);
											mem_vec_9117 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9118);
											mem_vec_9118 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9119);
											mem_vec_9119 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9120);
											mem_vec_9120 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9121);
											mem_vec_9121 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9122);
											mem_vec_9122 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9123);
											mem_vec_9123 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9124);
											mem_vec_9124 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9125);
											mem_vec_9125 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9126);
											mem_vec_9126 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9127);
											mem_vec_9127 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9128);
											mem_vec_9128 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9129);
											mem_vec_9129 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_9130);
											mem_vec_9130 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_9131);
											mem_vec_9131 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_9132);
											mem_vec_9132 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_9133);
											mem_vec_9133 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_9134);
											mem_vec_9134 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_9135);
											mem_vec_9135 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_42 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_9110);
											mem_vec_9110 = vec_41;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_9111);
											mem_vec_9111 = vec_44;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_9112);
											mem_vec_9112 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_9113);
											mem_vec_9113 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_9114);
											mem_vec_9114 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_9115);
											mem_vec_9115 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_9116);
											mem_vec_9116 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_9117);
											mem_vec_9117 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_9118);
											mem_vec_9118 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_9119);
											mem_vec_9119 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_9120);
											mem_vec_9120 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_9121);
											mem_vec_9121 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_9122);
											mem_vec_9122 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_9123);
											mem_vec_9123 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_9124);
											mem_vec_9124 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_9125);
											mem_vec_9125 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_9126);
											mem_vec_9126 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_9127);
											mem_vec_9127 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_9128);
											mem_vec_9128 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_9129);
											mem_vec_9129 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_9130);
											mem_vec_9130 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_9131);
											mem_vec_9131 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);


											vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_9132);
											mem_vec_9132 = vec_76;



											vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_9133);
											mem_vec_9133 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_9134);
											mem_vec_9134 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_9135);
											mem_vec_9135 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_9110);
											mem_vec_9110 = vec_82;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_9111);
											mem_vec_9111 = vec_85;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_9112);
											mem_vec_9112 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_9113);
											mem_vec_9113 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_9114);
											mem_vec_9114 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_9115);
											mem_vec_9115 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_9116);
											mem_vec_9116 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_9117);
											mem_vec_9117 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_9118);
											mem_vec_9118 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_9119);
											mem_vec_9119 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_9120);
											mem_vec_9120 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_9121);
											mem_vec_9121 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_9122);
											mem_vec_9122 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_9123);
											mem_vec_9123 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_9124);
											mem_vec_9124 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_9125);
											mem_vec_9125 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_9126);
											mem_vec_9126 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_9127);
											mem_vec_9127 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_9128);
											mem_vec_9128 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_9129);
											mem_vec_9129 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_9130);
											mem_vec_9130 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_9131);
											mem_vec_9131 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);


											vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_9132);
											mem_vec_9132 = vec_117;



											vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_9133);
											mem_vec_9133 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);


											vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_9134);
											mem_vec_9134 = vec_120;



											vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_9135);
											mem_vec_9135 = vec_122;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9110);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9111);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9112);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9113);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9114);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9115);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9116);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9117);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9118);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9119);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9120);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9121);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9122);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9123);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9124);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9125);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9126);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9127);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9128);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_9129);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9130);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_9131);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9132);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_9133);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9134);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_9135);
							}
						}
					}
				}
			}
		}
	}


}