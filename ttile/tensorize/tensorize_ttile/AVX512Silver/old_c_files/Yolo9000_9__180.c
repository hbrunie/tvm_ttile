#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (4, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, x, xp_0, x76_p_0, x77_p_0, xp_1, x76_p_1, xp_2, x76, x77, y, yp_0, y57_p_0, yp_1, y57;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y58 = 0;
IND_TYPE x78 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y57 = y58, y57_p_0 = 0;
		y57 < y58 + 36;
		y57 += 12, y57_p_0 += 12){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x77 = x78, x77_p_0 = 0;
			x77 < x78 + 68;
			x77 += 68, x77_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
				y < y57 + 12;
				y += 3, yp_1 += 3, yp_0 += 3){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x76 = x77, x76_p_1 = x77_p_0, x76_p_0 = 0;
					x76 < x77 + 68;
					x76 += 68, x76_p_1 += 68, x76_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f38, fp_0 = 0;
						f < f38 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c57 = c58, c57_p_0 = 0;
							c57 < c58 + 256;
							c57 += 256, c57_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;
								x < x76 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
											c < c57 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
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
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_704);
											mem_vec_704 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_705);
											mem_vec_705 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_706);
											mem_vec_706 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_707);
											mem_vec_707 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_708);
											mem_vec_708 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_709);
											mem_vec_709 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_710);
											mem_vec_710 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_711);
											mem_vec_711 = vec_18;
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
							}
						}
					}
				}
			}
		}
	}
	for (y57 = y58 + 36, y57_p_0 = 0;
		y57 < y58 + 36 + 32;
		y57 += 16, y57_p_0 += 16){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x77 = x78, x77_p_0 = 0;
			x77 < x78 + 68;
			x77 += 68, x77_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
				y < y57 + 16;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x76 = x77, x76_p_1 = x77_p_0, x76_p_0 = 0;
					x76 < x77 + 68;
					x76 += 68, x76_p_1 += 68, x76_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f38, fp_0 = 0;
						f < f38 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c57 = c58, c57_p_0 = 0;
							c57 < c58 + 256;
							c57 += 256, c57_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;
								x < x76 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
											c < c57 + 256;
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
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_716);
											mem_vec_716 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_717);
											mem_vec_717 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_718);
											mem_vec_718 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_719);
											mem_vec_719 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_720);
											mem_vec_720 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_721);
											mem_vec_721 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_722);
											mem_vec_722 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_723);
											mem_vec_723 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_724);
											mem_vec_724 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_725);
											mem_vec_725 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_726);
											mem_vec_726 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_727);
											mem_vec_727 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_712);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_713);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_714);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_715);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_716);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_717);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_718);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_719);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_725);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_727);
							}
						}
					}
				}
			}
		}
	}


}