#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (1, c)]
*/
IND_TYPE c, cp_0, c792_p_0, c793_p_0, cp_1, c792_p_1, cp_2, c792, c793, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y342 = 0;
IND_TYPE x480 = 0;
IND_TYPE h = 0;
IND_TYPE w344 = 0;
IND_TYPE c794 = 0;
IND_TYPE f648 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3752 ,mem_vec_3753 ,mem_vec_3754 ,mem_vec_3755 ,mem_vec_3756 ,mem_vec_3757 ,mem_vec_3758 ,mem_vec_3759 ,mem_vec_3760 ,mem_vec_3761 ,mem_vec_3762 ,mem_vec_3763 ,mem_vec_3764 ,mem_vec_3765 ,mem_vec_3766 ,mem_vec_3767 ,mem_vec_3768 ,mem_vec_3769 ,mem_vec_3770 ,mem_vec_3771 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 1) (512 / 512)
for (c793 = c794, c793_p_0 = 0;
	c793 < c794 + 512;
	c793 += 512, c793_p_0 += 512){
		for (y = y342, yp_0 = 0;
			y < y342 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f = f648, fp_0 = 0;
				f < f648 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 2) (512 / 256)
				for (c792 = c793, c792_p_1 = c793_p_0, c792_p_0 = 0;
					c792 < c793 + 512;
					c792 += 256, c792_p_1 += 256, c792_p_0 += 256){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
					// T (w, 3) (3 / 1)
					for (w = w344, wp_0 = 0;
						w < w344 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 256, f = 64
						// T (x, 7) (7 / 1)
						for (x = x480, xp_0 = 0;
							x < x480 + 7;
							x += 1, xp_0 += 1){
									mem_vec_3752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3754 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3755 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c792, cp_2 = c792_p_1, cp_1 = c792_p_0, cp_0 = 0;
										c < c792 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3752);
										mem_vec_3752 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3753);
										mem_vec_3753 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3754);
										mem_vec_3754 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3755);
										mem_vec_3755 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3756);
										mem_vec_3756 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3757);
										mem_vec_3757 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3758);
										mem_vec_3758 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3759);
										mem_vec_3759 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_3752);
										mem_vec_3752 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_3753);
										mem_vec_3753 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_3754);
										mem_vec_3754 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_3755);
										mem_vec_3755 = vec_21;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_3756);
										mem_vec_3756 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_3757);
										mem_vec_3757 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_3758);
										mem_vec_3758 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_3759);
										mem_vec_3759 = vec_27;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_3752);
										mem_vec_3752 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_3753);
										mem_vec_3753 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_3754);
										mem_vec_3754 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_3755);
										mem_vec_3755 = vec_35;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_3756);
										mem_vec_3756 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_3757);
										mem_vec_3757 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_3758);
										mem_vec_3758 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_3759);
										mem_vec_3759 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3759);
						}
					}
				}
			}
		}
		for (y = y342 + 4, yp_0 = 0;
			y < y342 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f = f648, fp_0 = 0;
				f < f648 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 2) (512 / 256)
				for (c792 = c793, c792_p_1 = c793_p_0, c792_p_0 = 0;
					c792 < c793 + 512;
					c792 += 256, c792_p_1 += 256, c792_p_0 += 256){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
					// T (w, 3) (3 / 1)
					for (w = w344, wp_0 = 0;
						w < w344 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 256, f = 64
						// T (x, 7) (7 / 1)
						for (x = x480, xp_0 = 0;
							x < x480 + 7;
							x += 1, xp_0 += 1){
									mem_vec_3760 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3761 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3762 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3763 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c792, cp_2 = c792_p_1, cp_1 = c792_p_0, cp_0 = 0;
										c < c792 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3760);
										mem_vec_3760 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3761);
										mem_vec_3761 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3762);
										mem_vec_3762 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3763);
										mem_vec_3763 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3764);
										mem_vec_3764 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3765);
										mem_vec_3765 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3766);
										mem_vec_3766 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3767);
										mem_vec_3767 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3768);
										mem_vec_3768 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3769);
										mem_vec_3769 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3770);
										mem_vec_3770 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3771);
										mem_vec_3771 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_3760);
										mem_vec_3760 = vec_19;

										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_3761);
										mem_vec_3761 = vec_22;

										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_3762);
										mem_vec_3762 = vec_24;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_3763);
										mem_vec_3763 = vec_26;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_4);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_3764);
										mem_vec_3764 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_3765);
										mem_vec_3765 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_3766);
										mem_vec_3766 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_3767);
										mem_vec_3767 = vec_32;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_3768);
										mem_vec_3768 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_3769);
										mem_vec_3769 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_3770);
										mem_vec_3770 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_3771);
										mem_vec_3771 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_3760);
										mem_vec_3760 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_3761);
										mem_vec_3761 = vec_41;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_3762);
										mem_vec_3762 = vec_43;

										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_3763);
										mem_vec_3763 = vec_45;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_7);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_3764);
										mem_vec_3764 = vec_47;



										vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_3765);
										mem_vec_3765 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_3766);
										mem_vec_3766 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_3767);
										mem_vec_3767 = vec_51;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_8);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_3768);
										mem_vec_3768 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_3769);
										mem_vec_3769 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_3770);
										mem_vec_3770 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_3771);
										mem_vec_3771 = vec_56;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3765);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3771);
						}
					}
				}
			}
		}
}


}