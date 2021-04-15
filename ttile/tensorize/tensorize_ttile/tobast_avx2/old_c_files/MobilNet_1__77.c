#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, w); Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))];
  T (2, f); T (32, c); T (16, x)]
*/
IND_TYPE c, cp_0, c858_p_0, cp_1, c858, f, fp_0, w, wp_0, x, xp_0, x1104_p_0, xp_1, x1104, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y572 = 0;
IND_TYPE x1105 = 0;
IND_TYPE h = 0;
IND_TYPE w458 = 0;
IND_TYPE c859 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,mem_vec_6300 ,mem_vec_6301 ,mem_vec_6302 ,mem_vec_6303 ,mem_vec_6304 ,mem_vec_6305 ,mem_vec_6306 ,mem_vec_6307 ,mem_vec_6308 ,mem_vec_6309 ,mem_vec_6310 ,mem_vec_6311 ,mem_vec_6312 ,mem_vec_6313 ,mem_vec_6314 ,mem_vec_6315 ,mem_vec_6316 ,mem_vec_6317 ,mem_vec_6318 ,mem_vec_6319 ,mem_vec_6320 ,mem_vec_6321 ,mem_vec_6322 ,mem_vec_6323 ,mem_vec_6324 ,mem_vec_6325 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 16) (112 / 7)
for (x1104 = x1105, x1104_p_0 = 0;
	x1104 < x1105 + 112;
	x1104 += 7, x1104_p_0 += 7){
	// y = 112, x = 7, h = 3, w = 3, c = 32, f = 32
	// T (c, 32) (32 / 1)
	for (c858 = c859, c858_p_0 = 0;
		c858 < c859 + 32;
		c858 += 1, c858_p_0 += 1){
		// y = 112, x = 7, h = 3, w = 3, c = 1, f = 32
		// T (f, 2) (32 / 16)
		for (f = f314, fp_0 = 0;
			f < f314 + 32;
			f += 16, fp_0 += 16){
				for (y = y572, yp_0 = 0;
					y < y572 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 16
					// T (w, 3) (3 / 1)
					for (w = w458, wp_0 = 0;
						w < w458 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 1, f = 16
						// T (x, 7) (7 / 1)
						for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
							x < x1104 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6292 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6293 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_6294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_6298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_6300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_6302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_6304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_6306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_6307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
									// T (c, 1) (1 / 1)
									for (c = c858, cp_1 = c858_p_0, cp_0 = 0;
										c < c858 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6292);
										mem_vec_6292 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6293);
										mem_vec_6293 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm256_set1_ps(scal_1);


										vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6294);
										mem_vec_6294 = vec_5;



										vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6295);
										mem_vec_6295 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm256_set1_ps(scal_2);


										vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6296);
										mem_vec_6296 = vec_8;



										vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6297);
										mem_vec_6297 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm256_set1_ps(scal_3);


										vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6298);
										mem_vec_6298 = vec_11;



										vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6299);
										mem_vec_6299 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm256_set1_ps(scal_4);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6300);
										mem_vec_6300 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6301);
										mem_vec_6301 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm256_set1_ps(scal_5);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6302);
										mem_vec_6302 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6303);
										mem_vec_6303 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm256_set1_ps(scal_6);


										vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6304);
										mem_vec_6304 = vec_20;



										vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6305);
										mem_vec_6305 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm256_set1_ps(scal_7);


										vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6306);
										mem_vec_6306 = vec_23;



										vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6307);
										mem_vec_6307 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_27 = _mm256_set1_ps(scal_8);
										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_6292);
										mem_vec_6292 = vec_26;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_6293);
										mem_vec_6293 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_32 = _mm256_set1_ps(scal_9);


										vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_6294);
										mem_vec_6294 = vec_31;



										vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_6295);
										mem_vec_6295 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_35 = _mm256_set1_ps(scal_10);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_6296);
										mem_vec_6296 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_6297);
										mem_vec_6297 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_38 = _mm256_set1_ps(scal_11);


										vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_6298);
										mem_vec_6298 = vec_37;



										vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_6299);
										mem_vec_6299 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_41 = _mm256_set1_ps(scal_12);


										vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_6300);
										mem_vec_6300 = vec_40;



										vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_6301);
										mem_vec_6301 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_13);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6302);
										mem_vec_6302 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6303);
										mem_vec_6303 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_47 = _mm256_set1_ps(scal_14);


										vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_6304);
										mem_vec_6304 = vec_46;



										vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_6305);
										mem_vec_6305 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_50 = _mm256_set1_ps(scal_15);


										vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_6306);
										mem_vec_6306 = vec_49;



										vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_6307);
										mem_vec_6307 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_53 = _mm256_set1_ps(scal_16);
										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_6292);
										mem_vec_6292 = vec_52;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_6293);
										mem_vec_6293 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_17);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6294);
										mem_vec_6294 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6295);
										mem_vec_6295 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm256_set1_ps(scal_18);


										vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_6296);
										mem_vec_6296 = vec_60;



										vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_6297);
										mem_vec_6297 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_64 = _mm256_set1_ps(scal_19);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_6298);
										mem_vec_6298 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_6299);
										mem_vec_6299 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_67 = _mm256_set1_ps(scal_20);


										vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_6300);
										mem_vec_6300 = vec_66;



										vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_6301);
										mem_vec_6301 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_70 = _mm256_set1_ps(scal_21);


										vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_6302);
										mem_vec_6302 = vec_69;



										vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_6303);
										mem_vec_6303 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_73 = _mm256_set1_ps(scal_22);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_6304);
										mem_vec_6304 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_6305);
										mem_vec_6305 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_76 = _mm256_set1_ps(scal_23);


										vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_6306);
										mem_vec_6306 = vec_75;



										vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_6307);
										mem_vec_6307 = vec_77;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6292);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6293);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6294);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6295);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6296);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6297);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6298);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6299);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6300);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6301);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6302);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6303);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6304);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6305);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6306);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6307);
						}
					}
				}
				for (y = y572 + 40, yp_0 = 0;
					y < y572 + 40 + 72;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 16
					// T (w, 3) (3 / 1)
					for (w = w458, wp_0 = 0;
						w < w458 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 1, f = 16
						// T (x, 7) (7 / 1)
						for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
							x < x1104 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6308 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6309 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_6310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_6314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_6316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_6318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_6320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_6322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_6323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									mem_vec_6324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_6325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
									// T (c, 1) (1 / 1)
									for (c = c858, cp_1 = c858_p_0, cp_0 = 0;
										c < c858 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6308);
										mem_vec_6308 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6309);
										mem_vec_6309 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm256_set1_ps(scal_1);


										vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6310);
										mem_vec_6310 = vec_5;



										vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6311);
										mem_vec_6311 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm256_set1_ps(scal_2);


										vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6312);
										mem_vec_6312 = vec_8;



										vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6313);
										mem_vec_6313 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm256_set1_ps(scal_3);


										vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6314);
										mem_vec_6314 = vec_11;



										vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6315);
										mem_vec_6315 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm256_set1_ps(scal_4);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6316);
										mem_vec_6316 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6317);
										mem_vec_6317 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm256_set1_ps(scal_5);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6318);
										mem_vec_6318 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6319);
										mem_vec_6319 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm256_set1_ps(scal_6);


										vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6320);
										mem_vec_6320 = vec_20;



										vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6321);
										mem_vec_6321 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm256_set1_ps(scal_7);


										vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6322);
										mem_vec_6322 = vec_23;



										vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6323);
										mem_vec_6323 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm256_set1_ps(scal_8);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6324);
										mem_vec_6324 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6325);
										mem_vec_6325 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_30 = _mm256_set1_ps(scal_9);
										vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6308);
										mem_vec_6308 = vec_29;

										vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6309);
										mem_vec_6309 = vec_32;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_35 = _mm256_set1_ps(scal_10);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_6310);
										mem_vec_6310 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_6311);
										mem_vec_6311 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_38 = _mm256_set1_ps(scal_11);


										vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_6312);
										mem_vec_6312 = vec_37;



										vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_6313);
										mem_vec_6313 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_41 = _mm256_set1_ps(scal_12);


										vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_6314);
										mem_vec_6314 = vec_40;



										vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_6315);
										mem_vec_6315 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_13);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6316);
										mem_vec_6316 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6317);
										mem_vec_6317 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_47 = _mm256_set1_ps(scal_14);


										vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_6318);
										mem_vec_6318 = vec_46;



										vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_6319);
										mem_vec_6319 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_50 = _mm256_set1_ps(scal_15);


										vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_6320);
										mem_vec_6320 = vec_49;



										vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_6321);
										mem_vec_6321 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_53 = _mm256_set1_ps(scal_16);


										vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_6322);
										mem_vec_6322 = vec_52;



										vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_6323);
										mem_vec_6323 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_56 = _mm256_set1_ps(scal_17);


										vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_6324);
										mem_vec_6324 = vec_55;



										vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_6325);
										mem_vec_6325 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_59 = _mm256_set1_ps(scal_18);
										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6308);
										mem_vec_6308 = vec_58;

										vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6309);
										mem_vec_6309 = vec_61;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_64 = _mm256_set1_ps(scal_19);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_6310);
										mem_vec_6310 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_6311);
										mem_vec_6311 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_67 = _mm256_set1_ps(scal_20);


										vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_6312);
										mem_vec_6312 = vec_66;



										vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_6313);
										mem_vec_6313 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_70 = _mm256_set1_ps(scal_21);


										vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_6314);
										mem_vec_6314 = vec_69;



										vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_6315);
										mem_vec_6315 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_73 = _mm256_set1_ps(scal_22);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6316);
										mem_vec_6316 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6317);
										mem_vec_6317 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_76 = _mm256_set1_ps(scal_23);


										vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_6318);
										mem_vec_6318 = vec_75;



										vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_6319);
										mem_vec_6319 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_79 = _mm256_set1_ps(scal_24);


										vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_6320);
										mem_vec_6320 = vec_78;



										vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_6321);
										mem_vec_6321 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_82 = _mm256_set1_ps(scal_25);


										vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_6322);
										mem_vec_6322 = vec_81;



										vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_6323);
										mem_vec_6323 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_85 = _mm256_set1_ps(scal_26);


										vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_6324);
										mem_vec_6324 = vec_84;



										vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_6325);
										mem_vec_6325 = vec_86;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6308);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6309);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6310);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6311);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6312);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6313);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6314);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6315);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6316);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6317);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6318);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6319);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6320);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6321);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6322);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6323);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6324);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6325);
						}
					}
				}
		}
	}
}


}