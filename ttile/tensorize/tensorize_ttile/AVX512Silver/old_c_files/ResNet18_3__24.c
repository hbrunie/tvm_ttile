#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (1, x); T (4, y); T (2, f); T (14, x); T (2, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, x, xp_0, x807_p_0, x808_p_0, x809_p_0, xp_1, x807_p_1, x808_p_1, xp_2, x807_p_2, xp_3, x807, x808, x809, y, yp_0, y642_p_0, y643_p_0, yp_1, y642_p_1, yp_2, y642, y643;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y644 = 0;
IND_TYPE x810 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c496 = 0;
IND_TYPE f312 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3150 ,mem_vec_3151 ,mem_vec_3152 ,mem_vec_3153 ,mem_vec_3154 ,mem_vec_3155 ,mem_vec_3156 ,mem_vec_3157 ,mem_vec_3158 ,mem_vec_3159 ,mem_vec_3160 ,mem_vec_3161 ,mem_vec_3162 ,mem_vec_3163 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y643 = y644, y643_p_0 = 0;
	y643 < y644 + 56;
	y643 += 56, y643_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x809 = x810, x809_p_0 = 0;
		x809 < x810 + 56;
		x809 += 56, x809_p_0 += 56){
		// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y642 = y643, y642_p_1 = y643_p_0, y642_p_0 = 0;
			y642 < y643 + 56;
			y642 += 28, y642_p_1 += 28, y642_p_0 += 28){
			// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 14) (56 / 4)
			for (x808 = x809, x808_p_1 = x809_p_0, x808_p_0 = 0;
				x808 < x809 + 56;
				x808 += 4, x808_p_1 += 4, x808_p_0 += 4){
				// y = 28, x = 4, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f312, fp_0 = 0;
					f < f312 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 4, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y642, yp_2 = y642_p_1, yp_1 = y642_p_0, yp_0 = 0;
						y < y642 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 4, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (4 / 4)
						for (x807 = x808, x807_p_2 = x808_p_1, x807_p_1 = x808_p_0, x807_p_0 = 0;
							x807 < x808 + 4;
							x807 += 4, x807_p_2 += 4, x807_p_1 += 4, x807_p_0 += 4){
							// y = 7, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c495 = c496, c495_p_0 = 0;
								c495 < c496 + 64;
								c495 += 64, c495_p_0 += 64){
								// y = 7, x = 4, h = 1, w = 1, c = 64, f = 32
								// T (x, 4) (4 / 1)
								for (x = x807, xp_3 = x807_p_2, xp_2 = x807_p_1, xp_1 = x807_p_0, xp_0 = 0;
									x < x807 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3150 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3151 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
												c < c495 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3150);
												mem_vec_3150 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3151);
												mem_vec_3151 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3152);
												mem_vec_3152 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3153);
												mem_vec_3153 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3154);
												mem_vec_3154 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3155);
												mem_vec_3155 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3156);
												mem_vec_3156 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3157);
												mem_vec_3157 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3158);
												mem_vec_3158 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3159);
												mem_vec_3159 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3160);
												mem_vec_3160 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3161);
												mem_vec_3161 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3162);
												mem_vec_3162 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3163);
												mem_vec_3163 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3161);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3163);
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