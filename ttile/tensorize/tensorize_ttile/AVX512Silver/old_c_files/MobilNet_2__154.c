#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); U (3, w); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (4, c); T (2, f); T (1, x); T (7, y); T (1, y)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, h, hp_0, x, xp_0, x12_p_0, xp_1, x12, y, yp_0, y6_p_0, yp_1, y6;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y7 = 0;
IND_TYPE x13 = 0;
IND_TYPE h4 = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f6 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,mem_vec_70 ,mem_vec_71 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y6 = y7, y6_p_0 = 0;
	y6 < y7 + 56;
	y6 += 56, y6_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 7) (56 / 8)
	for (y = y6, yp_1 = y6_p_0, yp_0 = 0;
		y < y6 + 56;
		y += 8, yp_1 += 8, yp_0 += 8){
		// y = 8, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (56 / 56)
		for (x12 = x13, x12_p_0 = 0;
			x12 < x13 + 56;
			x12 += 56, x12_p_0 += 56){
			// y = 8, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f6, fp_0 = 0;
				f < f6 + 64;
				f += 32, fp_0 += 32){
				// y = 8, x = 56, h = 3, w = 3, c = 64, f = 32
				// T (c, 4) (64 / 16)
				for (c9 = c10, c9_p_0 = 0;
					c9 < c10 + 64;
					c9 += 16, c9_p_0 += 16){
					// y = 8, x = 56, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h4, hp_0 = 0;
						h < h4 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 56, h = 1, w = 3, c = 16, f = 32
						// T (x, 56) (56 / 1)
						for (x = x12, xp_1 = x12_p_0, xp_0 = 0;
							x < x12 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_60 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_61 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_62 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_63 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_64 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_65 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_66 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_67 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_68 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_69 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_70 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_71 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_72 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_73 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_74 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_75 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
										c < c9 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_60);
										mem_vec_60 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_61);
										mem_vec_61 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_62);
										mem_vec_62 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_63);
										mem_vec_63 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_64);
										mem_vec_64 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_65);
										mem_vec_65 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_66);
										mem_vec_66 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_67);
										mem_vec_67 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_68);
										mem_vec_68 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_69);
										mem_vec_69 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_70);
										mem_vec_70 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_71);
										mem_vec_71 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_72);
										mem_vec_72 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_73);
										mem_vec_73 = vec_22;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_74);
										mem_vec_74 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_75);
										mem_vec_75 = vec_25;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_60);
										mem_vec_60 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_61);
										mem_vec_61 = vec_29;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_62);
										mem_vec_62 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_63);
										mem_vec_63 = vec_33;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_64);
										mem_vec_64 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_65);
										mem_vec_65 = vec_36;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_66);
										mem_vec_66 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_67);
										mem_vec_67 = vec_39;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_68);
										mem_vec_68 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_69);
										mem_vec_69 = vec_42;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_70);
										mem_vec_70 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_71);
										mem_vec_71 = vec_45;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_72);
										mem_vec_72 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_73);
										mem_vec_73 = vec_48;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_74);
										mem_vec_74 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_75);
										mem_vec_75 = vec_51;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_60);
										mem_vec_60 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_61);
										mem_vec_61 = vec_55;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_62);
										mem_vec_62 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_63);
										mem_vec_63 = vec_59;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_64);
										mem_vec_64 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_65);
										mem_vec_65 = vec_62;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_66);
										mem_vec_66 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_67);
										mem_vec_67 = vec_65;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_68);
										mem_vec_68 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_69);
										mem_vec_69 = vec_68;
										scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_70);
										mem_vec_70 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_71);
										mem_vec_71 = vec_71;
										scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_72);
										mem_vec_72 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_73);
										mem_vec_73 = vec_74;
										scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_74);
										mem_vec_74 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_75);
										mem_vec_75 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_60);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_61);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_62);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_63);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_64);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_65);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_66);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_67);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_68);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_69);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_70);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_71);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_72);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_73);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_74);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_75);
						}
					}
				}
			}
		}
	}
}


}