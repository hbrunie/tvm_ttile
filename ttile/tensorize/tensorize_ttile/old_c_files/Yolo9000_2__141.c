#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (4, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (2, x); T (68, y); T (8, c); T (1, x); T (4, x)]
*/
IND_TYPE c, cp_0, c678_p_0, cp_1, c678, h, hp_0, x, xp_0, x1130_p_0, x1131_p_0, x1132_p_0, xp_1, x1130_p_1, x1131_p_1, xp_2, x1130_p_2, xp_3, x1130, x1131, x1132, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y452 = 0;
IND_TYPE x1133 = 0;
IND_TYPE h452 = 0;
IND_TYPE w = 0;
IND_TYPE c679 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,mem_vec_3624 ,mem_vec_3625 ,mem_vec_3626 ,mem_vec_3627 ,mem_vec_3628 ,mem_vec_3629 ,mem_vec_3630 ,mem_vec_3631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 4) (272 / 68)
for (x1132 = x1133, x1132_p_0 = 0;
	x1132 < x1133 + 272;
	x1132 += 68, x1132_p_0 += 68){
	// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
	// T (x, 1) (68 / 68)
	for (x1131 = x1132, x1131_p_1 = x1132_p_0, x1131_p_0 = 0;
		x1131 < x1132 + 68;
		x1131 += 68, x1131_p_1 += 68, x1131_p_0 += 68){
		// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c678 = c679, c678_p_0 = 0;
			c678 < c679 + 32;
			c678 += 4, c678_p_0 += 4){
			// y = 272, x = 68, h = 3, w = 3, c = 4, f = 64
			// T (y, 68) (272 / 4)
			for (y = y452, yp_0 = 0;
				y < y452 + 272;
				y += 4, yp_0 += 4){
				// y = 4, x = 68, h = 3, w = 3, c = 4, f = 64
				// T (x, 2) (68 / 34)
				for (x1130 = x1131, x1130_p_2 = x1131_p_1, x1130_p_1 = x1131_p_0, x1130_p_0 = 0;
					x1130 < x1131 + 68;
					x1130 += 34, x1130_p_2 += 34, x1130_p_1 += 34, x1130_p_0 += 34){
					// y = 4, x = 34, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h452, hp_0 = 0;
						h < h452 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 34, h = 1, w = 3, c = 4, f = 64
						// T (x, 34) (34 / 1)
						for (x = x1130, xp_3 = x1130_p_2, xp_2 = x1130_p_1, xp_1 = x1130_p_0, xp_0 = 0;
							x < x1130 + 34;
							x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_3616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3617 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3618 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3619 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_3628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_3631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c678, cp_1 = c678_p_0, cp_0 = 0;
										c < c678 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3616);
										mem_vec_3616 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3617);
										mem_vec_3617 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3618);
										mem_vec_3618 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3619);
										mem_vec_3619 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3620);
										mem_vec_3620 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3621);
										mem_vec_3621 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3622);
										mem_vec_3622 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3623);
										mem_vec_3623 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3624);
										mem_vec_3624 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3625);
										mem_vec_3625 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3626);
										mem_vec_3626 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3627);
										mem_vec_3627 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3628);
										mem_vec_3628 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3629);
										mem_vec_3629 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3630);
										mem_vec_3630 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3631);
										mem_vec_3631 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_3616);
										mem_vec_3616 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_3617);
										mem_vec_3617 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_3618);
										mem_vec_3618 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_3619);
										mem_vec_3619 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_3620);
										mem_vec_3620 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_3621);
										mem_vec_3621 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_3622);
										mem_vec_3622 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3623);
										mem_vec_3623 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_3624);
										mem_vec_3624 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_3625);
										mem_vec_3625 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_3626);
										mem_vec_3626 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_3627);
										mem_vec_3627 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_3628);
										mem_vec_3628 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_3629);
										mem_vec_3629 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_3630);
										mem_vec_3630 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_3631);
										mem_vec_3631 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_3616);
										mem_vec_3616 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_3617);
										mem_vec_3617 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_3618);
										mem_vec_3618 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_3619);
										mem_vec_3619 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_3620);
										mem_vec_3620 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_3621);
										mem_vec_3621 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_3622);
										mem_vec_3622 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3623);
										mem_vec_3623 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_3624);
										mem_vec_3624 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_3625);
										mem_vec_3625 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_3626);
										mem_vec_3626 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_3627);
										mem_vec_3627 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_3628);
										mem_vec_3628 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_3629);
										mem_vec_3629 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_3630);
										mem_vec_3630 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_3631);
										mem_vec_3631 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3631);
						}
					}
				}
			}
		}
	}
}


}