#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); U (3, w); T (32, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (2, c); T (2, f); T (2, x); T (7, y); T (1, y)]
*/
IND_TYPE c, cp_0, c204_p_0, cp_1, c204, f, fp_0, h, hp_0, x, xp_0, x245_p_0, xp_1, x245, y, yp_0, y163_p_0, yp_1, y163;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y164 = 0;
IND_TYPE x246 = 0;
IND_TYPE h100 = 0;
IND_TYPE w = 0;
IND_TYPE c205 = 0;
IND_TYPE f113 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1746 ,mem_vec_1747 ,mem_vec_1748 ,mem_vec_1749 ,mem_vec_1750 ,mem_vec_1751 ,mem_vec_1752 ,mem_vec_1753 ,mem_vec_1754 ,mem_vec_1755 ,mem_vec_1756 ,mem_vec_1757 ,mem_vec_1758 ,mem_vec_1759 ,mem_vec_1760 ,mem_vec_1761 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y163 = y164, y163_p_0 = 0;
	y163 < y164 + 56;
	y163 += 56, y163_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 7) (56 / 8)
	for (y = y163, yp_1 = y163_p_0, yp_0 = 0;
		y < y163 + 56;
		y += 8, yp_1 += 8, yp_0 += 8){
		// y = 8, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 2) (56 / 28)
		for (x245 = x246, x245_p_0 = 0;
			x245 < x246 + 56;
			x245 += 28, x245_p_0 += 28){
			// y = 8, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f113, fp_0 = 0;
				f < f113 + 64;
				f += 32, fp_0 += 32){
				// y = 8, x = 28, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c204 = c205, c204_p_0 = 0;
					c204 < c205 + 64;
					c204 += 32, c204_p_0 += 32){
					// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h100, hp_0 = 0;
						h < h100 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 28, h = 1, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x245, xp_1 = x245_p_0, xp_0 = 0;
							x < x245 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1746 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1747 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c204, cp_1 = c204_p_0, cp_0 = 0;
										c < c204 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1746);
										mem_vec_1746 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1747);
										mem_vec_1747 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1748);
										mem_vec_1748 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1749);
										mem_vec_1749 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1750);
										mem_vec_1750 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1751);
										mem_vec_1751 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1752);
										mem_vec_1752 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1753);
										mem_vec_1753 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1754);
										mem_vec_1754 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1755);
										mem_vec_1755 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1756);
										mem_vec_1756 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1757);
										mem_vec_1757 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1758);
										mem_vec_1758 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1759);
										mem_vec_1759 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1760);
										mem_vec_1760 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1761);
										mem_vec_1761 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1746);
										mem_vec_1746 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_1747);
										mem_vec_1747 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_1748);
										mem_vec_1748 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_1749);
										mem_vec_1749 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_1750);
										mem_vec_1750 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_1751);
										mem_vec_1751 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_1752);
										mem_vec_1752 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1753);
										mem_vec_1753 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_1754);
										mem_vec_1754 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_1755);
										mem_vec_1755 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1756);
										mem_vec_1756 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1757);
										mem_vec_1757 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_1758);
										mem_vec_1758 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_1759);
										mem_vec_1759 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_1760);
										mem_vec_1760 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_1761);
										mem_vec_1761 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_1746);
										mem_vec_1746 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_1747);
										mem_vec_1747 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_1748);
										mem_vec_1748 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_1749);
										mem_vec_1749 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_1750);
										mem_vec_1750 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_1751);
										mem_vec_1751 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_1752);
										mem_vec_1752 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_1753);
										mem_vec_1753 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_1754);
										mem_vec_1754 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_1755);
										mem_vec_1755 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_1756);
										mem_vec_1756 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_1757);
										mem_vec_1757 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_1758);
										mem_vec_1758 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_1759);
										mem_vec_1759 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_1760);
										mem_vec_1760 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_1761);
										mem_vec_1761 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1747);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1751);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1761);
						}
					}
				}
			}
		}
	}
}


}