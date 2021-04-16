#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (8, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (2, f);
  T (17, x); T (8, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x567_p_0, xp_1, x567, y, yp_0, y567_p_0, yp_1, y567;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y568 = 0;
IND_TYPE x568 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c425 = 0;
IND_TYPE f331 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7682 ,mem_vec_7683 ,mem_vec_7684 ,mem_vec_7685 ,mem_vec_7686 ,mem_vec_7687 ,mem_vec_7688 ,mem_vec_7689 ,mem_vec_7690 ,mem_vec_7691 ,mem_vec_7692 ,mem_vec_7693 ,mem_vec_7694 ,mem_vec_7695 ,mem_vec_7696 ,mem_vec_7697 ,mem_vec_7698 ,mem_vec_7699 ,mem_vec_7700 ,mem_vec_7701 ,mem_vec_7702 ,mem_vec_7703 ,mem_vec_7704 ,mem_vec_7705 ,mem_vec_7706 ,mem_vec_7707 ,mem_vec_7708 ,mem_vec_7709 ,mem_vec_7710 ,mem_vec_7711 ,mem_vec_7712 ,mem_vec_7713 ,mem_vec_7714 ,mem_vec_7715 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 8) (136 / 17)
for (y567 = y568, y567_p_0 = 0;
	y567 < y568 + 136;
	y567 += 17, y567_p_0 += 17){
	// y = 17, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 17) (136 / 8)
	for (x567 = x568, x567_p_0 = 0;
		x567 < x568 + 136;
		x567 += 8, x567_p_0 += 8){
		// y = 17, x = 8, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f331, fp_0 = 0;
			f < f331 + 64;
			f += 32, fp_0 += 32){
				for (y = y567, yp_1 = y567_p_0, yp_0 = 0;
					y < y567 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (x, 8) (8 / 1)
					for (x = x567, xp_1 = x567_p_0, xp_0 = 0;
						x < x567 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_7682 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_7683 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_7684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_7685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_7686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_7687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_7688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_7689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_7690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_7691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_7692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_7693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_7694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_7695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c425, cp_0 = 0;
									c < c425 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7682);
									mem_vec_7682 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7683);
									mem_vec_7683 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7684);
									mem_vec_7684 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7685);
									mem_vec_7685 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7686);
									mem_vec_7686 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7687);
									mem_vec_7687 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7688);
									mem_vec_7688 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7689);
									mem_vec_7689 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7690);
									mem_vec_7690 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7691);
									mem_vec_7691 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7692);
									mem_vec_7692 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7693);
									mem_vec_7693 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7694);
									mem_vec_7694 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7695);
									mem_vec_7695 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7682);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7683);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7684);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7685);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7686);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7687);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7688);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7689);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7690);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7691);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7692);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7693);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7694);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7695);
					}
				}
				for (y = y567 + 7, yp_1 = y567_p_0, yp_0 = 0;
					y < y567 + 7 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (x, 8) (8 / 1)
					for (x = x567, xp_1 = x567_p_0, xp_0 = 0;
						x < x567 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_7696 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_7697 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_7698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_7699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_7700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_7701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_7702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_7703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_7704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_7705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_7706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_7707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_7708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_7709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_7710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_7711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_7712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_7713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_7714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_7715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c425, cp_0 = 0;
									c < c425 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7696);
									mem_vec_7696 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7697);
									mem_vec_7697 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7698);
									mem_vec_7698 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7699);
									mem_vec_7699 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7700);
									mem_vec_7700 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7701);
									mem_vec_7701 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7702);
									mem_vec_7702 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7703);
									mem_vec_7703 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7704);
									mem_vec_7704 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7705);
									mem_vec_7705 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7706);
									mem_vec_7706 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7707);
									mem_vec_7707 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7708);
									mem_vec_7708 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7709);
									mem_vec_7709 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7710);
									mem_vec_7710 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7711);
									mem_vec_7711 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7712);
									mem_vec_7712 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7713);
									mem_vec_7713 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7714);
									mem_vec_7714 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7715);
									mem_vec_7715 = vec_31;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7696);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7697);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7698);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7699);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7700);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7701);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7702);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7703);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7704);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7705);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7706);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7707);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7708);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7709);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7710);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7711);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7715);
					}
				}
		}
	}
}


}