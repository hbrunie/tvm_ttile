#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (34, x); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))]; T (4, f);
  T (64, c); T (2, x)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, f, fp_0, x, xp_0, x160_p_0, x161_p_0, xp_1, x160_p_1, xp_2, x160, x161, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y80 = 0;
IND_TYPE x162 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c121 = 0;
IND_TYPE f80 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x161 = x162, x161_p_0 = 0;
	x161 < x162 + 68;
	x161 += 34, x161_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 64) (256 / 4)
	for (c120 = c121, c120_p_0 = 0;
		c120 < c121 + 256;
		c120 += 4, c120_p_0 += 4){
		// y = 68, x = 34, h = 1, w = 1, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f80, fp_0 = 0;
			f < f80 + 128;
			f += 32, fp_0 += 32){
				for (y = y80, yp_0 = 0;
					y < y80 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 1) (34 / 34)
					for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
						x160 < x161 + 34;
						x160 += 34, x160_p_1 += 34, x160_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
						// T (x, 34) (34 / 1)
						for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
							x < x160 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_752);
										mem_vec_752 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_753);
										mem_vec_753 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_754);
										mem_vec_754 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_755);
										mem_vec_755 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_756);
										mem_vec_756 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_757);
										mem_vec_757 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_758);
										mem_vec_758 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_759);
										mem_vec_759 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_760);
										mem_vec_760 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_761);
										mem_vec_761 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_762);
										mem_vec_762 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_763);
										mem_vec_763 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_764);
										mem_vec_764 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_765);
										mem_vec_765 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_765);
						}
					}
				}
				for (y = y80 + 28, yp_0 = 0;
					y < y80 + 28 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 1) (34 / 34)
					for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
						x160 < x161 + 34;
						x160 += 34, x160_p_1 += 34, x160_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
						// T (x, 34) (34 / 1)
						for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
							x < x160 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_766);
										mem_vec_766 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_767);
										mem_vec_767 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_768);
										mem_vec_768 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_769);
										mem_vec_769 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_770);
										mem_vec_770 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_771);
										mem_vec_771 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_772);
										mem_vec_772 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_773);
										mem_vec_773 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_774);
										mem_vec_774 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_775);
										mem_vec_775 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_776);
										mem_vec_776 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_777);
										mem_vec_777 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_778);
										mem_vec_778 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_779);
										mem_vec_779 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_780);
										mem_vec_780 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_781);
										mem_vec_781 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_781);
						}
					}
				}
		}
	}
}


}