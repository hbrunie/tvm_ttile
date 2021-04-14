#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))];
  T (4, f); T (2, c); T (1, f); T (34, x); T (2, f)]
*/
IND_TYPE c, cp_0, c636_p_0, cp_1, c636, f, fp_0, f848_p_0, f849_p_0, fp_1, f848_p_1, fp_2, f848, f849, h, hp_0, w, wp_0, x, xp_0, x688_p_0, xp_1, x688, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y424 = 0;
IND_TYPE x689 = 0;
IND_TYPE h424 = 0;
IND_TYPE w372 = 0;
IND_TYPE c637 = 0;
IND_TYPE f850 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7472 ,mem_vec_7473 ,mem_vec_7474 ,mem_vec_7475 ,mem_vec_7476 ,mem_vec_7477 ,mem_vec_7478 ,mem_vec_7479 ,mem_vec_7480 ,mem_vec_7481 ,mem_vec_7482 ,mem_vec_7483 ,mem_vec_7484 ,mem_vec_7485 ,mem_vec_7486 ,mem_vec_7487 ,mem_vec_7488 ,mem_vec_7489 ,mem_vec_7490 ,mem_vec_7491 ,mem_vec_7492 ,mem_vec_7493 ,mem_vec_7494 ,mem_vec_7495 ,mem_vec_7496 ,mem_vec_7497 ,mem_vec_7498 ,mem_vec_7499 ,mem_vec_7500 ,mem_vec_7501 ,mem_vec_7502 ,mem_vec_7503 ,mem_vec_7504 ,mem_vec_7505 ,mem_vec_7506 ,mem_vec_7507 ,mem_vec_7508 ,mem_vec_7509 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f849 = f850, f849_p_0 = 0;
	f849 < f850 + 256;
	f849 += 128, f849_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 34) (68 / 2)
	for (x688 = x689, x688_p_0 = 0;
		x688 < x689 + 68;
		x688 += 2, x688_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
		// T (f, 1) (128 / 128)
		for (f848 = f849, f848_p_1 = f849_p_0, f848_p_0 = 0;
			f848 < f849 + 128;
			f848 += 128, f848_p_1 += 128, f848_p_0 += 128){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
			// T (c, 2) (128 / 64)
			for (c636 = c637, c636_p_0 = 0;
				c636 < c637 + 128;
				c636 += 64, c636_p_0 += 64){
				// y = 68, x = 2, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f848, fp_2 = f848_p_1, fp_1 = f848_p_0, fp_0 = 0;
					f < f848 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y424, yp_0 = 0;
							y < y424 + 18;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h424, hp_0 = 0;
								h < h424 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w372, wp_0 = 0;
									w < w372 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x688, xp_1 = x688_p_0, xp_0 = 0;
										x < x688 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_7485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_7486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_7487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_7488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_7489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
													c < c636 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7472);
													mem_vec_7472 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7473);
													mem_vec_7473 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7474);
													mem_vec_7474 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7475);
													mem_vec_7475 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7476);
													mem_vec_7476 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7477);
													mem_vec_7477 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7478);
													mem_vec_7478 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7479);
													mem_vec_7479 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7480);
													mem_vec_7480 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7481);
													mem_vec_7481 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7482);
													mem_vec_7482 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7483);
													mem_vec_7483 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7484);
													mem_vec_7484 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7485);
													mem_vec_7485 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7486);
													mem_vec_7486 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7487);
													mem_vec_7487 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7488);
													mem_vec_7488 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7489);
													mem_vec_7489 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7472);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7473);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7474);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7475);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7476);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7477);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7478);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7479);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7480);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7481);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7482);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7483);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7484);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7485);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7486);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7487);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7488);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7489);
									}
								}
							}
						}
						for (y = y424 + 18, yp_0 = 0;
							y < y424 + 18 + 50;
							y += 10, yp_0 += 10){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h424, hp_0 = 0;
								h < h424 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w372, wp_0 = 0;
									w < w372 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x688, xp_1 = x688_p_0, xp_0 = 0;
										x < x688 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_7503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_7504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_7505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_7506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_7507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_7508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_7509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
													c < c636 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7490);
													mem_vec_7490 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7491);
													mem_vec_7491 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7492);
													mem_vec_7492 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7493);
													mem_vec_7493 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7494);
													mem_vec_7494 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7495);
													mem_vec_7495 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7496);
													mem_vec_7496 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7497);
													mem_vec_7497 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7498);
													mem_vec_7498 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7499);
													mem_vec_7499 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7500);
													mem_vec_7500 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7501);
													mem_vec_7501 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7502);
													mem_vec_7502 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7503);
													mem_vec_7503 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7504);
													mem_vec_7504 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7505);
													mem_vec_7505 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7506);
													mem_vec_7506 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7507);
													mem_vec_7507 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7508);
													mem_vec_7508 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7509);
													mem_vec_7509 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7490);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7491);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7492);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7493);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7494);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7495);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7496);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7497);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7498);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7499);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7500);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7501);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7502);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7503);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7504);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7505);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7506);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7507);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7508);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7509);
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