#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (4, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (4, f);
  T (512, c); T (2, f)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, f72_p_0, f73_p_0, fp_1, f72_p_1, fp_2, f72, f73, h, hp_0, w, wp_0, x, xp_0, x54_p_0, xp_1, x54, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y36 = 0;
IND_TYPE x55 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c55 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f73 = f74, f73_p_0 = 0;
	f73 < f74 + 1024;
	f73 += 512, f73_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 512) (512 / 1)
	for (c54 = c55, c54_p_0 = 0;
		c54 < c55 + 512;
		c54 += 1, c54_p_0 += 1){
		// y = 17, x = 17, h = 3, w = 3, c = 1, f = 512
		// T (f, 4) (512 / 128)
		for (f72 = f73, f72_p_1 = f73_p_0, f72_p_0 = 0;
			f72 < f73 + 512;
			f72 += 128, f72_p_1 += 128, f72_p_0 += 128){
				for (y = y36, yp_0 = 0;
					y < y36 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 128
					// T (x, 1) (17 / 17)
					for (x54 = x55, x54_p_0 = 0;
						x54 < x55 + 17;
						x54 += 17, x54_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 128
						// T (f, 4) (128 / 32)
						for (f = f72, fp_2 = f72_p_1, fp_1 = f72_p_0, fp_0 = 0;
							f < f72 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h36, hp_0 = 0;
								h < h36 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w36, wp_0 = 0;
									w < w36 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
									// T (x, 17) (17 / 1)
									for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
										x < x54 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_648 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_649 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_650 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_651 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
													c < c54 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_648);
													mem_vec_648 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_649);
													mem_vec_649 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_650);
													mem_vec_650 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_651);
													mem_vec_651 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_652);
													mem_vec_652 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_653);
													mem_vec_653 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_654);
													mem_vec_654 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_655);
													mem_vec_655 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_656);
													mem_vec_656 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_657);
													mem_vec_657 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_658);
													mem_vec_658 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_659);
													mem_vec_659 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_660);
													mem_vec_660 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_661);
													mem_vec_661 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_662);
													mem_vec_662 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_663);
													mem_vec_663 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_648);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_649);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_650);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_651);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_652);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_653);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_654);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_655);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_656);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_657);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_658);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_659);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_660);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_661);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_662);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_663);
									}
								}
							}
						}
					}
				}
				for (y = y36 + 12, yp_0 = 0;
					y < y36 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 128
					// T (x, 1) (17 / 17)
					for (x54 = x55, x54_p_0 = 0;
						x54 < x55 + 17;
						x54 += 17, x54_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 128
						// T (f, 4) (128 / 32)
						for (f = f72, fp_2 = f72_p_1, fp_1 = f72_p_0, fp_0 = 0;
							f < f72 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h36, hp_0 = 0;
								h < h36 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w36, wp_0 = 0;
									w < w36 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
									// T (x, 17) (17 / 1)
									for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
										x < x54 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_664 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_665 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_666 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_667 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_672 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_673 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_674 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_675 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
													c < c54 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_664);
													mem_vec_664 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_665);
													mem_vec_665 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_666);
													mem_vec_666 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_667);
													mem_vec_667 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_668);
													mem_vec_668 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_669);
													mem_vec_669 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_670);
													mem_vec_670 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_671);
													mem_vec_671 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_672);
													mem_vec_672 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_673);
													mem_vec_673 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_674);
													mem_vec_674 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_675);
													mem_vec_675 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_676);
													mem_vec_676 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_677);
													mem_vec_677 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_678);
													mem_vec_678 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_679);
													mem_vec_679 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_680);
													mem_vec_680 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_681);
													mem_vec_681 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_682);
													mem_vec_682 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_683);
													mem_vec_683 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_664);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_665);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_666);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_667);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_668);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_669);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_670);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_671);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_672);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_673);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_674);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_675);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_676);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_677);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_678);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_679);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_680);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_681);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_682);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_683);
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