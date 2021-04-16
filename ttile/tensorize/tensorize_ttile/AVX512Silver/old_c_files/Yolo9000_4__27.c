#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); U (3, w); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (4, f); T (1, x); T (17, y); T (4, x)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, f, fp_0, h, hp_0, x, xp_0, x586_p_0, x587_p_0, xp_1, x586_p_1, xp_2, x586, x587, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y326 = 0;
IND_TYPE x588 = 0;
IND_TYPE h212 = 0;
IND_TYPE w = 0;
IND_TYPE c457 = 0;
IND_TYPE f304 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6574 ,mem_vec_6575 ,mem_vec_6576 ,mem_vec_6577 ,mem_vec_6578 ,mem_vec_6579 ,mem_vec_6580 ,mem_vec_6581 ,mem_vec_6582 ,mem_vec_6583 ,mem_vec_6584 ,mem_vec_6585 ,mem_vec_6586 ,mem_vec_6587 ,mem_vec_6588 ,mem_vec_6589 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
for (x587 = x588, x587_p_0 = 0;
	x587 < x588 + 136;
	x587 += 34, x587_p_0 += 34){
	// y = 136, x = 34, h = 3, w = 3, c = 64, f = 128
	// T (y, 17) (136 / 8)
	for (y = y326, yp_0 = 0;
		y < y326 + 136;
		y += 8, yp_0 += 8){
		// y = 8, x = 34, h = 3, w = 3, c = 64, f = 128
		// T (x, 1) (34 / 34)
		for (x586 = x587, x586_p_1 = x587_p_0, x586_p_0 = 0;
			x586 < x587 + 34;
			x586 += 34, x586_p_1 += 34, x586_p_0 += 34){
			// y = 8, x = 34, h = 3, w = 3, c = 64, f = 128
			// T (f, 4) (128 / 32)
			for (f = f304, fp_0 = 0;
				f < f304 + 128;
				f += 32, fp_0 += 32){
				// y = 8, x = 34, h = 3, w = 3, c = 64, f = 32
				// T (c, 4) (64 / 16)
				for (c456 = c457, c456_p_0 = 0;
					c456 < c457 + 64;
					c456 += 16, c456_p_0 += 16){
					// y = 8, x = 34, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h212, hp_0 = 0;
						h < h212 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 34, h = 1, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x586, xp_2 = x586_p_1, xp_1 = x586_p_0, xp_0 = 0;
							x < x586 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6574 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6575 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_6586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_6588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_6589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c456, cp_1 = c456_p_0, cp_0 = 0;
										c < c456 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6574);
										mem_vec_6574 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6575);
										mem_vec_6575 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6576);
										mem_vec_6576 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6577);
										mem_vec_6577 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6578);
										mem_vec_6578 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6579);
										mem_vec_6579 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6580);
										mem_vec_6580 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6581);
										mem_vec_6581 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6582);
										mem_vec_6582 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6583);
										mem_vec_6583 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6584);
										mem_vec_6584 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6585);
										mem_vec_6585 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6586);
										mem_vec_6586 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6587);
										mem_vec_6587 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6588);
										mem_vec_6588 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6589);
										mem_vec_6589 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_6574);
										mem_vec_6574 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_6575);
										mem_vec_6575 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_6576);
										mem_vec_6576 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_6577);
										mem_vec_6577 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_6578);
										mem_vec_6578 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_6579);
										mem_vec_6579 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_6580);
										mem_vec_6580 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6581);
										mem_vec_6581 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_6582);
										mem_vec_6582 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_6583);
										mem_vec_6583 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_6584);
										mem_vec_6584 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_6585);
										mem_vec_6585 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_6586);
										mem_vec_6586 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_6587);
										mem_vec_6587 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_6588);
										mem_vec_6588 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_6589);
										mem_vec_6589 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_6574);
										mem_vec_6574 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_6575);
										mem_vec_6575 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_6576);
										mem_vec_6576 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_6577);
										mem_vec_6577 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_6578);
										mem_vec_6578 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_6579);
										mem_vec_6579 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_6580);
										mem_vec_6580 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_6581);
										mem_vec_6581 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_6582);
										mem_vec_6582 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_6583);
										mem_vec_6583 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_6584);
										mem_vec_6584 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_6585);
										mem_vec_6585 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_6586);
										mem_vec_6586 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_6587);
										mem_vec_6587 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_6588);
										mem_vec_6588 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_6589);
										mem_vec_6589 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6589);
						}
					}
				}
			}
		}
	}
}


}