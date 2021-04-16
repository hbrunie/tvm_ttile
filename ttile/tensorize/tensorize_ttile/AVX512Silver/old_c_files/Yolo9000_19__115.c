#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (16, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]]
*/
IND_TYPE c, cp_0, c588_p_0, c589_p_0, cp_1, c588_p_1, cp_2, c588, c589, f, fp_0, x, xp_0, y, yp_0, y441_p_0, yp_1, y441;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y442 = 0;
IND_TYPE x294 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c590 = 0;
IND_TYPE f294 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_5852 ,mem_vec_5853 ,mem_vec_5854 ,mem_vec_5855 ,mem_vec_5856 ,mem_vec_5857 ,mem_vec_5858 ,mem_vec_5859 ,mem_vec_5860 ,mem_vec_5861 ,mem_vec_5862 ,mem_vec_5863 ,mem_vec_5864 ,mem_vec_5865 ,mem_vec_5866 ,mem_vec_5867 ,mem_vec_5868 ,mem_vec_5869 ,mem_vec_5870 ,mem_vec_5871 ,mem_vec_5872 ,mem_vec_5873 ,mem_vec_5874 ,mem_vec_5875 ,mem_vec_5876 ,mem_vec_5877 ,mem_vec_5878 ,mem_vec_5879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y441 = y442, y441_p_0 = 0;
		y441 < y442 + 9;
		y441 += 3, y441_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c589 = c590, c589_p_0 = 0;
			c589 < c590 + 1024;
			c589 += 1024, c589_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f294, fp_0 = 0;
				f < f294 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y441, yp_1 = y441_p_0, yp_0 = 0;
					y < y441 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c588 = c589, c588_p_1 = c589_p_0, c588_p_0 = 0;
						c588 < c589 + 1024;
						c588 += 64, c588_p_1 += 64, c588_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x294, xp_0 = 0;
							x < x294 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5854 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c588, cp_2 = c588_p_1, cp_1 = c588_p_0, cp_0 = 0;
										c < c588 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5852);
										mem_vec_5852 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5853);
										mem_vec_5853 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5854);
										mem_vec_5854 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5855);
										mem_vec_5855 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5856);
										mem_vec_5856 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5857);
										mem_vec_5857 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5858);
										mem_vec_5858 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5859);
										mem_vec_5859 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5860);
										mem_vec_5860 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5861);
										mem_vec_5861 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5862);
										mem_vec_5862 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5863);
										mem_vec_5863 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5863);
						}
					}
				}
			}
		}
	}
	for (y441 = y442 + 9, y441_p_0 = 0;
		y441 < y442 + 9 + 8;
		y441 += 4, y441_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c589 = c590, c589_p_0 = 0;
			c589 < c590 + 1024;
			c589 += 1024, c589_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f294, fp_0 = 0;
				f < f294 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y441, yp_1 = y441_p_0, yp_0 = 0;
					y < y441 + 4;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c588 = c589, c588_p_1 = c589_p_0, c588_p_0 = 0;
						c588 < c589 + 1024;
						c588 += 64, c588_p_1 += 64, c588_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x294, xp_0 = 0;
							x < x294 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5866 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5867 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c588, cp_2 = c588_p_1, cp_1 = c588_p_0, cp_0 = 0;
										c < c588 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5864);
										mem_vec_5864 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5865);
										mem_vec_5865 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5866);
										mem_vec_5866 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5867);
										mem_vec_5867 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5868);
										mem_vec_5868 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5869);
										mem_vec_5869 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5870);
										mem_vec_5870 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5871);
										mem_vec_5871 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5872);
										mem_vec_5872 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5873);
										mem_vec_5873 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5874);
										mem_vec_5874 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5875);
										mem_vec_5875 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5876);
										mem_vec_5876 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5877);
										mem_vec_5877 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5878);
										mem_vec_5878 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5879);
										mem_vec_5879 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5873);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5874);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5875);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5876);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5877);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5878);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5879);
						}
					}
				}
			}
		}
	}


}