#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (16, f);
  T (8, c); T (2, c)]
*/
IND_TYPE c, cp_0, c710_p_0, c711_p_0, c712_p_0, cp_1, c710_p_1, c711_p_1, cp_2, c710_p_2, cp_3, c710, c711, c712, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y284 = 0;
IND_TYPE x284 = 0;
IND_TYPE h245 = 0;
IND_TYPE w = 0;
IND_TYPE c713 = 0;
IND_TYPE f284 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5766 ,mem_vec_5767 ,mem_vec_5768 ,mem_vec_5769 ,mem_vec_5770 ,mem_vec_5771 ,mem_vec_5772 ,mem_vec_5773 ,mem_vec_5774 ,mem_vec_5775 ,mem_vec_5776 ,mem_vec_5777 ,mem_vec_5778 ,mem_vec_5779 ,mem_vec_5780 ,mem_vec_5781 ,mem_vec_5782 ,mem_vec_5783 ,mem_vec_5784 ,mem_vec_5785 ,mem_vec_5786 ,mem_vec_5787 ,mem_vec_5788 ,mem_vec_5789 ,mem_vec_5790 ,mem_vec_5791 ,mem_vec_5792 ,mem_vec_5793 ,mem_vec_5794 ,mem_vec_5795 ,mem_vec_5796 ,mem_vec_5797 ,mem_vec_5798 ,mem_vec_5799 ,mem_vec_5800 ,mem_vec_5801 ,mem_vec_5802 ,mem_vec_5803 ,mem_vec_5804 ,mem_vec_5805 ,mem_vec_5806 ,mem_vec_5807 ,mem_vec_5808 ,mem_vec_5809 ,mem_vec_5810 ,mem_vec_5811 ,mem_vec_5812 ,mem_vec_5813 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c712 = c713, c712_p_0 = 0;
	c712 < c713 + 512;
	c712 += 256, c712_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
	// T (c, 8) (256 / 32)
	for (c711 = c712, c711_p_1 = c712_p_0, c711_p_0 = 0;
		c711 < c712 + 256;
		c711 += 32, c711_p_1 += 32, c711_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f284, fp_0 = 0;
			f < f284 + 1024;
			f += 64, fp_0 += 64){
				for (y = y284, yp_0 = 0;
					y < y284 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c710 = c711, c710_p_2 = c711_p_1, c710_p_1 = c711_p_0, c710_p_0 = 0;
						c710 < c711 + 32;
						c710 += 16, c710_p_2 += 16, c710_p_1 += 16, c710_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x284, xp_0 = 0;
							x < x284 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h245, hp_0 = 0;
								h < h245 + 3;
								h += 1, hp_0 += 1){
										mem_vec_5766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c710, cp_3 = c710_p_2, cp_2 = c710_p_1, cp_1 = c710_p_0, cp_0 = 0;
											c < c710 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5766);
											mem_vec_5766 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5767);
											mem_vec_5767 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5768);
											mem_vec_5768 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5769);
											mem_vec_5769 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5770);
											mem_vec_5770 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5771);
											mem_vec_5771 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5772);
											mem_vec_5772 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5773);
											mem_vec_5773 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5774);
											mem_vec_5774 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5775);
											mem_vec_5775 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5776);
											mem_vec_5776 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5777);
											mem_vec_5777 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5778);
											mem_vec_5778 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5779);
											mem_vec_5779 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5780);
											mem_vec_5780 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5781);
											mem_vec_5781 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5782);
											mem_vec_5782 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5783);
											mem_vec_5783 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5784);
											mem_vec_5784 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5785);
											mem_vec_5785 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5766);
											mem_vec_5766 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5767);
											mem_vec_5767 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5768);
											mem_vec_5768 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5769);
											mem_vec_5769 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5770);
											mem_vec_5770 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5771);
											mem_vec_5771 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5772);
											mem_vec_5772 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5773);
											mem_vec_5773 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5774);
											mem_vec_5774 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5775);
											mem_vec_5775 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5776);
											mem_vec_5776 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5777);
											mem_vec_5777 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5778);
											mem_vec_5778 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5779);
											mem_vec_5779 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5780);
											mem_vec_5780 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5781);
											mem_vec_5781 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5782);
											mem_vec_5782 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5783);
											mem_vec_5783 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5784);
											mem_vec_5784 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5785);
											mem_vec_5785 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5766);
											mem_vec_5766 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5767);
											mem_vec_5767 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5768);
											mem_vec_5768 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5769);
											mem_vec_5769 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5770);
											mem_vec_5770 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5771);
											mem_vec_5771 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5772);
											mem_vec_5772 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5773);
											mem_vec_5773 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5774);
											mem_vec_5774 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5775);
											mem_vec_5775 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5776);
											mem_vec_5776 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5777);
											mem_vec_5777 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5778);
											mem_vec_5778 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5779);
											mem_vec_5779 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5780);
											mem_vec_5780 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5781);
											mem_vec_5781 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5782);
											mem_vec_5782 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5783);
											mem_vec_5783 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5784);
											mem_vec_5784 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5785);
											mem_vec_5785 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5783);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5785);
							}
						}
					}
				}
				for (y = y284 + 10, yp_0 = 0;
					y < y284 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c710 = c711, c710_p_2 = c711_p_1, c710_p_1 = c711_p_0, c710_p_0 = 0;
						c710 < c711 + 32;
						c710 += 16, c710_p_2 += 16, c710_p_1 += 16, c710_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x284, xp_0 = 0;
							x < x284 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h245, hp_0 = 0;
								h < h245 + 3;
								h += 1, hp_0 += 1){
										mem_vec_5786 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5787 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5788 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5789 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_5810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_5813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c710, cp_3 = c710_p_2, cp_2 = c710_p_1, cp_1 = c710_p_0, cp_0 = 0;
											c < c710 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5786);
											mem_vec_5786 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5787);
											mem_vec_5787 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5788);
											mem_vec_5788 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5789);
											mem_vec_5789 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5790);
											mem_vec_5790 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5791);
											mem_vec_5791 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5792);
											mem_vec_5792 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5793);
											mem_vec_5793 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5794);
											mem_vec_5794 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5795);
											mem_vec_5795 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5796);
											mem_vec_5796 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5797);
											mem_vec_5797 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5798);
											mem_vec_5798 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5799);
											mem_vec_5799 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5800);
											mem_vec_5800 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5801);
											mem_vec_5801 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5802);
											mem_vec_5802 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5803);
											mem_vec_5803 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5804);
											mem_vec_5804 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5805);
											mem_vec_5805 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5806);
											mem_vec_5806 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5807);
											mem_vec_5807 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5808);
											mem_vec_5808 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5809);
											mem_vec_5809 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5810);
											mem_vec_5810 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5811);
											mem_vec_5811 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5812);
											mem_vec_5812 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5813);
											mem_vec_5813 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_5786);
											mem_vec_5786 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_5787);
											mem_vec_5787 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_5788);
											mem_vec_5788 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_5789);
											mem_vec_5789 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_5790);
											mem_vec_5790 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_5791);
											mem_vec_5791 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_5792);
											mem_vec_5792 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_5793);
											mem_vec_5793 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_5794);
											mem_vec_5794 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_5795);
											mem_vec_5795 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_5796);
											mem_vec_5796 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_5797);
											mem_vec_5797 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_5798);
											mem_vec_5798 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_5799);
											mem_vec_5799 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_5800);
											mem_vec_5800 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_5801);
											mem_vec_5801 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_5802);
											mem_vec_5802 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_5803);
											mem_vec_5803 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_5804);
											mem_vec_5804 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_5805);
											mem_vec_5805 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_5806);
											mem_vec_5806 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_5807);
											mem_vec_5807 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_5808);
											mem_vec_5808 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_5809);
											mem_vec_5809 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_5810);
											mem_vec_5810 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_5811);
											mem_vec_5811 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_5812);
											mem_vec_5812 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_5813);
											mem_vec_5813 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_5786);
											mem_vec_5786 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_5787);
											mem_vec_5787 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_5788);
											mem_vec_5788 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_5789);
											mem_vec_5789 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_5790);
											mem_vec_5790 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_5791);
											mem_vec_5791 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_5792);
											mem_vec_5792 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_5793);
											mem_vec_5793 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_5794);
											mem_vec_5794 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_5795);
											mem_vec_5795 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_5796);
											mem_vec_5796 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_5797);
											mem_vec_5797 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_5798);
											mem_vec_5798 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_5799);
											mem_vec_5799 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_5800);
											mem_vec_5800 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_5801);
											mem_vec_5801 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_5802);
											mem_vec_5802 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_5803);
											mem_vec_5803 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_5804);
											mem_vec_5804 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_5805);
											mem_vec_5805 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_5806);
											mem_vec_5806 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_5807);
											mem_vec_5807 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_5808);
											mem_vec_5808 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_5809);
											mem_vec_5809 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_5810);
											mem_vec_5810 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_5811);
											mem_vec_5811 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_5812);
											mem_vec_5812 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_5813);
											mem_vec_5813 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5791);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5813);
							}
						}
					}
				}
		}
	}
}


}