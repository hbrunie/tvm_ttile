#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (64, c)]
*/
IND_TYPE c, cp_0, c1408_p_0, c1409_p_0, cp_1, c1408_p_1, cp_2, c1408, c1409, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y650 = 0;
IND_TYPE x788 = 0;
IND_TYPE h600 = 0;
IND_TYPE w = 0;
IND_TYPE c1410 = 0;
IND_TYPE f956 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7848 ,mem_vec_7849 ,mem_vec_7850 ,mem_vec_7851 ,mem_vec_7852 ,mem_vec_7853 ,mem_vec_7854 ,mem_vec_7855 ,mem_vec_7856 ,mem_vec_7857 ,mem_vec_7858 ,mem_vec_7859 ,mem_vec_7860 ,mem_vec_7861 ,mem_vec_7862 ,mem_vec_7863 ,mem_vec_7864 ,mem_vec_7865 ,mem_vec_7866 ,mem_vec_7867 ,mem_vec_7868 ,mem_vec_7869 ,mem_vec_7870 ,mem_vec_7871 ,mem_vec_7872 ,mem_vec_7873 ,mem_vec_7874 ,mem_vec_7875 ,mem_vec_7876 ,mem_vec_7877 ,mem_vec_7878 ,mem_vec_7879 ,mem_vec_7880 ,mem_vec_7881 ,mem_vec_7882 ,mem_vec_7883 ,mem_vec_7884 ,mem_vec_7885 ,mem_vec_7886 ,mem_vec_7887 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 64) (512 / 8)
for (c1409 = c1410, c1409_p_0 = 0;
	c1409 < c1410 + 512;
	c1409 += 8, c1409_p_0 += 8){
		for (y = y650, yp_0 = 0;
			y < y650 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 4) (512 / 128)
			for (f = f956, fp_0 = 0;
				f < f956 + 512;
				f += 128, fp_0 += 128){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 128
				// T (c, 4) (8 / 2)
				for (c1408 = c1409, c1408_p_1 = c1409_p_0, c1408_p_0 = 0;
					c1408 < c1409 + 8;
					c1408 += 2, c1408_p_1 += 2, c1408_p_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 128
					// T (h, 3) (3 / 1)
					for (h = h600, hp_0 = 0;
						h < h600 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 128
						// T (x, 7) (7 / 1)
						for (x = x788, xp_0 = 0;
							x < x788 + 7;
							x += 1, xp_0 += 1){
									mem_vec_7848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7851 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_7853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_7854 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_7855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_7856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_7861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_7862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_7863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 128
									// T (c, 2) (2 / 1)
									for (c = c1408, cp_2 = c1408_p_1, cp_1 = c1408_p_0, cp_0 = 0;
										c < c1408 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7848);
										mem_vec_7848 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7849);
										mem_vec_7849 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7850);
										mem_vec_7850 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7851);
										mem_vec_7851 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7852);
										mem_vec_7852 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7853);
										mem_vec_7853 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7854);
										mem_vec_7854 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7855);
										mem_vec_7855 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7856);
										mem_vec_7856 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7857);
										mem_vec_7857 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7858);
										mem_vec_7858 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7859);
										mem_vec_7859 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7860);
										mem_vec_7860 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7861);
										mem_vec_7861 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7862);
										mem_vec_7862 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7863);
										mem_vec_7863 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7848);
										mem_vec_7848 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7849);
										mem_vec_7849 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_7850);
										mem_vec_7850 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_7851);
										mem_vec_7851 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_7852);
										mem_vec_7852 = vec_35;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_7853);
										mem_vec_7853 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_7854);
										mem_vec_7854 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_7855);
										mem_vec_7855 = vec_41;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_3);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7856);
										mem_vec_7856 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7857);
										mem_vec_7857 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7858);
										mem_vec_7858 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_7859);
										mem_vec_7859 = vec_47;



										vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7860);
										mem_vec_7860 = vec_48;



										vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7861);
										mem_vec_7861 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7862);
										mem_vec_7862 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7863);
										mem_vec_7863 = vec_51;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7848);
										mem_vec_7848 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7849);
										mem_vec_7849 = vec_55;

										vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_7850);
										mem_vec_7850 = vec_57;

										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_7851);
										mem_vec_7851 = vec_59;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_7852);
										mem_vec_7852 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_7853);
										mem_vec_7853 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_7854);
										mem_vec_7854 = vec_65;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_7855);
										mem_vec_7855 = vec_67;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_70 = _mm512_set1_ps(scal_5);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7856);
										mem_vec_7856 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7857);
										mem_vec_7857 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_7858);
										mem_vec_7858 = vec_72;



										vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7859);
										mem_vec_7859 = vec_73;



										vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7860);
										mem_vec_7860 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_7861);
										mem_vec_7861 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_7862);
										mem_vec_7862 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_7863);
										mem_vec_7863 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7863);
						}
					}
				}
			}
		}
		for (y = y650 + 4, yp_0 = 0;
			y < y650 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 4) (512 / 128)
			for (f = f956, fp_0 = 0;
				f < f956 + 512;
				f += 128, fp_0 += 128){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 128
				// T (c, 4) (8 / 2)
				for (c1408 = c1409, c1408_p_1 = c1409_p_0, c1408_p_0 = 0;
					c1408 < c1409 + 8;
					c1408 += 2, c1408_p_1 += 2, c1408_p_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 128
					// T (h, 3) (3 / 1)
					for (h = h600, hp_0 = 0;
						h < h600 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 128
						// T (x, 7) (7 / 1)
						for (x = x788, xp_0 = 0;
							x < x788 + 7;
							x += 1, xp_0 += 1){
									mem_vec_7864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7866 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7867 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7868 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_7869 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_7870 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_7871 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_7872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_7877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_7878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_7879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									mem_vec_7880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64]);
									mem_vec_7885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80]);
									mem_vec_7886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96]);
									mem_vec_7887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 128
									// T (c, 2) (2 / 1)
									for (c = c1408, cp_2 = c1408_p_1, cp_1 = c1408_p_0, cp_0 = 0;
										c < c1408 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7864);
										mem_vec_7864 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7865);
										mem_vec_7865 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7866);
										mem_vec_7866 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7867);
										mem_vec_7867 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7868);
										mem_vec_7868 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7869);
										mem_vec_7869 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7870);
										mem_vec_7870 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7871);
										mem_vec_7871 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7872);
										mem_vec_7872 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7873);
										mem_vec_7873 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7874);
										mem_vec_7874 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7875);
										mem_vec_7875 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7876);
										mem_vec_7876 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7877);
										mem_vec_7877 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7878);
										mem_vec_7878 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7879);
										mem_vec_7879 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7880);
										mem_vec_7880 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7881);
										mem_vec_7881 = vec_28;



										vec_29 = _mm512_fmadd_ps(vec_27, vec_6, mem_vec_7882);
										mem_vec_7882 = vec_29;



										vec_30 = _mm512_fmadd_ps(vec_27, vec_8, mem_vec_7883);
										mem_vec_7883 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_27, vec_10, mem_vec_7884);
										mem_vec_7884 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_27, vec_12, mem_vec_7885);
										mem_vec_7885 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_27, vec_14, mem_vec_7886);
										mem_vec_7886 = vec_33;



										vec_34 = _mm512_fmadd_ps(vec_27, vec_16, mem_vec_7887);
										mem_vec_7887 = vec_34;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_36 = _mm512_set1_ps(scal_3);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_7864);
										mem_vec_7864 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_7865);
										mem_vec_7865 = vec_38;

										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_40 = _mm512_fmadd_ps(vec_36, vec_41, mem_vec_7866);
										mem_vec_7866 = vec_40;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_42 = _mm512_fmadd_ps(vec_36, vec_43, mem_vec_7867);
										mem_vec_7867 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_44 = _mm512_fmadd_ps(vec_36, vec_45, mem_vec_7868);
										mem_vec_7868 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_46 = _mm512_fmadd_ps(vec_36, vec_47, mem_vec_7869);
										mem_vec_7869 = vec_46;

										vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_48 = _mm512_fmadd_ps(vec_36, vec_49, mem_vec_7870);
										mem_vec_7870 = vec_48;

										vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_50 = _mm512_fmadd_ps(vec_36, vec_51, mem_vec_7871);
										mem_vec_7871 = vec_50;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_7872);
										mem_vec_7872 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_7873);
										mem_vec_7873 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_41, mem_vec_7874);
										mem_vec_7874 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_7875);
										mem_vec_7875 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_7876);
										mem_vec_7876 = vec_57;



										vec_58 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_7877);
										mem_vec_7877 = vec_58;



										vec_59 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_7878);
										mem_vec_7878 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_7879);
										mem_vec_7879 = vec_60;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_62 = _mm512_set1_ps(scal_5);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_7880);
										mem_vec_7880 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_7881);
										mem_vec_7881 = vec_63;



										vec_64 = _mm512_fmadd_ps(vec_62, vec_41, mem_vec_7882);
										mem_vec_7882 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_7883);
										mem_vec_7883 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_7884);
										mem_vec_7884 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_62, vec_47, mem_vec_7885);
										mem_vec_7885 = vec_67;



										vec_68 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_7886);
										mem_vec_7886 = vec_68;



										vec_69 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_7887);
										mem_vec_7887 = vec_69;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_71 = _mm512_set1_ps(scal_6);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_7864);
										mem_vec_7864 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_7865);
										mem_vec_7865 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_75 = _mm512_fmadd_ps(vec_71, vec_76, mem_vec_7866);
										mem_vec_7866 = vec_75;

										vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_77 = _mm512_fmadd_ps(vec_71, vec_78, mem_vec_7867);
										mem_vec_7867 = vec_77;

										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_79 = _mm512_fmadd_ps(vec_71, vec_80, mem_vec_7868);
										mem_vec_7868 = vec_79;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_81 = _mm512_fmadd_ps(vec_71, vec_82, mem_vec_7869);
										mem_vec_7869 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_83 = _mm512_fmadd_ps(vec_71, vec_84, mem_vec_7870);
										mem_vec_7870 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_85 = _mm512_fmadd_ps(vec_71, vec_86, mem_vec_7871);
										mem_vec_7871 = vec_85;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_7);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7872);
										mem_vec_7872 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7873);
										mem_vec_7873 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7874);
										mem_vec_7874 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_7875);
										mem_vec_7875 = vec_91;



										vec_92 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7876);
										mem_vec_7876 = vec_92;



										vec_93 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_7877);
										mem_vec_7877 = vec_93;



										vec_94 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_7878);
										mem_vec_7878 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_7879);
										mem_vec_7879 = vec_95;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_97 = _mm512_set1_ps(scal_8);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_7880);
										mem_vec_7880 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_7881);
										mem_vec_7881 = vec_98;



										vec_99 = _mm512_fmadd_ps(vec_97, vec_76, mem_vec_7882);
										mem_vec_7882 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_7883);
										mem_vec_7883 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_7884);
										mem_vec_7884 = vec_101;



										vec_102 = _mm512_fmadd_ps(vec_97, vec_82, mem_vec_7885);
										mem_vec_7885 = vec_102;



										vec_103 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_7886);
										mem_vec_7886 = vec_103;



										vec_104 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_7887);
										mem_vec_7887 = vec_104;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7873);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7874);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7875);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7876);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7877);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7878);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7879);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7880);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7881);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7882);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7883);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64], mem_vec_7884);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80], mem_vec_7885);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96], mem_vec_7886);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112], mem_vec_7887);
						}
					}
				}
			}
		}
}


}