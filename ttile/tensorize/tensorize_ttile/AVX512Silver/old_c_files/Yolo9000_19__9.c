#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, f);
  T (1, c); T (1, y)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, c1_p_0, c1, cp_1, c0_p_1, cp_2, f, fp_0, x, xp_0, y, y0, yp_0, y0_p_0, yp_1;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y1 = 0;
IND_TYPE x0 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c2 = 0;
IND_TYPE f0 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y0 = y1, y0_p_0 = 0;
	y0 < y1 + 17;
	y0 += 17, y0_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 1) (1024 / 1024)
	for (c1 = c2, c1_p_0 = 0;
		c1 < c2 + 1024;
		c1 += 1024, c1_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 8) (512 / 64)
		for (f = f0, fp_0 = 0;
			f < f0 + 512;
			f += 64, fp_0 += 64){
				for (y = y0, yp_1 = y0_p_0, yp_0 = 0;
					y < y0 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c0 = c1, c0_p_1 = c1_p_0, c0_p_0 = 0;
						c0 < c1 + 1024;
						c0 += 128, c0_p_1 += 128, c0_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x0, xp_0 = 0;
							x < x0 + 17;
							x += 1, xp_0 += 1){
									mem_vec_0 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_8 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c0, cp_2 = c0_p_1, cp_1 = c0_p_0, cp_0 = 0;
										c < c0 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_0);
										mem_vec_0 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1);
										mem_vec_1 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2);
										mem_vec_2 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3);
										mem_vec_3 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4);
										mem_vec_4 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5);
										mem_vec_5 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6);
										mem_vec_6 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7);
										mem_vec_7 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8);
										mem_vec_8 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9);
										mem_vec_9 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10);
										mem_vec_10 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11);
										mem_vec_11 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11);
						}
					}
				}
				for (y = y0 + 3, yp_1 = y0_p_0, yp_0 = 0;
					y < y0 + 3 + 14;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c0 = c1, c0_p_1 = c1_p_0, c0_p_0 = 0;
						c0 < c1 + 1024;
						c0 += 128, c0_p_1 += 128, c0_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x0, xp_0 = 0;
							x < x0 + 17;
							x += 1, xp_0 += 1){
									mem_vec_12 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_17 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_18 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_19 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_20 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_21 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_22 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_23 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_24 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_25 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_26 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_27 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_28 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_29 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_30 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_31 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_32 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_33 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c0, cp_2 = c0_p_1, cp_1 = c0_p_0, cp_0 = 0;
										c < c0 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12);
										mem_vec_12 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13);
										mem_vec_13 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14);
										mem_vec_14 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15);
										mem_vec_15 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16);
										mem_vec_16 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_17);
										mem_vec_17 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_18);
										mem_vec_18 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_19);
										mem_vec_19 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_20);
										mem_vec_20 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_21);
										mem_vec_21 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_22);
										mem_vec_22 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_23);
										mem_vec_23 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_24);
										mem_vec_24 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_25);
										mem_vec_25 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_26);
										mem_vec_26 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_27);
										mem_vec_27 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_28);
										mem_vec_28 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_29);
										mem_vec_29 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_30);
										mem_vec_30 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_31);
										mem_vec_31 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_32);
										mem_vec_32 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_33);
										mem_vec_33 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_34);
										mem_vec_34 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_35);
										mem_vec_35 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_36);
										mem_vec_36 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_37);
										mem_vec_37 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_38);
										mem_vec_38 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_39);
										mem_vec_39 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_17);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_18);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_19);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_20);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_21);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_22);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_23);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_24);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_25);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_26);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_27);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_28);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_29);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_30);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_31);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_32);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_33);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_34);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_35);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_36);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_37);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_38);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_39);
						}
					}
				}
		}
	}
}


}