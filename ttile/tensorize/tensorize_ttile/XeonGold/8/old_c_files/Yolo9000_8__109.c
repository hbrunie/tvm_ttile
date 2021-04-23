#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c285_p_0, cp_1, c285, f, fp_0, f380_p_0, f381_p_0, fp_1, f380_p_1, fp_2, f380, f381, h, hp_0, w, wp_0, x, xp_0, x285_p_0, xp_1, x285, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y190 = 0;
IND_TYPE x286 = 0;
IND_TYPE h190 = 0;
IND_TYPE w170 = 0;
IND_TYPE c286 = 0;
IND_TYPE f382 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3700 ,mem_vec_3701 ,mem_vec_3702 ,mem_vec_3703 ,mem_vec_3704 ,mem_vec_3705 ,mem_vec_3706 ,mem_vec_3707 ,mem_vec_3708 ,mem_vec_3709 ,mem_vec_3710 ,mem_vec_3711 ,mem_vec_3712 ,mem_vec_3713 ,mem_vec_3714 ,mem_vec_3715 ,mem_vec_3716 ,mem_vec_3717 ,mem_vec_3718 ,mem_vec_3719 ,mem_vec_3720 ,mem_vec_3721 ,mem_vec_3722 ,mem_vec_3723 ,mem_vec_3724 ,mem_vec_3725 ,mem_vec_3726 ,mem_vec_3727 ,mem_vec_3728 ,mem_vec_3729 ,mem_vec_3730 ,mem_vec_3731 ,mem_vec_3732 ,mem_vec_3733 ,mem_vec_3734 ,mem_vec_3735 ,mem_vec_3736 ,mem_vec_3737 ,mem_vec_3738 ,mem_vec_3739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f381 = f382, f381_p_0 = 0;
	f381 < f382 + 256;
	f381 += 128, f381_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 4) (128 / 32)
	for (f380 = f381, f380_p_1 = f381_p_0, f380_p_0 = 0;
		f380 < f381 + 128;
		f380 += 32, f380_p_1 += 32, f380_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x285 = x286, x285_p_0 = 0;
			x285 < x286 + 68;
			x285 += 17, x285_p_0 += 17){
				for (y = y190, yp_0 = 0;
					y < y190 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f380, fp_2 = f380_p_1, fp_1 = f380_p_0, fp_0 = 0;
						f < f380 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c285 = c286, c285_p_0 = 0;
							c285 < c286 + 128;
							c285 += 32, c285_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w170, wp_0 = 0;
								w < w170 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x285, xp_1 = x285_p_0, xp_0 = 0;
									x < x285 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h190, hp_0 = 0;
										h < h190 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c285, cp_1 = c285_p_0, cp_0 = 0;
													c < c285 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3700);
													mem_vec_3700 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3701);
													mem_vec_3701 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3702);
													mem_vec_3702 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3703);
													mem_vec_3703 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3704);
													mem_vec_3704 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3705);
													mem_vec_3705 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3706);
													mem_vec_3706 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3707);
													mem_vec_3707 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3708);
													mem_vec_3708 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3709);
													mem_vec_3709 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3710);
													mem_vec_3710 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3711);
													mem_vec_3711 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3712);
													mem_vec_3712 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3713);
													mem_vec_3713 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3714);
													mem_vec_3714 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3715);
													mem_vec_3715 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3707);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3708);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3709);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3710);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3711);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3712);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3713);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3714);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3715);
									}
								}
							}
						}
					}
				}
				for (y = y190 + 8, yp_0 = 0;
					y < y190 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f380, fp_2 = f380_p_1, fp_1 = f380_p_0, fp_0 = 0;
						f < f380 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c285 = c286, c285_p_0 = 0;
							c285 < c286 + 128;
							c285 += 32, c285_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w170, wp_0 = 0;
								w < w170 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x285, xp_1 = x285_p_0, xp_0 = 0;
									x < x285 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h190, hp_0 = 0;
										h < h190 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3716 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_3736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_3738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_3739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c285, cp_1 = c285_p_0, cp_0 = 0;
													c < c285 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3716);
													mem_vec_3716 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3717);
													mem_vec_3717 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3718);
													mem_vec_3718 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3719);
													mem_vec_3719 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3720);
													mem_vec_3720 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3721);
													mem_vec_3721 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3722);
													mem_vec_3722 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3723);
													mem_vec_3723 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3724);
													mem_vec_3724 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3725);
													mem_vec_3725 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3726);
													mem_vec_3726 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3727);
													mem_vec_3727 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3728);
													mem_vec_3728 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3729);
													mem_vec_3729 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3730);
													mem_vec_3730 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3731);
													mem_vec_3731 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3732);
													mem_vec_3732 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3733);
													mem_vec_3733 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3734);
													mem_vec_3734 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3735);
													mem_vec_3735 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3736);
													mem_vec_3736 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3737);
													mem_vec_3737 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3738);
													mem_vec_3738 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3739);
													mem_vec_3739 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3716);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3717);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3718);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3719);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3720);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3721);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3722);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3723);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3724);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3725);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3726);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3727);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3728);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3729);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3730);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3731);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3732);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3733);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3734);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3735);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3736);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3737);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3738);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3739);
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