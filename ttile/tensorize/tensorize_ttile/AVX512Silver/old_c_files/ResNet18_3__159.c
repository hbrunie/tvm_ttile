#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (4, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c153_p_0, cp_1, c153, f, fp_0, x, xp_0, x255_p_0, x256_p_0, x257_p_0, xp_1, x255_p_1, x256_p_1, xp_2, x255_p_2, xp_3, x255, x256, x257, y, yp_0, y204_p_0, y205_p_0, yp_1, y204_p_1, yp_2, y204, y205;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y206 = 0;
IND_TYPE x258 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c154 = 0;
IND_TYPE f102 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y205 = y206, y205_p_0 = 0;
	y205 < y206 + 56;
	y205 += 56, y205_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x257 = x258, x257_p_0 = 0;
		x257 < x258 + 56;
		x257 += 1, x257_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (56 / 14)
		for (y204 = y205, y204_p_1 = y205_p_0, y204_p_0 = 0;
			y204 < y205 + 56;
			y204 += 14, y204_p_1 += 14, y204_p_0 += 14){
			// y = 14, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x256 = x257, x256_p_1 = x257_p_0, x256_p_0 = 0;
				x256 < x257 + 1;
				x256 += 1, x256_p_1 += 1, x256_p_0 += 1){
				// y = 14, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f102, fp_0 = 0;
					f < f102 + 64;
					f += 32, fp_0 += 32){
					// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 2) (14 / 7)
					for (y = y204, yp_2 = y204_p_1, yp_1 = y204_p_0, yp_0 = 0;
						y < y204 + 14;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x255 = x256, x255_p_2 = x256_p_1, x255_p_1 = x256_p_0, x255_p_0 = 0;
							x255 < x256 + 1;
							x255 += 1, x255_p_2 += 1, x255_p_1 += 1, x255_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c153 = c154, c153_p_0 = 0;
								c153 < c154 + 64;
								c153 += 64, c153_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x255, xp_3 = x255_p_2, xp_2 = x255_p_1, xp_1 = x255_p_0, xp_0 = 0;
									x < x255 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c153, cp_1 = c153_p_0, cp_0 = 0;
												c < c153 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_714);
												mem_vec_714 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_715);
												mem_vec_715 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_716);
												mem_vec_716 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_717);
												mem_vec_717 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_718);
												mem_vec_718 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_719);
												mem_vec_719 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_720);
												mem_vec_720 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_721);
												mem_vec_721 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_722);
												mem_vec_722 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_723);
												mem_vec_723 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_724);
												mem_vec_724 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_725);
												mem_vec_725 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_726);
												mem_vec_726 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_727);
												mem_vec_727 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_727);
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