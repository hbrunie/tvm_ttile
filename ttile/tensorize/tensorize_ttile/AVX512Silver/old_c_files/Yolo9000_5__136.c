#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (2, f);
  T (34, x); T (8, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x570_p_0, xp_1, x570, y, yp_0, y570_p_0, yp_1, y570;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y571 = 0;
IND_TYPE x571 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c427 = 0;
IND_TYPE f333 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7716 ,mem_vec_7717 ,mem_vec_7718 ,mem_vec_7719 ,mem_vec_7720 ,mem_vec_7721 ,mem_vec_7722 ,mem_vec_7723 ,mem_vec_7724 ,mem_vec_7725 ,mem_vec_7726 ,mem_vec_7727 ,mem_vec_7728 ,mem_vec_7729 ,mem_vec_7730 ,mem_vec_7731 ,mem_vec_7732 ,mem_vec_7733 ,mem_vec_7734 ,mem_vec_7735 ,mem_vec_7736 ,mem_vec_7737 ,mem_vec_7738 ,mem_vec_7739 ,mem_vec_7740 ,mem_vec_7741 ,mem_vec_7742 ,mem_vec_7743 ,mem_vec_7744 ,mem_vec_7745 ,mem_vec_7746 ,mem_vec_7747 ,mem_vec_7748 ,mem_vec_7749 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 8) (136 / 17)
for (y570 = y571, y570_p_0 = 0;
	y570 < y571 + 136;
	y570 += 17, y570_p_0 += 17){
	// y = 17, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 34) (136 / 4)
	for (x570 = x571, x570_p_0 = 0;
		x570 < x571 + 136;
		x570 += 4, x570_p_0 += 4){
		// y = 17, x = 4, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f333, fp_0 = 0;
			f < f333 + 64;
			f += 32, fp_0 += 32){
				for (y = y570, yp_1 = y570_p_0, yp_0 = 0;
					y < y570 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x570, xp_1 = x570_p_0, xp_0 = 0;
						x < x570 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_7716 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_7717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_7718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_7719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_7720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_7721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_7722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_7723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_7724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_7725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_7726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_7727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_7728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_7729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c427, cp_0 = 0;
									c < c427 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7716);
									mem_vec_7716 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7717);
									mem_vec_7717 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7718);
									mem_vec_7718 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7719);
									mem_vec_7719 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7720);
									mem_vec_7720 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7721);
									mem_vec_7721 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7722);
									mem_vec_7722 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7723);
									mem_vec_7723 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7724);
									mem_vec_7724 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7725);
									mem_vec_7725 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7726);
									mem_vec_7726 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7727);
									mem_vec_7727 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7728);
									mem_vec_7728 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7729);
									mem_vec_7729 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7729);
					}
				}
				for (y = y570 + 7, yp_1 = y570_p_0, yp_0 = 0;
					y < y570 + 7 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x570, xp_1 = x570_p_0, xp_0 = 0;
						x < x570 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_7730 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_7731 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_7732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_7733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_7734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_7735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_7736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_7737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_7738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_7739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_7740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_7741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_7742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_7743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_7744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_7745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_7746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_7747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_7748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_7749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c427, cp_0 = 0;
									c < c427 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7730);
									mem_vec_7730 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7731);
									mem_vec_7731 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7732);
									mem_vec_7732 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7733);
									mem_vec_7733 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7734);
									mem_vec_7734 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7735);
									mem_vec_7735 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7736);
									mem_vec_7736 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7737);
									mem_vec_7737 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7738);
									mem_vec_7738 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7739);
									mem_vec_7739 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7740);
									mem_vec_7740 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7741);
									mem_vec_7741 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7742);
									mem_vec_7742 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7743);
									mem_vec_7743 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7744);
									mem_vec_7744 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7745);
									mem_vec_7745 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7746);
									mem_vec_7746 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7747);
									mem_vec_7747 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7748);
									mem_vec_7748 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7749);
									mem_vec_7749 = vec_31;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7734);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7735);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7736);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7737);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7738);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7739);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7740);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7741);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7742);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7743);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7744);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7745);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7746);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7747);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7748);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7749);
					}
				}
		}
	}
}


}