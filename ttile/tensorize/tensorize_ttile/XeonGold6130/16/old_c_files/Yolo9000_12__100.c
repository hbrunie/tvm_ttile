#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c435_p_0, cp_1, c435, f, fp_0, f526_p_0, f527_p_0, fp_1, f526_p_1, fp_2, f526, f527, h, hp_0, x, xp_0, x442_p_0, xp_1, x442, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y317 = 0;
IND_TYPE x443 = 0;
IND_TYPE h270 = 0;
IND_TYPE w = 0;
IND_TYPE c436 = 0;
IND_TYPE f528 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6463 ,mem_vec_6464 ,mem_vec_6465 ,mem_vec_6466 ,mem_vec_6467 ,mem_vec_6468 ,mem_vec_6469 ,mem_vec_6470 ,mem_vec_6471 ,mem_vec_6472 ,mem_vec_6473 ,mem_vec_6474 ,mem_vec_6475 ,mem_vec_6476 ,mem_vec_6477 ,mem_vec_6478 ,mem_vec_6479 ,mem_vec_6480 ,mem_vec_6481 ,mem_vec_6482 ,mem_vec_6483 ,mem_vec_6484 ,mem_vec_6485 ,mem_vec_6486 ,mem_vec_6487 ,mem_vec_6488 ,mem_vec_6489 ,mem_vec_6490 ,mem_vec_6491 ,mem_vec_6492 ,mem_vec_6493 ,mem_vec_6494 ,mem_vec_6495 ,mem_vec_6496 ,mem_vec_6497 ,mem_vec_6498 ,mem_vec_6499 ,mem_vec_6500 ,mem_vec_6501 ,mem_vec_6502 ,mem_vec_6503 ,mem_vec_6504 ,mem_vec_6505 ,mem_vec_6506 ,mem_vec_6507 ,mem_vec_6508 ,mem_vec_6509 ,mem_vec_6510 ,mem_vec_6511 ,mem_vec_6512 ,mem_vec_6513 ,mem_vec_6514 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f527 = f528, f527_p_0 = 0;
	f527 < f528 + 512;
	f527 += 512, f527_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (f, 4) (512 / 128)
	for (f526 = f527, f526_p_1 = f527_p_0, f526_p_0 = 0;
		f526 < f527 + 512;
		f526 += 128, f526_p_1 += 128, f526_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (x, 2) (34 / 17)
		for (x442 = x443, x442_p_0 = 0;
			x442 < x443 + 34;
			x442 += 17, x442_p_0 += 17){
				for (y = y317, yp_0 = 0;
					y < y317 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f526, fp_2 = f526_p_1, fp_1 = f526_p_0, fp_0 = 0;
						f < f526 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c435 = c436, c435_p_0 = 0;
							c435 < c436 + 256;
							c435 += 64, c435_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h270, hp_0 = 0;
								h < h270 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 64
								// T (x, 17) (17 / 1)
								for (x = x442, xp_1 = x442_p_0, xp_0 = 0;
									x < x442 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6466 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_6483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_6486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c435, cp_1 = c435_p_0, cp_0 = 0;
												c < c435 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6463);
												mem_vec_6463 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6464);
												mem_vec_6464 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6465);
												mem_vec_6465 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6466);
												mem_vec_6466 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6467);
												mem_vec_6467 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6468);
												mem_vec_6468 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6469);
												mem_vec_6469 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6470);
												mem_vec_6470 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6471);
												mem_vec_6471 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6472);
												mem_vec_6472 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6473);
												mem_vec_6473 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6474);
												mem_vec_6474 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6475);
												mem_vec_6475 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6476);
												mem_vec_6476 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6477);
												mem_vec_6477 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6478);
												mem_vec_6478 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6479);
												mem_vec_6479 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6480);
												mem_vec_6480 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6481);
												mem_vec_6481 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6482);
												mem_vec_6482 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6483);
												mem_vec_6483 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6484);
												mem_vec_6484 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6485);
												mem_vec_6485 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6486);
												mem_vec_6486 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6463);
												mem_vec_6463 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6464);
												mem_vec_6464 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_6465);
												mem_vec_6465 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_6466);
												mem_vec_6466 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_6467);
												mem_vec_6467 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_6468);
												mem_vec_6468 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_6469);
												mem_vec_6469 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_6470);
												mem_vec_6470 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6471);
												mem_vec_6471 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6472);
												mem_vec_6472 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_6473);
												mem_vec_6473 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6474);
												mem_vec_6474 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_6475);
												mem_vec_6475 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_6476);
												mem_vec_6476 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_6477);
												mem_vec_6477 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_6478);
												mem_vec_6478 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_6479);
												mem_vec_6479 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_6480);
												mem_vec_6480 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_6481);
												mem_vec_6481 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_6482);
												mem_vec_6482 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_6483);
												mem_vec_6483 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_6484);
												mem_vec_6484 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_6485);
												mem_vec_6485 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_6486);
												mem_vec_6486 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_6463);
												mem_vec_6463 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_6464);
												mem_vec_6464 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_6465);
												mem_vec_6465 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_6466);
												mem_vec_6466 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_6467);
												mem_vec_6467 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_6468);
												mem_vec_6468 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_6469);
												mem_vec_6469 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_6470);
												mem_vec_6470 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_6471);
												mem_vec_6471 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_6472);
												mem_vec_6472 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_6473);
												mem_vec_6473 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_6474);
												mem_vec_6474 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_6475);
												mem_vec_6475 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_6476);
												mem_vec_6476 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_6477);
												mem_vec_6477 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_6478);
												mem_vec_6478 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_6479);
												mem_vec_6479 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_6480);
												mem_vec_6480 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_6481);
												mem_vec_6481 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_6482);
												mem_vec_6482 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_6483);
												mem_vec_6483 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_6484);
												mem_vec_6484 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_6485);
												mem_vec_6485 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_6486);
												mem_vec_6486 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6463);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6486);
								}
							}
						}
					}
				}
				for (y = y317 + 6, yp_0 = 0;
					y < y317 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f526, fp_2 = f526_p_1, fp_1 = f526_p_0, fp_0 = 0;
						f < f526 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c435 = c436, c435_p_0 = 0;
							c435 < c436 + 256;
							c435 += 64, c435_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h270, hp_0 = 0;
								h < h270 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 64
								// T (x, 17) (17 / 1)
								for (x = x442, xp_1 = x442_p_0, xp_0 = 0;
									x < x442 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6487 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6488 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6489 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_6507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_6510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_6511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_6514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c435, cp_1 = c435_p_0, cp_0 = 0;
												c < c435 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6487);
												mem_vec_6487 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6488);
												mem_vec_6488 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6489);
												mem_vec_6489 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6490);
												mem_vec_6490 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6491);
												mem_vec_6491 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6492);
												mem_vec_6492 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6493);
												mem_vec_6493 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6494);
												mem_vec_6494 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6495);
												mem_vec_6495 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6496);
												mem_vec_6496 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6497);
												mem_vec_6497 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6498);
												mem_vec_6498 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6499);
												mem_vec_6499 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6500);
												mem_vec_6500 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6501);
												mem_vec_6501 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6502);
												mem_vec_6502 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6503);
												mem_vec_6503 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6504);
												mem_vec_6504 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6505);
												mem_vec_6505 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6506);
												mem_vec_6506 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6507);
												mem_vec_6507 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6508);
												mem_vec_6508 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6509);
												mem_vec_6509 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6510);
												mem_vec_6510 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_6511);
												mem_vec_6511 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_6512);
												mem_vec_6512 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_6513);
												mem_vec_6513 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_6514);
												mem_vec_6514 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_6487);
												mem_vec_6487 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_6488);
												mem_vec_6488 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_6489);
												mem_vec_6489 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_6490);
												mem_vec_6490 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_6491);
												mem_vec_6491 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_6492);
												mem_vec_6492 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_6493);
												mem_vec_6493 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_6494);
												mem_vec_6494 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_6495);
												mem_vec_6495 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_6496);
												mem_vec_6496 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_6497);
												mem_vec_6497 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_6498);
												mem_vec_6498 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_6499);
												mem_vec_6499 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_6500);
												mem_vec_6500 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_6501);
												mem_vec_6501 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_6502);
												mem_vec_6502 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_6503);
												mem_vec_6503 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_6504);
												mem_vec_6504 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_6505);
												mem_vec_6505 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_6506);
												mem_vec_6506 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_6507);
												mem_vec_6507 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_6508);
												mem_vec_6508 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_6509);
												mem_vec_6509 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_6510);
												mem_vec_6510 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_6511);
												mem_vec_6511 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_6512);
												mem_vec_6512 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_6513);
												mem_vec_6513 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_6514);
												mem_vec_6514 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_6487);
												mem_vec_6487 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_6488);
												mem_vec_6488 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_6489);
												mem_vec_6489 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_6490);
												mem_vec_6490 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_6491);
												mem_vec_6491 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_6492);
												mem_vec_6492 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_6493);
												mem_vec_6493 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_6494);
												mem_vec_6494 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_6495);
												mem_vec_6495 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_6496);
												mem_vec_6496 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_6497);
												mem_vec_6497 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_6498);
												mem_vec_6498 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_6499);
												mem_vec_6499 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_6500);
												mem_vec_6500 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_6501);
												mem_vec_6501 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_6502);
												mem_vec_6502 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_6503);
												mem_vec_6503 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_6504);
												mem_vec_6504 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_6505);
												mem_vec_6505 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_6506);
												mem_vec_6506 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_6507);
												mem_vec_6507 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_6508);
												mem_vec_6508 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_6509);
												mem_vec_6509 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_6510);
												mem_vec_6510 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_6511);
												mem_vec_6511 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_6512);
												mem_vec_6512 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_6513);
												mem_vec_6513 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_6514);
												mem_vec_6514 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6493);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6495);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6496);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6497);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6498);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6499);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6500);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6501);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6502);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6503);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6511);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_6513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_6514);
								}
							}
						}
					}
				}
		}
	}
}


}