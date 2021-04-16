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
  T (2, f); T (16, c); T (8, f); T (2, f)]
*/
IND_TYPE c, cp_0, c397_p_0, cp_1, c397, f, fp_0, f436_p_0, f437_p_0, fp_1, f436_p_1, fp_2, f436, f437, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y258 = 0;
IND_TYPE x238 = 0;
IND_TYPE h = 0;
IND_TYPE w208 = 0;
IND_TYPE c398 = 0;
IND_TYPE f438 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4764 ,mem_vec_4765 ,mem_vec_4766 ,mem_vec_4767 ,mem_vec_4768 ,mem_vec_4769 ,mem_vec_4770 ,mem_vec_4771 ,mem_vec_4772 ,mem_vec_4773 ,mem_vec_4774 ,mem_vec_4775 ,mem_vec_4776 ,mem_vec_4777 ,mem_vec_4778 ,mem_vec_4779 ,mem_vec_4780 ,mem_vec_4781 ,mem_vec_4782 ,mem_vec_4783 ,mem_vec_4784 ,mem_vec_4785 ,mem_vec_4786 ,mem_vec_4787 ,mem_vec_4788 ,mem_vec_4789 ,mem_vec_4790 ,mem_vec_4791 ,mem_vec_4792 ,mem_vec_4793 ,mem_vec_4794 ,mem_vec_4795 ,mem_vec_4796 ,mem_vec_4797 ,mem_vec_4798 ,mem_vec_4799 ,mem_vec_4800 ,mem_vec_4801 ,mem_vec_4802 ,mem_vec_4803 ,mem_vec_4804 ,mem_vec_4805 ,mem_vec_4806 ,mem_vec_4807 ,mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f437 = f438, f437_p_0 = 0;
	f437 < f438 + 1024;
	f437 += 512, f437_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 8) (512 / 64)
	for (f436 = f437, f436_p_1 = f437_p_0, f436_p_0 = 0;
		f436 < f437 + 512;
		f436 += 64, f436_p_1 += 64, f436_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
		// T (c, 16) (512 / 32)
		for (c397 = c398, c397_p_0 = 0;
			c397 < c398 + 512;
			c397 += 32, c397_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 64
			// T (f, 2) (64 / 32)
			for (f = f436, fp_2 = f436_p_1, fp_1 = f436_p_0, fp_0 = 0;
				f < f436 + 64;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y258, yp_0 = 0;
						y < y258 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x238, xp_0 = 0;
							x < x238 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w208, wp_0 = 0;
								w < w208 + 3;
								w += 1, wp_0 += 1){
										mem_vec_4764 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4765 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4766 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4767 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_4780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_4782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c397, cp_1 = c397_p_0, cp_0 = 0;
											c < c397 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4764);
											mem_vec_4764 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4765);
											mem_vec_4765 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4766);
											mem_vec_4766 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4767);
											mem_vec_4767 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4768);
											mem_vec_4768 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4769);
											mem_vec_4769 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4770);
											mem_vec_4770 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4771);
											mem_vec_4771 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4772);
											mem_vec_4772 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4773);
											mem_vec_4773 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4774);
											mem_vec_4774 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4775);
											mem_vec_4775 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4776);
											mem_vec_4776 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4777);
											mem_vec_4777 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4778);
											mem_vec_4778 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4779);
											mem_vec_4779 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4780);
											mem_vec_4780 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4781);
											mem_vec_4781 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4782);
											mem_vec_4782 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4783);
											mem_vec_4783 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_4764);
											mem_vec_4764 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_4765);
											mem_vec_4765 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_4766);
											mem_vec_4766 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_4767);
											mem_vec_4767 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_4768);
											mem_vec_4768 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_4769);
											mem_vec_4769 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_4770);
											mem_vec_4770 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_4771);
											mem_vec_4771 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_4772);
											mem_vec_4772 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_4773);
											mem_vec_4773 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_4774);
											mem_vec_4774 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_4775);
											mem_vec_4775 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_4776);
											mem_vec_4776 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_4777);
											mem_vec_4777 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_4778);
											mem_vec_4778 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_4779);
											mem_vec_4779 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_4780);
											mem_vec_4780 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_4781);
											mem_vec_4781 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_4782);
											mem_vec_4782 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_4783);
											mem_vec_4783 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_4764);
											mem_vec_4764 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_4765);
											mem_vec_4765 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_4766);
											mem_vec_4766 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_4767);
											mem_vec_4767 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_4768);
											mem_vec_4768 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_4769);
											mem_vec_4769 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_4770);
											mem_vec_4770 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_4771);
											mem_vec_4771 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_4772);
											mem_vec_4772 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_4773);
											mem_vec_4773 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_4774);
											mem_vec_4774 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4775);
											mem_vec_4775 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_4776);
											mem_vec_4776 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_4777);
											mem_vec_4777 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_4778);
											mem_vec_4778 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_4779);
											mem_vec_4779 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_4780);
											mem_vec_4780 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_4781);
											mem_vec_4781 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_4782);
											mem_vec_4782 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_4783);
											mem_vec_4783 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4764);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4765);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4766);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4767);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4768);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4769);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4770);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4771);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4772);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4773);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4774);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4775);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4776);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4777);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4778);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4779);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4780);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4781);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4782);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4783);
							}
						}
					}
					for (y = y258 + 10, yp_0 = 0;
						y < y258 + 10 + 7;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x238, xp_0 = 0;
							x < x238 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w208, wp_0 = 0;
								w < w208 + 3;
								w += 1, wp_0 += 1){
										mem_vec_4784 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4785 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4786 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4787 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_4800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_4802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_4804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_4806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_4808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_4810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c397, cp_1 = c397_p_0, cp_0 = 0;
											c < c397 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4784);
											mem_vec_4784 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4785);
											mem_vec_4785 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4786);
											mem_vec_4786 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4787);
											mem_vec_4787 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4788);
											mem_vec_4788 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4789);
											mem_vec_4789 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4790);
											mem_vec_4790 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4791);
											mem_vec_4791 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4792);
											mem_vec_4792 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4793);
											mem_vec_4793 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4794);
											mem_vec_4794 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4795);
											mem_vec_4795 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4796);
											mem_vec_4796 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4797);
											mem_vec_4797 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4798);
											mem_vec_4798 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4799);
											mem_vec_4799 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4800);
											mem_vec_4800 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4801);
											mem_vec_4801 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4802);
											mem_vec_4802 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4803);
											mem_vec_4803 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4804);
											mem_vec_4804 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4805);
											mem_vec_4805 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_4806);
											mem_vec_4806 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_4807);
											mem_vec_4807 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_4808);
											mem_vec_4808 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_4809);
											mem_vec_4809 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_4810);
											mem_vec_4810 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_4811);
											mem_vec_4811 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_4784);
											mem_vec_4784 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_4785);
											mem_vec_4785 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_4786);
											mem_vec_4786 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_4787);
											mem_vec_4787 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_4788);
											mem_vec_4788 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_4789);
											mem_vec_4789 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_4790);
											mem_vec_4790 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_4791);
											mem_vec_4791 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_4792);
											mem_vec_4792 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_4793);
											mem_vec_4793 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_4794);
											mem_vec_4794 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_4795);
											mem_vec_4795 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_4796);
											mem_vec_4796 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_4797);
											mem_vec_4797 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_4798);
											mem_vec_4798 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_4799);
											mem_vec_4799 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_4800);
											mem_vec_4800 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_4801);
											mem_vec_4801 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_4802);
											mem_vec_4802 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_4803);
											mem_vec_4803 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_4804);
											mem_vec_4804 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_4805);
											mem_vec_4805 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_4806);
											mem_vec_4806 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_4807);
											mem_vec_4807 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_4808);
											mem_vec_4808 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_4809);
											mem_vec_4809 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_4810);
											mem_vec_4810 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_4811);
											mem_vec_4811 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_4784);
											mem_vec_4784 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_4785);
											mem_vec_4785 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_4786);
											mem_vec_4786 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_4787);
											mem_vec_4787 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_4788);
											mem_vec_4788 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_4789);
											mem_vec_4789 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_4790);
											mem_vec_4790 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_4791);
											mem_vec_4791 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_4792);
											mem_vec_4792 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_4793);
											mem_vec_4793 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_4794);
											mem_vec_4794 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_4795);
											mem_vec_4795 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_4796);
											mem_vec_4796 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_4797);
											mem_vec_4797 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_4798);
											mem_vec_4798 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_4799);
											mem_vec_4799 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_4800);
											mem_vec_4800 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_4801);
											mem_vec_4801 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_4802);
											mem_vec_4802 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_4803);
											mem_vec_4803 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_4804);
											mem_vec_4804 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_4805);
											mem_vec_4805 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_4806);
											mem_vec_4806 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_4807);
											mem_vec_4807 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_4808);
											mem_vec_4808 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_4809);
											mem_vec_4809 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_4810);
											mem_vec_4810 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_4811);
											mem_vec_4811 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4784);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4785);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4786);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4787);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4788);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4789);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4790);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4791);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4792);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4793);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4794);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4795);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4796);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4797);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4798);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4799);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4800);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4801);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4802);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4803);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4804);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_4805);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4806);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_4807);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4808);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_4809);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4810);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_4811);
							}
						}
					}
			}
		}
	}
}


}