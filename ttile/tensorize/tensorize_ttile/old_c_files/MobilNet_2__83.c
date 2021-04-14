#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (32, c); T (8, x)]
*/
IND_TYPE c, cp_0, c632_p_0, cp_1, c632, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x698_p_0, x699_p_0, xp_1, x698_p_1, xp_2, x698, x699, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y380 = 0;
IND_TYPE x700 = 0;
IND_TYPE h344 = 0;
IND_TYPE w356 = 0;
IND_TYPE c633 = 0;
IND_TYPE f318 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6040 ,mem_vec_6041 ,mem_vec_6042 ,mem_vec_6043 ,mem_vec_6044 ,mem_vec_6045 ,mem_vec_6046 ,mem_vec_6047 ,mem_vec_6048 ,mem_vec_6049 ,mem_vec_6050 ,mem_vec_6051 ,mem_vec_6052 ,mem_vec_6053 ,mem_vec_6054 ,mem_vec_6055 ,mem_vec_6056 ,mem_vec_6057 ,mem_vec_6058 ,mem_vec_6059 ,mem_vec_6060 ,mem_vec_6061 ,mem_vec_6062 ,mem_vec_6063 ,mem_vec_6064 ,mem_vec_6065 ,mem_vec_6066 ,mem_vec_6067 ,mem_vec_6068 ,mem_vec_6069 ,mem_vec_6070 ,mem_vec_6071 ,mem_vec_6072 ,mem_vec_6073 ,mem_vec_6074 ,mem_vec_6075 ,mem_vec_6076 ,mem_vec_6077 ,mem_vec_6078 ,mem_vec_6079 ,mem_vec_6080 ,mem_vec_6081 ,mem_vec_6082 ,mem_vec_6083 ,mem_vec_6084 ,mem_vec_6085 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 8) (56 / 7)
for (x699 = x700, x699_p_0 = 0;
	x699 < x700 + 56;
	x699 += 7, x699_p_0 += 7){
	// y = 56, x = 7, h = 3, w = 3, c = 64, f = 64
	// T (c, 32) (64 / 2)
	for (c632 = c633, c632_p_0 = 0;
		c632 < c633 + 64;
		c632 += 2, c632_p_0 += 2){
		// y = 56, x = 7, h = 3, w = 3, c = 2, f = 64
		// T (f, 2) (64 / 32)
		for (f = f318, fp_0 = 0;
			f < f318 + 64;
			f += 32, fp_0 += 32){
				for (y = y380, yp_0 = 0;
					y < y380 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
					// T (x, 7) (7 / 1)
					for (x698 = x699, x698_p_1 = x699_p_0, x698_p_0 = 0;
						x698 < x699 + 7;
						x698 += 1, x698_p_1 += 1, x698_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (h, 3) (3 / 1)
						for (h = h344, hp_0 = 0;
							h < h344 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w356, wp_0 = 0;
								w < w356 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x698, xp_2 = x698_p_1, xp_1 = x698_p_0, xp_0 = 0;
									x < x698 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6040 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6041 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c632, cp_1 = c632_p_0, cp_0 = 0;
												c < c632 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6040);
												mem_vec_6040 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6041);
												mem_vec_6041 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6042);
												mem_vec_6042 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6043);
												mem_vec_6043 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6044);
												mem_vec_6044 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6045);
												mem_vec_6045 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6046);
												mem_vec_6046 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6047);
												mem_vec_6047 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6048);
												mem_vec_6048 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6049);
												mem_vec_6049 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6050);
												mem_vec_6050 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6051);
												mem_vec_6051 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6052);
												mem_vec_6052 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6053);
												mem_vec_6053 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6054);
												mem_vec_6054 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6055);
												mem_vec_6055 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6056);
												mem_vec_6056 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6057);
												mem_vec_6057 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6058);
												mem_vec_6058 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6059);
												mem_vec_6059 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6060);
												mem_vec_6060 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6061);
												mem_vec_6061 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6040);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6041);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6042);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6043);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6044);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6045);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6046);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6047);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6048);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6049);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6050);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6051);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6052);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6053);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6054);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6055);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6056);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6057);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6058);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6059);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6061);
								}
							}
						}
					}
				}
				for (y = y380 + 44, yp_0 = 0;
					y < y380 + 44 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
					// T (x, 7) (7 / 1)
					for (x698 = x699, x698_p_1 = x699_p_0, x698_p_0 = 0;
						x698 < x699 + 7;
						x698 += 1, x698_p_1 += 1, x698_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (h, 3) (3 / 1)
						for (h = h344, hp_0 = 0;
							h < h344 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w356, wp_0 = 0;
								w < w356 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x698, xp_2 = x698_p_1, xp_1 = x698_p_0, xp_0 = 0;
									x < x698 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c632, cp_1 = c632_p_0, cp_0 = 0;
												c < c632 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6062);
												mem_vec_6062 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6063);
												mem_vec_6063 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6064);
												mem_vec_6064 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6065);
												mem_vec_6065 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6066);
												mem_vec_6066 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6067);
												mem_vec_6067 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6068);
												mem_vec_6068 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6069);
												mem_vec_6069 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6070);
												mem_vec_6070 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6071);
												mem_vec_6071 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6072);
												mem_vec_6072 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6073);
												mem_vec_6073 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6074);
												mem_vec_6074 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6075);
												mem_vec_6075 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6076);
												mem_vec_6076 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6077);
												mem_vec_6077 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6078);
												mem_vec_6078 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6079);
												mem_vec_6079 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6080);
												mem_vec_6080 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6081);
												mem_vec_6081 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6082);
												mem_vec_6082 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6083);
												mem_vec_6083 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6084);
												mem_vec_6084 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6085);
												mem_vec_6085 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6071);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6075);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6081);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6083);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6085);
								}
							}
						}
					}
				}
		}
	}
}


}