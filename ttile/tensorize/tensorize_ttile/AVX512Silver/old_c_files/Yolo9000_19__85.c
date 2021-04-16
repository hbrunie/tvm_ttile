#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (8, f);
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c576_p_0, c577_p_0, cp_1, c576_p_1, cp_2, c576, c577, f, fp_0, x, xp_0, y, yp_0, y432_p_0, yp_1, y432;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y433 = 0;
IND_TYPE x288 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c578 = 0;
IND_TYPE f288 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_5768 ,mem_vec_5769 ,mem_vec_5770 ,mem_vec_5771 ,mem_vec_5772 ,mem_vec_5773 ,mem_vec_5774 ,mem_vec_5775 ,mem_vec_5776 ,mem_vec_5777 ,mem_vec_5778 ,mem_vec_5779 ,mem_vec_5780 ,mem_vec_5781 ,mem_vec_5782 ,mem_vec_5783 ,mem_vec_5784 ,mem_vec_5785 ,mem_vec_5786 ,mem_vec_5787 ,mem_vec_5788 ,mem_vec_5789 ,mem_vec_5790 ,mem_vec_5791 ,mem_vec_5792 ,mem_vec_5793 ,mem_vec_5794 ,mem_vec_5795 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y432 = y433, y432_p_0 = 0;
	y432 < y433 + 17;
	y432 += 17, y432_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 1) (1024 / 1024)
	for (c577 = c578, c577_p_0 = 0;
		c577 < c578 + 1024;
		c577 += 1024, c577_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 8) (512 / 64)
		for (f = f288, fp_0 = 0;
			f < f288 + 512;
			f += 64, fp_0 += 64){
				for (y = y432, yp_1 = y432_p_0, yp_0 = 0;
					y < y432 + 9;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c576 = c577, c576_p_1 = c577_p_0, c576_p_0 = 0;
						c576 < c577 + 1024;
						c576 += 32, c576_p_1 += 32, c576_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x288, xp_0 = 0;
							x < x288 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5770 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5771 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c576, cp_2 = c576_p_1, cp_1 = c576_p_0, cp_0 = 0;
										c < c576 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5768);
										mem_vec_5768 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5769);
										mem_vec_5769 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5770);
										mem_vec_5770 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5771);
										mem_vec_5771 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5772);
										mem_vec_5772 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5773);
										mem_vec_5773 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5774);
										mem_vec_5774 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5775);
										mem_vec_5775 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5776);
										mem_vec_5776 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5777);
										mem_vec_5777 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5778);
										mem_vec_5778 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5779);
										mem_vec_5779 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5779);
						}
					}
				}
				for (y = y432 + 9, yp_1 = y432_p_0, yp_0 = 0;
					y < y432 + 9 + 8;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c576 = c577, c576_p_1 = c577_p_0, c576_p_0 = 0;
						c576 < c577 + 1024;
						c576 += 32, c576_p_1 += 32, c576_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x288, xp_0 = 0;
							x < x288 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5780 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5781 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5782 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5783 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c576, cp_2 = c576_p_1, cp_1 = c576_p_0, cp_0 = 0;
										c < c576 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5780);
										mem_vec_5780 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5781);
										mem_vec_5781 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5782);
										mem_vec_5782 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5783);
										mem_vec_5783 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5784);
										mem_vec_5784 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5785);
										mem_vec_5785 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5786);
										mem_vec_5786 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5787);
										mem_vec_5787 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5788);
										mem_vec_5788 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5789);
										mem_vec_5789 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5790);
										mem_vec_5790 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5791);
										mem_vec_5791 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5792);
										mem_vec_5792 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5793);
										mem_vec_5793 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5794);
										mem_vec_5794 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5795);
										mem_vec_5795 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5783);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5784);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5785);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5786);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5787);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5788);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5789);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5790);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5791);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5795);
						}
					}
				}
		}
	}
}


}