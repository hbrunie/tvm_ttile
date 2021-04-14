#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (1, f); T (128, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (8, f)]
*/
IND_TYPE c, cp_0, c618_p_0, cp_1, c618, f, fp_0, f690_p_0, fp_1, f690, h, hp_0, w, wp_0, x, xp_0, x618_p_0, xp_1, x618, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y412 = 0;
IND_TYPE x619 = 0;
IND_TYPE h338 = 0;
IND_TYPE w362 = 0;
IND_TYPE c619 = 0;
IND_TYPE f691 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5060 ,mem_vec_5061 ,mem_vec_5062 ,mem_vec_5063 ,mem_vec_5064 ,mem_vec_5065 ,mem_vec_5066 ,mem_vec_5067 ,mem_vec_5068 ,mem_vec_5069 ,mem_vec_5070 ,mem_vec_5071 ,mem_vec_5072 ,mem_vec_5073 ,mem_vec_5074 ,mem_vec_5075 ,mem_vec_5076 ,mem_vec_5077 ,mem_vec_5078 ,mem_vec_5079 ,mem_vec_5080 ,mem_vec_5081 ,mem_vec_5082 ,mem_vec_5083 ,mem_vec_5084 ,mem_vec_5085 ,mem_vec_5086 ,mem_vec_5087 ,mem_vec_5088 ,mem_vec_5089 ,mem_vec_5090 ,mem_vec_5091 ,mem_vec_5092 ,mem_vec_5093 ,mem_vec_5094 ,mem_vec_5095 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f690 = f691, f690_p_0 = 0;
	f690 < f691 + 256;
	f690 += 32, f690_p_0 += 32){
		for (y = y412, yp_0 = 0;
			y < y412 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x618 = x619, x618_p_0 = 0;
				x618 < x619 + 28;
				x618 += 28, x618_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 128) (128 / 1)
				for (c618 = c619, c618_p_0 = 0;
					c618 < c619 + 128;
					c618 += 1, c618_p_0 += 1){
					// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f690, fp_1 = f690_p_0, fp_0 = 0;
						f < f690 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h338, hp_0 = 0;
							h < h338 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w362, wp_0 = 0;
								w < w362 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 1, f = 32
								// T (x, 28) (28 / 1)
								for (x = x618, xp_1 = x618_p_0, xp_0 = 0;
									x < x618 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5060 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5061 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c618, cp_1 = c618_p_0, cp_0 = 0;
												c < c618 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5060);
												mem_vec_5060 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5061);
												mem_vec_5061 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5062);
												mem_vec_5062 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5063);
												mem_vec_5063 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5064);
												mem_vec_5064 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5065);
												mem_vec_5065 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5066);
												mem_vec_5066 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5067);
												mem_vec_5067 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5068);
												mem_vec_5068 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5069);
												mem_vec_5069 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5070);
												mem_vec_5070 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5071);
												mem_vec_5071 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5072);
												mem_vec_5072 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5073);
												mem_vec_5073 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5074);
												mem_vec_5074 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5075);
												mem_vec_5075 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5061);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5071);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5075);
								}
							}
						}
					}
				}
			}
		}
		for (y = y412 + 8, yp_0 = 0;
			y < y412 + 8 + 20;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x618 = x619, x618_p_0 = 0;
				x618 < x619 + 28;
				x618 += 28, x618_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 128) (128 / 1)
				for (c618 = c619, c618_p_0 = 0;
					c618 < c619 + 128;
					c618 += 1, c618_p_0 += 1){
					// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f690, fp_1 = f690_p_0, fp_0 = 0;
						f < f690 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h338, hp_0 = 0;
							h < h338 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w362, wp_0 = 0;
								w < w362 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 1, f = 32
								// T (x, 28) (28 / 1)
								for (x = x618, xp_1 = x618_p_0, xp_0 = 0;
									x < x618 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5076 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5077 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c618, cp_1 = c618_p_0, cp_0 = 0;
												c < c618 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5076);
												mem_vec_5076 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5077);
												mem_vec_5077 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5078);
												mem_vec_5078 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5079);
												mem_vec_5079 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5080);
												mem_vec_5080 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5081);
												mem_vec_5081 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5082);
												mem_vec_5082 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5083);
												mem_vec_5083 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5084);
												mem_vec_5084 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5085);
												mem_vec_5085 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5086);
												mem_vec_5086 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5087);
												mem_vec_5087 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5088);
												mem_vec_5088 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5089);
												mem_vec_5089 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5090);
												mem_vec_5090 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5091);
												mem_vec_5091 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5092);
												mem_vec_5092 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5093);
												mem_vec_5093 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5094);
												mem_vec_5094 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5095);
												mem_vec_5095 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5081);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5083);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5085);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5086);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5087);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5088);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5089);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5090);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5091);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5092);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5093);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5094);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5095);
								}
							}
						}
					}
				}
			}
		}
}


}