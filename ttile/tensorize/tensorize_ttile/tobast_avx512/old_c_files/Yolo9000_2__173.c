#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (17, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (2, c); T (1, x); T (8, x)]
*/
IND_TYPE c, cp_0, c984_p_0, cp_1, c984, f, fp_0, w, wp_0, x, xp_0, x1648_p_0, x1649_p_0, x1650_p_0, xp_1, x1648_p_1, x1649_p_1, xp_2, x1648_p_2, xp_3, x1648, x1649, x1650, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y676 = 0;
IND_TYPE x1651 = 0;
IND_TYPE h = 0;
IND_TYPE w512 = 0;
IND_TYPE c985 = 0;
IND_TYPE f578 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6392 ,mem_vec_6393 ,mem_vec_6394 ,mem_vec_6395 ,mem_vec_6396 ,mem_vec_6397 ,mem_vec_6398 ,mem_vec_6399 ,mem_vec_6400 ,mem_vec_6401 ,mem_vec_6402 ,mem_vec_6403 ,mem_vec_6404 ,mem_vec_6405 ,mem_vec_6406 ,mem_vec_6407 ,mem_vec_6408 ,mem_vec_6409 ,mem_vec_6410 ,mem_vec_6411 ,mem_vec_6412 ,mem_vec_6413 ,mem_vec_6414 ,mem_vec_6415 ,mem_vec_6416 ,mem_vec_6417 ,mem_vec_6418 ,mem_vec_6419 ,mem_vec_6420 ,mem_vec_6421 ,mem_vec_6422 ,mem_vec_6423 ,mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,mem_vec_6440 ,mem_vec_6441 ,mem_vec_6442 ,mem_vec_6443 ,mem_vec_6444 ,mem_vec_6445 ,mem_vec_6446 ,mem_vec_6447 ,mem_vec_6448 ,mem_vec_6449 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 8) (272 / 34)
for (x1650 = x1651, x1650_p_0 = 0;
	x1650 < x1651 + 272;
	x1650 += 34, x1650_p_0 += 34){
	// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
	// T (x, 1) (34 / 34)
	for (x1649 = x1650, x1649_p_1 = x1650_p_0, x1649_p_0 = 0;
		x1649 < x1650 + 34;
		x1649 += 34, x1649_p_1 += 34, x1649_p_0 += 34){
		// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (c, 2) (32 / 16)
		for (c984 = c985, c984_p_0 = 0;
			c984 < c985 + 32;
			c984 += 16, c984_p_0 += 16){
			// y = 272, x = 34, h = 3, w = 3, c = 16, f = 64
			// T (f, 2) (64 / 32)
			for (f = f578, fp_0 = 0;
				f < f578 + 64;
				f += 32, fp_0 += 32){
					for (y = y676, yp_0 = 0;
						y < y676 + 182;
						y += 14, yp_0 += 14){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (34 / 2)
						for (x1648 = x1649, x1648_p_2 = x1649_p_1, x1648_p_1 = x1649_p_0, x1648_p_0 = 0;
							x1648 < x1649 + 34;
							x1648 += 2, x1648_p_2 += 2, x1648_p_1 += 2, x1648_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w512, wp_0 = 0;
								w < w512 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1648, xp_3 = x1648_p_2, xp_2 = x1648_p_1, xp_1 = x1648_p_0, xp_0 = 0;
									x < x1648 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6392 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6393 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_6416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_6417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_6418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_6419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6392);
												mem_vec_6392 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6393);
												mem_vec_6393 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6394);
												mem_vec_6394 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6395);
												mem_vec_6395 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6396);
												mem_vec_6396 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6397);
												mem_vec_6397 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6398);
												mem_vec_6398 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6399);
												mem_vec_6399 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6400);
												mem_vec_6400 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6401);
												mem_vec_6401 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6402);
												mem_vec_6402 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6403);
												mem_vec_6403 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6404);
												mem_vec_6404 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6405);
												mem_vec_6405 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6406);
												mem_vec_6406 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6407);
												mem_vec_6407 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6408);
												mem_vec_6408 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6409);
												mem_vec_6409 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6410);
												mem_vec_6410 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6411);
												mem_vec_6411 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6412);
												mem_vec_6412 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6413);
												mem_vec_6413 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6414);
												mem_vec_6414 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6415);
												mem_vec_6415 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6416);
												mem_vec_6416 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6417);
												mem_vec_6417 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_6418);
												mem_vec_6418 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_6419);
												mem_vec_6419 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_45 = _mm512_set1_ps(scal_14);
												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_6392);
												mem_vec_6392 = vec_44;

												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_47 = _mm512_fmadd_ps(vec_45, vec_48, mem_vec_6393);
												mem_vec_6393 = vec_47;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_6394);
												mem_vec_6394 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_6395);
												mem_vec_6395 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6396);
												mem_vec_6396 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_48, mem_vec_6397);
												mem_vec_6397 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_46, mem_vec_6398);
												mem_vec_6398 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_6399);
												mem_vec_6399 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_46, mem_vec_6400);
												mem_vec_6400 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_48, mem_vec_6401);
												mem_vec_6401 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_46, mem_vec_6402);
												mem_vec_6402 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_6403);
												mem_vec_6403 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_46, mem_vec_6404);
												mem_vec_6404 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_48, mem_vec_6405);
												mem_vec_6405 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_46, mem_vec_6406);
												mem_vec_6406 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_6407);
												mem_vec_6407 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_71 = _mm512_set1_ps(scal_22);


												vec_70 = _mm512_fmadd_ps(vec_71, vec_46, mem_vec_6408);
												mem_vec_6408 = vec_70;



												vec_72 = _mm512_fmadd_ps(vec_71, vec_48, mem_vec_6409);
												mem_vec_6409 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_23);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_46, mem_vec_6410);
												mem_vec_6410 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_48, mem_vec_6411);
												mem_vec_6411 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_77 = _mm512_set1_ps(scal_24);


												vec_76 = _mm512_fmadd_ps(vec_77, vec_46, mem_vec_6412);
												mem_vec_6412 = vec_76;



												vec_78 = _mm512_fmadd_ps(vec_77, vec_48, mem_vec_6413);
												mem_vec_6413 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_80 = _mm512_set1_ps(scal_25);


												vec_79 = _mm512_fmadd_ps(vec_80, vec_46, mem_vec_6414);
												mem_vec_6414 = vec_79;



												vec_81 = _mm512_fmadd_ps(vec_80, vec_48, mem_vec_6415);
												mem_vec_6415 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_83 = _mm512_set1_ps(scal_26);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_46, mem_vec_6416);
												mem_vec_6416 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_48, mem_vec_6417);
												mem_vec_6417 = vec_84;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
												vec_86 = _mm512_set1_ps(scal_27);


												vec_85 = _mm512_fmadd_ps(vec_86, vec_46, mem_vec_6418);
												mem_vec_6418 = vec_85;



												vec_87 = _mm512_fmadd_ps(vec_86, vec_48, mem_vec_6419);
												mem_vec_6419 = vec_87;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_89 = _mm512_set1_ps(scal_28);
												vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_6392);
												mem_vec_6392 = vec_88;

												vec_92 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_91 = _mm512_fmadd_ps(vec_89, vec_92, mem_vec_6393);
												mem_vec_6393 = vec_91;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_6394);
												mem_vec_6394 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_92, mem_vec_6395);
												mem_vec_6395 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_90, mem_vec_6396);
												mem_vec_6396 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_92, mem_vec_6397);
												mem_vec_6397 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_90, mem_vec_6398);
												mem_vec_6398 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_92, mem_vec_6399);
												mem_vec_6399 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_90, mem_vec_6400);
												mem_vec_6400 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_92, mem_vec_6401);
												mem_vec_6401 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_106 = _mm512_set1_ps(scal_33);


												vec_105 = _mm512_fmadd_ps(vec_106, vec_90, mem_vec_6402);
												mem_vec_6402 = vec_105;



												vec_107 = _mm512_fmadd_ps(vec_106, vec_92, mem_vec_6403);
												mem_vec_6403 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_109 = _mm512_set1_ps(scal_34);


												vec_108 = _mm512_fmadd_ps(vec_109, vec_90, mem_vec_6404);
												mem_vec_6404 = vec_108;



												vec_110 = _mm512_fmadd_ps(vec_109, vec_92, mem_vec_6405);
												mem_vec_6405 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_112 = _mm512_set1_ps(scal_35);


												vec_111 = _mm512_fmadd_ps(vec_112, vec_90, mem_vec_6406);
												mem_vec_6406 = vec_111;



												vec_113 = _mm512_fmadd_ps(vec_112, vec_92, mem_vec_6407);
												mem_vec_6407 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_115 = _mm512_set1_ps(scal_36);


												vec_114 = _mm512_fmadd_ps(vec_115, vec_90, mem_vec_6408);
												mem_vec_6408 = vec_114;



												vec_116 = _mm512_fmadd_ps(vec_115, vec_92, mem_vec_6409);
												mem_vec_6409 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_118 = _mm512_set1_ps(scal_37);


												vec_117 = _mm512_fmadd_ps(vec_118, vec_90, mem_vec_6410);
												mem_vec_6410 = vec_117;



												vec_119 = _mm512_fmadd_ps(vec_118, vec_92, mem_vec_6411);
												mem_vec_6411 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_121 = _mm512_set1_ps(scal_38);


												vec_120 = _mm512_fmadd_ps(vec_121, vec_90, mem_vec_6412);
												mem_vec_6412 = vec_120;



												vec_122 = _mm512_fmadd_ps(vec_121, vec_92, mem_vec_6413);
												mem_vec_6413 = vec_122;
												scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_124 = _mm512_set1_ps(scal_39);


												vec_123 = _mm512_fmadd_ps(vec_124, vec_90, mem_vec_6414);
												mem_vec_6414 = vec_123;



												vec_125 = _mm512_fmadd_ps(vec_124, vec_92, mem_vec_6415);
												mem_vec_6415 = vec_125;
												scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_127 = _mm512_set1_ps(scal_40);


												vec_126 = _mm512_fmadd_ps(vec_127, vec_90, mem_vec_6416);
												mem_vec_6416 = vec_126;



												vec_128 = _mm512_fmadd_ps(vec_127, vec_92, mem_vec_6417);
												mem_vec_6417 = vec_128;
												scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
												vec_130 = _mm512_set1_ps(scal_41);


												vec_129 = _mm512_fmadd_ps(vec_130, vec_90, mem_vec_6418);
												mem_vec_6418 = vec_129;



												vec_131 = _mm512_fmadd_ps(vec_130, vec_92, mem_vec_6419);
												mem_vec_6419 = vec_131;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6395);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6396);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6397);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6398);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6399);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6400);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6401);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6402);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6403);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6404);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6405);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6406);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6407);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6408);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6409);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6410);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6411);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6412);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6413);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6414);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6415);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6416);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6417);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6418);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_6419);
								}
							}
						}
					}
					for (y = y676 + 182, yp_0 = 0;
						y < y676 + 182 + 90;
						y += 15, yp_0 += 15){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (34 / 2)
						for (x1648 = x1649, x1648_p_2 = x1649_p_1, x1648_p_1 = x1649_p_0, x1648_p_0 = 0;
							x1648 < x1649 + 34;
							x1648 += 2, x1648_p_2 += 2, x1648_p_1 += 2, x1648_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w512, wp_0 = 0;
								w < w512 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1648, xp_3 = x1648_p_2, xp_2 = x1648_p_1, xp_1 = x1648_p_0, xp_0 = 0;
									x < x1648 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6420 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6421 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_6444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_6445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_6446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_6447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_6448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_6449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6420);
												mem_vec_6420 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6421);
												mem_vec_6421 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6422);
												mem_vec_6422 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6423);
												mem_vec_6423 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6424);
												mem_vec_6424 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6425);
												mem_vec_6425 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6426);
												mem_vec_6426 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6427);
												mem_vec_6427 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6428);
												mem_vec_6428 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6429);
												mem_vec_6429 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6430);
												mem_vec_6430 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6431);
												mem_vec_6431 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6432);
												mem_vec_6432 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6433);
												mem_vec_6433 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6434);
												mem_vec_6434 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6435);
												mem_vec_6435 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6436);
												mem_vec_6436 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6437);
												mem_vec_6437 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6438);
												mem_vec_6438 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6439);
												mem_vec_6439 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6440);
												mem_vec_6440 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6441);
												mem_vec_6441 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6442);
												mem_vec_6442 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6443);
												mem_vec_6443 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6444);
												mem_vec_6444 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6445);
												mem_vec_6445 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_6446);
												mem_vec_6446 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_6447);
												mem_vec_6447 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_6448);
												mem_vec_6448 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_6449);
												mem_vec_6449 = vec_46;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_48 = _mm512_set1_ps(scal_15);
												vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_47 = _mm512_fmadd_ps(vec_48, vec_49, mem_vec_6420);
												mem_vec_6420 = vec_47;

												vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_50 = _mm512_fmadd_ps(vec_48, vec_51, mem_vec_6421);
												mem_vec_6421 = vec_50;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_6422);
												mem_vec_6422 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_6423);
												mem_vec_6423 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_49, mem_vec_6424);
												mem_vec_6424 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_51, mem_vec_6425);
												mem_vec_6425 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_49, mem_vec_6426);
												mem_vec_6426 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_51, mem_vec_6427);
												mem_vec_6427 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_6428);
												mem_vec_6428 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_6429);
												mem_vec_6429 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_49, mem_vec_6430);
												mem_vec_6430 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_51, mem_vec_6431);
												mem_vec_6431 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_49, mem_vec_6432);
												mem_vec_6432 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_51, mem_vec_6433);
												mem_vec_6433 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_71 = _mm512_set1_ps(scal_22);


												vec_70 = _mm512_fmadd_ps(vec_71, vec_49, mem_vec_6434);
												mem_vec_6434 = vec_70;



												vec_72 = _mm512_fmadd_ps(vec_71, vec_51, mem_vec_6435);
												mem_vec_6435 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_23);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_49, mem_vec_6436);
												mem_vec_6436 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_51, mem_vec_6437);
												mem_vec_6437 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_77 = _mm512_set1_ps(scal_24);


												vec_76 = _mm512_fmadd_ps(vec_77, vec_49, mem_vec_6438);
												mem_vec_6438 = vec_76;



												vec_78 = _mm512_fmadd_ps(vec_77, vec_51, mem_vec_6439);
												mem_vec_6439 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_80 = _mm512_set1_ps(scal_25);


												vec_79 = _mm512_fmadd_ps(vec_80, vec_49, mem_vec_6440);
												mem_vec_6440 = vec_79;



												vec_81 = _mm512_fmadd_ps(vec_80, vec_51, mem_vec_6441);
												mem_vec_6441 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_83 = _mm512_set1_ps(scal_26);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_49, mem_vec_6442);
												mem_vec_6442 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_51, mem_vec_6443);
												mem_vec_6443 = vec_84;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_86 = _mm512_set1_ps(scal_27);


												vec_85 = _mm512_fmadd_ps(vec_86, vec_49, mem_vec_6444);
												mem_vec_6444 = vec_85;



												vec_87 = _mm512_fmadd_ps(vec_86, vec_51, mem_vec_6445);
												mem_vec_6445 = vec_87;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
												vec_89 = _mm512_set1_ps(scal_28);


												vec_88 = _mm512_fmadd_ps(vec_89, vec_49, mem_vec_6446);
												mem_vec_6446 = vec_88;



												vec_90 = _mm512_fmadd_ps(vec_89, vec_51, mem_vec_6447);
												mem_vec_6447 = vec_90;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 1) + c];
												vec_92 = _mm512_set1_ps(scal_29);


												vec_91 = _mm512_fmadd_ps(vec_92, vec_49, mem_vec_6448);
												mem_vec_6448 = vec_91;



												vec_93 = _mm512_fmadd_ps(vec_92, vec_51, mem_vec_6449);
												mem_vec_6449 = vec_93;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_95 = _mm512_set1_ps(scal_30);
												vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_94 = _mm512_fmadd_ps(vec_95, vec_96, mem_vec_6420);
												mem_vec_6420 = vec_94;

												vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_97 = _mm512_fmadd_ps(vec_95, vec_98, mem_vec_6421);
												mem_vec_6421 = vec_97;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_96, mem_vec_6422);
												mem_vec_6422 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_98, mem_vec_6423);
												mem_vec_6423 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_96, mem_vec_6424);
												mem_vec_6424 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_98, mem_vec_6425);
												mem_vec_6425 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_106 = _mm512_set1_ps(scal_33);


												vec_105 = _mm512_fmadd_ps(vec_106, vec_96, mem_vec_6426);
												mem_vec_6426 = vec_105;



												vec_107 = _mm512_fmadd_ps(vec_106, vec_98, mem_vec_6427);
												mem_vec_6427 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_109 = _mm512_set1_ps(scal_34);


												vec_108 = _mm512_fmadd_ps(vec_109, vec_96, mem_vec_6428);
												mem_vec_6428 = vec_108;



												vec_110 = _mm512_fmadd_ps(vec_109, vec_98, mem_vec_6429);
												mem_vec_6429 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_112 = _mm512_set1_ps(scal_35);


												vec_111 = _mm512_fmadd_ps(vec_112, vec_96, mem_vec_6430);
												mem_vec_6430 = vec_111;



												vec_113 = _mm512_fmadd_ps(vec_112, vec_98, mem_vec_6431);
												mem_vec_6431 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_115 = _mm512_set1_ps(scal_36);


												vec_114 = _mm512_fmadd_ps(vec_115, vec_96, mem_vec_6432);
												mem_vec_6432 = vec_114;



												vec_116 = _mm512_fmadd_ps(vec_115, vec_98, mem_vec_6433);
												mem_vec_6433 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_118 = _mm512_set1_ps(scal_37);


												vec_117 = _mm512_fmadd_ps(vec_118, vec_96, mem_vec_6434);
												mem_vec_6434 = vec_117;



												vec_119 = _mm512_fmadd_ps(vec_118, vec_98, mem_vec_6435);
												mem_vec_6435 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_121 = _mm512_set1_ps(scal_38);


												vec_120 = _mm512_fmadd_ps(vec_121, vec_96, mem_vec_6436);
												mem_vec_6436 = vec_120;



												vec_122 = _mm512_fmadd_ps(vec_121, vec_98, mem_vec_6437);
												mem_vec_6437 = vec_122;
												scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_124 = _mm512_set1_ps(scal_39);


												vec_123 = _mm512_fmadd_ps(vec_124, vec_96, mem_vec_6438);
												mem_vec_6438 = vec_123;



												vec_125 = _mm512_fmadd_ps(vec_124, vec_98, mem_vec_6439);
												mem_vec_6439 = vec_125;
												scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_127 = _mm512_set1_ps(scal_40);


												vec_126 = _mm512_fmadd_ps(vec_127, vec_96, mem_vec_6440);
												mem_vec_6440 = vec_126;



												vec_128 = _mm512_fmadd_ps(vec_127, vec_98, mem_vec_6441);
												mem_vec_6441 = vec_128;
												scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_130 = _mm512_set1_ps(scal_41);


												vec_129 = _mm512_fmadd_ps(vec_130, vec_96, mem_vec_6442);
												mem_vec_6442 = vec_129;



												vec_131 = _mm512_fmadd_ps(vec_130, vec_98, mem_vec_6443);
												mem_vec_6443 = vec_131;
												scal_42 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_133 = _mm512_set1_ps(scal_42);


												vec_132 = _mm512_fmadd_ps(vec_133, vec_96, mem_vec_6444);
												mem_vec_6444 = vec_132;



												vec_134 = _mm512_fmadd_ps(vec_133, vec_98, mem_vec_6445);
												mem_vec_6445 = vec_134;
												scal_43 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
												vec_136 = _mm512_set1_ps(scal_43);


												vec_135 = _mm512_fmadd_ps(vec_136, vec_96, mem_vec_6446);
												mem_vec_6446 = vec_135;



												vec_137 = _mm512_fmadd_ps(vec_136, vec_98, mem_vec_6447);
												mem_vec_6447 = vec_137;
												scal_44 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 2) + c];
												vec_139 = _mm512_set1_ps(scal_44);


												vec_138 = _mm512_fmadd_ps(vec_139, vec_96, mem_vec_6448);
												mem_vec_6448 = vec_138;



												vec_140 = _mm512_fmadd_ps(vec_139, vec_98, mem_vec_6449);
												mem_vec_6449 = vec_140;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6420);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6421);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6422);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6423);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6424);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6425);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6426);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6427);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6428);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6429);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6431);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6432);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6433);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6434);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6435);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6437);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_6447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_6448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_6449);
								}
							}
						}
					}
			}
		}
	}
}


}