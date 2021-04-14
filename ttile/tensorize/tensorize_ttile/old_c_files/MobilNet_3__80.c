#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (4, f);
  T (4, c); T (14, x)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x480_p_0, x481_p_0, xp_1, x480_p_1, xp_2, x480, x481, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y256 = 0;
IND_TYPE x482 = 0;
IND_TYPE h208 = 0;
IND_TYPE w226 = 0;
IND_TYPE c385 = 0;
IND_TYPE f320 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2984 ,mem_vec_2985 ,mem_vec_2986 ,mem_vec_2987 ,mem_vec_2988 ,mem_vec_2989 ,mem_vec_2990 ,mem_vec_2991 ,mem_vec_2992 ,mem_vec_2993 ,mem_vec_2994 ,mem_vec_2995 ,mem_vec_2996 ,mem_vec_2997 ,mem_vec_2998 ,mem_vec_2999 ,mem_vec_3000 ,mem_vec_3001 ,mem_vec_3002 ,mem_vec_3003 ,mem_vec_3004 ,mem_vec_3005 ,mem_vec_3006 ,mem_vec_3007 ,mem_vec_3008 ,mem_vec_3009 ,mem_vec_3010 ,mem_vec_3011 ,mem_vec_3012 ,mem_vec_3013 ,mem_vec_3014 ,mem_vec_3015 ,mem_vec_3016 ,mem_vec_3017 ,mem_vec_3018 ,mem_vec_3019 ,mem_vec_3020 ,mem_vec_3021 ,mem_vec_3022 ,mem_vec_3023 ,mem_vec_3024 ,mem_vec_3025 ,mem_vec_3026 ,mem_vec_3027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 14) (56 / 4)
for (x481 = x482, x481_p_0 = 0;
	x481 < x482 + 56;
	x481 += 4, x481_p_0 += 4){
	// y = 56, x = 4, h = 3, w = 3, c = 128, f = 128
	// T (c, 4) (128 / 32)
	for (c384 = c385, c384_p_0 = 0;
		c384 < c385 + 128;
		c384 += 32, c384_p_0 += 32){
		// y = 56, x = 4, h = 3, w = 3, c = 32, f = 128
		// T (f, 4) (128 / 32)
		for (f = f320, fp_0 = 0;
			f < f320 + 128;
			f += 32, fp_0 += 32){
				for (y = y256, yp_0 = 0;
					y < y256 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
					// T (x, 1) (4 / 4)
					for (x480 = x481, x480_p_1 = x481_p_0, x480_p_0 = 0;
						x480 < x481 + 4;
						x480 += 4, x480_p_1 += 4, x480_p_0 += 4){
						// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h208, hp_0 = 0;
							h < h208 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w226, wp_0 = 0;
								w < w226 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 32, f = 32
								// T (x, 4) (4 / 1)
								for (x = x480, xp_2 = x480_p_1, xp_1 = x480_p_0, xp_0 = 0;
									x < x480 + 4;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2984 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2985 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
												c < c384 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2984);
												mem_vec_2984 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2985);
												mem_vec_2985 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2986);
												mem_vec_2986 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2987);
												mem_vec_2987 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2988);
												mem_vec_2988 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2989);
												mem_vec_2989 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2990);
												mem_vec_2990 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2991);
												mem_vec_2991 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2992);
												mem_vec_2992 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2993);
												mem_vec_2993 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2994);
												mem_vec_2994 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2995);
												mem_vec_2995 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2996);
												mem_vec_2996 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2997);
												mem_vec_2997 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2998);
												mem_vec_2998 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2999);
												mem_vec_2999 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3000);
												mem_vec_3000 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3001);
												mem_vec_3001 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3002);
												mem_vec_3002 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3003);
												mem_vec_3003 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2984);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2985);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2986);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2987);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2988);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2989);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2990);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2991);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2992);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2993);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2994);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2995);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2996);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2997);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2998);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2999);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3000);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3001);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3002);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3003);
								}
							}
						}
					}
				}
				for (y = y256 + 20, yp_0 = 0;
					y < y256 + 20 + 36;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
					// T (x, 1) (4 / 4)
					for (x480 = x481, x480_p_1 = x481_p_0, x480_p_0 = 0;
						x480 < x481 + 4;
						x480 += 4, x480_p_1 += 4, x480_p_0 += 4){
						// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h208, hp_0 = 0;
							h < h208 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w226, wp_0 = 0;
								w < w226 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 32, f = 32
								// T (x, 4) (4 / 1)
								for (x = x480, xp_2 = x480_p_1, xp_1 = x480_p_0, xp_0 = 0;
									x < x480 + 4;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3004 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3005 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
												c < c384 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3004);
												mem_vec_3004 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3005);
												mem_vec_3005 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3006);
												mem_vec_3006 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3007);
												mem_vec_3007 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3008);
												mem_vec_3008 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3009);
												mem_vec_3009 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3010);
												mem_vec_3010 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3011);
												mem_vec_3011 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3012);
												mem_vec_3012 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3013);
												mem_vec_3013 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3014);
												mem_vec_3014 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3015);
												mem_vec_3015 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3016);
												mem_vec_3016 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3017);
												mem_vec_3017 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3018);
												mem_vec_3018 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3019);
												mem_vec_3019 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3020);
												mem_vec_3020 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3021);
												mem_vec_3021 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3022);
												mem_vec_3022 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3023);
												mem_vec_3023 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3024);
												mem_vec_3024 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3025);
												mem_vec_3025 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3026);
												mem_vec_3026 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3027);
												mem_vec_3027 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3004);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3005);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3006);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3007);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3008);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3009);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3010);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3011);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3012);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3013);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3014);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3015);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3016);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3017);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3018);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3019);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3020);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3021);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3022);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3023);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3024);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3025);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3026);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3027);
								}
							}
						}
					}
				}
		}
	}
}


}