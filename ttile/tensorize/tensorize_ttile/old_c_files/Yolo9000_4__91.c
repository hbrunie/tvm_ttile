#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (17, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (4, f);
  T (4, c); T (1, x)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x936_p_0, x937_p_0, xp_1, x936_p_1, xp_2, x936, x937, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y468 = 0;
IND_TYPE x938 = 0;
IND_TYPE h468 = 0;
IND_TYPE w438 = 0;
IND_TYPE c703 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9112 ,mem_vec_9113 ,mem_vec_9114 ,mem_vec_9115 ,mem_vec_9116 ,mem_vec_9117 ,mem_vec_9118 ,mem_vec_9119 ,mem_vec_9120 ,mem_vec_9121 ,mem_vec_9122 ,mem_vec_9123 ,mem_vec_9124 ,mem_vec_9125 ,mem_vec_9126 ,mem_vec_9127 ,mem_vec_9128 ,mem_vec_9129 ,mem_vec_9130 ,mem_vec_9131 ,mem_vec_9132 ,mem_vec_9133 ,mem_vec_9134 ,mem_vec_9135 ,mem_vec_9136 ,mem_vec_9137 ,mem_vec_9138 ,mem_vec_9139 ,mem_vec_9140 ,mem_vec_9141 ,mem_vec_9142 ,mem_vec_9143 ,mem_vec_9144 ,mem_vec_9145 ,mem_vec_9146 ,mem_vec_9147 ,mem_vec_9148 ,mem_vec_9149 ,mem_vec_9150 ,mem_vec_9151 ,mem_vec_9152 ,mem_vec_9153 ,mem_vec_9154 ,mem_vec_9155 ,mem_vec_9156 ,mem_vec_9157 ,mem_vec_9158 ,mem_vec_9159 ,mem_vec_9160 ,mem_vec_9161 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x937 = x938, x937_p_0 = 0;
	x937 < x938 + 136;
	x937 += 136, x937_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 4) (64 / 16)
	for (c702 = c703, c702_p_0 = 0;
		c702 < c703 + 64;
		c702 += 16, c702_p_0 += 16){
		// y = 136, x = 136, h = 3, w = 3, c = 16, f = 128
		// T (f, 4) (128 / 32)
		for (f = f468, fp_0 = 0;
			f < f468 + 128;
			f += 32, fp_0 += 32){
				for (y = y468, yp_0 = 0;
					y < y468 + 84;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 136, h = 3, w = 3, c = 16, f = 32
					// T (x, 17) (136 / 8)
					for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
						x936 < x937 + 136;
						x936 += 8, x936_p_1 += 8, x936_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h468, hp_0 = 0;
							h < h468 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w438, wp_0 = 0;
								w < w438 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
									x < x936 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
												c < c702 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9112);
												mem_vec_9112 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9113);
												mem_vec_9113 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9114);
												mem_vec_9114 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9115);
												mem_vec_9115 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9116);
												mem_vec_9116 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9117);
												mem_vec_9117 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9118);
												mem_vec_9118 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9119);
												mem_vec_9119 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9120);
												mem_vec_9120 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9121);
												mem_vec_9121 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9122);
												mem_vec_9122 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9123);
												mem_vec_9123 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9124);
												mem_vec_9124 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9125);
												mem_vec_9125 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9126);
												mem_vec_9126 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9127);
												mem_vec_9127 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9128);
												mem_vec_9128 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9129);
												mem_vec_9129 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9130);
												mem_vec_9130 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9131);
												mem_vec_9131 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9132);
												mem_vec_9132 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9133);
												mem_vec_9133 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9134);
												mem_vec_9134 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9135);
												mem_vec_9135 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9115);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9116);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9117);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9118);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9119);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9120);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9121);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9123);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9124);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9125);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9133);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9135);
								}
							}
						}
					}
				}
				for (y = y468 + 84, yp_0 = 0;
					y < y468 + 84 + 52;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 136, h = 3, w = 3, c = 16, f = 32
					// T (x, 17) (136 / 8)
					for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
						x936 < x937 + 136;
						x936 += 8, x936_p_1 += 8, x936_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h468, hp_0 = 0;
							h < h468 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w438, wp_0 = 0;
								w < w438 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
									x < x936 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_9160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_9161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
												c < c702 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9136);
												mem_vec_9136 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9137);
												mem_vec_9137 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9138);
												mem_vec_9138 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9139);
												mem_vec_9139 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9140);
												mem_vec_9140 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9141);
												mem_vec_9141 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9142);
												mem_vec_9142 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9143);
												mem_vec_9143 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9144);
												mem_vec_9144 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9145);
												mem_vec_9145 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9146);
												mem_vec_9146 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9147);
												mem_vec_9147 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9148);
												mem_vec_9148 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9149);
												mem_vec_9149 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9150);
												mem_vec_9150 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9151);
												mem_vec_9151 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9152);
												mem_vec_9152 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9153);
												mem_vec_9153 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9154);
												mem_vec_9154 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9155);
												mem_vec_9155 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9156);
												mem_vec_9156 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9157);
												mem_vec_9157 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9158);
												mem_vec_9158 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9159);
												mem_vec_9159 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9160);
												mem_vec_9160 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9161);
												mem_vec_9161 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9136);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9137);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9139);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9161);
								}
							}
						}
					}
				}
		}
	}
}


}