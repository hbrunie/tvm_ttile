#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (4, c); T (8, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1090_p_0, c1091_p_0, cp_1, c1090_p_1, cp_2, c1090, c1091, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x834_p_0, xp_1, x834, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y556 = 0;
IND_TYPE x835 = 0;
IND_TYPE h454 = 0;
IND_TYPE w528 = 0;
IND_TYPE c1092 = 0;
IND_TYPE f928 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8140 ,mem_vec_8141 ,mem_vec_8142 ,mem_vec_8143 ,mem_vec_8144 ,mem_vec_8145 ,mem_vec_8146 ,mem_vec_8147 ,mem_vec_8148 ,mem_vec_8149 ,mem_vec_8150 ,mem_vec_8151 ,mem_vec_8152 ,mem_vec_8153 ,mem_vec_8154 ,mem_vec_8155 ,mem_vec_8156 ,mem_vec_8157 ,mem_vec_8158 ,mem_vec_8159 ,mem_vec_8160 ,mem_vec_8161 ,mem_vec_8162 ,mem_vec_8163 ,mem_vec_8164 ,mem_vec_8165 ,mem_vec_8166 ,mem_vec_8167 ,mem_vec_8168 ,mem_vec_8169 ,mem_vec_8170 ,mem_vec_8171 ,mem_vec_8172 ,mem_vec_8173 ,mem_vec_8174 ,mem_vec_8175 ,mem_vec_8176 ,mem_vec_8177 ,mem_vec_8178 ,mem_vec_8179 ,mem_vec_8180 ,mem_vec_8181 ,mem_vec_8182 ,mem_vec_8183 ,mem_vec_8184 ,mem_vec_8185 ,mem_vec_8186 ,mem_vec_8187 ,mem_vec_8188 ,mem_vec_8189 ,mem_vec_8190 ,mem_vec_8191 ,mem_vec_8192 ,mem_vec_8193 ,mem_vec_8194 ,mem_vec_8195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (c, 4) (256 / 64)
for (c1091 = c1092, c1091_p_0 = 0;
	c1091 < c1092 + 256;
	c1091 += 64, c1091_p_0 += 64){
		for (y = y556, yp_0 = 0;
			y < y556 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 256
			// T (x, 7) (28 / 4)
			for (x834 = x835, x834_p_0 = 0;
				x834 < x835 + 28;
				x834 += 4, x834_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 256
				// T (f, 8) (256 / 32)
				for (f = f928, fp_0 = 0;
					f < f928 + 256;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c1090 = c1091, c1090_p_1 = c1091_p_0, c1090_p_0 = 0;
						c1090 < c1091 + 64;
						c1090 += 16, c1090_p_1 += 16, c1090_p_0 += 16){
						// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h454, hp_0 = 0;
							h < h454 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w528, wp_0 = 0;
								w < w528 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
								// T (x, 4) (4 / 1)
								for (x = x834, xp_1 = x834_p_0, xp_0 = 0;
									x < x834 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_8164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_8165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1090, cp_2 = c1090_p_1, cp_1 = c1090_p_0, cp_0 = 0;
												c < c1090 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8140);
												mem_vec_8140 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8141);
												mem_vec_8141 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8142);
												mem_vec_8142 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8143);
												mem_vec_8143 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8144);
												mem_vec_8144 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8145);
												mem_vec_8145 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8146);
												mem_vec_8146 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8147);
												mem_vec_8147 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8148);
												mem_vec_8148 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8149);
												mem_vec_8149 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8150);
												mem_vec_8150 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8151);
												mem_vec_8151 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8152);
												mem_vec_8152 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8153);
												mem_vec_8153 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8154);
												mem_vec_8154 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8155);
												mem_vec_8155 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8156);
												mem_vec_8156 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8157);
												mem_vec_8157 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8158);
												mem_vec_8158 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8159);
												mem_vec_8159 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8160);
												mem_vec_8160 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8161);
												mem_vec_8161 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8162);
												mem_vec_8162 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8163);
												mem_vec_8163 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8164);
												mem_vec_8164 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8165);
												mem_vec_8165 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8161);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8163);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8165);
								}
							}
						}
					}
				}
			}
		}
		for (y = y556 + 13, yp_0 = 0;
			y < y556 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 256
			// T (x, 7) (28 / 4)
			for (x834 = x835, x834_p_0 = 0;
				x834 < x835 + 28;
				x834 += 4, x834_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 256
				// T (f, 8) (256 / 32)
				for (f = f928, fp_0 = 0;
					f < f928 + 256;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c1090 = c1091, c1090_p_1 = c1091_p_0, c1090_p_0 = 0;
						c1090 < c1091 + 64;
						c1090 += 16, c1090_p_1 += 16, c1090_p_0 += 16){
						// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h454, hp_0 = 0;
							h < h454 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w528, wp_0 = 0;
								w < w528 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
								// T (x, 4) (4 / 1)
								for (x = x834, xp_1 = x834_p_0, xp_0 = 0;
									x < x834 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8166 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8167 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_8190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_8191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_8192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_8193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_8194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_8195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1090, cp_2 = c1090_p_1, cp_1 = c1090_p_0, cp_0 = 0;
												c < c1090 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8166);
												mem_vec_8166 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8167);
												mem_vec_8167 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8168);
												mem_vec_8168 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8169);
												mem_vec_8169 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8170);
												mem_vec_8170 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8171);
												mem_vec_8171 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8172);
												mem_vec_8172 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8173);
												mem_vec_8173 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8174);
												mem_vec_8174 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8175);
												mem_vec_8175 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8176);
												mem_vec_8176 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8177);
												mem_vec_8177 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8178);
												mem_vec_8178 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8179);
												mem_vec_8179 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8180);
												mem_vec_8180 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8181);
												mem_vec_8181 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8182);
												mem_vec_8182 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8183);
												mem_vec_8183 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8184);
												mem_vec_8184 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8185);
												mem_vec_8185 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8186);
												mem_vec_8186 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8187);
												mem_vec_8187 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8188);
												mem_vec_8188 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8189);
												mem_vec_8189 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8190);
												mem_vec_8190 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8191);
												mem_vec_8191 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8192);
												mem_vec_8192 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8193);
												mem_vec_8193 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8194);
												mem_vec_8194 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8195);
												mem_vec_8195 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8166);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8167);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8168);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8169);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8170);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8171);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8172);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8173);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8174);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8175);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8177);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8178);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8179);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8180);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8181);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8182);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8183);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8186);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8191);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8192);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8193);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_8194);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_8195);
								}
							}
						}
					}
				}
			}
		}
}


}