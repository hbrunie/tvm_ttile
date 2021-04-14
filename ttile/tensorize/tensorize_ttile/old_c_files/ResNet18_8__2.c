#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, f); T (1, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (4, f)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, f774_p_0, fp_1, f774, h, hp_0, w, wp_0, x, xp_0, x702_p_0, xp_1, x702, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y468 = 0;
IND_TYPE x703 = 0;
IND_TYPE h394 = 0;
IND_TYPE w418 = 0;
IND_TYPE c703 = 0;
IND_TYPE f775 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6084 ,mem_vec_6085 ,mem_vec_6086 ,mem_vec_6087 ,mem_vec_6088 ,mem_vec_6089 ,mem_vec_6090 ,mem_vec_6091 ,mem_vec_6092 ,mem_vec_6093 ,mem_vec_6094 ,mem_vec_6095 ,mem_vec_6096 ,mem_vec_6097 ,mem_vec_6098 ,mem_vec_6099 ,mem_vec_6100 ,mem_vec_6101 ,mem_vec_6102 ,mem_vec_6103 ,mem_vec_6104 ,mem_vec_6105 ,mem_vec_6106 ,mem_vec_6107 ,mem_vec_6108 ,mem_vec_6109 ,mem_vec_6110 ,mem_vec_6111 ,mem_vec_6112 ,mem_vec_6113 ,mem_vec_6114 ,mem_vec_6115 ,mem_vec_6116 ,mem_vec_6117 ,mem_vec_6118 ,mem_vec_6119 ,mem_vec_6120 ,mem_vec_6121 ,mem_vec_6122 ,mem_vec_6123 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f774 = f775, f774_p_0 = 0;
	f774 < f775 + 256;
	f774 += 64, f774_p_0 += 64){
		for (y = y468, yp_0 = 0;
			y < y468 + 16;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x702 = x703, x702_p_0 = 0;
				x702 < x703 + 28;
				x702 += 14, x702_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c702 = c703, c702_p_0 = 0;
					c702 < c703 + 128;
					c702 += 128, c702_p_0 += 128){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f774, fp_1 = f774_p_0, fp_0 = 0;
						f < f774 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h394, hp_0 = 0;
							h < h394 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w418, wp_0 = 0;
								w < w418 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 128, f = 32
								// T (x, 14) (14 / 1)
								for (x = x702, xp_1 = x702_p_0, xp_0 = 0;
									x < x702 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6084 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6085 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
												c < c702 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6084);
												mem_vec_6084 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6085);
												mem_vec_6085 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6086);
												mem_vec_6086 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6087);
												mem_vec_6087 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6088);
												mem_vec_6088 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6089);
												mem_vec_6089 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6090);
												mem_vec_6090 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6091);
												mem_vec_6091 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6092);
												mem_vec_6092 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6093);
												mem_vec_6093 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6094);
												mem_vec_6094 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6095);
												mem_vec_6095 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6096);
												mem_vec_6096 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6097);
												mem_vec_6097 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6098);
												mem_vec_6098 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6099);
												mem_vec_6099 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6085);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6086);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6087);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6088);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6089);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6090);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6091);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6092);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6093);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6094);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6095);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6096);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6097);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6098);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6099);
								}
							}
						}
					}
				}
			}
		}
		for (y = y468 + 16, yp_0 = 0;
			y < y468 + 16 + 12;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x702 = x703, x702_p_0 = 0;
				x702 < x703 + 28;
				x702 += 14, x702_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c702 = c703, c702_p_0 = 0;
					c702 < c703 + 128;
					c702 += 128, c702_p_0 += 128){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f774, fp_1 = f774_p_0, fp_0 = 0;
						f < f774 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h394, hp_0 = 0;
							h < h394 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w418, wp_0 = 0;
								w < w418 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 128, f = 32
								// T (x, 14) (14 / 1)
								for (x = x702, xp_1 = x702_p_0, xp_0 = 0;
									x < x702 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6100 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6101 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
												c < c702 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6100);
												mem_vec_6100 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6101);
												mem_vec_6101 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6102);
												mem_vec_6102 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6103);
												mem_vec_6103 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6104);
												mem_vec_6104 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6105);
												mem_vec_6105 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6106);
												mem_vec_6106 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6107);
												mem_vec_6107 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6108);
												mem_vec_6108 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6109);
												mem_vec_6109 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6110);
												mem_vec_6110 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6111);
												mem_vec_6111 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6112);
												mem_vec_6112 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6113);
												mem_vec_6113 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6114);
												mem_vec_6114 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6115);
												mem_vec_6115 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6116);
												mem_vec_6116 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6117);
												mem_vec_6117 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6118);
												mem_vec_6118 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6119);
												mem_vec_6119 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6120);
												mem_vec_6120 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6121);
												mem_vec_6121 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6122);
												mem_vec_6122 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6123);
												mem_vec_6123 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6111);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6115);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6116);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6117);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6118);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6119);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6120);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6121);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6123);
								}
							}
						}
					}
				}
			}
		}
}


}