#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (64, c)]
*/
IND_TYPE c, cp_0, c864_p_0, c865_p_0, cp_1, c864_p_1, cp_2, c864, c865, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y378 = 0;
IND_TYPE x516 = 0;
IND_TYPE h = 0;
IND_TYPE w380 = 0;
IND_TYPE c866 = 0;
IND_TYPE f684 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4112 ,mem_vec_4113 ,mem_vec_4114 ,mem_vec_4115 ,mem_vec_4116 ,mem_vec_4117 ,mem_vec_4118 ,mem_vec_4119 ,mem_vec_4120 ,mem_vec_4121 ,mem_vec_4122 ,mem_vec_4123 ,mem_vec_4124 ,mem_vec_4125 ,mem_vec_4126 ,mem_vec_4127 ,mem_vec_4128 ,mem_vec_4129 ,mem_vec_4130 ,mem_vec_4131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 64) (512 / 8)
for (c865 = c866, c865_p_0 = 0;
	c865 < c866 + 512;
	c865 += 8, c865_p_0 += 8){
		for (y = y378, yp_0 = 0;
			y < y378 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 8) (512 / 64)
			for (f = f684, fp_0 = 0;
				f < f684 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (c, 1) (8 / 8)
				for (c864 = c865, c864_p_1 = c865_p_0, c864_p_0 = 0;
					c864 < c865 + 8;
					c864 += 8, c864_p_1 += 8, c864_p_0 += 8){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w380, wp_0 = 0;
						w < w380 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 8, f = 64
						// T (x, 7) (7 / 1)
						for (x = x516, xp_0 = 0;
							x < x516 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4114 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4115 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c864, cp_2 = c864_p_1, cp_1 = c864_p_0, cp_0 = 0;
										c < c864 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4112);
										mem_vec_4112 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4113);
										mem_vec_4113 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4114);
										mem_vec_4114 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4115);
										mem_vec_4115 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4116);
										mem_vec_4116 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4117);
										mem_vec_4117 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4118);
										mem_vec_4118 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4119);
										mem_vec_4119 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4112);
										mem_vec_4112 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4113);
										mem_vec_4113 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_4114);
										mem_vec_4114 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_4115);
										mem_vec_4115 = vec_21;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4116);
										mem_vec_4116 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_4117);
										mem_vec_4117 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4118);
										mem_vec_4118 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_4119);
										mem_vec_4119 = vec_27;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4112);
										mem_vec_4112 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4113);
										mem_vec_4113 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_4114);
										mem_vec_4114 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_4115);
										mem_vec_4115 = vec_35;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4116);
										mem_vec_4116 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_4117);
										mem_vec_4117 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4118);
										mem_vec_4118 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4119);
										mem_vec_4119 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4119);
						}
					}
				}
			}
		}
		for (y = y378 + 4, yp_0 = 0;
			y < y378 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 8) (512 / 64)
			for (f = f684, fp_0 = 0;
				f < f684 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (c, 1) (8 / 8)
				for (c864 = c865, c864_p_1 = c865_p_0, c864_p_0 = 0;
					c864 < c865 + 8;
					c864 += 8, c864_p_1 += 8, c864_p_0 += 8){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w380, wp_0 = 0;
						w < w380 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 8, f = 64
						// T (x, 7) (7 / 1)
						for (x = x516, xp_0 = 0;
							x < x516 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c864, cp_2 = c864_p_1, cp_1 = c864_p_0, cp_0 = 0;
										c < c864 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4120);
										mem_vec_4120 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4121);
										mem_vec_4121 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4122);
										mem_vec_4122 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4123);
										mem_vec_4123 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4124);
										mem_vec_4124 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4125);
										mem_vec_4125 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4126);
										mem_vec_4126 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4127);
										mem_vec_4127 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4128);
										mem_vec_4128 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4129);
										mem_vec_4129 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4130);
										mem_vec_4130 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4131);
										mem_vec_4131 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_4120);
										mem_vec_4120 = vec_19;

										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_4121);
										mem_vec_4121 = vec_22;

										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_4122);
										mem_vec_4122 = vec_24;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_4123);
										mem_vec_4123 = vec_26;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_4);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_4124);
										mem_vec_4124 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_4125);
										mem_vec_4125 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4126);
										mem_vec_4126 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4127);
										mem_vec_4127 = vec_32;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_4128);
										mem_vec_4128 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_4129);
										mem_vec_4129 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_4130);
										mem_vec_4130 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_4131);
										mem_vec_4131 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4120);
										mem_vec_4120 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4121);
										mem_vec_4121 = vec_41;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_4122);
										mem_vec_4122 = vec_43;

										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_4123);
										mem_vec_4123 = vec_45;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_7);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_4124);
										mem_vec_4124 = vec_47;



										vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_4125);
										mem_vec_4125 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_4126);
										mem_vec_4126 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_4127);
										mem_vec_4127 = vec_51;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_8);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4128);
										mem_vec_4128 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4129);
										mem_vec_4129 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_4130);
										mem_vec_4130 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_4131);
										mem_vec_4131 = vec_56;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4131);
						}
					}
				}
			}
		}
}


}