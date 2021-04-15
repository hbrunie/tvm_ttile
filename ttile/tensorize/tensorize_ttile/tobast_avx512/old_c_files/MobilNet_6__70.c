#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (16, c); T (2, f); T (7, x); T (7, y); T (2, c)]
*/
IND_TYPE c, cp_0, c378_p_0, c379_p_0, cp_1, c378_p_1, cp_2, c378, c379, f, fp_0, h, hp_0, x, xp_0, x316_p_0, xp_1, x316, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y212 = 0;
IND_TYPE x317 = 0;
IND_TYPE h184 = 0;
IND_TYPE w = 0;
IND_TYPE c380 = 0;
IND_TYPE f362 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1658 ,mem_vec_1659 ,mem_vec_1660 ,mem_vec_1661 ,mem_vec_1662 ,mem_vec_1663 ,mem_vec_1664 ,mem_vec_1665 ,mem_vec_1666 ,mem_vec_1667 ,mem_vec_1668 ,mem_vec_1669 ,mem_vec_1670 ,mem_vec_1671 ,mem_vec_1672 ,mem_vec_1673 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (c, 2) (256 / 128)
for (c379 = c380, c379_p_0 = 0;
	c379 < c380 + 256;
	c379 += 128, c379_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (y, 7) (14 / 2)
	for (y = y212, yp_0 = 0;
		y < y212 + 14;
		y += 2, yp_0 += 2){
		// y = 2, x = 14, h = 3, w = 3, c = 128, f = 256
		// T (x, 7) (14 / 2)
		for (x316 = x317, x316_p_0 = 0;
			x316 < x317 + 14;
			x316 += 2, x316_p_0 += 2){
			// y = 2, x = 2, h = 3, w = 3, c = 128, f = 256
			// T (f, 2) (256 / 128)
			for (f = f362, fp_0 = 0;
				f < f362 + 256;
				f += 128, fp_0 += 128){
				// y = 2, x = 2, h = 3, w = 3, c = 128, f = 128
				// T (c, 16) (128 / 8)
				for (c378 = c379, c378_p_1 = c379_p_0, c378_p_0 = 0;
					c378 < c379 + 128;
					c378 += 8, c378_p_1 += 8, c378_p_0 += 8){
					// y = 2, x = 2, h = 3, w = 3, c = 8, f = 128
					// T (h, 3) (3 / 1)
					for (h = h184, hp_0 = 0;
						h < h184 + 3;
						h += 1, hp_0 += 1){
						// y = 2, x = 2, h = 1, w = 3, c = 8, f = 128
						// T (x, 2) (2 / 1)
						for (x = x316, xp_1 = x316_p_0, xp_0 = 0;
							x < x316 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1662 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_1663 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_1664 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_1665 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_1666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_1671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_1672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_1673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									// y = 2, x = 1, h = 1, w = 3, c = 8, f = 128
									// T (c, 8) (8 / 1)
									for (c = c378, cp_2 = c378_p_1, cp_1 = c378_p_0, cp_0 = 0;
										c < c378 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1658);
										mem_vec_1658 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1659);
										mem_vec_1659 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1660);
										mem_vec_1660 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1661);
										mem_vec_1661 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_1662);
										mem_vec_1662 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_1663);
										mem_vec_1663 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_1664);
										mem_vec_1664 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_1665);
										mem_vec_1665 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1666);
										mem_vec_1666 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1667);
										mem_vec_1667 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_1668);
										mem_vec_1668 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_1669);
										mem_vec_1669 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_1670);
										mem_vec_1670 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_1671);
										mem_vec_1671 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_1672);
										mem_vec_1672 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_1673);
										mem_vec_1673 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1658);
										mem_vec_1658 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_1659);
										mem_vec_1659 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_1660);
										mem_vec_1660 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_1661);
										mem_vec_1661 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_1662);
										mem_vec_1662 = vec_35;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_1663);
										mem_vec_1663 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_1664);
										mem_vec_1664 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_1665);
										mem_vec_1665 = vec_41;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_3);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1666);
										mem_vec_1666 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1667);
										mem_vec_1667 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1668);
										mem_vec_1668 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_1669);
										mem_vec_1669 = vec_47;



										vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1670);
										mem_vec_1670 = vec_48;



										vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1671);
										mem_vec_1671 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1672);
										mem_vec_1672 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1673);
										mem_vec_1673 = vec_51;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_1658);
										mem_vec_1658 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_1659);
										mem_vec_1659 = vec_55;

										vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_1660);
										mem_vec_1660 = vec_57;

										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_1661);
										mem_vec_1661 = vec_59;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_1662);
										mem_vec_1662 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_1663);
										mem_vec_1663 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_1664);
										mem_vec_1664 = vec_65;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_1665);
										mem_vec_1665 = vec_67;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_70 = _mm512_set1_ps(scal_5);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_1666);
										mem_vec_1666 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_1667);
										mem_vec_1667 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_1668);
										mem_vec_1668 = vec_72;



										vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_1669);
										mem_vec_1669 = vec_73;



										vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_1670);
										mem_vec_1670 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_1671);
										mem_vec_1671 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_1672);
										mem_vec_1672 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_1673);
										mem_vec_1673 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1659);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1660);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1661);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_1662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_1663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_1664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_1665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_1670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_1671);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_1672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_1673);
						}
					}
				}
			}
		}
	}
}


}