#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f);
  T (128, c); T (4, f)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, f80_p_0, f81_p_0, fp_1, f80_p_1, fp_2, f80, f81, h, hp_0, w, wp_0, x, xp_0, x60_p_0, xp_1, x60, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y40 = 0;
IND_TYPE x61 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c61 = 0;
IND_TYPE f82 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f81 = f82, f81_p_0 = 0;
	f81 < f82 + 1024;
	f81 += 256, f81_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (c, 128) (512 / 4)
	for (c60 = c61, c60_p_0 = 0;
		c60 < c61 + 512;
		c60 += 4, c60_p_0 += 4){
		// y = 17, x = 17, h = 3, w = 3, c = 4, f = 256
		// T (f, 1) (256 / 256)
		for (f80 = f81, f80_p_1 = f81_p_0, f80_p_0 = 0;
			f80 < f81 + 256;
			f80 += 256, f80_p_1 += 256, f80_p_0 += 256){
				for (y = y40, yp_0 = 0;
					y < y40 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 256
					// T (x, 17) (17 / 1)
					for (x60 = x61, x60_p_0 = 0;
						x60 < x61 + 17;
						x60 += 1, x60_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 256
						// T (f, 4) (256 / 64)
						for (f = f80, fp_2 = f80_p_1, fp_1 = f80_p_0, fp_0 = 0;
							f < f80 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (x, 1) (1 / 1)
									for (x = x60, xp_1 = x60_p_0, xp_0 = 0;
										x < x60 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
													c < c60 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_668);
													mem_vec_668 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_669);
													mem_vec_669 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_670);
													mem_vec_670 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_671);
													mem_vec_671 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_672);
													mem_vec_672 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_673);
													mem_vec_673 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_674);
													mem_vec_674 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_675);
													mem_vec_675 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_676);
													mem_vec_676 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_677);
													mem_vec_677 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_678);
													mem_vec_678 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_679);
													mem_vec_679 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_680);
													mem_vec_680 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_681);
													mem_vec_681 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_682);
													mem_vec_682 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_683);
													mem_vec_683 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_679);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_683);
									}
								}
							}
						}
					}
				}
				for (y = y40 + 12, yp_0 = 0;
					y < y40 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 256
					// T (x, 17) (17 / 1)
					for (x60 = x61, x60_p_0 = 0;
						x60 < x61 + 17;
						x60 += 1, x60_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 256
						// T (f, 4) (256 / 64)
						for (f = f80, fp_2 = f80_p_1, fp_1 = f80_p_0, fp_0 = 0;
							f < f80 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (x, 1) (1 / 1)
									for (x = x60, xp_1 = x60_p_0, xp_0 = 0;
										x < x60 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
													c < c60 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_684);
													mem_vec_684 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_685);
													mem_vec_685 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_686);
													mem_vec_686 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_687);
													mem_vec_687 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_688);
													mem_vec_688 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_689);
													mem_vec_689 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_690);
													mem_vec_690 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_691);
													mem_vec_691 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_692);
													mem_vec_692 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_693);
													mem_vec_693 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_694);
													mem_vec_694 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_695);
													mem_vec_695 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_696);
													mem_vec_696 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_697);
													mem_vec_697 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_698);
													mem_vec_698 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_699);
													mem_vec_699 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_700);
													mem_vec_700 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_701);
													mem_vec_701 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_702);
													mem_vec_702 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_703);
													mem_vec_703 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_695);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_696);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_697);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_698);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_699);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_703);
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