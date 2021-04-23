#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (28, x); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))];
  T (2, f); T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c462_p_0, cp_1, c462, f, fp_0, f462_p_0, fp_1, f462, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y308 = 0;
IND_TYPE x447 = 0;
IND_TYPE h = 0;
IND_TYPE w288 = 0;
IND_TYPE c463 = 0;
IND_TYPE f463 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5141 ,mem_vec_5142 ,mem_vec_5143 ,mem_vec_5144 ,mem_vec_5145 ,mem_vec_5146 ,mem_vec_5147 ,mem_vec_5148 ,mem_vec_5149 ,mem_vec_5150 ,mem_vec_5151 ,mem_vec_5152 ,mem_vec_5153 ,mem_vec_5154 ,mem_vec_5155 ,mem_vec_5156 ,mem_vec_5157 ,mem_vec_5158 ,mem_vec_5159 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f462 = f463, f462_p_0 = 0;
	f462 < f463 + 128;
	f462 += 32, f462_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
	// T (c, 2) (64 / 32)
	for (c462 = c463, c462_p_0 = 0;
		c462 < c463 + 64;
		c462 += 32, c462_p_0 += 32){
		// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
		// T (f, 2) (32 / 16)
		for (f = f462, fp_1 = f462_p_0, fp_0 = 0;
			f < f462 + 32;
			f += 16, fp_1 += 16, fp_0 += 16){
				for (y = y308, yp_0 = 0;
					y < y308 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (x, 28) (28 / 1)
					for (x = x447, xp_0 = 0;
						x < x447 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w288, wp_0 = 0;
							w < w288 + 3;
							w += 1, wp_0 += 1){
									mem_vec_5141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_5148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_5149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
									// T (c, 32) (32 / 1)
									for (c = c462, cp_1 = c462_p_0, cp_0 = 0;
										c < c462 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5141);
										mem_vec_5141 = vec_0;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5142);
										mem_vec_5142 = vec_3;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5143);
										mem_vec_5143 = vec_5;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5144);
										mem_vec_5144 = vec_7;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5145);
										mem_vec_5145 = vec_9;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5146);
										mem_vec_5146 = vec_11;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5147);
										mem_vec_5147 = vec_13;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5148);
										mem_vec_5148 = vec_15;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5149);
										mem_vec_5149 = vec_17;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_9);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_5141);
										mem_vec_5141 = vec_19;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_5142);
										mem_vec_5142 = vec_22;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_5143);
										mem_vec_5143 = vec_24;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_5144);
										mem_vec_5144 = vec_26;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5145);
										mem_vec_5145 = vec_28;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_5146);
										mem_vec_5146 = vec_30;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_5147);
										mem_vec_5147 = vec_32;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_5148);
										mem_vec_5148 = vec_34;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_5149);
										mem_vec_5149 = vec_36;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_18);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_5141);
										mem_vec_5141 = vec_38;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_42 = _mm512_set1_ps(scal_19);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_5142);
										mem_vec_5142 = vec_41;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_44 = _mm512_set1_ps(scal_20);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5143);
										mem_vec_5143 = vec_43;
										scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_5144);
										mem_vec_5144 = vec_45;
										scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_5145);
										mem_vec_5145 = vec_47;
										scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_5146);
										mem_vec_5146 = vec_49;
										scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_5147);
										mem_vec_5147 = vec_51;
										scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5148);
										mem_vec_5148 = vec_53;
										scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_5149);
										mem_vec_5149 = vec_55;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5149);
						}
					}
				}
				for (y = y308 + 18, yp_0 = 0;
					y < y308 + 18 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (x, 28) (28 / 1)
					for (x = x447, xp_0 = 0;
						x < x447 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w288, wp_0 = 0;
							w < w288 + 3;
							w += 1, wp_0 += 1){
									mem_vec_5150 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_5157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_5158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_5159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
									// T (c, 32) (32 / 1)
									for (c = c462, cp_1 = c462_p_0, cp_0 = 0;
										c < c462 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5150);
										mem_vec_5150 = vec_0;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5151);
										mem_vec_5151 = vec_3;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5152);
										mem_vec_5152 = vec_5;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5153);
										mem_vec_5153 = vec_7;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5154);
										mem_vec_5154 = vec_9;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5155);
										mem_vec_5155 = vec_11;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5156);
										mem_vec_5156 = vec_13;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5157);
										mem_vec_5157 = vec_15;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5158);
										mem_vec_5158 = vec_17;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5159);
										mem_vec_5159 = vec_19;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_22 = _mm512_set1_ps(scal_10);
										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_21 = _mm512_fmadd_ps(vec_22, vec_23, mem_vec_5150);
										mem_vec_5150 = vec_21;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_23, mem_vec_5151);
										mem_vec_5151 = vec_24;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_23, mem_vec_5152);
										mem_vec_5152 = vec_26;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_5153);
										mem_vec_5153 = vec_28;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_23, mem_vec_5154);
										mem_vec_5154 = vec_30;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_23, mem_vec_5155);
										mem_vec_5155 = vec_32;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_23, mem_vec_5156);
										mem_vec_5156 = vec_34;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_23, mem_vec_5157);
										mem_vec_5157 = vec_36;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_23, mem_vec_5158);
										mem_vec_5158 = vec_38;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_23, mem_vec_5159);
										mem_vec_5159 = vec_40;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_43 = _mm512_set1_ps(scal_20);
										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_42 = _mm512_fmadd_ps(vec_43, vec_44, mem_vec_5150);
										mem_vec_5150 = vec_42;
										scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_5151);
										mem_vec_5151 = vec_45;
										scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_5152);
										mem_vec_5152 = vec_47;
										scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_44, mem_vec_5153);
										mem_vec_5153 = vec_49;
										scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_5154);
										mem_vec_5154 = vec_51;
										scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_44, mem_vec_5155);
										mem_vec_5155 = vec_53;
										scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_44, mem_vec_5156);
										mem_vec_5156 = vec_55;
										scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_5157);
										mem_vec_5157 = vec_57;
										scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_44, mem_vec_5158);
										mem_vec_5158 = vec_59;
										scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_44, mem_vec_5159);
										mem_vec_5159 = vec_61;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5159);
						}
					}
				}
		}
	}
}


}