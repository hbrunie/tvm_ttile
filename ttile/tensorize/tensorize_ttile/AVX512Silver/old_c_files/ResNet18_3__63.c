#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (7, x); T (4, y); T (2, f); T (8, x); T (1, y); T (1, x); T (2, y)]
*/
IND_TYPE c, cp_0, c489_p_0, cp_1, c489, f, fp_0, x, xp_0, x797_p_0, x798_p_0, x799_p_0, xp_1, x797_p_1, x798_p_1, xp_2, x797_p_2, xp_3, x797, x798, x799, y, yp_0, y634_p_0, y635_p_0, yp_1, y634_p_1, yp_2, y634, y635;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y636 = 0;
IND_TYPE x800 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c490 = 0;
IND_TYPE f308 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3122 ,mem_vec_3123 ,mem_vec_3124 ,mem_vec_3125 ,mem_vec_3126 ,mem_vec_3127 ,mem_vec_3128 ,mem_vec_3129 ,mem_vec_3130 ,mem_vec_3131 ,mem_vec_3132 ,mem_vec_3133 ,mem_vec_3134 ,mem_vec_3135 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 2) (56 / 28)
for (y635 = y636, y635_p_0 = 0;
	y635 < y636 + 56;
	y635 += 28, y635_p_0 += 28){
	// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x799 = x800, x799_p_0 = 0;
		x799 < x800 + 56;
		x799 += 56, x799_p_0 += 56){
		// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (28 / 28)
		for (y634 = y635, y634_p_1 = y635_p_0, y634_p_0 = 0;
			y634 < y635 + 28;
			y634 += 28, y634_p_1 += 28, y634_p_0 += 28){
			// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 8) (56 / 7)
			for (x798 = x799, x798_p_1 = x799_p_0, x798_p_0 = 0;
				x798 < x799 + 56;
				x798 += 7, x798_p_1 += 7, x798_p_0 += 7){
				// y = 28, x = 7, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f308, fp_0 = 0;
					f < f308 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 7, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y634, yp_2 = y634_p_1, yp_1 = y634_p_0, yp_0 = 0;
						y < y634 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 7, h = 1, w = 1, c = 64, f = 32
						// T (x, 7) (7 / 1)
						for (x797 = x798, x797_p_2 = x798_p_1, x797_p_1 = x798_p_0, x797_p_0 = 0;
							x797 < x798 + 7;
							x797 += 1, x797_p_2 += 1, x797_p_1 += 1, x797_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c489 = c490, c489_p_0 = 0;
								c489 < c490 + 64;
								c489 += 32, c489_p_0 += 32){
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x797, xp_3 = x797_p_2, xp_2 = x797_p_1, xp_1 = x797_p_0, xp_0 = 0;
									x < x797 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c489, cp_1 = c489_p_0, cp_0 = 0;
												c < c489 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3122);
												mem_vec_3122 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3123);
												mem_vec_3123 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3124);
												mem_vec_3124 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3125);
												mem_vec_3125 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3126);
												mem_vec_3126 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3127);
												mem_vec_3127 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3128);
												mem_vec_3128 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3129);
												mem_vec_3129 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3130);
												mem_vec_3130 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3131);
												mem_vec_3131 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3132);
												mem_vec_3132 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3133);
												mem_vec_3133 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3134);
												mem_vec_3134 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3135);
												mem_vec_3135 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3123);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3124);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3125);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3133);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3135);
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