#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (1, c); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1104_p_0, c1105_p_0, cp_1, c1104_p_1, cp_2, c1104, c1105, w, wp_0, x, xp_0, x1262_p_0, xp_1, x1262, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y676 = 0;
IND_TYPE x1263 = 0;
IND_TYPE h = 0;
IND_TYPE w652 = 0;
IND_TYPE c1106 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11324 ,mem_vec_11325 ,mem_vec_11326 ,mem_vec_11327 ,mem_vec_11328 ,mem_vec_11329 ,mem_vec_11330 ,mem_vec_11331 ,mem_vec_11332 ,mem_vec_11333 ,mem_vec_11334 ,mem_vec_11335 ,mem_vec_11336 ,mem_vec_11337 ,mem_vec_11338 ,mem_vec_11339 ,mem_vec_11340 ,mem_vec_11341 ,mem_vec_11342 ,mem_vec_11343 ,mem_vec_11344 ,mem_vec_11345 ,mem_vec_11346 ,mem_vec_11347 ,mem_vec_11348 ,mem_vec_11349 ,mem_vec_11350 ,mem_vec_11351 ,mem_vec_11352 ,mem_vec_11353 ,mem_vec_11354 ,mem_vec_11355 ,mem_vec_11356 ,mem_vec_11357 ,mem_vec_11358 ,mem_vec_11359 ,mem_vec_11360 ,mem_vec_11361 ,mem_vec_11362 ,mem_vec_11363 ,mem_vec_11364 ,mem_vec_11365 ,mem_vec_11366 ,mem_vec_11367 ,mem_vec_11368 ,mem_vec_11369 ,mem_vec_11370 ,mem_vec_11371 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c1105 = c1106, c1105_p_0 = 0;
	c1105 < c1106 + 64;
	c1105 += 64, c1105_p_0 += 64){
		for (y = y676, yp_0 = 0;
			y < y676 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 4) (56 / 14)
			for (x1262 = x1263, x1262_p_0 = 0;
				x1262 < x1263 + 56;
				x1262 += 14, x1262_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c1104 = c1105, c1104_p_1 = c1105_p_0, c1104_p_0 = 0;
					c1104 < c1105 + 64;
					c1104 += 64, c1104_p_1 += 64, c1104_p_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
					// T (w, 3) (3 / 1)
					for (w = w652, wp_0 = 0;
						w < w652 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 64, f = 64
						// T (x, 14) (14 / 1)
						for (x = x1262, xp_1 = x1262_p_0, xp_0 = 0;
							x < x1262 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11324 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11325 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11326 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11327 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c1104, cp_2 = c1104_p_1, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11324);
										mem_vec_11324 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11325);
										mem_vec_11325 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11326);
										mem_vec_11326 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11327);
										mem_vec_11327 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11328);
										mem_vec_11328 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11329);
										mem_vec_11329 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11330);
										mem_vec_11330 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11331);
										mem_vec_11331 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11332);
										mem_vec_11332 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11333);
										mem_vec_11333 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11334);
										mem_vec_11334 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11335);
										mem_vec_11335 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11336);
										mem_vec_11336 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11337);
										mem_vec_11337 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11338);
										mem_vec_11338 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11339);
										mem_vec_11339 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11340);
										mem_vec_11340 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11341);
										mem_vec_11341 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11342);
										mem_vec_11342 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11343);
										mem_vec_11343 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11324);
										mem_vec_11324 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11325);
										mem_vec_11325 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11326);
										mem_vec_11326 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11327);
										mem_vec_11327 = vec_36;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11328);
										mem_vec_11328 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11329);
										mem_vec_11329 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11330);
										mem_vec_11330 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11331);
										mem_vec_11331 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11332);
										mem_vec_11332 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11333);
										mem_vec_11333 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11334);
										mem_vec_11334 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11335);
										mem_vec_11335 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11336);
										mem_vec_11336 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11337);
										mem_vec_11337 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11338);
										mem_vec_11338 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11339);
										mem_vec_11339 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11340);
										mem_vec_11340 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11341);
										mem_vec_11341 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11342);
										mem_vec_11342 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11343);
										mem_vec_11343 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11324);
										mem_vec_11324 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11325);
										mem_vec_11325 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11326);
										mem_vec_11326 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11327);
										mem_vec_11327 = vec_65;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11328);
										mem_vec_11328 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11329);
										mem_vec_11329 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11330);
										mem_vec_11330 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11331);
										mem_vec_11331 = vec_71;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11332);
										mem_vec_11332 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11333);
										mem_vec_11333 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11334);
										mem_vec_11334 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11335);
										mem_vec_11335 = vec_76;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11336);
										mem_vec_11336 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11337);
										mem_vec_11337 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11338);
										mem_vec_11338 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11339);
										mem_vec_11339 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11340);
										mem_vec_11340 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11341);
										mem_vec_11341 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11342);
										mem_vec_11342 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11343);
										mem_vec_11343 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11335);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11343);
						}
					}
				}
			}
		}
		for (y = y676 + 35, yp_0 = 0;
			y < y676 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 4) (56 / 14)
			for (x1262 = x1263, x1262_p_0 = 0;
				x1262 < x1263 + 56;
				x1262 += 14, x1262_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c1104 = c1105, c1104_p_1 = c1105_p_0, c1104_p_0 = 0;
					c1104 < c1105 + 64;
					c1104 += 64, c1104_p_1 += 64, c1104_p_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
					// T (w, 3) (3 / 1)
					for (w = w652, wp_0 = 0;
						w < w652 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 64, f = 64
						// T (x, 14) (14 / 1)
						for (x = x1262, xp_1 = x1262_p_0, xp_0 = 0;
							x < x1262 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11346 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11347 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_11364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_11367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_11368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_11371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c1104, cp_2 = c1104_p_1, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11344);
										mem_vec_11344 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11345);
										mem_vec_11345 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11346);
										mem_vec_11346 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11347);
										mem_vec_11347 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11348);
										mem_vec_11348 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11349);
										mem_vec_11349 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11350);
										mem_vec_11350 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11351);
										mem_vec_11351 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11352);
										mem_vec_11352 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11353);
										mem_vec_11353 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11354);
										mem_vec_11354 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11355);
										mem_vec_11355 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11356);
										mem_vec_11356 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11357);
										mem_vec_11357 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11358);
										mem_vec_11358 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11359);
										mem_vec_11359 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11360);
										mem_vec_11360 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11361);
										mem_vec_11361 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11362);
										mem_vec_11362 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11363);
										mem_vec_11363 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11364);
										mem_vec_11364 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11365);
										mem_vec_11365 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11366);
										mem_vec_11366 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11367);
										mem_vec_11367 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_11368);
										mem_vec_11368 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_11369);
										mem_vec_11369 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_11370);
										mem_vec_11370 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_11371);
										mem_vec_11371 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_11344);
										mem_vec_11344 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_11345);
										mem_vec_11345 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_11346);
										mem_vec_11346 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_11347);
										mem_vec_11347 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_11348);
										mem_vec_11348 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_11349);
										mem_vec_11349 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_11350);
										mem_vec_11350 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_11351);
										mem_vec_11351 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_11352);
										mem_vec_11352 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_11353);
										mem_vec_11353 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_11354);
										mem_vec_11354 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_11355);
										mem_vec_11355 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_11356);
										mem_vec_11356 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_11357);
										mem_vec_11357 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_11358);
										mem_vec_11358 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_11359);
										mem_vec_11359 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_11360);
										mem_vec_11360 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_11361);
										mem_vec_11361 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_11362);
										mem_vec_11362 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_11363);
										mem_vec_11363 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_11364);
										mem_vec_11364 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_11365);
										mem_vec_11365 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_11366);
										mem_vec_11366 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_11367);
										mem_vec_11367 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_11368);
										mem_vec_11368 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_11369);
										mem_vec_11369 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_11370);
										mem_vec_11370 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_11371);
										mem_vec_11371 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_11344);
										mem_vec_11344 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_11345);
										mem_vec_11345 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_11346);
										mem_vec_11346 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_11347);
										mem_vec_11347 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_11348);
										mem_vec_11348 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_11349);
										mem_vec_11349 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_11350);
										mem_vec_11350 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_11351);
										mem_vec_11351 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_11352);
										mem_vec_11352 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_11353);
										mem_vec_11353 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_11354);
										mem_vec_11354 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_11355);
										mem_vec_11355 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_11356);
										mem_vec_11356 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_11357);
										mem_vec_11357 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_11358);
										mem_vec_11358 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_11359);
										mem_vec_11359 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_11360);
										mem_vec_11360 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_11361);
										mem_vec_11361 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_11362);
										mem_vec_11362 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_11363);
										mem_vec_11363 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_11364);
										mem_vec_11364 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_11365);
										mem_vec_11365 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_11366);
										mem_vec_11366 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_11367);
										mem_vec_11367 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_11368);
										mem_vec_11368 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_11369);
										mem_vec_11369 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_11370);
										mem_vec_11370 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_11371);
										mem_vec_11371 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11361);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11362);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11363);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11364);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11365);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11366);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11367);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11368);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11369);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_11370);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_11371);
						}
					}
				}
			}
		}
}


}