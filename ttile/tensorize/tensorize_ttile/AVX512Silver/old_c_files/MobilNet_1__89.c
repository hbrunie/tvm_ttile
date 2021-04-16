#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (112, x); T (2, y); T (1, c);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]]
*/
IND_TYPE c, cp_0, c468_p_0, cp_1, c468, h, hp_0, x, xp_0, y, yp_0, y429_p_0, yp_1, y429;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y430 = 0;
IND_TYPE x390 = 0;
IND_TYPE h250 = 0;
IND_TYPE w = 0;
IND_TYPE c469 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4463 ,mem_vec_4464 ,mem_vec_4465 ,mem_vec_4466 ,mem_vec_4467 ,mem_vec_4468 ,mem_vec_4469 ,mem_vec_4470 ,mem_vec_4471 ,mem_vec_4472 ,mem_vec_4473 ,mem_vec_4474 ,mem_vec_4475 ,mem_vec_4476 ,mem_vec_4477 ,mem_vec_4478 ,mem_vec_4479 ,mem_vec_4480 ,mem_vec_4481 ,mem_vec_4482 ,mem_vec_4483 ,mem_vec_4484 ,mem_vec_4485 ,mem_vec_4486 ,mem_vec_4487 ,mem_vec_4488 ,mem_vec_4489 ,mem_vec_4490 ,mem_vec_4491 ,mem_vec_4492 ,mem_vec_4493 ,mem_vec_4494 ,mem_vec_4495 ,mem_vec_4496 ,mem_vec_4497 ,mem_vec_4498 ,mem_vec_4499 ,mem_vec_4500 ,mem_vec_4501 ,mem_vec_4502 ,mem_vec_4503 ,mem_vec_4504 ,mem_vec_4505 ,mem_vec_4506 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y429 = y430, y429_p_0 = 0;
		y429 < y430 + 40;
		y429 += 20, y429_p_0 += 20){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c468 = c469, c468_p_0 = 0;
			c468 < c469 + 32;
			c468 += 32, c468_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y429, yp_1 = y429_p_0, yp_0 = 0;
				y < y429 + 20;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x390, xp_0 = 0;
					x < x390 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h250, hp_0 = 0;
						h < h250 + 3;
						h += 1, hp_0 += 1){
								mem_vec_4463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_4479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_4480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_4481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_4482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
									c < c468 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4463);
									mem_vec_4463 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4464);
									mem_vec_4464 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4465);
									mem_vec_4465 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4466);
									mem_vec_4466 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4467);
									mem_vec_4467 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4468);
									mem_vec_4468 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4469);
									mem_vec_4469 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4470);
									mem_vec_4470 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4471);
									mem_vec_4471 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4472);
									mem_vec_4472 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4473);
									mem_vec_4473 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4474);
									mem_vec_4474 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4475);
									mem_vec_4475 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4476);
									mem_vec_4476 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4477);
									mem_vec_4477 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4478);
									mem_vec_4478 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4479);
									mem_vec_4479 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4480);
									mem_vec_4480 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4481);
									mem_vec_4481 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4482);
									mem_vec_4482 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_4463);
									mem_vec_4463 = vec_32;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_4464);
									mem_vec_4464 = vec_35;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4465);
									mem_vec_4465 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4466);
									mem_vec_4466 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_4467);
									mem_vec_4467 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_4468);
									mem_vec_4468 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_4469);
									mem_vec_4469 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_4470);
									mem_vec_4470 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_4471);
									mem_vec_4471 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_4472);
									mem_vec_4472 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_4473);
									mem_vec_4473 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_4474);
									mem_vec_4474 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_4475);
									mem_vec_4475 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_4476);
									mem_vec_4476 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_4477);
									mem_vec_4477 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_4478);
									mem_vec_4478 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_4479);
									mem_vec_4479 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_4480);
									mem_vec_4480 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_4481);
									mem_vec_4481 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_4482);
									mem_vec_4482 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_65 = _mm512_set1_ps(scal_20);
									vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_4463);
									mem_vec_4463 = vec_64;

									vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_4464);
									mem_vec_4464 = vec_67;
									scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_70 = _mm512_set1_ps(scal_21);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_4465);
									mem_vec_4465 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_4466);
									mem_vec_4466 = vec_71;
									scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_73 = _mm512_set1_ps(scal_22);


									vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4467);
									mem_vec_4467 = vec_72;



									vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_4468);
									mem_vec_4468 = vec_74;
									scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_4469);
									mem_vec_4469 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_4470);
									mem_vec_4470 = vec_77;
									scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
									vec_79 = _mm512_set1_ps(scal_24);


									vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_4471);
									mem_vec_4471 = vec_78;



									vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_4472);
									mem_vec_4472 = vec_80;
									scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_4473);
									mem_vec_4473 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_4474);
									mem_vec_4474 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_4475);
									mem_vec_4475 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_4476);
									mem_vec_4476 = vec_86;
									scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
									vec_88 = _mm512_set1_ps(scal_27);


									vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_4477);
									mem_vec_4477 = vec_87;



									vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_4478);
									mem_vec_4478 = vec_89;
									scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
									vec_91 = _mm512_set1_ps(scal_28);


									vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_4479);
									mem_vec_4479 = vec_90;



									vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_4480);
									mem_vec_4480 = vec_92;
									scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
									vec_94 = _mm512_set1_ps(scal_29);


									vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_4481);
									mem_vec_4481 = vec_93;



									vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_4482);
									mem_vec_4482 = vec_95;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4463);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4464);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4465);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4466);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4467);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4468);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4469);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4470);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4471);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4472);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4473);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4474);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4475);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4476);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4477);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4478);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4479);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4480);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4481);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4482);
					}
				}
			}
		}
	}
	for (y429 = y430 + 40, y429_p_0 = 0;
		y429 < y430 + 40 + 72;
		y429 += 24, y429_p_0 += 24){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c468 = c469, c468_p_0 = 0;
			c468 < c469 + 32;
			c468 += 32, c468_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y429, yp_1 = y429_p_0, yp_0 = 0;
				y < y429 + 24;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x390, xp_0 = 0;
					x < x390 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h250, hp_0 = 0;
						h < h250 + 3;
						h += 1, hp_0 += 1){
								mem_vec_4483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4484 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_4499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_4500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_4501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_4502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_4503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_4504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_4505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_4506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
									c < c468 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4483);
									mem_vec_4483 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4484);
									mem_vec_4484 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4485);
									mem_vec_4485 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4486);
									mem_vec_4486 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4487);
									mem_vec_4487 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4488);
									mem_vec_4488 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4489);
									mem_vec_4489 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4490);
									mem_vec_4490 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4491);
									mem_vec_4491 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4492);
									mem_vec_4492 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4493);
									mem_vec_4493 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4494);
									mem_vec_4494 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4495);
									mem_vec_4495 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4496);
									mem_vec_4496 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4497);
									mem_vec_4497 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4498);
									mem_vec_4498 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4499);
									mem_vec_4499 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4500);
									mem_vec_4500 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4501);
									mem_vec_4501 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4502);
									mem_vec_4502 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4503);
									mem_vec_4503 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4504);
									mem_vec_4504 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4505);
									mem_vec_4505 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4506);
									mem_vec_4506 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);
									vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4483);
									mem_vec_4483 = vec_38;

									vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4484);
									mem_vec_4484 = vec_41;
									scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_4485);
									mem_vec_4485 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_4486);
									mem_vec_4486 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_4487);
									mem_vec_4487 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_4488);
									mem_vec_4488 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_4489);
									mem_vec_4489 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_4490);
									mem_vec_4490 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4491);
									mem_vec_4491 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4492);
									mem_vec_4492 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_4493);
									mem_vec_4493 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_4494);
									mem_vec_4494 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_4495);
									mem_vec_4495 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_4496);
									mem_vec_4496 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_4497);
									mem_vec_4497 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_4498);
									mem_vec_4498 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
									vec_65 = _mm512_set1_ps(scal_20);


									vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_4499);
									mem_vec_4499 = vec_64;



									vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_4500);
									mem_vec_4500 = vec_66;
									scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
									vec_68 = _mm512_set1_ps(scal_21);


									vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_4501);
									mem_vec_4501 = vec_67;



									vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_4502);
									mem_vec_4502 = vec_69;
									scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
									vec_71 = _mm512_set1_ps(scal_22);


									vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_4503);
									mem_vec_4503 = vec_70;



									vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_4504);
									mem_vec_4504 = vec_72;
									scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
									vec_74 = _mm512_set1_ps(scal_23);


									vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_4505);
									mem_vec_4505 = vec_73;



									vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_4506);
									mem_vec_4506 = vec_75;
									scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_77 = _mm512_set1_ps(scal_24);
									vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_4483);
									mem_vec_4483 = vec_76;

									vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_4484);
									mem_vec_4484 = vec_79;
									scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_4485);
									mem_vec_4485 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_4486);
									mem_vec_4486 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_4487);
									mem_vec_4487 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_4488);
									mem_vec_4488 = vec_86;
									scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_88 = _mm512_set1_ps(scal_27);


									vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_4489);
									mem_vec_4489 = vec_87;



									vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_4490);
									mem_vec_4490 = vec_89;
									scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
									vec_91 = _mm512_set1_ps(scal_28);


									vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_4491);
									mem_vec_4491 = vec_90;



									vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_4492);
									mem_vec_4492 = vec_92;
									scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
									vec_94 = _mm512_set1_ps(scal_29);


									vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_4493);
									mem_vec_4493 = vec_93;



									vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_4494);
									mem_vec_4494 = vec_95;
									scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
									vec_97 = _mm512_set1_ps(scal_30);


									vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_4495);
									mem_vec_4495 = vec_96;



									vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_4496);
									mem_vec_4496 = vec_98;
									scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
									vec_100 = _mm512_set1_ps(scal_31);


									vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_4497);
									mem_vec_4497 = vec_99;



									vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_4498);
									mem_vec_4498 = vec_101;
									scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
									vec_103 = _mm512_set1_ps(scal_32);


									vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_4499);
									mem_vec_4499 = vec_102;



									vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_4500);
									mem_vec_4500 = vec_104;
									scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
									vec_106 = _mm512_set1_ps(scal_33);


									vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_4501);
									mem_vec_4501 = vec_105;



									vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_4502);
									mem_vec_4502 = vec_107;
									scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
									vec_109 = _mm512_set1_ps(scal_34);


									vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_4503);
									mem_vec_4503 = vec_108;



									vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_4504);
									mem_vec_4504 = vec_110;
									scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
									vec_112 = _mm512_set1_ps(scal_35);


									vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_4505);
									mem_vec_4505 = vec_111;



									vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_4506);
									mem_vec_4506 = vec_113;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4483);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4484);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4485);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4486);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4487);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4488);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4489);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4490);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4491);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4492);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4493);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4494);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4495);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4496);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4497);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4498);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4499);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4500);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4501);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4502);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4503);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4504);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4505);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4506);
					}
				}
			}
		}
	}


}