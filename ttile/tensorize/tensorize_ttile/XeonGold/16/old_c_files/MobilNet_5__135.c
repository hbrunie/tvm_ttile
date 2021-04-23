#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (8, c); T (1, f); T (4, y); T (2, x); T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c156_p_0, cp_1, c156, f, fp_0, f192_p_0, f193_p_0, fp_1, f192_p_1, fp_2, f192, f193, h, hp_0, w, wp_0, x, xp_0, x156_p_0, xp_1, x156, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y112 = 0;
IND_TYPE x157 = 0;
IND_TYPE h100 = 0;
IND_TYPE w62 = 0;
IND_TYPE c157 = 0;
IND_TYPE f194 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1184 ,mem_vec_1185 ,mem_vec_1186 ,mem_vec_1187 ,mem_vec_1188 ,mem_vec_1189 ,mem_vec_1190 ,mem_vec_1191 ,mem_vec_1192 ,mem_vec_1193 ,mem_vec_1194 ,mem_vec_1195 ,mem_vec_1196 ,mem_vec_1197 ,mem_vec_1198 ,mem_vec_1199 ,mem_vec_1200 ,mem_vec_1201 ,mem_vec_1202 ,mem_vec_1203 ,mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f193 = f194, f193_p_0 = 0;
	f193 < f194 + 256;
	f193 += 256, f193_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 4) (256 / 64)
	for (f192 = f193, f192_p_1 = f193_p_0, f192_p_0 = 0;
		f192 < f193 + 256;
		f192 += 64, f192_p_1 += 64, f192_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
		// T (x, 2) (28 / 14)
		for (x156 = x157, x156_p_0 = 0;
			x156 < x157 + 28;
			x156 += 14, x156_p_0 += 14){
			// y = 28, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (y, 4) (28 / 7)
			for (y = y112, yp_0 = 0;
				y < y112 + 28;
				y += 7, yp_0 += 7){
				// y = 7, x = 14, h = 3, w = 3, c = 256, f = 64
				// T (f, 1) (64 / 64)
				for (f = f192, fp_2 = f192_p_1, fp_1 = f192_p_0, fp_0 = 0;
					f < f192 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 14, h = 3, w = 3, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c156 = c157, c156_p_0 = 0;
						c156 < c157 + 256;
						c156 += 32, c156_p_0 += 32){
						// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w62, wp_0 = 0;
							w < w62 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 3, w = 1, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x156, xp_1 = x156_p_0, xp_0 = 0;
								x < x156 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h100, hp_0 = 0;
									h < h100 + 3;
									h += 1, hp_0 += 1){
											mem_vec_1184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1185 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1186 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_1187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_1188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_1191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_1192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_1195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_1196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_1199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_1200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_1203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_1204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_1207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_1208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_1211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
												c < c156 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1184);
												mem_vec_1184 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1185);
												mem_vec_1185 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1186);
												mem_vec_1186 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1187);
												mem_vec_1187 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1188);
												mem_vec_1188 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1189);
												mem_vec_1189 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1190);
												mem_vec_1190 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1191);
												mem_vec_1191 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1192);
												mem_vec_1192 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1193);
												mem_vec_1193 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1194);
												mem_vec_1194 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1195);
												mem_vec_1195 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1196);
												mem_vec_1196 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1197);
												mem_vec_1197 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1198);
												mem_vec_1198 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1199);
												mem_vec_1199 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1200);
												mem_vec_1200 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1201);
												mem_vec_1201 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1202);
												mem_vec_1202 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1203);
												mem_vec_1203 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1204);
												mem_vec_1204 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1205);
												mem_vec_1205 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1206);
												mem_vec_1206 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1207);
												mem_vec_1207 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1208);
												mem_vec_1208 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1209);
												mem_vec_1209 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1210);
												mem_vec_1210 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1211);
												mem_vec_1211 = vec_38;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1186);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1191);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1192);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1193);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1194);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1195);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1205);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1209);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1210);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1211);
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