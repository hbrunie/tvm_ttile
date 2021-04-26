#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (7, x); T (128, c);
  T (4, f); T (1, y); T (2, f)]
*/
IND_TYPE c, cp_0, c75_p_0, cp_1, c75, f, fp_0, f75_p_0, fp_1, f75, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y50 = 0;
IND_TYPE x50 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c76 = 0;
IND_TYPE f76 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f75 = f76, f75_p_0 = 0;
	f75 < f76 + 512;
	f75 += 256, f75_p_0 += 256){
	// y = 7, x = 7, h = 1, w = 1, c = 256, f = 256
	// T (y, 1) (7 / 7)
	for (y = y50, yp_0 = 0;
		y < y50 + 7;
		y += 7, yp_0 += 7){
		// y = 7, x = 7, h = 1, w = 1, c = 256, f = 256
		// T (f, 4) (256 / 64)
		for (f = f75, fp_1 = f75_p_0, fp_0 = 0;
			f < f75 + 256;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
			// T (c, 128) (256 / 2)
			for (c75 = c76, c75_p_0 = 0;
				c75 < c76 + 256;
				c75 += 2, c75_p_0 += 2){
				// y = 7, x = 7, h = 1, w = 1, c = 2, f = 64
				// T (x, 7) (7 / 1)
				for (x = x50, xp_0 = 0;
					x < x50 + 7;
					x += 1, xp_0 += 1){
							mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
							mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
							// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
							// T (c, 2) (2 / 1)
							for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
								c < c75 + 2;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_700);
								mem_vec_700 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_701);
								mem_vec_701 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_702);
								mem_vec_702 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_703);
								mem_vec_703 = vec_7;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_704);
								mem_vec_704 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_705);
								mem_vec_705 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_706);
								mem_vec_706 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_707);
								mem_vec_707 = vec_13;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_708);
								mem_vec_708 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_709);
								mem_vec_709 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_710);
								mem_vec_710 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_711);
								mem_vec_711 = vec_18;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_712);
								mem_vec_712 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_713);
								mem_vec_713 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_714);
								mem_vec_714 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_715);
								mem_vec_715 = vec_23;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_716);
								mem_vec_716 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_717);
								mem_vec_717 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_718);
								mem_vec_718 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_719);
								mem_vec_719 = vec_28;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_720);
								mem_vec_720 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_721);
								mem_vec_721 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_722);
								mem_vec_722 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_723);
								mem_vec_723 = vec_33;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_724);
								mem_vec_724 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_725);
								mem_vec_725 = vec_36;



								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_726);
								mem_vec_726 = vec_37;



								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_727);
								mem_vec_727 = vec_38;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_700);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_701);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_702);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_703);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_704);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_705);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_706);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_707);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_708);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_709);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_710);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_711);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_712);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_713);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_714);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_715);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_716);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_717);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_718);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_719);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_720);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_721);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_722);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_723);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_724);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_725);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_726);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_727);
				}
			}
		}
	}
}


}