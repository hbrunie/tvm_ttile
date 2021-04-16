#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (1, c); T (2, f); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, x)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x488_p_0, x489_p_0, xp_1, x488_p_1, xp_2, x488, x489, y, yp_0, y454_p_0, yp_1, y454;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y455 = 0;
IND_TYPE x490 = 0;
IND_TYPE h146 = 0;
IND_TYPE w229 = 0;
IND_TYPE c367 = 0;
IND_TYPE f239 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4704 ,mem_vec_4705 ,mem_vec_4706 ,mem_vec_4707 ,mem_vec_4708 ,mem_vec_4709 ,mem_vec_4710 ,mem_vec_4711 ,mem_vec_4712 ,mem_vec_4713 ,mem_vec_4714 ,mem_vec_4715 ,mem_vec_4716 ,mem_vec_4717 ,mem_vec_4718 ,mem_vec_4719 ,mem_vec_4720 ,mem_vec_4721 ,mem_vec_4722 ,mem_vec_4723 ,mem_vec_4724 ,mem_vec_4725 ,mem_vec_4726 ,mem_vec_4727 ,mem_vec_4728 ,mem_vec_4729 ,mem_vec_4730 ,mem_vec_4731 ,mem_vec_4732 ,mem_vec_4733 ,mem_vec_4734 ,mem_vec_4735 ,mem_vec_4736 ,mem_vec_4737 ,mem_vec_4738 ,mem_vec_4739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x489 = x490, x489_p_0 = 0;
	x489 < x490 + 272;
	x489 += 136, x489_p_0 += 136){
		for (y454 = y455, y454_p_0 = 0;
			y454 < y455 + 192;
			y454 += 64, y454_p_0 += 64){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x488 = x489, x488_p_1 = x489_p_0, x488_p_0 = 0;
				x488 < x489 + 136;
				x488 += 1, x488_p_1 += 1, x488_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f239, fp_0 = 0;
					f < f239 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 1) (32 / 32)
					for (c366 = c367, c366_p_0 = 0;
						c366 < c367 + 32;
						c366 += 32, c366_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y454, yp_1 = y454_p_0, yp_0 = 0;
							y < y454 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;
								x < x488 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h146, hp_0 = 0;
									h < h146 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w229, wp_0 = 0;
										w < w229 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4704 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4705 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4706 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4707 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4708 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4709 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4710 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4711 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4714 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4715 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4716 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4717 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c366, cp_1 = c366_p_0, cp_0 = 0;
													c < c366 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4704);
													mem_vec_4704 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4705);
													mem_vec_4705 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4706);
													mem_vec_4706 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4707);
													mem_vec_4707 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4708);
													mem_vec_4708 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4709);
													mem_vec_4709 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4710);
													mem_vec_4710 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4711);
													mem_vec_4711 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4712);
													mem_vec_4712 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4713);
													mem_vec_4713 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4714);
													mem_vec_4714 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4715);
													mem_vec_4715 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4716);
													mem_vec_4716 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4717);
													mem_vec_4717 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4718);
													mem_vec_4718 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4719);
													mem_vec_4719 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4704);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4705);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4706);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4707);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4708);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4709);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4710);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4711);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4712);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4713);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4714);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4715);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4716);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4717);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4718);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4719);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y454 = y455 + 192, y454_p_0 = 0;
			y454 < y455 + 192 + 80;
			y454 += 80, y454_p_0 += 80){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x488 = x489, x488_p_1 = x489_p_0, x488_p_0 = 0;
				x488 < x489 + 136;
				x488 += 1, x488_p_1 += 1, x488_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f239, fp_0 = 0;
					f < f239 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 1) (32 / 32)
					for (c366 = c367, c366_p_0 = 0;
						c366 < c367 + 32;
						c366 += 32, c366_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y454, yp_1 = y454_p_0, yp_0 = 0;
							y < y454 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;
								x < x488 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h146, hp_0 = 0;
									h < h146 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w229, wp_0 = 0;
										w < w229 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4720 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4721 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4722 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4723 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_4736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_4738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c366, cp_1 = c366_p_0, cp_0 = 0;
													c < c366 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4720);
													mem_vec_4720 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4721);
													mem_vec_4721 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4722);
													mem_vec_4722 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4723);
													mem_vec_4723 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4724);
													mem_vec_4724 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4725);
													mem_vec_4725 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4726);
													mem_vec_4726 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4727);
													mem_vec_4727 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4728);
													mem_vec_4728 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4729);
													mem_vec_4729 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4730);
													mem_vec_4730 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4731);
													mem_vec_4731 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4732);
													mem_vec_4732 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4733);
													mem_vec_4733 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4734);
													mem_vec_4734 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4735);
													mem_vec_4735 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4736);
													mem_vec_4736 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4737);
													mem_vec_4737 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4738);
													mem_vec_4738 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4739);
													mem_vec_4739 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4720);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4721);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4722);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4723);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4724);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4725);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4726);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4727);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4731);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4735);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4739);
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