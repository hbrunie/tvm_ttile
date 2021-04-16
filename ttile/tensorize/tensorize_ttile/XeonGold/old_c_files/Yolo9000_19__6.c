#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, x, xp_0, y, yp_0, y57_p_0, yp_1, y57;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y58 = 0;
IND_TYPE x38 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y57 = y58, y57_p_0 = 0;
		y57 < y58 + 8;
		y57 += 8, y57_p_0 += 8){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f38, fp_0 = 0;
			f < f38 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
				y < y57 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 4) (1024 / 256)
				for (c57 = c58, c57_p_0 = 0;
					c57 < c58 + 1024;
					c57 += 256, c57_p_0 += 256){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x = x38, xp_0 = 0;
						x < x38 + 17;
						x += 1, xp_0 += 1){
								mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
								// T (c, 256) (256 / 1)
								for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
									c < c57 + 256;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_646);
									mem_vec_646 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_647);
									mem_vec_647 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_648);
									mem_vec_648 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_649);
									mem_vec_649 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_650);
									mem_vec_650 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_651);
									mem_vec_651 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_652);
									mem_vec_652 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_653);
									mem_vec_653 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_654);
									mem_vec_654 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_655);
									mem_vec_655 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_656);
									mem_vec_656 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_657);
									mem_vec_657 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_658);
									mem_vec_658 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_659);
									mem_vec_659 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_660);
									mem_vec_660 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_661);
									mem_vec_661 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_646);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_647);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_648);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_649);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_650);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_651);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_652);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_653);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_654);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_655);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_656);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_657);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_658);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_659);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_660);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_661);
					}
				}
			}
		}
	}
	for (y57 = y58 + 8, y57_p_0 = 0;
		y57 < y58 + 8 + 9;
		y57 += 9, y57_p_0 += 9){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f38, fp_0 = 0;
			f < f38 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
				y < y57 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 4) (1024 / 256)
				for (c57 = c58, c57_p_0 = 0;
					c57 < c58 + 1024;
					c57 += 256, c57_p_0 += 256){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x = x38, xp_0 = 0;
						x < x38 + 17;
						x += 1, xp_0 += 1){
								mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
								// T (c, 256) (256 / 1)
								for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
									c < c57 + 256;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_662);
									mem_vec_662 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_663);
									mem_vec_663 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_664);
									mem_vec_664 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_665);
									mem_vec_665 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_666);
									mem_vec_666 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_667);
									mem_vec_667 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_668);
									mem_vec_668 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_669);
									mem_vec_669 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_670);
									mem_vec_670 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_671);
									mem_vec_671 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_672);
									mem_vec_672 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_673);
									mem_vec_673 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_674);
									mem_vec_674 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_675);
									mem_vec_675 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_676);
									mem_vec_676 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_677);
									mem_vec_677 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_678);
									mem_vec_678 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_679);
									mem_vec_679 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_662);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_663);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_664);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_665);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_666);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_667);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_668);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_669);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_670);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_671);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_672);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_673);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_674);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_675);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_676);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_677);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_678);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_679);
					}
				}
			}
		}
	}


}