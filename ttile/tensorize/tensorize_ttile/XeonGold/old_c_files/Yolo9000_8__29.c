#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, f68_p_0, f69_p_0, fp_1, f68_p_1, fp_2, f68, f69, h, hp_0, w, wp_0, x, xp_0, x51_p_0, xp_1, x51, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y34 = 0;
IND_TYPE x52 = 0;
IND_TYPE h34 = 0;
IND_TYPE w34 = 0;
IND_TYPE c52 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f69 = f70, f69_p_0 = 0;
	f69 < f70 + 256;
	f69 += 128, f69_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 1) (128 / 128)
	for (f68 = f69, f68_p_1 = f69_p_0, f68_p_0 = 0;
		f68 < f69 + 128;
		f68 += 128, f68_p_1 += 128, f68_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (68 / 34)
		for (x51 = x52, x51_p_0 = 0;
			x51 < x52 + 68;
			x51 += 34, x51_p_0 += 34){
				for (y = y34, yp_0 = 0;
					y < y34 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f68, fp_2 = f68_p_1, fp_1 = f68_p_0, fp_0 = 0;
						f < f68 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 128;
							c51 += 16, c51_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w34, wp_0 = 0;
								w < w34 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
									x < x51 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h34, hp_0 = 0;
										h < h34 + 3;
										h += 1, hp_0 += 1){
												mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
													c < c51 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_660);
													mem_vec_660 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_661);
													mem_vec_661 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_662);
													mem_vec_662 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_663);
													mem_vec_663 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_664);
													mem_vec_664 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_665);
													mem_vec_665 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_666);
													mem_vec_666 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_667);
													mem_vec_667 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_668);
													mem_vec_668 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_669);
													mem_vec_669 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_670);
													mem_vec_670 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_671);
													mem_vec_671 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_672);
													mem_vec_672 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_673);
													mem_vec_673 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_674);
													mem_vec_674 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_675);
													mem_vec_675 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_663);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_664);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_665);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_666);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_667);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_675);
									}
								}
							}
						}
					}
				}
				for (y = y34 + 8, yp_0 = 0;
					y < y34 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f68, fp_2 = f68_p_1, fp_1 = f68_p_0, fp_0 = 0;
						f < f68 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 128;
							c51 += 16, c51_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w34, wp_0 = 0;
								w < w34 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
									x < x51 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h34, hp_0 = 0;
										h < h34 + 3;
										h += 1, hp_0 += 1){
												mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
													c < c51 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_676);
													mem_vec_676 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_677);
													mem_vec_677 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_678);
													mem_vec_678 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_679);
													mem_vec_679 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_680);
													mem_vec_680 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_681);
													mem_vec_681 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_682);
													mem_vec_682 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_683);
													mem_vec_683 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_684);
													mem_vec_684 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_685);
													mem_vec_685 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_686);
													mem_vec_686 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_687);
													mem_vec_687 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_688);
													mem_vec_688 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_689);
													mem_vec_689 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_690);
													mem_vec_690 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_691);
													mem_vec_691 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_692);
													mem_vec_692 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_693);
													mem_vec_693 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_694);
													mem_vec_694 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_695);
													mem_vec_695 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_696);
													mem_vec_696 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_697);
													mem_vec_697 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_698);
													mem_vec_698 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_699);
													mem_vec_699 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_679);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_695);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_696);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_697);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_698);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_699);
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