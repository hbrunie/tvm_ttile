#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (1, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, f, fp_0, x, xp_0, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y64 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c64 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y63 = y64, y63_p_0 = 0;
		y63 < y64 + 8;
		y63 += 8, y63_p_0 += 8){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f42, fp_0 = 0;
			f < f42 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1) (1024 / 1024)
				for (c63 = c64, c63_p_0 = 0;
					c63 < c64 + 1024;
					c63 += 1024, c63_p_0 += 1024){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
					// T (x, 17) (17 / 1)
					for (x = x42, xp_0 = 0;
						x < x42 + 17;
						x += 1, xp_0 += 1){
								mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
								// T (c, 1024) (1024 / 1)
								for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
									c < c63 + 1024;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_714);
									mem_vec_714 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_715);
									mem_vec_715 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_716);
									mem_vec_716 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_717);
									mem_vec_717 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_718);
									mem_vec_718 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_719);
									mem_vec_719 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_720);
									mem_vec_720 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_721);
									mem_vec_721 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_722);
									mem_vec_722 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_723);
									mem_vec_723 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_724);
									mem_vec_724 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_725);
									mem_vec_725 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_726);
									mem_vec_726 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_727);
									mem_vec_727 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_728);
									mem_vec_728 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_729);
									mem_vec_729 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_729);
					}
				}
			}
		}
	}
	for (y63 = y64 + 8, y63_p_0 = 0;
		y63 < y64 + 8 + 9;
		y63 += 9, y63_p_0 += 9){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f42, fp_0 = 0;
			f < f42 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1) (1024 / 1024)
				for (c63 = c64, c63_p_0 = 0;
					c63 < c64 + 1024;
					c63 += 1024, c63_p_0 += 1024){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
					// T (x, 17) (17 / 1)
					for (x = x42, xp_0 = 0;
						x < x42 + 17;
						x += 1, xp_0 += 1){
								mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
								// T (c, 1024) (1024 / 1)
								for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
									c < c63 + 1024;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_730);
									mem_vec_730 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_731);
									mem_vec_731 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_732);
									mem_vec_732 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_733);
									mem_vec_733 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_734);
									mem_vec_734 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_735);
									mem_vec_735 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_736);
									mem_vec_736 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_737);
									mem_vec_737 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_738);
									mem_vec_738 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_739);
									mem_vec_739 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_740);
									mem_vec_740 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_741);
									mem_vec_741 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_742);
									mem_vec_742 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_743);
									mem_vec_743 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_744);
									mem_vec_744 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_745);
									mem_vec_745 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_746);
									mem_vec_746 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_747);
									mem_vec_747 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_734);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_735);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_736);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_737);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_738);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_739);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_740);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_741);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_742);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_743);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_744);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_745);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_746);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_747);
					}
				}
			}
		}
	}


}