#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (64, c); Hoist_vars [c];
  T (1, x); T (16, f); T (4, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c1388_p_0, cp_1, c1388, f, fp_0, f1380_p_0, fp_1, f1380, x, xp_0, x1120_p_0, xp_1, x1120, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y748 = 0;
IND_TYPE x1121 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1389 = 0;
IND_TYPE f1381 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1380 = f1381, f1380_p_0 = 0;
	f1380 < f1381 + 256;
	f1380 += 256, f1380_p_0 += 256){
		for (y = y748, yp_0 = 0;
			y < y748 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 256
			// T (x, 14) (14 / 1)
			for (x1120 = x1121, x1120_p_0 = 0;
				x1120 < x1121 + 14;
				x1120 += 1, x1120_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 256
				// T (c, 4) (256 / 64)
				for (c1388 = c1389, c1388_p_0 = 0;
					c1388 < c1389 + 256;
					c1388 += 64, c1388_p_0 += 64){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 256
					// T (f, 16) (256 / 16)
					for (f = f1380, fp_1 = f1380_p_0, fp_0 = 0;
						f < f1380 + 256;
						f += 16, fp_1 += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (x, 1) (1 / 1)
						for (x = x1120, xp_1 = x1120_p_0, xp_0 = 0;
							x < x1120 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8492 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c1388, cp_1 = c1388_p_0, cp_0 = 0;
										c < c1388 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8492);
										mem_vec_8492 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8493);
										mem_vec_8493 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8494);
										mem_vec_8494 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8495);
										mem_vec_8495 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_8492);
										mem_vec_8492 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_13 = _mm512_set1_ps(scal_5);


										vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_8493);
										mem_vec_8493 = vec_12;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_8494);
										mem_vec_8494 = vec_14;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_8495);
										mem_vec_8495 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_19 = _mm512_set1_ps(scal_8);
										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_8492);
										mem_vec_8492 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_22 = _mm512_set1_ps(scal_9);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_8493);
										mem_vec_8493 = vec_21;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_24 = _mm512_set1_ps(scal_10);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_8494);
										mem_vec_8494 = vec_23;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_8495);
										mem_vec_8495 = vec_25;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_28 = _mm512_set1_ps(scal_12);
										vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_8492);
										mem_vec_8492 = vec_27;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_31 = _mm512_set1_ps(scal_13);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_8493);
										mem_vec_8493 = vec_30;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_33 = _mm512_set1_ps(scal_14);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_8494);
										mem_vec_8494 = vec_32;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_35 = _mm512_set1_ps(scal_15);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_8495);
										mem_vec_8495 = vec_34;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_16);
										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_36 = _mm512_fmadd_ps(vec_37, vec_38, mem_vec_8492);
										mem_vec_8492 = vec_36;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_17);


										vec_39 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_8493);
										mem_vec_8493 = vec_39;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_42 = _mm512_set1_ps(scal_18);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_38, mem_vec_8494);
										mem_vec_8494 = vec_41;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_19);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_8495);
										mem_vec_8495 = vec_43;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_20);
										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_45 = _mm512_fmadd_ps(vec_46, vec_47, mem_vec_8492);
										mem_vec_8492 = vec_45;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_49 = _mm512_set1_ps(scal_21);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_8493);
										mem_vec_8493 = vec_48;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_51 = _mm512_set1_ps(scal_22);


										vec_50 = _mm512_fmadd_ps(vec_51, vec_47, mem_vec_8494);
										mem_vec_8494 = vec_50;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_23);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_8495);
										mem_vec_8495 = vec_52;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_55 = _mm512_set1_ps(scal_24);
										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_8492);
										mem_vec_8492 = vec_54;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_25);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8493);
										mem_vec_8493 = vec_57;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_60 = _mm512_set1_ps(scal_26);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_8494);
										mem_vec_8494 = vec_59;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_62 = _mm512_set1_ps(scal_27);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_8495);
										mem_vec_8495 = vec_61;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_28);
										vec_65 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_63 = _mm512_fmadd_ps(vec_64, vec_65, mem_vec_8492);
										mem_vec_8492 = vec_63;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_67 = _mm512_set1_ps(scal_29);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_65, mem_vec_8493);
										mem_vec_8493 = vec_66;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_30);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_65, mem_vec_8494);
										mem_vec_8494 = vec_68;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_71 = _mm512_set1_ps(scal_31);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_65, mem_vec_8495);
										mem_vec_8495 = vec_70;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_32);
										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_72 = _mm512_fmadd_ps(vec_73, vec_74, mem_vec_8492);
										mem_vec_8492 = vec_72;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_33);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_8493);
										mem_vec_8493 = vec_75;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_34);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_8494);
										mem_vec_8494 = vec_77;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_80 = _mm512_set1_ps(scal_35);


										vec_79 = _mm512_fmadd_ps(vec_80, vec_74, mem_vec_8495);
										mem_vec_8495 = vec_79;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8495);
						}
					}
				}
			}
		}
		for (y = y748 + 4, yp_0 = 0;
			y < y748 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 256
			// T (x, 14) (14 / 1)
			for (x1120 = x1121, x1120_p_0 = 0;
				x1120 < x1121 + 14;
				x1120 += 1, x1120_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 256
				// T (c, 4) (256 / 64)
				for (c1388 = c1389, c1388_p_0 = 0;
					c1388 < c1389 + 256;
					c1388 += 64, c1388_p_0 += 64){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 256
					// T (f, 16) (256 / 16)
					for (f = f1380, fp_1 = f1380_p_0, fp_0 = 0;
						f < f1380 + 256;
						f += 16, fp_1 += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (x, 1) (1 / 1)
						for (x = x1120, xp_1 = x1120_p_0, xp_0 = 0;
							x < x1120 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8496 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c1388, cp_1 = c1388_p_0, cp_0 = 0;
										c < c1388 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8496);
										mem_vec_8496 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8497);
										mem_vec_8497 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8498);
										mem_vec_8498 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8499);
										mem_vec_8499 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8500);
										mem_vec_8500 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_12 = _mm512_set1_ps(scal_5);
										vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_8496);
										mem_vec_8496 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_8497);
										mem_vec_8497 = vec_14;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_8498);
										mem_vec_8498 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_19 = _mm512_set1_ps(scal_8);


										vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_8499);
										mem_vec_8499 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_8500);
										mem_vec_8500 = vec_20;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_23 = _mm512_set1_ps(scal_10);
										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_8496);
										mem_vec_8496 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_8497);
										mem_vec_8497 = vec_25;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_28 = _mm512_set1_ps(scal_12);


										vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_8498);
										mem_vec_8498 = vec_27;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_30 = _mm512_set1_ps(scal_13);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_8499);
										mem_vec_8499 = vec_29;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_32 = _mm512_set1_ps(scal_14);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_8500);
										mem_vec_8500 = vec_31;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_34 = _mm512_set1_ps(scal_15);
										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_33 = _mm512_fmadd_ps(vec_34, vec_35, mem_vec_8496);
										mem_vec_8496 = vec_33;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_37 = _mm512_set1_ps(scal_16);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_35, mem_vec_8497);
										mem_vec_8497 = vec_36;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_17);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8498);
										mem_vec_8498 = vec_38;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_41 = _mm512_set1_ps(scal_18);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_35, mem_vec_8499);
										mem_vec_8499 = vec_40;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_43 = _mm512_set1_ps(scal_19);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_35, mem_vec_8500);
										mem_vec_8500 = vec_42;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_20);
										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_8496);
										mem_vec_8496 = vec_44;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_48 = _mm512_set1_ps(scal_21);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_8497);
										mem_vec_8497 = vec_47;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_22);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_8498);
										mem_vec_8498 = vec_49;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_52 = _mm512_set1_ps(scal_23);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_46, mem_vec_8499);
										mem_vec_8499 = vec_51;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_24);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_46, mem_vec_8500);
										mem_vec_8500 = vec_53;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_25);
										vec_57 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_55 = _mm512_fmadd_ps(vec_56, vec_57, mem_vec_8496);
										mem_vec_8496 = vec_55;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_26);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_57, mem_vec_8497);
										mem_vec_8497 = vec_58;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_27);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_57, mem_vec_8498);
										mem_vec_8498 = vec_60;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_63 = _mm512_set1_ps(scal_28);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_57, mem_vec_8499);
										mem_vec_8499 = vec_62;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_65 = _mm512_set1_ps(scal_29);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_57, mem_vec_8500);
										mem_vec_8500 = vec_64;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_67 = _mm512_set1_ps(scal_30);
										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_66 = _mm512_fmadd_ps(vec_67, vec_68, mem_vec_8496);
										mem_vec_8496 = vec_66;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_70 = _mm512_set1_ps(scal_31);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_8497);
										mem_vec_8497 = vec_69;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_72 = _mm512_set1_ps(scal_32);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_68, mem_vec_8498);
										mem_vec_8498 = vec_71;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_74 = _mm512_set1_ps(scal_33);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_68, mem_vec_8499);
										mem_vec_8499 = vec_73;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_76 = _mm512_set1_ps(scal_34);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_8500);
										mem_vec_8500 = vec_75;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_78 = _mm512_set1_ps(scal_35);
										vec_79 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_77 = _mm512_fmadd_ps(vec_78, vec_79, mem_vec_8496);
										mem_vec_8496 = vec_77;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_81 = _mm512_set1_ps(scal_36);


										vec_80 = _mm512_fmadd_ps(vec_81, vec_79, mem_vec_8497);
										mem_vec_8497 = vec_80;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_83 = _mm512_set1_ps(scal_37);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_79, mem_vec_8498);
										mem_vec_8498 = vec_82;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_85 = _mm512_set1_ps(scal_38);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_79, mem_vec_8499);
										mem_vec_8499 = vec_84;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_87 = _mm512_set1_ps(scal_39);


										vec_86 = _mm512_fmadd_ps(vec_87, vec_79, mem_vec_8500);
										mem_vec_8500 = vec_86;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_89 = _mm512_set1_ps(scal_40);
										vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_8496);
										mem_vec_8496 = vec_88;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_92 = _mm512_set1_ps(scal_41);


										vec_91 = _mm512_fmadd_ps(vec_92, vec_90, mem_vec_8497);
										mem_vec_8497 = vec_91;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_42);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_8498);
										mem_vec_8498 = vec_93;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_96 = _mm512_set1_ps(scal_43);


										vec_95 = _mm512_fmadd_ps(vec_96, vec_90, mem_vec_8499);
										mem_vec_8499 = vec_95;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_44);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_90, mem_vec_8500);
										mem_vec_8500 = vec_97;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8500);
						}
					}
				}
			}
		}
}


}