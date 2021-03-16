#include <assert.h>
#include <immintrin.h>

void MMttile_conv2d(float * params, float * input, float * output,
		int W, int H,
		int C, int F,
		int X, int Y) {
/*
[V f; U (2, f); U (14, y); U (3, h); T (128, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, h); T (1, y); T (8, f); T (1, c); T (56, x); T (4, y)]
*/
int c, c0, cp_0, c0_p_0, cp_1, f, fp_0, h, hp_0, w, wp_0, x, x0, xp_0, x0_p_0, xp_1, y, y0, yp_0, y0_p_0, yp_1;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
int y1 = 0;
int x1 = 0;
int h0 = 0;
int w0 = 0;
int c1 = 0;
int f0 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 4) (56 / 14)
for (y0 = y1, y0_p_0 = 0;
	y0 < y1 + 56;
	y0 += 14, y0_p_0 += 14){
	// y = 14, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (x, 56) (56 / 1)
	for (x0 = x1, x0_p_0 = 0;
		x0 < x1 + 56;
		x0 += 1, x0_p_0 += 1){
		// y = 14, x = 1, h = 3, w = 3, c = 128, f = 128
		// T (c, 1) (128 / 128)
		for (c0 = c1, c0_p_0 = 0;
			c0 < c1 + 128;
			c0 += 128, c0_p_0 += 128){
			// y = 14, x = 1, h = 3, w = 3, c = 128, f = 128
			// T (f, 8) (128 / 16)
			for (f = f0, fp_0 = 0;
				f < f0 + 128;
				f += 16, fp_0 += 16){
				// y = 14, x = 1, h = 3, w = 3, c = 128, f = 16
				// T (y, 1) (14 / 14)
				for (y = y0, yp_1 = y0_p_0, yp_0 = 0;
					y < y0 + 14;
					y += 14, yp_1 += 14, yp_0 += 14){
					// y = 14, x = 1, h = 3, w = 3, c = 128, f = 16
					// T (h, 1) (3 / 3)
					for (h = h0, hp_0 = 0;
						h < h0 + 3;
						h += 3, hp_0 += 3){
						// y = 14, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (w, 3) (3 / 1)
						for (w = w0, wp_0 = 0;
							w < w0 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 128, f = 16
							// T (x, 1) (1 / 1)
							for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
								x < x0 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_0 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_11 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_12 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_13 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_14 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_15 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_16 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_17 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_18 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_19 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_20 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_21 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_22 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_23 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										mem_vec_24 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_25 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
										mem_vec_26 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_27 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 8]);
										// y = 14, x = 1, h = 3, w = 1, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
											c < c0 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
											mem_vec_0 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
											mem_vec_1 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2);
											mem_vec_2 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3);
											mem_vec_3 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4);
											mem_vec_4 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5);
											mem_vec_5 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6);
											mem_vec_6 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7);
											mem_vec_7 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8);
											mem_vec_8 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9);
											mem_vec_9 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_10);
											mem_vec_10 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_11);
											mem_vec_11 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_12);
											mem_vec_12 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_13);
											mem_vec_13 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_14);
											mem_vec_14 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_15);
											mem_vec_15 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_16);
											mem_vec_16 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_17);
											mem_vec_17 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_18);
											mem_vec_18 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_19);
											mem_vec_19 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_20);
											mem_vec_20 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_21);
											mem_vec_21 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_22);
											mem_vec_22 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_23);
											mem_vec_23 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_24);
											mem_vec_24 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_25);
											mem_vec_25 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm256_set1_ps(scal_13);


											vec_41 = _mm256_fmadd_ps(vec_42, vec_2, mem_vec_26);
											mem_vec_26 = vec_41;



											vec_43 = _mm256_fmadd_ps(vec_42, vec_4, mem_vec_27);
											mem_vec_27 = vec_43;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_45 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_0);
											mem_vec_0 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_1);
											mem_vec_1 = vec_47;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_46, mem_vec_2);
											mem_vec_2 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_48, mem_vec_3);
											mem_vec_3 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_46, mem_vec_4);
											mem_vec_4 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_48, mem_vec_5);
											mem_vec_5 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_46, mem_vec_6);
											mem_vec_6 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_48, mem_vec_7);
											mem_vec_7 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_46, mem_vec_8);
											mem_vec_8 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_48, mem_vec_9);
											mem_vec_9 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_10);
											mem_vec_10 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_11);
											mem_vec_11 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_46, mem_vec_12);
											mem_vec_12 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_48, mem_vec_13);
											mem_vec_13 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_46, mem_vec_14);
											mem_vec_14 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_48, mem_vec_15);
											mem_vec_15 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_16);
											mem_vec_16 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_17);
											mem_vec_17 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_46, mem_vec_18);
											mem_vec_18 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_48, mem_vec_19);
											mem_vec_19 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);


											vec_76 = _mm256_fmadd_ps(vec_77, vec_46, mem_vec_20);
											mem_vec_20 = vec_76;



											vec_78 = _mm256_fmadd_ps(vec_77, vec_48, mem_vec_21);
											mem_vec_21 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_22);
											mem_vec_22 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_23);
											mem_vec_23 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_83 = _mm256_set1_ps(scal_26);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_46, mem_vec_24);
											mem_vec_24 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_48, mem_vec_25);
											mem_vec_25 = vec_84;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
											vec_86 = _mm256_set1_ps(scal_27);


											vec_85 = _mm256_fmadd_ps(vec_86, vec_46, mem_vec_26);
											mem_vec_26 = vec_85;



											vec_87 = _mm256_fmadd_ps(vec_86, vec_48, mem_vec_27);
											mem_vec_27 = vec_87;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_89 = _mm256_set1_ps(scal_28);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_0);
											mem_vec_0 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_1);
											mem_vec_1 = vec_91;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_90, mem_vec_2);
											mem_vec_2 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_92, mem_vec_3);
											mem_vec_3 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_90, mem_vec_4);
											mem_vec_4 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_92, mem_vec_5);
											mem_vec_5 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_90, mem_vec_6);
											mem_vec_6 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_92, mem_vec_7);
											mem_vec_7 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_90, mem_vec_8);
											mem_vec_8 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_92, mem_vec_9);
											mem_vec_9 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_10);
											mem_vec_10 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_11);
											mem_vec_11 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_90, mem_vec_12);
											mem_vec_12 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_92, mem_vec_13);
											mem_vec_13 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_90, mem_vec_14);
											mem_vec_14 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_92, mem_vec_15);
											mem_vec_15 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_16);
											mem_vec_16 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_17);
											mem_vec_17 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);


											vec_117 = _mm256_fmadd_ps(vec_118, vec_90, mem_vec_18);
											mem_vec_18 = vec_117;



											vec_119 = _mm256_fmadd_ps(vec_118, vec_92, mem_vec_19);
											mem_vec_19 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);


											vec_120 = _mm256_fmadd_ps(vec_121, vec_90, mem_vec_20);
											mem_vec_20 = vec_120;



											vec_122 = _mm256_fmadd_ps(vec_121, vec_92, mem_vec_21);
											mem_vec_21 = vec_122;
											scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_124 = _mm256_set1_ps(scal_39);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_22);
											mem_vec_22 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_23);
											mem_vec_23 = vec_125;
											scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_127 = _mm256_set1_ps(scal_40);


											vec_126 = _mm256_fmadd_ps(vec_127, vec_90, mem_vec_24);
											mem_vec_24 = vec_126;



											vec_128 = _mm256_fmadd_ps(vec_127, vec_92, mem_vec_25);
											mem_vec_25 = vec_128;
											scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
											vec_130 = _mm256_set1_ps(scal_41);


											vec_129 = _mm256_fmadd_ps(vec_130, vec_90, mem_vec_26);
											mem_vec_26 = vec_129;



											vec_131 = _mm256_fmadd_ps(vec_130, vec_92, mem_vec_27);
											mem_vec_27 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_13);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_15);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_16);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_17);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_18);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_19);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_20);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_21);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_22);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_23);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_24);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_25);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_26);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 8], mem_vec_27);
							}
						}
					}
				}
			}
		}
	}
}


}
