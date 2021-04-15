#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (2, f); T (128, c); T (1, f); T (1, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c454_p_0, c455_p_0, cp_1, c454_p_1, cp_2, c454, c455, f, fp_0, f446_p_0, f447_p_0, fp_1, f446_p_1, fp_2, f446, f447, h, hp_0, x, xp_0, x406_p_0, xp_1, x406, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y272 = 0;
IND_TYPE x407 = 0;
IND_TYPE h198 = 0;
IND_TYPE w = 0;
IND_TYPE c456 = 0;
IND_TYPE f448 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2660 ,mem_vec_2661 ,mem_vec_2662 ,mem_vec_2663 ,mem_vec_2664 ,mem_vec_2665 ,mem_vec_2666 ,mem_vec_2667 ,mem_vec_2668 ,mem_vec_2669 ,mem_vec_2670 ,mem_vec_2671 ,mem_vec_2672 ,mem_vec_2673 ,mem_vec_2674 ,mem_vec_2675 ,mem_vec_2676 ,mem_vec_2677 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f447 = f448, f447_p_0 = 0;
	f447 < f448 + 256;
	f447 += 64, f447_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
	// T (x, 1) (14 / 14)
	for (x406 = x407, x406_p_0 = 0;
		x406 < x407 + 14;
		x406 += 14, x406_p_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
		// T (c, 1) (256 / 256)
		for (c455 = c456, c455_p_0 = 0;
			c455 < c456 + 256;
			c455 += 256, c455_p_0 += 256){
			// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (f, 1) (64 / 64)
			for (f446 = f447, f446_p_1 = f447_p_0, f446_p_0 = 0;
				f446 < f447 + 64;
				f446 += 64, f446_p_1 += 64, f446_p_0 += 64){
				// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
				// T (c, 128) (256 / 2)
				for (c454 = c455, c454_p_1 = c455_p_0, c454_p_0 = 0;
					c454 < c455 + 256;
					c454 += 2, c454_p_1 += 2, c454_p_0 += 2){
					// y = 14, x = 14, h = 3, w = 3, c = 2, f = 64
					// T (f, 2) (64 / 32)
					for (f = f446, fp_2 = f446_p_1, fp_1 = f446_p_0, fp_0 = 0;
						f < f446 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y272, yp_0 = 0;
								y < y272 + 4;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h198, hp_0 = 0;
									h < h198 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 32
									// T (x, 14) (14 / 1)
									for (x = x406, xp_1 = x406_p_0, xp_0 = 0;
										x < x406 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c454, cp_2 = c454_p_1, cp_1 = c454_p_0, cp_0 = 0;
													c < c454 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2660);
													mem_vec_2660 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2661);
													mem_vec_2661 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2662);
													mem_vec_2662 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2663);
													mem_vec_2663 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2664);
													mem_vec_2664 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2665);
													mem_vec_2665 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2666);
													mem_vec_2666 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2667);
													mem_vec_2667 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_2660);
													mem_vec_2660 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_2661);
													mem_vec_2661 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_2662);
													mem_vec_2662 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_2663);
													mem_vec_2663 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_2664);
													mem_vec_2664 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_2665);
													mem_vec_2665 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_2666);
													mem_vec_2666 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_2667);
													mem_vec_2667 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_2660);
													mem_vec_2660 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_2661);
													mem_vec_2661 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2662);
													mem_vec_2662 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2663);
													mem_vec_2663 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_2664);
													mem_vec_2664 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_2665);
													mem_vec_2665 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_2666);
													mem_vec_2666 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_2667);
													mem_vec_2667 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2663);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2664);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2665);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2666);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2667);
									}
								}
							}
							for (y = y272 + 4, yp_0 = 0;
								y < y272 + 4 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h198, hp_0 = 0;
									h < h198 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 32
									// T (x, 14) (14 / 1)
									for (x = x406, xp_1 = x406_p_0, xp_0 = 0;
										x < x406 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2668 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2669 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c454, cp_2 = c454_p_1, cp_1 = c454_p_0, cp_0 = 0;
													c < c454 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2668);
													mem_vec_2668 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2669);
													mem_vec_2669 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2670);
													mem_vec_2670 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2671);
													mem_vec_2671 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2672);
													mem_vec_2672 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2673);
													mem_vec_2673 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2674);
													mem_vec_2674 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2675);
													mem_vec_2675 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2676);
													mem_vec_2676 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2677);
													mem_vec_2677 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_2668);
													mem_vec_2668 = vec_17;

													vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_2669);
													mem_vec_2669 = vec_20;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_2670);
													mem_vec_2670 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_2671);
													mem_vec_2671 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_2672);
													mem_vec_2672 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_2673);
													mem_vec_2673 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_2674);
													mem_vec_2674 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_2675);
													mem_vec_2675 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_2676);
													mem_vec_2676 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_2677);
													mem_vec_2677 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2668);
													mem_vec_2668 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_2669);
													mem_vec_2669 = vec_37;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_2670);
													mem_vec_2670 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_2671);
													mem_vec_2671 = vec_41;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_43 = _mm512_set1_ps(scal_12);


													vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_2672);
													mem_vec_2672 = vec_42;



													vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_2673);
													mem_vec_2673 = vec_44;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_2674);
													mem_vec_2674 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_2675);
													mem_vec_2675 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_2676);
													mem_vec_2676 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_2677);
													mem_vec_2677 = vec_50;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2677);
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