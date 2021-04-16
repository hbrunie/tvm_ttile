#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (1, f); T (16, c); T (16, f); T (2, f)]
*/
IND_TYPE c, cp_0, c492_p_0, cp_1, c492, f, fp_0, f516_p_0, f517_p_0, fp_1, f516_p_1, fp_2, f516, f517, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y318 = 0;
IND_TYPE x288 = 0;
IND_TYPE h = 0;
IND_TYPE w256 = 0;
IND_TYPE c493 = 0;
IND_TYPE f518 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5720 ,mem_vec_5721 ,mem_vec_5722 ,mem_vec_5723 ,mem_vec_5724 ,mem_vec_5725 ,mem_vec_5726 ,mem_vec_5727 ,mem_vec_5728 ,mem_vec_5729 ,mem_vec_5730 ,mem_vec_5731 ,mem_vec_5732 ,mem_vec_5733 ,mem_vec_5734 ,mem_vec_5735 ,mem_vec_5736 ,mem_vec_5737 ,mem_vec_5738 ,mem_vec_5739 ,mem_vec_5740 ,mem_vec_5741 ,mem_vec_5742 ,mem_vec_5743 ,mem_vec_5744 ,mem_vec_5745 ,mem_vec_5746 ,mem_vec_5747 ,mem_vec_5748 ,mem_vec_5749 ,mem_vec_5750 ,mem_vec_5751 ,mem_vec_5752 ,mem_vec_5753 ,mem_vec_5754 ,mem_vec_5755 ,mem_vec_5756 ,mem_vec_5757 ,mem_vec_5758 ,mem_vec_5759 ,mem_vec_5760 ,mem_vec_5761 ,mem_vec_5762 ,mem_vec_5763 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f517 = f518, f517_p_0 = 0;
	f517 < f518 + 1024;
	f517 += 512, f517_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 16) (512 / 32)
	for (f516 = f517, f516_p_1 = f517_p_0, f516_p_0 = 0;
		f516 < f517 + 512;
		f516 += 32, f516_p_1 += 32, f516_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 32
		// T (c, 16) (512 / 32)
		for (c492 = c493, c492_p_0 = 0;
			c492 < c493 + 512;
			c492 += 32, c492_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 32
			// T (f, 1) (32 / 32)
			for (f = f516, fp_2 = f516_p_1, fp_1 = f516_p_0, fp_0 = 0;
				f < f516 + 32;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y318, yp_0 = 0;
						y < y318 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x288, xp_0 = 0;
							x < x288 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w256, wp_0 = 0;
								w < w256 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5720 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5721 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5722 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5723 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c492, cp_1 = c492_p_0, cp_0 = 0;
											c < c492 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5720);
											mem_vec_5720 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5721);
											mem_vec_5721 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5722);
											mem_vec_5722 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5723);
											mem_vec_5723 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5724);
											mem_vec_5724 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5725);
											mem_vec_5725 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5726);
											mem_vec_5726 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5727);
											mem_vec_5727 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5728);
											mem_vec_5728 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5729);
											mem_vec_5729 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5730);
											mem_vec_5730 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5731);
											mem_vec_5731 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5732);
											mem_vec_5732 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5733);
											mem_vec_5733 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5734);
											mem_vec_5734 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5735);
											mem_vec_5735 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5736);
											mem_vec_5736 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5737);
											mem_vec_5737 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5738);
											mem_vec_5738 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5739);
											mem_vec_5739 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_5720);
											mem_vec_5720 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_5721);
											mem_vec_5721 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_5722);
											mem_vec_5722 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_5723);
											mem_vec_5723 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_5724);
											mem_vec_5724 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_5725);
											mem_vec_5725 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_5726);
											mem_vec_5726 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_5727);
											mem_vec_5727 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_5728);
											mem_vec_5728 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_5729);
											mem_vec_5729 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_5730);
											mem_vec_5730 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_5731);
											mem_vec_5731 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_5732);
											mem_vec_5732 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_5733);
											mem_vec_5733 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_5734);
											mem_vec_5734 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_5735);
											mem_vec_5735 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_5736);
											mem_vec_5736 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_5737);
											mem_vec_5737 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_5738);
											mem_vec_5738 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_5739);
											mem_vec_5739 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_5720);
											mem_vec_5720 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_5721);
											mem_vec_5721 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_5722);
											mem_vec_5722 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_5723);
											mem_vec_5723 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_5724);
											mem_vec_5724 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_5725);
											mem_vec_5725 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_5726);
											mem_vec_5726 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_5727);
											mem_vec_5727 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_5728);
											mem_vec_5728 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_5729);
											mem_vec_5729 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_5730);
											mem_vec_5730 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_5731);
											mem_vec_5731 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_5732);
											mem_vec_5732 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_5733);
											mem_vec_5733 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_5734);
											mem_vec_5734 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_5735);
											mem_vec_5735 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_5736);
											mem_vec_5736 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_5737);
											mem_vec_5737 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_5738);
											mem_vec_5738 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_5739);
											mem_vec_5739 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5720);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5721);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5722);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5723);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5724);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5725);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5726);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5727);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5728);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5729);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5730);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5731);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5732);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5733);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5734);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5735);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5736);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5737);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5738);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5739);
							}
						}
					}
					for (y = y318 + 5, yp_0 = 0;
						y < y318 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x288, xp_0 = 0;
							x < x288 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w256, wp_0 = 0;
								w < w256 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5740 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5741 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5742 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5743 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_5760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_5762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c492, cp_1 = c492_p_0, cp_0 = 0;
											c < c492 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5740);
											mem_vec_5740 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5741);
											mem_vec_5741 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5742);
											mem_vec_5742 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5743);
											mem_vec_5743 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5744);
											mem_vec_5744 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5745);
											mem_vec_5745 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5746);
											mem_vec_5746 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5747);
											mem_vec_5747 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5748);
											mem_vec_5748 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5749);
											mem_vec_5749 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5750);
											mem_vec_5750 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5751);
											mem_vec_5751 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5752);
											mem_vec_5752 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5753);
											mem_vec_5753 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5754);
											mem_vec_5754 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5755);
											mem_vec_5755 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5756);
											mem_vec_5756 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5757);
											mem_vec_5757 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5758);
											mem_vec_5758 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5759);
											mem_vec_5759 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5760);
											mem_vec_5760 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5761);
											mem_vec_5761 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5762);
											mem_vec_5762 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5763);
											mem_vec_5763 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_5740);
											mem_vec_5740 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_5741);
											mem_vec_5741 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_5742);
											mem_vec_5742 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_5743);
											mem_vec_5743 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5744);
											mem_vec_5744 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_5745);
											mem_vec_5745 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_5746);
											mem_vec_5746 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_5747);
											mem_vec_5747 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_5748);
											mem_vec_5748 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_5749);
											mem_vec_5749 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_5750);
											mem_vec_5750 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_5751);
											mem_vec_5751 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_5752);
											mem_vec_5752 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_5753);
											mem_vec_5753 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_5754);
											mem_vec_5754 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_5755);
											mem_vec_5755 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5756);
											mem_vec_5756 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_5757);
											mem_vec_5757 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_5758);
											mem_vec_5758 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_5759);
											mem_vec_5759 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_5760);
											mem_vec_5760 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_5761);
											mem_vec_5761 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_5762);
											mem_vec_5762 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_5763);
											mem_vec_5763 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_5740);
											mem_vec_5740 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_5741);
											mem_vec_5741 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_5742);
											mem_vec_5742 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_5743);
											mem_vec_5743 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_5744);
											mem_vec_5744 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_5745);
											mem_vec_5745 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_5746);
											mem_vec_5746 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_5747);
											mem_vec_5747 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_5748);
											mem_vec_5748 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_5749);
											mem_vec_5749 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_5750);
											mem_vec_5750 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_5751);
											mem_vec_5751 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_5752);
											mem_vec_5752 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5753);
											mem_vec_5753 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5754);
											mem_vec_5754 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5755);
											mem_vec_5755 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_5756);
											mem_vec_5756 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_5757);
											mem_vec_5757 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_5758);
											mem_vec_5758 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_5759);
											mem_vec_5759 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_5760);
											mem_vec_5760 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_5761);
											mem_vec_5761 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_5762);
											mem_vec_5762 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_5763);
											mem_vec_5763 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5740);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5741);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5742);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5743);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5744);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5745);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5746);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5747);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5748);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5749);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5750);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5751);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5752);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5753);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5754);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5755);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5756);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5757);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5758);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5759);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5760);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5761);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5762);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5763);
							}
						}
					}
			}
		}
	}
}


}