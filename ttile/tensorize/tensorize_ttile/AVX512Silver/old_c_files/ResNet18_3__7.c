#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c144_p_0, cp_1, c144, f, fp_0, x, xp_0, x240_p_0, x241_p_0, x242_p_0, xp_1, x240_p_1, x241_p_1, xp_2, x240_p_2, xp_3, x240, x241, x242, y, yp_0, y192_p_0, y193_p_0, yp_1, y192_p_1, yp_2, y192, y193;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y194 = 0;
IND_TYPE x243 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c145 = 0;
IND_TYPE f96 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y193 = y194, y193_p_0 = 0;
	y193 < y194 + 56;
	y193 += 56, y193_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x242 = x243, x242_p_0 = 0;
		x242 < x243 + 56;
		x242 += 1, x242_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y192 = y193, y192_p_1 = y193_p_0, y192_p_0 = 0;
			y192 < y193 + 56;
			y192 += 28, y192_p_1 += 28, y192_p_0 += 28){
			// y = 28, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x241 = x242, x241_p_1 = x242_p_0, x241_p_0 = 0;
				x241 < x242 + 1;
				x241 += 1, x241_p_1 += 1, x241_p_0 += 1){
				// y = 28, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f96, fp_0 = 0;
					f < f96 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y192, yp_2 = y192_p_1, yp_1 = y192_p_0, yp_0 = 0;
						y < y192 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x240 = x241, x240_p_2 = x241_p_1, x240_p_1 = x241_p_0, x240_p_0 = 0;
							x240 < x241 + 1;
							x240 += 1, x240_p_2 += 1, x240_p_1 += 1, x240_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c144 = c145, c144_p_0 = 0;
								c144 < c145 + 64;
								c144 += 64, c144_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x240, xp_3 = x240_p_2, xp_2 = x240_p_1, xp_1 = x240_p_0, xp_0 = 0;
									x < x240 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c144, cp_1 = c144_p_0, cp_0 = 0;
												c < c144 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_672);
												mem_vec_672 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_673);
												mem_vec_673 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_674);
												mem_vec_674 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_675);
												mem_vec_675 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_676);
												mem_vec_676 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_677);
												mem_vec_677 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_678);
												mem_vec_678 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_679);
												mem_vec_679 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_680);
												mem_vec_680 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_681);
												mem_vec_681 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_682);
												mem_vec_682 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_683);
												mem_vec_683 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_684);
												mem_vec_684 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_685);
												mem_vec_685 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_672);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_673);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_674);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_675);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_676);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_677);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_678);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_679);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_680);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_681);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_682);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_683);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_684);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_685);
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