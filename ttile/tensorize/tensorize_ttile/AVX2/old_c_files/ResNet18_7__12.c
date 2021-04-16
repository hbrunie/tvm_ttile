#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (14, x); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (1, c); T (8, f); T (2, c)]
*/
IND_TYPE c, cp_0, c112_p_0, c113_p_0, cp_1, c112_p_1, cp_2, c112, c113, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y56 = 0;
IND_TYPE x56 = 0;
IND_TYPE h = 0;
IND_TYPE w42 = 0;
IND_TYPE c114 = 0;
IND_TYPE f56 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (c, 2) (128 / 64)
for (c113 = c114, c113_p_0 = 0;
	c113 < c114 + 128;
	c113 += 64, c113_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 64, f = 256
	// T (f, 8) (256 / 32)
	for (f = f56, fp_0 = 0;
		f < f56 + 256;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 64, f = 32
		// T (c, 1) (64 / 64)
		for (c112 = c113, c112_p_1 = c113_p_0, c112_p_0 = 0;
			c112 < c113 + 64;
			c112 += 64, c112_p_1 += 64, c112_p_0 += 64){
				for (y = y56, yp_0 = 0;
					y < y56 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (x, 14) (14 / 1)
					for (x = x56, xp_0 = 0;
						x < x56 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w42, wp_0 = 0;
							w < w42 + 3;
							w += 1, wp_0 += 1){
									mem_vec_784 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_785 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_786 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_787 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c112, cp_2 = c112_p_1, cp_1 = c112_p_0, cp_0 = 0;
										c < c112 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_784);
										mem_vec_784 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_785);
										mem_vec_785 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_786);
										mem_vec_786 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_787);
										mem_vec_787 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_788);
										mem_vec_788 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_789);
										mem_vec_789 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_790);
										mem_vec_790 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_791);
										mem_vec_791 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_792);
										mem_vec_792 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_793);
										mem_vec_793 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_794);
										mem_vec_794 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_795);
										mem_vec_795 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_796);
										mem_vec_796 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_797);
										mem_vec_797 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_798);
										mem_vec_798 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_799);
										mem_vec_799 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_784);
										mem_vec_784 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_785);
										mem_vec_785 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_786);
										mem_vec_786 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_787);
										mem_vec_787 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_788);
										mem_vec_788 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_789);
										mem_vec_789 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_790);
										mem_vec_790 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_791);
										mem_vec_791 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_792);
										mem_vec_792 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_793);
										mem_vec_793 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_794);
										mem_vec_794 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_795);
										mem_vec_795 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_796);
										mem_vec_796 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_797);
										mem_vec_797 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_798);
										mem_vec_798 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_799);
										mem_vec_799 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_784);
										mem_vec_784 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_785);
										mem_vec_785 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_786);
										mem_vec_786 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_787);
										mem_vec_787 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_788);
										mem_vec_788 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_789);
										mem_vec_789 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_790);
										mem_vec_790 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_791);
										mem_vec_791 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_792);
										mem_vec_792 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_793);
										mem_vec_793 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_794);
										mem_vec_794 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_795);
										mem_vec_795 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_796);
										mem_vec_796 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_797);
										mem_vec_797 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_798);
										mem_vec_798 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_799);
										mem_vec_799 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_784);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_785);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_786);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_787);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_788);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_789);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_790);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_791);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_792);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_793);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_794);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_795);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_796);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_797);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_798);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_799);
						}
					}
				}
				for (y = y56 + 8, yp_0 = 0;
					y < y56 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (x, 14) (14 / 1)
					for (x = x56, xp_0 = 0;
						x < x56 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w42, wp_0 = 0;
							w < w42 + 3;
							w += 1, wp_0 += 1){
									mem_vec_800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									mem_vec_820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c112, cp_2 = c112_p_1, cp_1 = c112_p_0, cp_0 = 0;
										c < c112 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_800);
										mem_vec_800 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_801);
										mem_vec_801 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_802);
										mem_vec_802 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_803);
										mem_vec_803 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_804);
										mem_vec_804 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_805);
										mem_vec_805 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_806);
										mem_vec_806 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_807);
										mem_vec_807 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_808);
										mem_vec_808 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_809);
										mem_vec_809 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_810);
										mem_vec_810 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_811);
										mem_vec_811 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_812);
										mem_vec_812 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_813);
										mem_vec_813 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_814);
										mem_vec_814 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_815);
										mem_vec_815 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_816);
										mem_vec_816 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_817);
										mem_vec_817 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_818);
										mem_vec_818 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_819);
										mem_vec_819 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_820);
										mem_vec_820 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_821);
										mem_vec_821 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_822);
										mem_vec_822 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_823);
										mem_vec_823 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_35 = _mm256_set1_ps(scal_6);
										vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_800);
										mem_vec_800 = vec_34;

										vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_801);
										mem_vec_801 = vec_37;

										vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_802);
										mem_vec_802 = vec_39;

										vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_803);
										mem_vec_803 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_804);
										mem_vec_804 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_805);
										mem_vec_805 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_806);
										mem_vec_806 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_807);
										mem_vec_807 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_808);
										mem_vec_808 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_809);
										mem_vec_809 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_810);
										mem_vec_810 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_811);
										mem_vec_811 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_812);
										mem_vec_812 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_813);
										mem_vec_813 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_814);
										mem_vec_814 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_815);
										mem_vec_815 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_59 = _mm256_set1_ps(scal_10);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_816);
										mem_vec_816 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_817);
										mem_vec_817 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_818);
										mem_vec_818 = vec_61;



										vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_819);
										mem_vec_819 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_64 = _mm256_set1_ps(scal_11);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_820);
										mem_vec_820 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_821);
										mem_vec_821 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_822);
										mem_vec_822 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_823);
										mem_vec_823 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_69 = _mm256_set1_ps(scal_12);
										vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_800);
										mem_vec_800 = vec_68;

										vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_801);
										mem_vec_801 = vec_71;

										vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_802);
										mem_vec_802 = vec_73;

										vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_803);
										mem_vec_803 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_78 = _mm256_set1_ps(scal_13);


										vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_804);
										mem_vec_804 = vec_77;



										vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_805);
										mem_vec_805 = vec_79;



										vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_806);
										mem_vec_806 = vec_80;



										vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_807);
										mem_vec_807 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_83 = _mm256_set1_ps(scal_14);


										vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_808);
										mem_vec_808 = vec_82;



										vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_809);
										mem_vec_809 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_810);
										mem_vec_810 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_811);
										mem_vec_811 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_88 = _mm256_set1_ps(scal_15);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_812);
										mem_vec_812 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_813);
										mem_vec_813 = vec_89;



										vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_814);
										mem_vec_814 = vec_90;



										vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_815);
										mem_vec_815 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_93 = _mm256_set1_ps(scal_16);


										vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_816);
										mem_vec_816 = vec_92;



										vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_817);
										mem_vec_817 = vec_94;



										vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_818);
										mem_vec_818 = vec_95;



										vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_819);
										mem_vec_819 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_98 = _mm256_set1_ps(scal_17);


										vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_820);
										mem_vec_820 = vec_97;



										vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_821);
										mem_vec_821 = vec_99;



										vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_822);
										mem_vec_822 = vec_100;



										vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_823);
										mem_vec_823 = vec_101;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_800);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_801);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_802);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_803);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_804);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_805);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_806);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_807);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_808);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_809);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_810);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_811);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_812);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_813);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_814);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_815);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_816);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_817);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_818);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_819);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_820);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_821);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_822);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_823);
						}
					}
				}
		}
	}
}


}