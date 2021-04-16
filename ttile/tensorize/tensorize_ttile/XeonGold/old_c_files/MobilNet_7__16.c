#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (8, c); T (2, y); T (8, f); T (2, c)]
*/
IND_TYPE c, cp_0, c104_p_0, c105_p_0, cp_1, c104_p_1, cp_2, c104, c105, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y52 = 0;
IND_TYPE x52 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c106 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 2) (512 / 256)
for (c105 = c106, c105_p_0 = 0;
	c105 < c106 + 512;
	c105 += 256, c105_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 512
	// T (f, 8) (512 / 64)
	for (f = f52, fp_0 = 0;
		f < f52 + 512;
		f += 64, fp_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
		// T (y, 2) (14 / 7)
		for (y = y52, yp_0 = 0;
			y < y52 + 14;
			y += 7, yp_0 += 7){
			// y = 7, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (c, 8) (256 / 32)
			for (c104 = c105, c104_p_1 = c105_p_0, c104_p_0 = 0;
				c104 < c105 + 256;
				c104 += 32, c104_p_1 += 32, c104_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
				// T (x, 14) (14 / 1)
				for (x = x52, xp_0 = 0;
					x < x52 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (h, 3) (3 / 1)
					for (h = h48, hp_0 = 0;
						h < h48 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w48, wp_0 = 0;
							w < w48 + 3;
							w += 1, wp_0 += 1){
									mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c104, cp_2 = c104_p_1, cp_1 = c104_p_0, cp_0 = 0;
										c < c104 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_728);
										mem_vec_728 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_729);
										mem_vec_729 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_730);
										mem_vec_730 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_731);
										mem_vec_731 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_732);
										mem_vec_732 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_733);
										mem_vec_733 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_734);
										mem_vec_734 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_735);
										mem_vec_735 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_736);
										mem_vec_736 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_737);
										mem_vec_737 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_738);
										mem_vec_738 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_739);
										mem_vec_739 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_740);
										mem_vec_740 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_741);
										mem_vec_741 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_742);
										mem_vec_742 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_743);
										mem_vec_743 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_744);
										mem_vec_744 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_745);
										mem_vec_745 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_746);
										mem_vec_746 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_747);
										mem_vec_747 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_748);
										mem_vec_748 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_749);
										mem_vec_749 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_750);
										mem_vec_750 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_751);
										mem_vec_751 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_752);
										mem_vec_752 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_753);
										mem_vec_753 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_754);
										mem_vec_754 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_755);
										mem_vec_755 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_745);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_747);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_751);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_755);
						}
					}
				}
			}
		}
	}
}


}