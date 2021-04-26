#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (16, c); T (2, y); T (8, f); T (2, c)]
*/
IND_TYPE c, cp_0, c108_p_0, c109_p_0, cp_1, c108_p_1, cp_2, c108, c109, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y54 = 0;
IND_TYPE x54 = 0;
IND_TYPE h50 = 0;
IND_TYPE w50 = 0;
IND_TYPE c110 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 2) (512 / 256)
for (c109 = c110, c109_p_0 = 0;
	c109 < c110 + 512;
	c109 += 256, c109_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 512
	// T (f, 8) (512 / 64)
	for (f = f54, fp_0 = 0;
		f < f54 + 512;
		f += 64, fp_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
		// T (y, 2) (14 / 7)
		for (y = y54, yp_0 = 0;
			y < y54 + 14;
			y += 7, yp_0 += 7){
			// y = 7, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (c, 16) (256 / 16)
			for (c108 = c109, c108_p_1 = c109_p_0, c108_p_0 = 0;
				c108 < c109 + 256;
				c108 += 16, c108_p_1 += 16, c108_p_0 += 16){
				// y = 7, x = 14, h = 3, w = 3, c = 16, f = 64
				// T (x, 14) (14 / 1)
				for (x = x54, xp_0 = 0;
					x < x54 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (h, 3) (3 / 1)
					for (h = h50, hp_0 = 0;
						h < h50 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w50, wp_0 = 0;
							w < w50 + 3;
							w += 1, wp_0 += 1){
									mem_vec_756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_758 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_759 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c108, cp_2 = c108_p_1, cp_1 = c108_p_0, cp_0 = 0;
										c < c108 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_756);
										mem_vec_756 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_757);
										mem_vec_757 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_758);
										mem_vec_758 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_759);
										mem_vec_759 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_760);
										mem_vec_760 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_761);
										mem_vec_761 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_762);
										mem_vec_762 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_763);
										mem_vec_763 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_764);
										mem_vec_764 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_765);
										mem_vec_765 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_766);
										mem_vec_766 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_767);
										mem_vec_767 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_768);
										mem_vec_768 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_769);
										mem_vec_769 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_770);
										mem_vec_770 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_771);
										mem_vec_771 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_772);
										mem_vec_772 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_773);
										mem_vec_773 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_774);
										mem_vec_774 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_775);
										mem_vec_775 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_776);
										mem_vec_776 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_777);
										mem_vec_777 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_778);
										mem_vec_778 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_779);
										mem_vec_779 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_780);
										mem_vec_780 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_781);
										mem_vec_781 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_782);
										mem_vec_782 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_783);
										mem_vec_783 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_765);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_783);
						}
					}
				}
			}
		}
	}
}


}