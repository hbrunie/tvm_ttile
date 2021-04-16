#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (1, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, x, xp_0, x145_p_0, x146_p_0, x147_p_0, xp_1, x145_p_1, x146_p_1, xp_2, x145_p_2, xp_3, x145, x146, x147, y, yp_0, y116_p_0, y117_p_0, yp_1, y116_p_1, yp_2, y116, y117;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y118 = 0;
IND_TYPE x148 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c88 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y117 = y118, y117_p_0 = 0;
		y117 < y118 + 96;
		y117 += 32, y117_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x147 = x148, x147_p_0 = 0;
			x147 < x148 + 136;
			x147 += 136, x147_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y116 = y117, y116_p_1 = y117_p_0, y116_p_0 = 0;
				y116 < y117 + 32;
				y116 += 32, y116_p_1 += 32, y116_p_0 += 32){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x146 = x147, x146_p_1 = x147_p_0, x146_p_0 = 0;
					x146 < x147 + 136;
					x146 += 2, x146_p_1 += 2, x146_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f58, fp_0 = 0;
						f < f58 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y116, yp_2 = y116_p_1, yp_1 = y116_p_0, yp_0 = 0;
							y < y116 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x145 = x146, x145_p_2 = x146_p_1, x145_p_1 = x146_p_0, x145_p_0 = 0;
								x145 < x146 + 2;
								x145 += 2, x145_p_2 += 2, x145_p_1 += 2, x145_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c87 = c88, c87_p_0 = 0;
									c87 < c88 + 128;
									c87 += 128, c87_p_0 += 128){
									// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
									// T (x, 2) (2 / 1)
									for (x = x145, xp_3 = x145_p_2, xp_2 = x145_p_1, xp_1 = x145_p_0, xp_0 = 0;
										x < x145 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_644 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_645 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_646 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_647 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
													c < c87 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_644);
													mem_vec_644 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_645);
													mem_vec_645 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_646);
													mem_vec_646 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_647);
													mem_vec_647 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_648);
													mem_vec_648 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_649);
													mem_vec_649 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_650);
													mem_vec_650 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_651);
													mem_vec_651 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_652);
													mem_vec_652 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_653);
													mem_vec_653 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_654);
													mem_vec_654 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_655);
													mem_vec_655 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_656);
													mem_vec_656 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_657);
													mem_vec_657 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_658);
													mem_vec_658 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_659);
													mem_vec_659 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_644);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_645);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_646);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_647);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_648);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_649);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_650);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_651);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_652);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_653);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_654);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_655);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_656);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_657);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_658);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_659);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y117 = y118 + 96, y117_p_0 = 0;
		y117 < y118 + 96 + 40;
		y117 += 40, y117_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x147 = x148, x147_p_0 = 0;
			x147 < x148 + 136;
			x147 += 136, x147_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y116 = y117, y116_p_1 = y117_p_0, y116_p_0 = 0;
				y116 < y117 + 40;
				y116 += 40, y116_p_1 += 40, y116_p_0 += 40){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x146 = x147, x146_p_1 = x147_p_0, x146_p_0 = 0;
					x146 < x147 + 136;
					x146 += 2, x146_p_1 += 2, x146_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f58, fp_0 = 0;
						f < f58 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y116, yp_2 = y116_p_1, yp_1 = y116_p_0, yp_0 = 0;
							y < y116 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x145 = x146, x145_p_2 = x146_p_1, x145_p_1 = x146_p_0, x145_p_0 = 0;
								x145 < x146 + 2;
								x145 += 2, x145_p_2 += 2, x145_p_1 += 2, x145_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c87 = c88, c87_p_0 = 0;
									c87 < c88 + 128;
									c87 += 128, c87_p_0 += 128){
									// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
									// T (x, 2) (2 / 1)
									for (x = x145, xp_3 = x145_p_2, xp_2 = x145_p_1, xp_1 = x145_p_0, xp_0 = 0;
										x < x145 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_660 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_661 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_662 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_663 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_672 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_673 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_674 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_675 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
													c < c87 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_660);
													mem_vec_660 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_661);
													mem_vec_661 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_662);
													mem_vec_662 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_663);
													mem_vec_663 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_664);
													mem_vec_664 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_665);
													mem_vec_665 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_666);
													mem_vec_666 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_667);
													mem_vec_667 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_668);
													mem_vec_668 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_669);
													mem_vec_669 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_670);
													mem_vec_670 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_671);
													mem_vec_671 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_672);
													mem_vec_672 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_673);
													mem_vec_673 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_674);
													mem_vec_674 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_675);
													mem_vec_675 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_676);
													mem_vec_676 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_677);
													mem_vec_677 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_678);
													mem_vec_678 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_679);
													mem_vec_679 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_660);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_661);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_662);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_663);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_664);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_665);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_666);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_667);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_668);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_669);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_670);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_671);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_672);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_673);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_674);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_675);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_676);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_677);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_678);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_679);
									}
								}
							}
						}
					}
				}
			}
		}
	}


}