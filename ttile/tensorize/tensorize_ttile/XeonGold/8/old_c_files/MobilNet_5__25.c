#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (4, c); T (1, y); T (16, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c573_p_0, cp_1, c573, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y423_p_0, yp_1, y423;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y424 = 0;
IND_TYPE x596 = 0;
IND_TYPE h = 0;
IND_TYPE w256 = 0;
IND_TYPE c574 = 0;
IND_TYPE f682 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_7 ,vec_8 ,vec_9;
	for (y423 = y424, y423_p_0 = 0;
		y423 < y424 + 18;
		y423 += 9, y423_p_0 += 9){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 16) (256 / 16)
		for (f = f682, fp_0 = 0;
			f < f682 + 256;
			f += 16, fp_0 += 16){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 16
			// T (y, 1) (ph_y / ph_y)
			for (y = y423, yp_1 = y423_p_0, yp_0 = 0;
				y < y423 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 16
				// T (c, 4) (256 / 64)
				for (c573 = c574, c573_p_0 = 0;
					c573 < c574 + 256;
					c573 += 64, c573_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 16
					// T (x, 28) (28 / 1)
					for (x = x596, xp_0 = 0;
						x < x596 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w256, wp_0 = 0;
							w < w256 + 3;
							w += 1, wp_0 += 1){
									mem_vec_5381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_5388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_5389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c573, cp_1 = c573_p_0, cp_0 = 0;
										c < c573 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5381);
										mem_vec_5381 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5382);
										mem_vec_5382 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5383);
										mem_vec_5383 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5384);
										mem_vec_5384 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5385);
										mem_vec_5385 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5386);
										mem_vec_5386 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5387);
										mem_vec_5387 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5388);
										mem_vec_5388 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5389);
										mem_vec_5389 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_9);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_5381);
										mem_vec_5381 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_5382);
										mem_vec_5382 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_5383);
										mem_vec_5383 = vec_24;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_5384);
										mem_vec_5384 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5385);
										mem_vec_5385 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_5386);
										mem_vec_5386 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_5387);
										mem_vec_5387 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_5388);
										mem_vec_5388 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_5389);
										mem_vec_5389 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_18);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_5381);
										mem_vec_5381 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_42 = _mm512_set1_ps(scal_19);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_5382);
										mem_vec_5382 = vec_41;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_44 = _mm512_set1_ps(scal_20);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5383);
										mem_vec_5383 = vec_43;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_5384);
										mem_vec_5384 = vec_45;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_5385);
										mem_vec_5385 = vec_47;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_5386);
										mem_vec_5386 = vec_49;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_5387);
										mem_vec_5387 = vec_51;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5388);
										mem_vec_5388 = vec_53;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_5389);
										mem_vec_5389 = vec_55;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5389);
						}
					}
				}
			}
		}
	}
	for (y423 = y424 + 18, y423_p_0 = 0;
		y423 < y424 + 18 + 10;
		y423 += 10, y423_p_0 += 10){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 16) (256 / 16)
		for (f = f682, fp_0 = 0;
			f < f682 + 256;
			f += 16, fp_0 += 16){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 16
			// T (y, 1) (ph_y / ph_y)
			for (y = y423, yp_1 = y423_p_0, yp_0 = 0;
				y < y423 + 10;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 16
				// T (c, 4) (256 / 64)
				for (c573 = c574, c573_p_0 = 0;
					c573 < c574 + 256;
					c573 += 64, c573_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 16
					// T (x, 28) (28 / 1)
					for (x = x596, xp_0 = 0;
						x < x596 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w256, wp_0 = 0;
							w < w256 + 3;
							w += 1, wp_0 += 1){
									mem_vec_5390 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_5397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_5398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_5399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c573, cp_1 = c573_p_0, cp_0 = 0;
										c < c573 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5390);
										mem_vec_5390 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5391);
										mem_vec_5391 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5392);
										mem_vec_5392 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5393);
										mem_vec_5393 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5394);
										mem_vec_5394 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5395);
										mem_vec_5395 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5396);
										mem_vec_5396 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5397);
										mem_vec_5397 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5398);
										mem_vec_5398 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5399);
										mem_vec_5399 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_22 = _mm512_set1_ps(scal_10);
										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_21 = _mm512_fmadd_ps(vec_22, vec_23, mem_vec_5390);
										mem_vec_5390 = vec_21;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_23, mem_vec_5391);
										mem_vec_5391 = vec_24;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_23, mem_vec_5392);
										mem_vec_5392 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_5393);
										mem_vec_5393 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_23, mem_vec_5394);
										mem_vec_5394 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_23, mem_vec_5395);
										mem_vec_5395 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_23, mem_vec_5396);
										mem_vec_5396 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_23, mem_vec_5397);
										mem_vec_5397 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_23, mem_vec_5398);
										mem_vec_5398 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_23, mem_vec_5399);
										mem_vec_5399 = vec_40;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_43 = _mm512_set1_ps(scal_20);
										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_42 = _mm512_fmadd_ps(vec_43, vec_44, mem_vec_5390);
										mem_vec_5390 = vec_42;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_5391);
										mem_vec_5391 = vec_45;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_5392);
										mem_vec_5392 = vec_47;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_44, mem_vec_5393);
										mem_vec_5393 = vec_49;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_5394);
										mem_vec_5394 = vec_51;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_44, mem_vec_5395);
										mem_vec_5395 = vec_53;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_44, mem_vec_5396);
										mem_vec_5396 = vec_55;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_5397);
										mem_vec_5397 = vec_57;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_44, mem_vec_5398);
										mem_vec_5398 = vec_59;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_44, mem_vec_5399);
										mem_vec_5399 = vec_61;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5399);
						}
					}
				}
			}
		}
	}


}