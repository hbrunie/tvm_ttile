#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (128, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (1, c); T (1, x); T (28, y); T (1, y)]
*/
IND_TYPE c, cp_0, c99_p_0, cp_1, c99, h, hp_0, x, xp_0, x114_p_0, xp_1, x114, y, yp_0, y82_p_0, yp_1, y82;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y83 = 0;
IND_TYPE x115 = 0;
IND_TYPE h49 = 0;
IND_TYPE w = 0;
IND_TYPE c100 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 1) (56 / 56)
for (y82 = y83, y82_p_0 = 0;
	y82 < y83 + 56;
	y82 += 56, y82_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (y, 28) (56 / 2)
	for (y = y82, yp_1 = y82_p_0, yp_0 = 0;
		y < y82 + 56;
		y += 2, yp_1 += 2, yp_0 += 2){
		// y = 2, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (56 / 56)
		for (x114 = x115, x114_p_0 = 0;
			x114 < x115 + 56;
			x114 += 56, x114_p_0 += 56){
			// y = 2, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (c, 1) (128 / 128)
			for (c99 = c100, c99_p_0 = 0;
				c99 < c100 + 128;
				c99 += 128, c99_p_0 += 128){
				// y = 2, x = 56, h = 3, w = 3, c = 128, f = 128
				// T (h, 3) (3 / 1)
				for (h = h49, hp_0 = 0;
					h < h49 + 3;
					h += 1, hp_0 += 1){
					// y = 2, x = 56, h = 1, w = 3, c = 128, f = 128
					// T (x, 56) (56 / 1)
					for (x = x114, xp_1 = x114_p_0, xp_0 = 0;
						x < x114 + 56;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
								mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
								mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
								mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
								// y = 2, x = 1, h = 1, w = 3, c = 128, f = 128
								// T (c, 128) (128 / 1)
								for (c = c99, cp_1 = c99_p_0, cp_0 = 0;
									c < c99 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_712);
									mem_vec_712 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_713);
									mem_vec_713 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_714);
									mem_vec_714 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_715);
									mem_vec_715 = vec_7;

									vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

									vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_716);
									mem_vec_716 = vec_9;

									vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

									vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_717);
									mem_vec_717 = vec_11;

									vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

									vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_718);
									mem_vec_718 = vec_13;

									vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

									vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_719);
									mem_vec_719 = vec_15;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_18 = _mm512_set1_ps(scal_1);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_720);
									mem_vec_720 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_721);
									mem_vec_721 = vec_19;



									vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_722);
									mem_vec_722 = vec_20;



									vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_723);
									mem_vec_723 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_724);
									mem_vec_724 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_725);
									mem_vec_725 = vec_23;



									vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_726);
									mem_vec_726 = vec_24;



									vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_727);
									mem_vec_727 = vec_25;
									scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_27 = _mm512_set1_ps(scal_2);
									vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_712);
									mem_vec_712 = vec_26;

									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_713);
									mem_vec_713 = vec_29;

									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

									vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_714);
									mem_vec_714 = vec_31;

									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

									vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_715);
									mem_vec_715 = vec_33;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

									vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_716);
									mem_vec_716 = vec_35;

									vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

									vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_717);
									mem_vec_717 = vec_37;

									vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

									vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_718);
									mem_vec_718 = vec_39;

									vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

									vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_719);
									mem_vec_719 = vec_41;
									scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_44 = _mm512_set1_ps(scal_3);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_720);
									mem_vec_720 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_721);
									mem_vec_721 = vec_45;



									vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_722);
									mem_vec_722 = vec_46;



									vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_723);
									mem_vec_723 = vec_47;



									vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_724);
									mem_vec_724 = vec_48;



									vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_725);
									mem_vec_725 = vec_49;



									vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_726);
									mem_vec_726 = vec_50;



									vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_727);
									mem_vec_727 = vec_51;
									scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_53 = _mm512_set1_ps(scal_4);
									vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_712);
									mem_vec_712 = vec_52;

									vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_713);
									mem_vec_713 = vec_55;

									vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

									vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_714);
									mem_vec_714 = vec_57;

									vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

									vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_715);
									mem_vec_715 = vec_59;

									vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

									vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_716);
									mem_vec_716 = vec_61;

									vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

									vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_717);
									mem_vec_717 = vec_63;

									vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

									vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_718);
									mem_vec_718 = vec_65;

									vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

									vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_719);
									mem_vec_719 = vec_67;
									scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_70 = _mm512_set1_ps(scal_5);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_720);
									mem_vec_720 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_721);
									mem_vec_721 = vec_71;



									vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_722);
									mem_vec_722 = vec_72;



									vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_723);
									mem_vec_723 = vec_73;



									vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_724);
									mem_vec_724 = vec_74;



									vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_725);
									mem_vec_725 = vec_75;



									vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_726);
									mem_vec_726 = vec_76;



									vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_727);
									mem_vec_727 = vec_77;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_727);
					}
				}
			}
		}
	}
}


}