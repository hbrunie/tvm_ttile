#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1262_p_0, cp_1, c1262, f, fp_0, f1376_p_0, f1377_p_0, fp_1, f1376_p_1, fp_2, f1376, f1377, h, hp_0, x, xp_0, x1262_p_0, xp_1, x1262, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y780 = 0;
IND_TYPE x1263 = 0;
IND_TYPE h620 = 0;
IND_TYPE w = 0;
IND_TYPE c1263 = 0;
IND_TYPE f1378 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_15430 ,mem_vec_15431 ,mem_vec_15432 ,mem_vec_15433 ,mem_vec_15434 ,mem_vec_15435 ,mem_vec_15436 ,mem_vec_15437 ,mem_vec_15438 ,mem_vec_15439 ,mem_vec_15440 ,mem_vec_15441 ,mem_vec_15442 ,mem_vec_15443 ,mem_vec_15444 ,mem_vec_15445 ,mem_vec_15446 ,mem_vec_15447 ,mem_vec_15448 ,mem_vec_15449 ,mem_vec_15450 ,mem_vec_15451 ,mem_vec_15452 ,mem_vec_15453 ,mem_vec_15454 ,mem_vec_15455 ,mem_vec_15456 ,mem_vec_15457 ,mem_vec_15458 ,mem_vec_15459 ,mem_vec_15460 ,mem_vec_15461 ,mem_vec_15462 ,mem_vec_15463 ,mem_vec_15464 ,mem_vec_15465 ,mem_vec_15466 ,mem_vec_15467 ,mem_vec_15468 ,mem_vec_15469 ,mem_vec_15470 ,mem_vec_15471 ,mem_vec_15472 ,mem_vec_15473 ,mem_vec_15474 ,mem_vec_15475 ,mem_vec_15476 ,mem_vec_15477 ,mem_vec_15478 ,mem_vec_15479 ,mem_vec_15480 ,mem_vec_15481 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f1377 = f1378, f1377_p_0 = 0;
	f1377 < f1378 + 512;
	f1377 += 128, f1377_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 2) (256 / 128)
	for (c1262 = c1263, c1262_p_0 = 0;
		c1262 < c1263 + 256;
		c1262 += 128, c1262_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 128
		// T (f, 2) (128 / 64)
		for (f1376 = f1377, f1376_p_1 = f1377_p_0, f1376_p_0 = 0;
			f1376 < f1377 + 128;
			f1376 += 64, f1376_p_1 += 64, f1376_p_0 += 64){
				for (y = y780, yp_0 = 0;
					y < y780 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (x, 17) (34 / 2)
					for (x1262 = x1263, x1262_p_0 = 0;
						x1262 < x1263 + 34;
						x1262 += 2, x1262_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1376, fp_2 = f1376_p_1, fp_1 = f1376_p_0, fp_0 = 0;
							f < f1376 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h620, hp_0 = 0;
								h < h620 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1262, xp_1 = x1262_p_0, xp_0 = 0;
									x < x1262 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_15430 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15431 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15432 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15433 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_15443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_15444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_15445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_15446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_15447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_15448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_15449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_15450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_15451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_15452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_15453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c1262, cp_1 = c1262_p_0, cp_0 = 0;
												c < c1262 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15430);
												mem_vec_15430 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15431);
												mem_vec_15431 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15432);
												mem_vec_15432 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15433);
												mem_vec_15433 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15434);
												mem_vec_15434 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15435);
												mem_vec_15435 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15436);
												mem_vec_15436 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15437);
												mem_vec_15437 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15438);
												mem_vec_15438 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15439);
												mem_vec_15439 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15440);
												mem_vec_15440 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15441);
												mem_vec_15441 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15442);
												mem_vec_15442 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15443);
												mem_vec_15443 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15444);
												mem_vec_15444 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15445);
												mem_vec_15445 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15446);
												mem_vec_15446 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15447);
												mem_vec_15447 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15448);
												mem_vec_15448 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15449);
												mem_vec_15449 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15450);
												mem_vec_15450 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15451);
												mem_vec_15451 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15452);
												mem_vec_15452 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15453);
												mem_vec_15453 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_15430);
												mem_vec_15430 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_15431);
												mem_vec_15431 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_15432);
												mem_vec_15432 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_15433);
												mem_vec_15433 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_15434);
												mem_vec_15434 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_15435);
												mem_vec_15435 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_15436);
												mem_vec_15436 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_15437);
												mem_vec_15437 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_15438);
												mem_vec_15438 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_15439);
												mem_vec_15439 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_15440);
												mem_vec_15440 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_15441);
												mem_vec_15441 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_15442);
												mem_vec_15442 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_15443);
												mem_vec_15443 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_15444);
												mem_vec_15444 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_15445);
												mem_vec_15445 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_15446);
												mem_vec_15446 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_15447);
												mem_vec_15447 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_15448);
												mem_vec_15448 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_15449);
												mem_vec_15449 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_15450);
												mem_vec_15450 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_15451);
												mem_vec_15451 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_15452);
												mem_vec_15452 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_15453);
												mem_vec_15453 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_15430);
												mem_vec_15430 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_15431);
												mem_vec_15431 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_15432);
												mem_vec_15432 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_15433);
												mem_vec_15433 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_15434);
												mem_vec_15434 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_15435);
												mem_vec_15435 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_15436);
												mem_vec_15436 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_15437);
												mem_vec_15437 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_15438);
												mem_vec_15438 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_15439);
												mem_vec_15439 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_15440);
												mem_vec_15440 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_15441);
												mem_vec_15441 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_15442);
												mem_vec_15442 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_15443);
												mem_vec_15443 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_15444);
												mem_vec_15444 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_15445);
												mem_vec_15445 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_15446);
												mem_vec_15446 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_15447);
												mem_vec_15447 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_15448);
												mem_vec_15448 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_15449);
												mem_vec_15449 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_15450);
												mem_vec_15450 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_15451);
												mem_vec_15451 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_15452);
												mem_vec_15452 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_15453);
												mem_vec_15453 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15431);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15432);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15433);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15434);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15435);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15437);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15453);
								}
							}
						}
					}
				}
				for (y = y780 + 6, yp_0 = 0;
					y < y780 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (x, 17) (34 / 2)
					for (x1262 = x1263, x1262_p_0 = 0;
						x1262 < x1263 + 34;
						x1262 += 2, x1262_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1376, fp_2 = f1376_p_1, fp_1 = f1376_p_0, fp_0 = 0;
							f < f1376 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h620, hp_0 = 0;
								h < h620 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1262, xp_1 = x1262_p_0, xp_0 = 0;
									x < x1262 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_15454 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15455 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15456 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15457 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_15467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_15468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_15469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_15470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_15471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_15472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_15473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_15474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_15475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_15476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_15477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_15478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_15479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_15480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_15481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c1262, cp_1 = c1262_p_0, cp_0 = 0;
												c < c1262 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15454);
												mem_vec_15454 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15455);
												mem_vec_15455 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15456);
												mem_vec_15456 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15457);
												mem_vec_15457 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15458);
												mem_vec_15458 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15459);
												mem_vec_15459 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15460);
												mem_vec_15460 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15461);
												mem_vec_15461 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15462);
												mem_vec_15462 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15463);
												mem_vec_15463 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15464);
												mem_vec_15464 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15465);
												mem_vec_15465 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15466);
												mem_vec_15466 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15467);
												mem_vec_15467 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15468);
												mem_vec_15468 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15469);
												mem_vec_15469 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15470);
												mem_vec_15470 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15471);
												mem_vec_15471 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15472);
												mem_vec_15472 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15473);
												mem_vec_15473 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15474);
												mem_vec_15474 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15475);
												mem_vec_15475 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15476);
												mem_vec_15476 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15477);
												mem_vec_15477 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15478);
												mem_vec_15478 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15479);
												mem_vec_15479 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15480);
												mem_vec_15480 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15481);
												mem_vec_15481 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_15454);
												mem_vec_15454 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_15455);
												mem_vec_15455 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_15456);
												mem_vec_15456 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_15457);
												mem_vec_15457 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_15458);
												mem_vec_15458 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_15459);
												mem_vec_15459 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_15460);
												mem_vec_15460 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_15461);
												mem_vec_15461 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_15462);
												mem_vec_15462 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_15463);
												mem_vec_15463 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_15464);
												mem_vec_15464 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_15465);
												mem_vec_15465 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_15466);
												mem_vec_15466 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_15467);
												mem_vec_15467 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_15468);
												mem_vec_15468 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_15469);
												mem_vec_15469 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_15470);
												mem_vec_15470 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_15471);
												mem_vec_15471 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_15472);
												mem_vec_15472 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_15473);
												mem_vec_15473 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_15474);
												mem_vec_15474 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_15475);
												mem_vec_15475 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_15476);
												mem_vec_15476 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_15477);
												mem_vec_15477 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_15478);
												mem_vec_15478 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_15479);
												mem_vec_15479 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_15480);
												mem_vec_15480 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_15481);
												mem_vec_15481 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_15454);
												mem_vec_15454 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_15455);
												mem_vec_15455 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_15456);
												mem_vec_15456 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_15457);
												mem_vec_15457 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_15458);
												mem_vec_15458 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_15459);
												mem_vec_15459 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_15460);
												mem_vec_15460 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_15461);
												mem_vec_15461 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_15462);
												mem_vec_15462 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_15463);
												mem_vec_15463 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_15464);
												mem_vec_15464 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_15465);
												mem_vec_15465 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_15466);
												mem_vec_15466 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_15467);
												mem_vec_15467 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_15468);
												mem_vec_15468 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_15469);
												mem_vec_15469 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_15470);
												mem_vec_15470 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_15471);
												mem_vec_15471 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_15472);
												mem_vec_15472 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_15473);
												mem_vec_15473 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_15474);
												mem_vec_15474 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_15475);
												mem_vec_15475 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_15476);
												mem_vec_15476 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_15477);
												mem_vec_15477 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_15478);
												mem_vec_15478 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_15479);
												mem_vec_15479 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_15480);
												mem_vec_15480 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_15481);
												mem_vec_15481 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15457);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15459);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15463);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_15480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_15481);
								}
							}
						}
					}
				}
		}
	}
}


}