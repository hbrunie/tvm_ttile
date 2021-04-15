#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (3, c); Hoist_vars [c]; T (4, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 11))];
  T (2, x); T (32, y); T (68, x)]
*/
IND_TYPE c, cp_0, h, hp_0, x, xp_0, x838_p_0, x839_p_0, xp_1, x838_p_1, xp_2, x838, x839, y, yp_0, y730_p_0, yp_1, y730;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y731 = 0;
IND_TYPE x840 = 0;
IND_TYPE h330 = 0;
IND_TYPE w = 0;
IND_TYPE c448 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6380 ,mem_vec_6381 ,mem_vec_6382 ,mem_vec_6383 ,mem_vec_6384 ,mem_vec_6385 ,mem_vec_6386 ,mem_vec_6387 ,mem_vec_6388 ,mem_vec_6389 ,mem_vec_6390 ,mem_vec_6391 ,mem_vec_6392 ,mem_vec_6393 ,mem_vec_6394 ,mem_vec_6395 ,mem_vec_6396 ,mem_vec_6397 ,mem_vec_6398 ,mem_vec_6399 ,mem_vec_6400 ,mem_vec_6401 ,mem_vec_6402 ,mem_vec_6403 ,mem_vec_6404 ,mem_vec_6405 ,mem_vec_6406 ,mem_vec_6407 ,mem_vec_6408 ,mem_vec_6409 ,mem_vec_6410 ,mem_vec_6411 ,mem_vec_6412 ,mem_vec_6413 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 68) (544 / 8)
for (x839 = x840, x839_p_0 = 0;
	x839 < x840 + 544;
	x839 += 8, x839_p_0 += 8){
	// y = 544, x = 8, h = 3, w = 3, c = 3, f = 32
	// T (y, 32) (544 / 17)
	for (y730 = y731, y730_p_0 = 0;
		y730 < y731 + 544;
		y730 += 17, y730_p_0 += 17){
		// y = 17, x = 8, h = 3, w = 3, c = 3, f = 32
		// T (x, 2) (8 / 4)
		for (x838 = x839, x838_p_1 = x839_p_0, x838_p_0 = 0;
			x838 < x839 + 8;
			x838 += 4, x838_p_1 += 4, x838_p_0 += 4){
				for (y = y730, yp_1 = y730_p_0, yp_0 = 0;
					y < y730 + 6;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 4, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h330, hp_0 = 0;
						h < h330 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 3, f = 32
						// T (x, 4) (4 / 1)
						for (x = x838, xp_2 = x838_p_1, xp_1 = x838_p_0, xp_0 = 0;
							x < x838 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6380 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c448, cp_0 = 0;
										c < c448 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6380);
										mem_vec_6380 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6381);
										mem_vec_6381 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6382);
										mem_vec_6382 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6383);
										mem_vec_6383 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6384);
										mem_vec_6384 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6385);
										mem_vec_6385 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6386);
										mem_vec_6386 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6387);
										mem_vec_6387 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6388);
										mem_vec_6388 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6389);
										mem_vec_6389 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6390);
										mem_vec_6390 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6391);
										mem_vec_6391 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_6380);
										mem_vec_6380 = vec_20;

										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_6381);
										mem_vec_6381 = vec_23;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_6382);
										mem_vec_6382 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_6383);
										mem_vec_6383 = vec_27;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_6384);
										mem_vec_6384 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_6385);
										mem_vec_6385 = vec_30;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_6386);
										mem_vec_6386 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_6387);
										mem_vec_6387 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_6388);
										mem_vec_6388 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_6389);
										mem_vec_6389 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_6390);
										mem_vec_6390 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_6391);
										mem_vec_6391 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_6380);
										mem_vec_6380 = vec_40;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_6381);
										mem_vec_6381 = vec_43;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_46 = _mm512_set1_ps(scal_13);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_6382);
										mem_vec_6382 = vec_45;



										vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_6383);
										mem_vec_6383 = vec_47;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_49 = _mm512_set1_ps(scal_14);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6384);
										mem_vec_6384 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_6385);
										mem_vec_6385 = vec_50;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_6386);
										mem_vec_6386 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_6387);
										mem_vec_6387 = vec_53;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_6388);
										mem_vec_6388 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_6389);
										mem_vec_6389 = vec_56;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_6390);
										mem_vec_6390 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_6391);
										mem_vec_6391 = vec_59;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6391);
						}
					}
				}
				for (y = y730 + 6, yp_1 = y730_p_0, yp_0 = 0;
					y < y730 + 6 + 11;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 4, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h330, hp_0 = 0;
						h < h330 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 3, f = 32
						// T (x, 4) (4 / 1)
						for (x = x838, xp_2 = x838_p_1, xp_1 = x838_p_0, xp_0 = 0;
							x < x838 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
									// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c448, cp_0 = 0;
										c < c448 + 3;
										c += 1, cp_0 += 1){
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
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_6392);
										mem_vec_6392 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_6393);
										mem_vec_6393 = vec_38;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_6394);
										mem_vec_6394 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_6395);
										mem_vec_6395 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6396);
										mem_vec_6396 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_6397);
										mem_vec_6397 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_6398);
										mem_vec_6398 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_6399);
										mem_vec_6399 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_6400);
										mem_vec_6400 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_6401);
										mem_vec_6401 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_6402);
										mem_vec_6402 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_6403);
										mem_vec_6403 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_6404);
										mem_vec_6404 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_6405);
										mem_vec_6405 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_6406);
										mem_vec_6406 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_6407);
										mem_vec_6407 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_6408);
										mem_vec_6408 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_6409);
										mem_vec_6409 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_6410);
										mem_vec_6410 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_6411);
										mem_vec_6411 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_6412);
										mem_vec_6412 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_6413);
										mem_vec_6413 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_71 = _mm512_set1_ps(scal_22);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_6392);
										mem_vec_6392 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_6393);
										mem_vec_6393 = vec_73;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_6394);
										mem_vec_6394 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_6395);
										mem_vec_6395 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_6396);
										mem_vec_6396 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_6397);
										mem_vec_6397 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_6398);
										mem_vec_6398 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_6399);
										mem_vec_6399 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_6400);
										mem_vec_6400 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_6401);
										mem_vec_6401 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_6402);
										mem_vec_6402 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_6403);
										mem_vec_6403 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_6404);
										mem_vec_6404 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_6405);
										mem_vec_6405 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_6406);
										mem_vec_6406 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_6407);
										mem_vec_6407 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_6408);
										mem_vec_6408 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_6409);
										mem_vec_6409 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_6410);
										mem_vec_6410 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_6411);
										mem_vec_6411 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_6412);
										mem_vec_6412 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_6413);
										mem_vec_6413 = vec_104;
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
						}
					}
				}
		}
	}
}


}