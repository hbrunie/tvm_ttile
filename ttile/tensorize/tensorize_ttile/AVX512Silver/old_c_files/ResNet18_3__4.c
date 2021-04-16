#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (1, y); T (2, f); T (2, x); T (8, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c132_p_0, cp_1, c132, f, fp_0, x, xp_0, x220_p_0, x221_p_0, x222_p_0, xp_1, x220_p_1, x221_p_1, xp_2, x220_p_2, xp_3, x220, x221, x222, y, yp_0, y176_p_0, y177_p_0, yp_1, y176_p_1, yp_2, y176, y177;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y178 = 0;
IND_TYPE x223 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c133 = 0;
IND_TYPE f88 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y177 = y178, y177_p_0 = 0;
	y177 < y178 + 56;
	y177 += 56, y177_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x222 = x223, x222_p_0 = 0;
		x222 < x223 + 56;
		x222 += 2, x222_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 8) (56 / 7)
		for (y176 = y177, y176_p_1 = y177_p_0, y176_p_0 = 0;
			y176 < y177 + 56;
			y176 += 7, y176_p_1 += 7, y176_p_0 += 7){
			// y = 7, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (2 / 1)
			for (x221 = x222, x221_p_1 = x222_p_0, x221_p_0 = 0;
				x221 < x222 + 2;
				x221 += 1, x221_p_1 += 1, x221_p_0 += 1){
				// y = 7, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f88, fp_0 = 0;
					f < f88 + 64;
					f += 32, fp_0 += 32){
					// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (7 / 7)
					for (y = y176, yp_2 = y176_p_1, yp_1 = y176_p_0, yp_0 = 0;
						y < y176 + 7;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x220 = x221, x220_p_2 = x221_p_1, x220_p_1 = x221_p_0, x220_p_0 = 0;
							x220 < x221 + 1;
							x220 += 1, x220_p_2 += 1, x220_p_1 += 1, x220_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c132 = c133, c132_p_0 = 0;
								c132 < c133 + 64;
								c132 += 16, c132_p_0 += 16){
								// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x220, xp_3 = x220_p_2, xp_2 = x220_p_1, xp_1 = x220_p_0, xp_0 = 0;
									x < x220 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c132, cp_1 = c132_p_0, cp_0 = 0;
												c < c132 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_616);
												mem_vec_616 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_617);
												mem_vec_617 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_618);
												mem_vec_618 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_619);
												mem_vec_619 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_620);
												mem_vec_620 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_621);
												mem_vec_621 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_622);
												mem_vec_622 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_623);
												mem_vec_623 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_624);
												mem_vec_624 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_625);
												mem_vec_625 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_626);
												mem_vec_626 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_627);
												mem_vec_627 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_628);
												mem_vec_628 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_629);
												mem_vec_629 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_629);
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