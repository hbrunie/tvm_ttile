#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (16, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c62_p_0, c63_p_0, cp_1, c62_p_1, cp_2, c62, c63, f, fp_0, f64_p_0, fp_1, f64, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y46 = 0;
IND_TYPE x36 = 0;
IND_TYPE h = 0;
IND_TYPE w32 = 0;
IND_TYPE c64 = 0;
IND_TYPE f65 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f64 = f65, f64_p_0 = 0;
	f64 < f65 + 512;
	f64 += 512, f64_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 2) (256 / 128)
	for (c63 = c64, c63_p_0 = 0;
		c63 < c64 + 256;
		c63 += 128, c63_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
		// T (f, 16) (512 / 32)
		for (f = f64, fp_1 = f64_p_0, fp_0 = 0;
			f < f64 + 512;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y46, yp_0 = 0;
					y < y46 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c62 = c63, c62_p_1 = c63_p_0, c62_p_0 = 0;
						c62 < c63 + 128;
						c62 += 32, c62_p_1 += 32, c62_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x36, xp_0 = 0;
							x < x36 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w32, wp_0 = 0;
								w < w32 + 3;
								w += 1, wp_0 += 1){
										mem_vec_776 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_777 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_778 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_779 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c62, cp_2 = c62_p_1, cp_1 = c62_p_0, cp_0 = 0;
											c < c62 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_776);
											mem_vec_776 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_777);
											mem_vec_777 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_778);
											mem_vec_778 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_779);
											mem_vec_779 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_780);
											mem_vec_780 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_781);
											mem_vec_781 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_782);
											mem_vec_782 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_783);
											mem_vec_783 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_784);
											mem_vec_784 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_785);
											mem_vec_785 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_786);
											mem_vec_786 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_787);
											mem_vec_787 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_788);
											mem_vec_788 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_789);
											mem_vec_789 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_790);
											mem_vec_790 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_791);
											mem_vec_791 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_776);
											mem_vec_776 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_777);
											mem_vec_777 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_778);
											mem_vec_778 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_779);
											mem_vec_779 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_780);
											mem_vec_780 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_781);
											mem_vec_781 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_782);
											mem_vec_782 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_783);
											mem_vec_783 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_784);
											mem_vec_784 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_785);
											mem_vec_785 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_786);
											mem_vec_786 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_787);
											mem_vec_787 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_788);
											mem_vec_788 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_789);
											mem_vec_789 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_790);
											mem_vec_790 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_791);
											mem_vec_791 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_776);
											mem_vec_776 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_777);
											mem_vec_777 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_778);
											mem_vec_778 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_779);
											mem_vec_779 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_780);
											mem_vec_780 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_781);
											mem_vec_781 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_782);
											mem_vec_782 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_783);
											mem_vec_783 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_784);
											mem_vec_784 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_785);
											mem_vec_785 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_786);
											mem_vec_786 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_787);
											mem_vec_787 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_788);
											mem_vec_788 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_789);
											mem_vec_789 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_790);
											mem_vec_790 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_791);
											mem_vec_791 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_776);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_777);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_778);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_779);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_780);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_781);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_782);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_783);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_784);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_785);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_786);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_787);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_788);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_789);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_790);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_791);
							}
						}
					}
				}
				for (y = y46 + 4, yp_0 = 0;
					y < y46 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c62 = c63, c62_p_1 = c63_p_0, c62_p_0 = 0;
						c62 < c63 + 128;
						c62 += 32, c62_p_1 += 32, c62_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x36, xp_0 = 0;
							x < x36 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w32, wp_0 = 0;
								w < w32 + 3;
								w += 1, wp_0 += 1){
										mem_vec_792 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_793 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_794 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_795 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c62, cp_2 = c62_p_1, cp_1 = c62_p_0, cp_0 = 0;
											c < c62 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_792);
											mem_vec_792 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_793);
											mem_vec_793 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_794);
											mem_vec_794 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_795);
											mem_vec_795 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_796);
											mem_vec_796 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_797);
											mem_vec_797 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_798);
											mem_vec_798 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_799);
											mem_vec_799 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_800);
											mem_vec_800 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_801);
											mem_vec_801 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_802);
											mem_vec_802 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_803);
											mem_vec_803 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_804);
											mem_vec_804 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_805);
											mem_vec_805 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_806);
											mem_vec_806 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_807);
											mem_vec_807 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_808);
											mem_vec_808 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_809);
											mem_vec_809 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_810);
											mem_vec_810 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_811);
											mem_vec_811 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_812);
											mem_vec_812 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_813);
											mem_vec_813 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_814);
											mem_vec_814 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_815);
											mem_vec_815 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_792);
											mem_vec_792 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_793);
											mem_vec_793 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_794);
											mem_vec_794 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_795);
											mem_vec_795 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_796);
											mem_vec_796 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_797);
											mem_vec_797 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_798);
											mem_vec_798 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_799);
											mem_vec_799 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_800);
											mem_vec_800 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_801);
											mem_vec_801 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_802);
											mem_vec_802 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_803);
											mem_vec_803 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_804);
											mem_vec_804 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_805);
											mem_vec_805 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_806);
											mem_vec_806 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_807);
											mem_vec_807 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_808);
											mem_vec_808 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_809);
											mem_vec_809 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_810);
											mem_vec_810 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_811);
											mem_vec_811 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_812);
											mem_vec_812 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_813);
											mem_vec_813 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_814);
											mem_vec_814 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_815);
											mem_vec_815 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_792);
											mem_vec_792 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_793);
											mem_vec_793 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_794);
											mem_vec_794 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_795);
											mem_vec_795 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_796);
											mem_vec_796 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_797);
											mem_vec_797 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_798);
											mem_vec_798 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_799);
											mem_vec_799 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_800);
											mem_vec_800 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_801);
											mem_vec_801 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_802);
											mem_vec_802 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_803);
											mem_vec_803 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_804);
											mem_vec_804 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_805);
											mem_vec_805 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_806);
											mem_vec_806 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_807);
											mem_vec_807 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_808);
											mem_vec_808 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_809);
											mem_vec_809 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_810);
											mem_vec_810 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_811);
											mem_vec_811 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_812);
											mem_vec_812 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_813);
											mem_vec_813 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_814);
											mem_vec_814 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_815);
											mem_vec_815 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_792);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_793);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_794);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_795);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_796);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_797);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_798);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_799);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_800);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_801);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_802);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_803);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_804);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_805);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_806);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_807);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_808);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_809);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_810);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_811);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_812);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_813);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_814);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_815);
							}
						}
					}
				}
		}
	}
}


}