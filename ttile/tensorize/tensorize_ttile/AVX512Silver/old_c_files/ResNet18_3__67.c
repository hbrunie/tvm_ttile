#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c150_p_0, cp_1, c150, f, fp_0, x, xp_0, x250_p_0, x251_p_0, x252_p_0, xp_1, x250_p_1, x251_p_1, xp_2, x250_p_2, xp_3, x250, x251, x252, y, yp_0, y200_p_0, y201_p_0, yp_1, y200_p_1, yp_2, y200, y201;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y202 = 0;
IND_TYPE x253 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c151 = 0;
IND_TYPE f100 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y201 = y202, y201_p_0 = 0;
	y201 < y202 + 56;
	y201 += 56, y201_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x252 = x253, x252_p_0 = 0;
		x252 < x253 + 56;
		x252 += 1, x252_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y200 = y201, y200_p_1 = y201_p_0, y200_p_0 = 0;
			y200 < y201 + 56;
			y200 += 28, y200_p_1 += 28, y200_p_0 += 28){
			// y = 28, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x251 = x252, x251_p_1 = x252_p_0, x251_p_0 = 0;
				x251 < x252 + 1;
				x251 += 1, x251_p_1 += 1, x251_p_0 += 1){
				// y = 28, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f100, fp_0 = 0;
					f < f100 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y200, yp_2 = y200_p_1, yp_1 = y200_p_0, yp_0 = 0;
						y < y200 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x250 = x251, x250_p_2 = x251_p_1, x250_p_1 = x251_p_0, x250_p_0 = 0;
							x250 < x251 + 1;
							x250 += 1, x250_p_2 += 1, x250_p_1 += 1, x250_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c150 = c151, c150_p_0 = 0;
								c150 < c151 + 64;
								c150 += 16, c150_p_0 += 16){
								// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x250, xp_3 = x250_p_2, xp_2 = x250_p_1, xp_1 = x250_p_0, xp_0 = 0;
									x < x250 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c150, cp_1 = c150_p_0, cp_0 = 0;
												c < c150 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_700);
												mem_vec_700 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_701);
												mem_vec_701 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_702);
												mem_vec_702 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_703);
												mem_vec_703 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_704);
												mem_vec_704 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_705);
												mem_vec_705 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_706);
												mem_vec_706 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_707);
												mem_vec_707 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_708);
												mem_vec_708 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_709);
												mem_vec_709 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_710);
												mem_vec_710 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_711);
												mem_vec_711 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_712);
												mem_vec_712 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_713);
												mem_vec_713 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_700);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_701);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_702);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_703);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_713);
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