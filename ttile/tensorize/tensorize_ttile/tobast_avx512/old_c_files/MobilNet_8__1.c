#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1384_p_0, c1385_p_0, cp_1, c1384_p_1, cp_2, c1384, c1385, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y638 = 0;
IND_TYPE x776 = 0;
IND_TYPE h588 = 0;
IND_TYPE w = 0;
IND_TYPE c1386 = 0;
IND_TYPE f944 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7608 ,mem_vec_7609 ,mem_vec_7610 ,mem_vec_7611 ,mem_vec_7612 ,mem_vec_7613 ,mem_vec_7614 ,mem_vec_7615 ,mem_vec_7616 ,mem_vec_7617 ,mem_vec_7618 ,mem_vec_7619 ,mem_vec_7620 ,mem_vec_7621 ,mem_vec_7622 ,mem_vec_7623 ,mem_vec_7624 ,mem_vec_7625 ,mem_vec_7626 ,mem_vec_7627 ,mem_vec_7628 ,mem_vec_7629 ,mem_vec_7630 ,mem_vec_7631 ,mem_vec_7632 ,mem_vec_7633 ,mem_vec_7634 ,mem_vec_7635 ,mem_vec_7636 ,mem_vec_7637 ,mem_vec_7638 ,mem_vec_7639 ,mem_vec_7640 ,mem_vec_7641 ,mem_vec_7642 ,mem_vec_7643 ,mem_vec_7644 ,mem_vec_7645 ,mem_vec_7646 ,mem_vec_7647 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 4) (512 / 128)
for (c1385 = c1386, c1385_p_0 = 0;
	c1385 < c1386 + 512;
	c1385 += 128, c1385_p_0 += 128){
		for (y = y638, yp_0 = 0;
			y < y638 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
			// T (f, 4) (512 / 128)
			for (f = f944, fp_0 = 0;
				f < f944 + 512;
				f += 128, fp_0 += 128){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
				// T (c, 1) (128 / 128)
				for (c1384 = c1385, c1384_p_1 = c1385_p_0, c1384_p_0 = 0;
					c1384 < c1385 + 128;
					c1384 += 128, c1384_p_1 += 128, c1384_p_0 += 128){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
					// T (h, 3) (3 / 1)
					for (h = h588, hp_0 = 0;
						h < h588 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 128, f = 128
						// T (x, 7) (7 / 1)
						for (x = x776, xp_0 = 0;
							x < x776 + 7;
							x += 1, xp_0 += 1){
									mem_vec_7608 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7609 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7610 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7611 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_7613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_7614 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_7615 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_7616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_7621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_7622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_7623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 128
									// T (c, 128) (128 / 1)
									for (c = c1384, cp_2 = c1384_p_1, cp_1 = c1384_p_0, cp_0 = 0;
										c < c1384 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7608);
										mem_vec_7608 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7609);
										mem_vec_7609 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7610);
										mem_vec_7610 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7611);
										mem_vec_7611 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7612);
										mem_vec_7612 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7613);
										mem_vec_7613 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7614);
										mem_vec_7614 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7615);
										mem_vec_7615 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7616);
										mem_vec_7616 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7617);
										mem_vec_7617 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7618);
										mem_vec_7618 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7619);
										mem_vec_7619 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7620);
										mem_vec_7620 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7621);
										mem_vec_7621 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7622);
										mem_vec_7622 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7623);
										mem_vec_7623 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7608);
										mem_vec_7608 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7609);
										mem_vec_7609 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_7610);
										mem_vec_7610 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_7611);
										mem_vec_7611 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_7612);
										mem_vec_7612 = vec_35;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_7613);
										mem_vec_7613 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_7614);
										mem_vec_7614 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_7615);
										mem_vec_7615 = vec_41;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_3);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7616);
										mem_vec_7616 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7617);
										mem_vec_7617 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7618);
										mem_vec_7618 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_7619);
										mem_vec_7619 = vec_47;



										vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7620);
										mem_vec_7620 = vec_48;



										vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7621);
										mem_vec_7621 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7622);
										mem_vec_7622 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7623);
										mem_vec_7623 = vec_51;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7608);
										mem_vec_7608 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7609);
										mem_vec_7609 = vec_55;

										vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_7610);
										mem_vec_7610 = vec_57;

										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_7611);
										mem_vec_7611 = vec_59;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_7612);
										mem_vec_7612 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_7613);
										mem_vec_7613 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_7614);
										mem_vec_7614 = vec_65;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_7615);
										mem_vec_7615 = vec_67;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_70 = _mm512_set1_ps(scal_5);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7616);
										mem_vec_7616 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7617);
										mem_vec_7617 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_7618);
										mem_vec_7618 = vec_72;



										vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7619);
										mem_vec_7619 = vec_73;



										vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7620);
										mem_vec_7620 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_7621);
										mem_vec_7621 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_7622);
										mem_vec_7622 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_7623);
										mem_vec_7623 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7623);
						}
					}
				}
			}
		}
		for (y = y638 + 4, yp_0 = 0;
			y < y638 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
			// T (f, 4) (512 / 128)
			for (f = f944, fp_0 = 0;
				f < f944 + 512;
				f += 128, fp_0 += 128){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
				// T (c, 1) (128 / 128)
				for (c1384 = c1385, c1384_p_1 = c1385_p_0, c1384_p_0 = 0;
					c1384 < c1385 + 128;
					c1384 += 128, c1384_p_1 += 128, c1384_p_0 += 128){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
					// T (h, 3) (3 / 1)
					for (h = h588, hp_0 = 0;
						h < h588 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 128, f = 128
						// T (x, 7) (7 / 1)
						for (x = x776, xp_0 = 0;
							x < x776 + 7;
							x += 1, xp_0 += 1){
									mem_vec_7624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7628 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_7629 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_7630 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_7631 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_7632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_7637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_7638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_7639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									mem_vec_7640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64]);
									mem_vec_7645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80]);
									mem_vec_7646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96]);
									mem_vec_7647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 128
									// T (c, 128) (128 / 1)
									for (c = c1384, cp_2 = c1384_p_1, cp_1 = c1384_p_0, cp_0 = 0;
										c < c1384 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7624);
										mem_vec_7624 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7625);
										mem_vec_7625 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7626);
										mem_vec_7626 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7627);
										mem_vec_7627 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7628);
										mem_vec_7628 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7629);
										mem_vec_7629 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7630);
										mem_vec_7630 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7631);
										mem_vec_7631 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7632);
										mem_vec_7632 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7633);
										mem_vec_7633 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7634);
										mem_vec_7634 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7635);
										mem_vec_7635 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7636);
										mem_vec_7636 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7637);
										mem_vec_7637 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7638);
										mem_vec_7638 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7639);
										mem_vec_7639 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7640);
										mem_vec_7640 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7641);
										mem_vec_7641 = vec_28;



										vec_29 = _mm512_fmadd_ps(vec_27, vec_6, mem_vec_7642);
										mem_vec_7642 = vec_29;



										vec_30 = _mm512_fmadd_ps(vec_27, vec_8, mem_vec_7643);
										mem_vec_7643 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_27, vec_10, mem_vec_7644);
										mem_vec_7644 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_27, vec_12, mem_vec_7645);
										mem_vec_7645 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_27, vec_14, mem_vec_7646);
										mem_vec_7646 = vec_33;



										vec_34 = _mm512_fmadd_ps(vec_27, vec_16, mem_vec_7647);
										mem_vec_7647 = vec_34;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_36 = _mm512_set1_ps(scal_3);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_7624);
										mem_vec_7624 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_7625);
										mem_vec_7625 = vec_38;

										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_40 = _mm512_fmadd_ps(vec_36, vec_41, mem_vec_7626);
										mem_vec_7626 = vec_40;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_42 = _mm512_fmadd_ps(vec_36, vec_43, mem_vec_7627);
										mem_vec_7627 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_44 = _mm512_fmadd_ps(vec_36, vec_45, mem_vec_7628);
										mem_vec_7628 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_46 = _mm512_fmadd_ps(vec_36, vec_47, mem_vec_7629);
										mem_vec_7629 = vec_46;

										vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_48 = _mm512_fmadd_ps(vec_36, vec_49, mem_vec_7630);
										mem_vec_7630 = vec_48;

										vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_50 = _mm512_fmadd_ps(vec_36, vec_51, mem_vec_7631);
										mem_vec_7631 = vec_50;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_7632);
										mem_vec_7632 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_7633);
										mem_vec_7633 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_41, mem_vec_7634);
										mem_vec_7634 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_7635);
										mem_vec_7635 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_7636);
										mem_vec_7636 = vec_57;



										vec_58 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_7637);
										mem_vec_7637 = vec_58;



										vec_59 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_7638);
										mem_vec_7638 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_7639);
										mem_vec_7639 = vec_60;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_62 = _mm512_set1_ps(scal_5);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_7640);
										mem_vec_7640 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_7641);
										mem_vec_7641 = vec_63;



										vec_64 = _mm512_fmadd_ps(vec_62, vec_41, mem_vec_7642);
										mem_vec_7642 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_7643);
										mem_vec_7643 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_7644);
										mem_vec_7644 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_62, vec_47, mem_vec_7645);
										mem_vec_7645 = vec_67;



										vec_68 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_7646);
										mem_vec_7646 = vec_68;



										vec_69 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_7647);
										mem_vec_7647 = vec_69;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_71 = _mm512_set1_ps(scal_6);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_7624);
										mem_vec_7624 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_7625);
										mem_vec_7625 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_75 = _mm512_fmadd_ps(vec_71, vec_76, mem_vec_7626);
										mem_vec_7626 = vec_75;

										vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_77 = _mm512_fmadd_ps(vec_71, vec_78, mem_vec_7627);
										mem_vec_7627 = vec_77;

										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_79 = _mm512_fmadd_ps(vec_71, vec_80, mem_vec_7628);
										mem_vec_7628 = vec_79;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_81 = _mm512_fmadd_ps(vec_71, vec_82, mem_vec_7629);
										mem_vec_7629 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_83 = _mm512_fmadd_ps(vec_71, vec_84, mem_vec_7630);
										mem_vec_7630 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_85 = _mm512_fmadd_ps(vec_71, vec_86, mem_vec_7631);
										mem_vec_7631 = vec_85;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_7);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7632);
										mem_vec_7632 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7633);
										mem_vec_7633 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7634);
										mem_vec_7634 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_7635);
										mem_vec_7635 = vec_91;



										vec_92 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7636);
										mem_vec_7636 = vec_92;



										vec_93 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_7637);
										mem_vec_7637 = vec_93;



										vec_94 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_7638);
										mem_vec_7638 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_7639);
										mem_vec_7639 = vec_95;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_97 = _mm512_set1_ps(scal_8);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_7640);
										mem_vec_7640 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_7641);
										mem_vec_7641 = vec_98;



										vec_99 = _mm512_fmadd_ps(vec_97, vec_76, mem_vec_7642);
										mem_vec_7642 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_7643);
										mem_vec_7643 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_7644);
										mem_vec_7644 = vec_101;



										vec_102 = _mm512_fmadd_ps(vec_97, vec_82, mem_vec_7645);
										mem_vec_7645 = vec_102;



										vec_103 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_7646);
										mem_vec_7646 = vec_103;



										vec_104 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_7647);
										mem_vec_7647 = vec_104;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64], mem_vec_7644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80], mem_vec_7645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96], mem_vec_7646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112], mem_vec_7647);
						}
					}
				}
			}
		}
}


}