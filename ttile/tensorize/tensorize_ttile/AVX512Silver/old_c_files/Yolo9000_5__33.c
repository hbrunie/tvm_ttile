#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 5), (Arg 7)); ((Iter 3), (Arg 11))]; T (2, f);
  T (136, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0, y57_p_0, yp_1, y57;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y58 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c43 = 0;
IND_TYPE f33 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y57 = y58, y57_p_0 = 0;
	y57 < y58 + 136;
	y57 += 68, y57_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x57 = x58, x57_p_0 = 0;
		x57 < x58 + 136;
		x57 += 1, x57_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f33, fp_0 = 0;
			f < f33 + 64;
			f += 32, fp_0 += 32){
				for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
					y < y57 + 35;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
						x < x57 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c43, cp_0 = 0;
									c < c43 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_704);
									mem_vec_704 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_705);
									mem_vec_705 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_706);
									mem_vec_706 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_707);
									mem_vec_707 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_708);
									mem_vec_708 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_709);
									mem_vec_709 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_710);
									mem_vec_710 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_711);
									mem_vec_711 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_712);
									mem_vec_712 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_713);
									mem_vec_713 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_714);
									mem_vec_714 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_715);
									mem_vec_715 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_716);
									mem_vec_716 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_717);
									mem_vec_717 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_704);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_705);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_706);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_707);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_708);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_709);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_710);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_711);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_717);
					}
				}
				for (y = y57 + 35, yp_1 = y57_p_0, yp_0 = 0;
					y < y57 + 35 + 33;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
						x < x57 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c43, cp_0 = 0;
									c < c43 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_718);
									mem_vec_718 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_719);
									mem_vec_719 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_720);
									mem_vec_720 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_721);
									mem_vec_721 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_722);
									mem_vec_722 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_723);
									mem_vec_723 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_724);
									mem_vec_724 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_725);
									mem_vec_725 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_726);
									mem_vec_726 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_727);
									mem_vec_727 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_728);
									mem_vec_728 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_729);
									mem_vec_729 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_730);
									mem_vec_730 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_731);
									mem_vec_731 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_732);
									mem_vec_732 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_733);
									mem_vec_733 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_734);
									mem_vec_734 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_735);
									mem_vec_735 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_736);
									mem_vec_736 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_737);
									mem_vec_737 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_738);
									mem_vec_738 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_739);
									mem_vec_739 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_729);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_734);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_735);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_736);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_737);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_738);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_739);
					}
				}
		}
	}
}


}