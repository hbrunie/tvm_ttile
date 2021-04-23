#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (2, c); T (8, c)]
*/
IND_TYPE c, cp_0, c155_p_0, c156_p_0, c157_p_0, cp_1, c155_p_1, c156_p_1, cp_2, c155_p_2, cp_3, c155, c156, c157, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y62 = 0;
IND_TYPE x62 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c158 = 0;
IND_TYPE f62 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1198 ,mem_vec_1199 ,mem_vec_1200 ,mem_vec_1201 ,mem_vec_1202 ,mem_vec_1203 ,mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 8) (512 / 64)
for (c157 = c158, c157_p_0 = 0;
	c157 < c158 + 512;
	c157 += 64, c157_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 64, f = 1024
	// T (c, 2) (64 / 32)
	for (c156 = c157, c156_p_1 = c157_p_0, c156_p_0 = 0;
		c156 < c157 + 64;
		c156 += 32, c156_p_1 += 32, c156_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f62, fp_0 = 0;
			f < f62 + 1024;
			f += 32, fp_0 += 32){
				for (y = y62, yp_0 = 0;
					y < y62 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
					// T (c, 8) (32 / 4)
					for (c155 = c156, c155_p_2 = c156_p_1, c155_p_1 = c156_p_0, c155_p_0 = 0;
						c155 < c156 + 32;
						c155 += 4, c155_p_2 += 4, c155_p_1 += 4, c155_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x62, xp_0 = 0;
							x < x62 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1198 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1199 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c155, cp_3 = c155_p_2, cp_2 = c155_p_1, cp_1 = c155_p_0, cp_0 = 0;
												c < c155 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1198);
												mem_vec_1198 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1199);
												mem_vec_1199 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1200);
												mem_vec_1200 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1201);
												mem_vec_1201 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1202);
												mem_vec_1202 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1203);
												mem_vec_1203 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1204);
												mem_vec_1204 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1205);
												mem_vec_1205 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1206);
												mem_vec_1206 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1207);
												mem_vec_1207 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1208);
												mem_vec_1208 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1209);
												mem_vec_1209 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1210);
												mem_vec_1210 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1211);
												mem_vec_1211 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1212);
												mem_vec_1212 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1213);
												mem_vec_1213 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1205);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1209);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1210);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1211);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1212);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1213);
								}
							}
						}
					}
				}
				for (y = y62 + 8, yp_0 = 0;
					y < y62 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
					// T (c, 8) (32 / 4)
					for (c155 = c156, c155_p_2 = c156_p_1, c155_p_1 = c156_p_0, c155_p_0 = 0;
						c155 < c156 + 32;
						c155 += 4, c155_p_2 += 4, c155_p_1 += 4, c155_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x62, xp_0 = 0;
							x < x62 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1214 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1215 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_1230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c155, cp_3 = c155_p_2, cp_2 = c155_p_1, cp_1 = c155_p_0, cp_0 = 0;
												c < c155 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1214);
												mem_vec_1214 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1215);
												mem_vec_1215 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1216);
												mem_vec_1216 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1217);
												mem_vec_1217 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1218);
												mem_vec_1218 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1219);
												mem_vec_1219 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1220);
												mem_vec_1220 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1221);
												mem_vec_1221 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1222);
												mem_vec_1222 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1223);
												mem_vec_1223 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1224);
												mem_vec_1224 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1225);
												mem_vec_1225 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1226);
												mem_vec_1226 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1227);
												mem_vec_1227 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1228);
												mem_vec_1228 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1229);
												mem_vec_1229 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1230);
												mem_vec_1230 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1231);
												mem_vec_1231 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1214);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1215);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1216);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1217);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1218);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1219);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1220);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1221);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1222);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1223);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1224);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1225);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1226);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1227);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1228);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1229);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1230);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1231);
								}
							}
						}
					}
				}
		}
	}
}


}