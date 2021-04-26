#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (16, f);
  T (2, c); T (2, c)]
*/
IND_TYPE c, cp_0, c935_p_0, c936_p_0, c937_p_0, cp_1, c935_p_1, c936_p_1, cp_2, c935_p_2, cp_3, c935, c936, c937, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y374 = 0;
IND_TYPE x374 = 0;
IND_TYPE h = 0;
IND_TYPE w305 = 0;
IND_TYPE c938 = 0;
IND_TYPE f374 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7714 ,mem_vec_7715 ,mem_vec_7716 ,mem_vec_7717 ,mem_vec_7718 ,mem_vec_7719 ,mem_vec_7720 ,mem_vec_7721 ,mem_vec_7722 ,mem_vec_7723 ,mem_vec_7724 ,mem_vec_7725 ,mem_vec_7726 ,mem_vec_7727 ,mem_vec_7728 ,mem_vec_7729 ,mem_vec_7730 ,mem_vec_7731 ,mem_vec_7732 ,mem_vec_7733 ,mem_vec_7734 ,mem_vec_7735 ,mem_vec_7736 ,mem_vec_7737 ,mem_vec_7738 ,mem_vec_7739 ,mem_vec_7740 ,mem_vec_7741 ,mem_vec_7742 ,mem_vec_7743 ,mem_vec_7744 ,mem_vec_7745 ,mem_vec_7746 ,mem_vec_7747 ,mem_vec_7748 ,mem_vec_7749 ,mem_vec_7750 ,mem_vec_7751 ,mem_vec_7752 ,mem_vec_7753 ,mem_vec_7754 ,mem_vec_7755 ,mem_vec_7756 ,mem_vec_7757 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c937 = c938, c937_p_0 = 0;
	c937 < c938 + 512;
	c937 += 256, c937_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
	// T (c, 2) (256 / 128)
	for (c936 = c937, c936_p_1 = c937_p_0, c936_p_0 = 0;
		c936 < c937 + 256;
		c936 += 128, c936_p_1 += 128, c936_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 128, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f374, fp_0 = 0;
			f < f374 + 1024;
			f += 64, fp_0 += 64){
				for (y = y374, yp_0 = 0;
					y < y374 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c935 = c936, c935_p_2 = c936_p_1, c935_p_1 = c936_p_0, c935_p_0 = 0;
						c935 < c936 + 128;
						c935 += 32, c935_p_2 += 32, c935_p_1 += 32, c935_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x374, xp_0 = 0;
							x < x374 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w305, wp_0 = 0;
								w < w305 + 3;
								w += 1, wp_0 += 1){
										mem_vec_7714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7716 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c935, cp_3 = c935_p_2, cp_2 = c935_p_1, cp_1 = c935_p_0, cp_0 = 0;
											c < c935 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7714);
											mem_vec_7714 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7715);
											mem_vec_7715 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7716);
											mem_vec_7716 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7717);
											mem_vec_7717 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7718);
											mem_vec_7718 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7719);
											mem_vec_7719 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7720);
											mem_vec_7720 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7721);
											mem_vec_7721 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7722);
											mem_vec_7722 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7723);
											mem_vec_7723 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7724);
											mem_vec_7724 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7725);
											mem_vec_7725 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7726);
											mem_vec_7726 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7727);
											mem_vec_7727 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7728);
											mem_vec_7728 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7729);
											mem_vec_7729 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7730);
											mem_vec_7730 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7731);
											mem_vec_7731 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7732);
											mem_vec_7732 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7733);
											mem_vec_7733 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7714);
											mem_vec_7714 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7715);
											mem_vec_7715 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_7716);
											mem_vec_7716 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_7717);
											mem_vec_7717 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_7718);
											mem_vec_7718 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_7719);
											mem_vec_7719 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_7720);
											mem_vec_7720 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_7721);
											mem_vec_7721 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7722);
											mem_vec_7722 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7723);
											mem_vec_7723 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_7724);
											mem_vec_7724 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_7725);
											mem_vec_7725 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_7726);
											mem_vec_7726 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_7727);
											mem_vec_7727 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_7728);
											mem_vec_7728 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_7729);
											mem_vec_7729 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_7730);
											mem_vec_7730 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_7731);
											mem_vec_7731 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_7732);
											mem_vec_7732 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_7733);
											mem_vec_7733 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7714);
											mem_vec_7714 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7715);
											mem_vec_7715 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_7716);
											mem_vec_7716 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_7717);
											mem_vec_7717 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_7718);
											mem_vec_7718 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_7719);
											mem_vec_7719 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_7720);
											mem_vec_7720 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_7721);
											mem_vec_7721 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7722);
											mem_vec_7722 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7723);
											mem_vec_7723 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_7724);
											mem_vec_7724 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_7725);
											mem_vec_7725 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_7726);
											mem_vec_7726 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_7727);
											mem_vec_7727 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_7728);
											mem_vec_7728 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_7729);
											mem_vec_7729 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_7730);
											mem_vec_7730 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_7731);
											mem_vec_7731 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_7732);
											mem_vec_7732 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_7733);
											mem_vec_7733 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7714);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7715);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7716);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7717);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7718);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7719);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7725);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7733);
							}
						}
					}
				}
				for (y = y374 + 5, yp_0 = 0;
					y < y374 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c935 = c936, c935_p_2 = c936_p_1, c935_p_1 = c936_p_0, c935_p_0 = 0;
						c935 < c936 + 128;
						c935 += 32, c935_p_2 += 32, c935_p_1 += 32, c935_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x374, xp_0 = 0;
							x < x374 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w305, wp_0 = 0;
								w < w305 + 3;
								w += 1, wp_0 += 1){
										mem_vec_7734 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7735 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7736 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7737 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_7754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_7757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c935, cp_3 = c935_p_2, cp_2 = c935_p_1, cp_1 = c935_p_0, cp_0 = 0;
											c < c935 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7734);
											mem_vec_7734 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7735);
											mem_vec_7735 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7736);
											mem_vec_7736 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7737);
											mem_vec_7737 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7738);
											mem_vec_7738 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7739);
											mem_vec_7739 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7740);
											mem_vec_7740 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7741);
											mem_vec_7741 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7742);
											mem_vec_7742 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7743);
											mem_vec_7743 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7744);
											mem_vec_7744 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7745);
											mem_vec_7745 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7746);
											mem_vec_7746 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7747);
											mem_vec_7747 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7748);
											mem_vec_7748 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7749);
											mem_vec_7749 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7750);
											mem_vec_7750 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7751);
											mem_vec_7751 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7752);
											mem_vec_7752 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7753);
											mem_vec_7753 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7754);
											mem_vec_7754 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7755);
											mem_vec_7755 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7756);
											mem_vec_7756 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7757);
											mem_vec_7757 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_7734);
											mem_vec_7734 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_7735);
											mem_vec_7735 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_7736);
											mem_vec_7736 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_7737);
											mem_vec_7737 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7738);
											mem_vec_7738 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7739);
											mem_vec_7739 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7740);
											mem_vec_7740 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7741);
											mem_vec_7741 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_7742);
											mem_vec_7742 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_7743);
											mem_vec_7743 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_7744);
											mem_vec_7744 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_7745);
											mem_vec_7745 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_7746);
											mem_vec_7746 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_7747);
											mem_vec_7747 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_7748);
											mem_vec_7748 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_7749);
											mem_vec_7749 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_7750);
											mem_vec_7750 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_7751);
											mem_vec_7751 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_7752);
											mem_vec_7752 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_7753);
											mem_vec_7753 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_7754);
											mem_vec_7754 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_7755);
											mem_vec_7755 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_7756);
											mem_vec_7756 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_7757);
											mem_vec_7757 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_7734);
											mem_vec_7734 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_7735);
											mem_vec_7735 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_7736);
											mem_vec_7736 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_7737);
											mem_vec_7737 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_7738);
											mem_vec_7738 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_7739);
											mem_vec_7739 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_7740);
											mem_vec_7740 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_7741);
											mem_vec_7741 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_7742);
											mem_vec_7742 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_7743);
											mem_vec_7743 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_7744);
											mem_vec_7744 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_7745);
											mem_vec_7745 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_7746);
											mem_vec_7746 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7747);
											mem_vec_7747 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7748);
											mem_vec_7748 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7749);
											mem_vec_7749 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_7750);
											mem_vec_7750 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_7751);
											mem_vec_7751 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_7752);
											mem_vec_7752 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_7753);
											mem_vec_7753 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_7754);
											mem_vec_7754 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_7755);
											mem_vec_7755 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_7756);
											mem_vec_7756 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_7757);
											mem_vec_7757 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7749);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7755);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7757);
							}
						}
					}
				}
		}
	}
}


}