#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (64, c); T (4, f)]
*/
IND_TYPE c, cp_0, c490_p_0, c491_p_0, cp_1, c490_p_1, cp_2, c490, c491, f, fp_0, f546_p_0, fp_1, f546, h, hp_0, x, xp_0, x444_p_0, xp_1, x444, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y296 = 0;
IND_TYPE x445 = 0;
IND_TYPE h182 = 0;
IND_TYPE w = 0;
IND_TYPE c492 = 0;
IND_TYPE f547 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4454 ,mem_vec_4455 ,mem_vec_4456 ,mem_vec_4457 ,mem_vec_4458 ,mem_vec_4459 ,mem_vec_4460 ,mem_vec_4461 ,mem_vec_4462 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f546 = f547, f546_p_0 = 0;
	f546 < f547 + 1024;
	f546 += 256, f546_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (c, 64) (512 / 8)
	for (c491 = c492, c491_p_0 = 0;
		c491 < c492 + 512;
		c491 += 8, c491_p_0 += 8){
		// y = 17, x = 17, h = 3, w = 3, c = 8, f = 256
		// T (f, 16) (256 / 16)
		for (f = f546, fp_1 = f546_p_0, fp_0 = 0;
			f < f546 + 256;
			f += 16, fp_1 += 16, fp_0 += 16){
				for (y = y296, yp_0 = 0;
					y < y296 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
					// T (x, 1) (17 / 17)
					for (x444 = x445, x444_p_0 = 0;
						x444 < x445 + 17;
						x444 += 17, x444_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c490 = c491, c490_p_1 = c491_p_0, c490_p_0 = 0;
							c490 < c491 + 8;
							c490 += 2, c490_p_1 += 2, c490_p_0 += 2){
							// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 16
							// T (h, 3) (3 / 1)
							for (h = h182, hp_0 = 0;
								h < h182 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 16
								// T (x, 17) (17 / 1)
								for (x = x444, xp_1 = x444_p_0, xp_0 = 0;
									x < x444 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4454 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c490, cp_2 = c490_p_1, cp_1 = c490_p_0, cp_0 = 0;
												c < c490 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4454);
												mem_vec_4454 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4455);
												mem_vec_4455 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4456);
												mem_vec_4456 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4457);
												mem_vec_4457 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_4454);
												mem_vec_4454 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_13 = _mm512_set1_ps(scal_5);


												vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_4455);
												mem_vec_4455 = vec_12;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_6);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_4456);
												mem_vec_4456 = vec_14;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_4457);
												mem_vec_4457 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_19 = _mm512_set1_ps(scal_8);
												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_4454);
												mem_vec_4454 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_22 = _mm512_set1_ps(scal_9);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_4455);
												mem_vec_4455 = vec_21;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_24 = _mm512_set1_ps(scal_10);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4456);
												mem_vec_4456 = vec_23;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_26 = _mm512_set1_ps(scal_11);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_4457);
												mem_vec_4457 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4457);
								}
							}
						}
					}
				}
				for (y = y296 + 12, yp_0 = 0;
					y < y296 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
					// T (x, 1) (17 / 17)
					for (x444 = x445, x444_p_0 = 0;
						x444 < x445 + 17;
						x444 += 17, x444_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c490 = c491, c490_p_1 = c491_p_0, c490_p_0 = 0;
							c490 < c491 + 8;
							c490 += 2, c490_p_1 += 2, c490_p_0 += 2){
							// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 16
							// T (h, 3) (3 / 1)
							for (h = h182, hp_0 = 0;
								h < h182 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 16
								// T (x, 17) (17 / 1)
								for (x = x444, xp_1 = x444_p_0, xp_0 = 0;
									x < x444 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4458 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c490, cp_2 = c490_p_1, cp_1 = c490_p_0, cp_0 = 0;
												c < c490 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4458);
												mem_vec_4458 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4459);
												mem_vec_4459 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4460);
												mem_vec_4460 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4461);
												mem_vec_4461 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4462);
												mem_vec_4462 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_4458);
												mem_vec_4458 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_15 = _mm512_set1_ps(scal_6);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_4459);
												mem_vec_4459 = vec_14;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_4460);
												mem_vec_4460 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_19 = _mm512_set1_ps(scal_8);


												vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_4461);
												mem_vec_4461 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_21 = _mm512_set1_ps(scal_9);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_4462);
												mem_vec_4462 = vec_20;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_23 = _mm512_set1_ps(scal_10);
												vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_4458);
												mem_vec_4458 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_26 = _mm512_set1_ps(scal_11);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_4459);
												mem_vec_4459 = vec_25;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_28 = _mm512_set1_ps(scal_12);


												vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_4460);
												mem_vec_4460 = vec_27;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_30 = _mm512_set1_ps(scal_13);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_4461);
												mem_vec_4461 = vec_29;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_32 = _mm512_set1_ps(scal_14);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_4462);
												mem_vec_4462 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4459);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4462);
								}
							}
						}
					}
				}
		}
	}
}


}