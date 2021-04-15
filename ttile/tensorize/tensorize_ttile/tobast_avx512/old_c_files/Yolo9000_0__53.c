#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (3, c); Hoist_vars [c]; T (32, x);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 6)); ((Iter 2), (Arg 7))];
  T (1, x); T (17, y); T (17, x)]
*/
IND_TYPE c, cp_0, h, hp_0, x, xp_0, x830_p_0, x831_p_0, xp_1, x830_p_1, xp_2, x830, x831, y, yp_0, y724_p_0, yp_1, y724;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y725 = 0;
IND_TYPE x832 = 0;
IND_TYPE h326 = 0;
IND_TYPE w = 0;
IND_TYPE c444 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6328 ,mem_vec_6329 ,mem_vec_6330 ,mem_vec_6331 ,mem_vec_6332 ,mem_vec_6333 ,mem_vec_6334 ,mem_vec_6335 ,mem_vec_6336 ,mem_vec_6337 ,mem_vec_6338 ,mem_vec_6339 ,mem_vec_6340 ,mem_vec_6341 ,mem_vec_6342 ,mem_vec_6343 ,mem_vec_6344 ,mem_vec_6345 ,mem_vec_6346 ,mem_vec_6347 ,mem_vec_6348 ,mem_vec_6349 ,mem_vec_6350 ,mem_vec_6351 ,mem_vec_6352 ,mem_vec_6353 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 17) (544 / 32)
for (x831 = x832, x831_p_0 = 0;
	x831 < x832 + 544;
	x831 += 32, x831_p_0 += 32){
	// y = 544, x = 32, h = 3, w = 3, c = 3, f = 32
	// T (y, 17) (544 / 32)
	for (y724 = y725, y724_p_0 = 0;
		y724 < y725 + 544;
		y724 += 32, y724_p_0 += 32){
		// y = 32, x = 32, h = 3, w = 3, c = 3, f = 32
		// T (x, 1) (32 / 32)
		for (x830 = x831, x830_p_1 = x831_p_0, x830_p_0 = 0;
			x830 < x831 + 32;
			x830 += 32, x830_p_1 += 32, x830_p_0 += 32){
				for (y = y724, yp_1 = y724_p_0, yp_0 = 0;
					y < y724 + 18;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 32, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h326, hp_0 = 0;
						h < h326 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 32, h = 1, w = 3, c = 3, f = 32
						// T (x, 32) (32 / 1)
						for (x = x830, xp_2 = x830_p_1, xp_1 = x830_p_0, xp_0 = 0;
							x < x830 + 32;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6328 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6329 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c444, cp_0 = 0;
										c < c444 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6328);
										mem_vec_6328 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6329);
										mem_vec_6329 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6330);
										mem_vec_6330 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6331);
										mem_vec_6331 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6332);
										mem_vec_6332 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6333);
										mem_vec_6333 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6334);
										mem_vec_6334 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6335);
										mem_vec_6335 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6336);
										mem_vec_6336 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6337);
										mem_vec_6337 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6338);
										mem_vec_6338 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6339);
										mem_vec_6339 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_6328);
										mem_vec_6328 = vec_20;

										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_6329);
										mem_vec_6329 = vec_23;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_6330);
										mem_vec_6330 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_6331);
										mem_vec_6331 = vec_27;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_6332);
										mem_vec_6332 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_6333);
										mem_vec_6333 = vec_30;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_6334);
										mem_vec_6334 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_6335);
										mem_vec_6335 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_6336);
										mem_vec_6336 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_6337);
										mem_vec_6337 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_6338);
										mem_vec_6338 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_6339);
										mem_vec_6339 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_6328);
										mem_vec_6328 = vec_40;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_6329);
										mem_vec_6329 = vec_43;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_46 = _mm512_set1_ps(scal_13);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_6330);
										mem_vec_6330 = vec_45;



										vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_6331);
										mem_vec_6331 = vec_47;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_49 = _mm512_set1_ps(scal_14);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6332);
										mem_vec_6332 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_6333);
										mem_vec_6333 = vec_50;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_6334);
										mem_vec_6334 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_6335);
										mem_vec_6335 = vec_53;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_6336);
										mem_vec_6336 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_6337);
										mem_vec_6337 = vec_56;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_6338);
										mem_vec_6338 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_6339);
										mem_vec_6339 = vec_59;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6335);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6339);
						}
					}
				}
				for (y = y724 + 18, yp_1 = y724_p_0, yp_0 = 0;
					y < y724 + 18 + 14;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 32, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h326, hp_0 = 0;
						h < h326 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 32, h = 1, w = 3, c = 3, f = 32
						// T (x, 32) (32 / 1)
						for (x = x830, xp_2 = x830_p_1, xp_1 = x830_p_0, xp_0 = 0;
							x < x830 + 32;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_6352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c444, cp_0 = 0;
										c < c444 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6340);
										mem_vec_6340 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6341);
										mem_vec_6341 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6342);
										mem_vec_6342 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6343);
										mem_vec_6343 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6344);
										mem_vec_6344 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6345);
										mem_vec_6345 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6346);
										mem_vec_6346 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6347);
										mem_vec_6347 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6348);
										mem_vec_6348 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6349);
										mem_vec_6349 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6350);
										mem_vec_6350 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6351);
										mem_vec_6351 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6352);
										mem_vec_6352 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6353);
										mem_vec_6353 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_6340);
										mem_vec_6340 = vec_23;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_6341);
										mem_vec_6341 = vec_26;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6342);
										mem_vec_6342 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6343);
										mem_vec_6343 = vec_30;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_6344);
										mem_vec_6344 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_6345);
										mem_vec_6345 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_6346);
										mem_vec_6346 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6347);
										mem_vec_6347 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_6348);
										mem_vec_6348 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_6349);
										mem_vec_6349 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_6350);
										mem_vec_6350 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6351);
										mem_vec_6351 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_6352);
										mem_vec_6352 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_6353);
										mem_vec_6353 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);
										vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_6340);
										mem_vec_6340 = vec_46;

										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_6341);
										mem_vec_6341 = vec_49;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_6342);
										mem_vec_6342 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_6343);
										mem_vec_6343 = vec_53;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_6344);
										mem_vec_6344 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_6345);
										mem_vec_6345 = vec_56;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_6346);
										mem_vec_6346 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_6347);
										mem_vec_6347 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_6348);
										mem_vec_6348 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_6349);
										mem_vec_6349 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_6350);
										mem_vec_6350 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_6351);
										mem_vec_6351 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_6352);
										mem_vec_6352 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_6353);
										mem_vec_6353 = vec_68;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6353);
						}
					}
				}
		}
	}
}


}