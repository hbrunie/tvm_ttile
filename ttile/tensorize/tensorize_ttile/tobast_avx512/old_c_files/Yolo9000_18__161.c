#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (8, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (4, f);
  T (2, c); T (16, f)]
*/
IND_TYPE c, cp_0, c514_p_0, c515_p_0, cp_1, c514_p_1, cp_2, c514, c515, f, fp_0, f564_p_0, fp_1, f564, h, hp_0, x, xp_0, x462_p_0, xp_1, x462, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y308 = 0;
IND_TYPE x463 = 0;
IND_TYPE h194 = 0;
IND_TYPE w = 0;
IND_TYPE c516 = 0;
IND_TYPE f565 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4508 ,mem_vec_4509 ,mem_vec_4510 ,mem_vec_4511 ,mem_vec_4512 ,mem_vec_4513 ,mem_vec_4514 ,mem_vec_4515 ,mem_vec_4516 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f564 = f565, f564_p_0 = 0;
	f564 < f565 + 1024;
	f564 += 64, f564_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 2) (512 / 256)
	for (c515 = c516, c515_p_0 = 0;
		c515 < c516 + 512;
		c515 += 256, c515_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 64
		// T (f, 4) (64 / 16)
		for (f = f564, fp_1 = f564_p_0, fp_0 = 0;
			f < f564 + 64;
			f += 16, fp_1 += 16, fp_0 += 16){
				for (y = y308, yp_0 = 0;
					y < y308 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (x, 17) (17 / 1)
					for (x462 = x463, x462_p_0 = 0;
						x462 < x463 + 17;
						x462 += 1, x462_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 16
						// T (c, 8) (256 / 32)
						for (c514 = c515, c514_p_1 = c515_p_0, c514_p_0 = 0;
							c514 < c515 + 256;
							c514 += 32, c514_p_1 += 32, c514_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (h, 3) (3 / 1)
							for (h = h194, hp_0 = 0;
								h < h194 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x462, xp_1 = x462_p_0, xp_0 = 0;
									x < x462 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4508 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c514, cp_2 = c514_p_1, cp_1 = c514_p_0, cp_0 = 0;
												c < c514 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4508);
												mem_vec_4508 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4509);
												mem_vec_4509 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4510);
												mem_vec_4510 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4511);
												mem_vec_4511 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_4508);
												mem_vec_4508 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_13 = _mm512_set1_ps(scal_5);


												vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_4509);
												mem_vec_4509 = vec_12;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_6);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_4510);
												mem_vec_4510 = vec_14;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_4511);
												mem_vec_4511 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_19 = _mm512_set1_ps(scal_8);
												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_4508);
												mem_vec_4508 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_22 = _mm512_set1_ps(scal_9);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_4509);
												mem_vec_4509 = vec_21;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_24 = _mm512_set1_ps(scal_10);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4510);
												mem_vec_4510 = vec_23;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_26 = _mm512_set1_ps(scal_11);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_4511);
												mem_vec_4511 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4511);
								}
							}
						}
					}
				}
				for (y = y308 + 12, yp_0 = 0;
					y < y308 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (x, 17) (17 / 1)
					for (x462 = x463, x462_p_0 = 0;
						x462 < x463 + 17;
						x462 += 1, x462_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 16
						// T (c, 8) (256 / 32)
						for (c514 = c515, c514_p_1 = c515_p_0, c514_p_0 = 0;
							c514 < c515 + 256;
							c514 += 32, c514_p_1 += 32, c514_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (h, 3) (3 / 1)
							for (h = h194, hp_0 = 0;
								h < h194 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x462, xp_1 = x462_p_0, xp_0 = 0;
									x < x462 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c514, cp_2 = c514_p_1, cp_1 = c514_p_0, cp_0 = 0;
												c < c514 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4512);
												mem_vec_4512 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4513);
												mem_vec_4513 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4514);
												mem_vec_4514 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4515);
												mem_vec_4515 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4516);
												mem_vec_4516 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_4512);
												mem_vec_4512 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_15 = _mm512_set1_ps(scal_6);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_4513);
												mem_vec_4513 = vec_14;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_4514);
												mem_vec_4514 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_19 = _mm512_set1_ps(scal_8);


												vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_4515);
												mem_vec_4515 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_21 = _mm512_set1_ps(scal_9);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_4516);
												mem_vec_4516 = vec_20;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_23 = _mm512_set1_ps(scal_10);
												vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_4512);
												mem_vec_4512 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_26 = _mm512_set1_ps(scal_11);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_4513);
												mem_vec_4513 = vec_25;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_28 = _mm512_set1_ps(scal_12);


												vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_4514);
												mem_vec_4514 = vec_27;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_30 = _mm512_set1_ps(scal_13);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_4515);
												mem_vec_4515 = vec_29;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_32 = _mm512_set1_ps(scal_14);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_4516);
												mem_vec_4516 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4514);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4515);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4516);
								}
							}
						}
					}
				}
		}
	}
}


}