#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (2, f); T (64, c); T (1, f); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c954_p_0, cp_1, c954, f, fp_0, f1272_p_0, f1273_p_0, fp_1, f1272_p_1, fp_2, f1272, f1273, h, hp_0, w, wp_0, x, xp_0, x1006_p_0, xp_1, x1006, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y636 = 0;
IND_TYPE x1007 = 0;
IND_TYPE h636 = 0;
IND_TYPE w584 = 0;
IND_TYPE c955 = 0;
IND_TYPE f1274 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12464 ,mem_vec_12465 ,mem_vec_12466 ,mem_vec_12467 ,mem_vec_12468 ,mem_vec_12469 ,mem_vec_12470 ,mem_vec_12471 ,mem_vec_12472 ,mem_vec_12473 ,mem_vec_12474 ,mem_vec_12475 ,mem_vec_12476 ,mem_vec_12477 ,mem_vec_12478 ,mem_vec_12479 ,mem_vec_12480 ,mem_vec_12481 ,mem_vec_12482 ,mem_vec_12483 ,mem_vec_12484 ,mem_vec_12485 ,mem_vec_12486 ,mem_vec_12487 ,mem_vec_12488 ,mem_vec_12489 ,mem_vec_12490 ,mem_vec_12491 ,mem_vec_12492 ,mem_vec_12493 ,mem_vec_12494 ,mem_vec_12495 ,mem_vec_12496 ,mem_vec_12497 ,mem_vec_12498 ,mem_vec_12499 ,mem_vec_12500 ,mem_vec_12501 ,mem_vec_12502 ,mem_vec_12503 ,mem_vec_12504 ,mem_vec_12505 ,mem_vec_12506 ,mem_vec_12507 ,mem_vec_12508 ,mem_vec_12509 ,mem_vec_12510 ,mem_vec_12511 ,mem_vec_12512 ,mem_vec_12513 ,mem_vec_12514 ,mem_vec_12515 ,mem_vec_12516 ,mem_vec_12517 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f1273 = f1274, f1273_p_0 = 0;
	f1273 < f1274 + 256;
	f1273 += 64, f1273_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 1) (68 / 68)
	for (x1006 = x1007, x1006_p_0 = 0;
		x1006 < x1007 + 68;
		x1006 += 68, x1006_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f1272 = f1273, f1272_p_1 = f1273_p_0, f1272_p_0 = 0;
			f1272 < f1273 + 64;
			f1272 += 64, f1272_p_1 += 64, f1272_p_0 += 64){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
			// T (c, 64) (128 / 2)
			for (c954 = c955, c954_p_0 = 0;
				c954 < c955 + 128;
				c954 += 2, c954_p_0 += 2){
				// y = 68, x = 68, h = 3, w = 3, c = 2, f = 64
				// T (f, 2) (64 / 32)
				for (f = f1272, fp_2 = f1272_p_1, fp_1 = f1272_p_0, fp_0 = 0;
					f < f1272 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y636, yp_0 = 0;
							y < y636 + 26;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 68, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h636, hp_0 = 0;
								h < h636 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w584, wp_0 = 0;
									w < w584 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 2, f = 32
									// T (x, 68) (68 / 1)
									for (x = x1006, xp_1 = x1006_p_0, xp_0 = 0;
										x < x1006 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_12488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_12489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c954, cp_1 = c954_p_0, cp_0 = 0;
													c < c954 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12464);
													mem_vec_12464 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12465);
													mem_vec_12465 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12466);
													mem_vec_12466 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12467);
													mem_vec_12467 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12468);
													mem_vec_12468 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12469);
													mem_vec_12469 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12470);
													mem_vec_12470 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12471);
													mem_vec_12471 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12472);
													mem_vec_12472 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12473);
													mem_vec_12473 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12474);
													mem_vec_12474 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12475);
													mem_vec_12475 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12476);
													mem_vec_12476 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12477);
													mem_vec_12477 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12478);
													mem_vec_12478 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12479);
													mem_vec_12479 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12480);
													mem_vec_12480 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12481);
													mem_vec_12481 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12482);
													mem_vec_12482 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12483);
													mem_vec_12483 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12484);
													mem_vec_12484 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12485);
													mem_vec_12485 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12486);
													mem_vec_12486 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12487);
													mem_vec_12487 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12488);
													mem_vec_12488 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12489);
													mem_vec_12489 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12464);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12465);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12466);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12467);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12468);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12469);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12470);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12471);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12472);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12473);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12474);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12475);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12476);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12477);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12478);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12479);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12480);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12481);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12482);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12483);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12484);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12485);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12486);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12487);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12488);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12489);
									}
								}
							}
						}
						for (y = y636 + 26, yp_0 = 0;
							y < y636 + 26 + 42;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 68, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h636, hp_0 = 0;
								h < h636 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w584, wp_0 = 0;
									w < w584 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 2, f = 32
									// T (x, 68) (68 / 1)
									for (x = x1006, xp_1 = x1006_p_0, xp_0 = 0;
										x < x1006 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_12514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_12515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_12516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_12517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c954, cp_1 = c954_p_0, cp_0 = 0;
													c < c954 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12490);
													mem_vec_12490 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12491);
													mem_vec_12491 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12492);
													mem_vec_12492 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12493);
													mem_vec_12493 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12494);
													mem_vec_12494 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12495);
													mem_vec_12495 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12496);
													mem_vec_12496 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12497);
													mem_vec_12497 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12498);
													mem_vec_12498 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12499);
													mem_vec_12499 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12500);
													mem_vec_12500 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12501);
													mem_vec_12501 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12502);
													mem_vec_12502 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12503);
													mem_vec_12503 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12504);
													mem_vec_12504 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12505);
													mem_vec_12505 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12506);
													mem_vec_12506 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12507);
													mem_vec_12507 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12508);
													mem_vec_12508 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12509);
													mem_vec_12509 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12510);
													mem_vec_12510 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12511);
													mem_vec_12511 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12512);
													mem_vec_12512 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12513);
													mem_vec_12513 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12514);
													mem_vec_12514 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12515);
													mem_vec_12515 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_12516);
													mem_vec_12516 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_12517);
													mem_vec_12517 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12490);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12491);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12492);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12493);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12494);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12495);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12496);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12497);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12498);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12499);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12500);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12501);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12502);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12503);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12504);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12505);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12506);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12507);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12508);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12509);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12510);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12511);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12512);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12513);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12514);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12515);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_12516);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_12517);
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