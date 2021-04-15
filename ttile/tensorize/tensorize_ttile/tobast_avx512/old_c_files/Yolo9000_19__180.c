#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (128, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c944_p_0, c945_p_0, cp_1, c944_p_1, cp_2, c944, c945, f, fp_0, x, xp_0, x708_p_0, xp_1, x708, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y472 = 0;
IND_TYPE x709 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c946 = 0;
IND_TYPE f472 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7672 ,mem_vec_7673 ,mem_vec_7674 ,mem_vec_7675 ,mem_vec_7676 ,mem_vec_7677 ,mem_vec_7678 ,mem_vec_7679 ,mem_vec_7680 ,mem_vec_7681 ,mem_vec_7682 ,mem_vec_7683 ,mem_vec_7684 ,mem_vec_7685 ,mem_vec_7686 ,mem_vec_7687 ,mem_vec_7688 ,mem_vec_7689 ,mem_vec_7690 ,mem_vec_7691 ,mem_vec_7692 ,mem_vec_7693 ,mem_vec_7694 ,mem_vec_7695 ,mem_vec_7696 ,mem_vec_7697 ,mem_vec_7698 ,mem_vec_7699 ,mem_vec_7700 ,mem_vec_7701 ,mem_vec_7702 ,mem_vec_7703 ,mem_vec_7704 ,mem_vec_7705 ,mem_vec_7706 ,mem_vec_7707 ,mem_vec_7708 ,mem_vec_7709 ,mem_vec_7710 ,mem_vec_7711 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c945 = c946, c945_p_0 = 0;
	c945 < c946 + 1024;
	c945 += 128, c945_p_0 += 128){
		for (y = y472, yp_0 = 0;
			y < y472 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x708 = x709, x708_p_0 = 0;
				x708 < x709 + 17;
				x708 += 17, x708_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f472, fp_0 = 0;
					f < f472 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 128) (128 / 1)
					for (c944 = c945, c944_p_1 = c945_p_0, c944_p_0 = 0;
						c944 < c945 + 128;
						c944 += 1, c944_p_1 += 1, c944_p_0 += 1){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 64
						// T (x, 17) (17 / 1)
						for (x = x708, xp_1 = x708_p_0, xp_0 = 0;
							x < x708 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7674 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7675 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c944, cp_2 = c944_p_1, cp_1 = c944_p_0, cp_0 = 0;
										c < c944 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7672);
										mem_vec_7672 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7673);
										mem_vec_7673 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7674);
										mem_vec_7674 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7675);
										mem_vec_7675 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7676);
										mem_vec_7676 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7677);
										mem_vec_7677 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7678);
										mem_vec_7678 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7679);
										mem_vec_7679 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7680);
										mem_vec_7680 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7681);
										mem_vec_7681 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7682);
										mem_vec_7682 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7683);
										mem_vec_7683 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7675);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7677);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7678);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7679);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7680);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7681);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7682);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7683);
						}
					}
				}
			}
		}
		for (y = y472 + 3, yp_0 = 0;
			y < y472 + 3 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x708 = x709, x708_p_0 = 0;
				x708 < x709 + 17;
				x708 += 17, x708_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f472, fp_0 = 0;
					f < f472 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 128) (128 / 1)
					for (c944 = c945, c944_p_1 = c945_p_0, c944_p_0 = 0;
						c944 < c945 + 128;
						c944 += 1, c944_p_1 += 1, c944_p_0 += 1){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 64
						// T (x, 17) (17 / 1)
						for (x = x708, xp_1 = x708_p_0, xp_0 = 0;
							x < x708 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7686 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7687 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_7699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_7700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_7703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_7704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_7707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_7708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_7711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c944, cp_2 = c944_p_1, cp_1 = c944_p_0, cp_0 = 0;
										c < c944 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7684);
										mem_vec_7684 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7685);
										mem_vec_7685 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7686);
										mem_vec_7686 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7687);
										mem_vec_7687 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7688);
										mem_vec_7688 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7689);
										mem_vec_7689 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7690);
										mem_vec_7690 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7691);
										mem_vec_7691 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7692);
										mem_vec_7692 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7693);
										mem_vec_7693 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7694);
										mem_vec_7694 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7695);
										mem_vec_7695 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7696);
										mem_vec_7696 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7697);
										mem_vec_7697 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7698);
										mem_vec_7698 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7699);
										mem_vec_7699 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7700);
										mem_vec_7700 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7701);
										mem_vec_7701 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7702);
										mem_vec_7702 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7703);
										mem_vec_7703 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7704);
										mem_vec_7704 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7705);
										mem_vec_7705 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7706);
										mem_vec_7706 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7707);
										mem_vec_7707 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7708);
										mem_vec_7708 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7709);
										mem_vec_7709 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7710);
										mem_vec_7710 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7711);
										mem_vec_7711 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7684);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7685);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7686);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7687);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7711);
						}
					}
				}
			}
		}
}


}