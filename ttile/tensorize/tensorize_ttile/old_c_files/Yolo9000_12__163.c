#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (1, f);
  T (2, c); T (16, f)]
*/
IND_TYPE c, cp_0, c96_p_0, cp_1, c96, f, fp_0, f128_p_0, f129_p_0, fp_1, f128_p_1, fp_2, f128, f129, h, hp_0, w, wp_0, x, xp_0, x96_p_0, xp_1, x96, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y64 = 0;
IND_TYPE x97 = 0;
IND_TYPE h64 = 0;
IND_TYPE w64 = 0;
IND_TYPE c97 = 0;
IND_TYPE f130 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1176 ,mem_vec_1177 ,mem_vec_1178 ,mem_vec_1179 ,mem_vec_1180 ,mem_vec_1181 ,mem_vec_1182 ,mem_vec_1183 ,mem_vec_1184 ,mem_vec_1185 ,mem_vec_1186 ,mem_vec_1187 ,mem_vec_1188 ,mem_vec_1189 ,mem_vec_1190 ,mem_vec_1191 ,mem_vec_1192 ,mem_vec_1193 ,mem_vec_1194 ,mem_vec_1195 ,mem_vec_1196 ,mem_vec_1197 ,mem_vec_1198 ,mem_vec_1199 ,mem_vec_1200 ,mem_vec_1201 ,mem_vec_1202 ,mem_vec_1203 ,mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 16) (512 / 32)
for (f129 = f130, f129_p_0 = 0;
	f129 < f130 + 512;
	f129 += 32, f129_p_0 += 32){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 32
	// T (c, 2) (256 / 128)
	for (c96 = c97, c96_p_0 = 0;
		c96 < c97 + 256;
		c96 += 128, c96_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f128 = f129, f128_p_1 = f129_p_0, f128_p_0 = 0;
			f128 < f129 + 32;
			f128 += 32, f128_p_1 += 32, f128_p_0 += 32){
				for (y = y64, yp_0 = 0;
					y < y64 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (x, 1) (34 / 34)
					for (x96 = x97, x96_p_0 = 0;
						x96 < x97 + 34;
						x96 += 34, x96_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (f, 1) (32 / 32)
						for (f = f128, fp_2 = f128_p_1, fp_1 = f128_p_0, fp_0 = 0;
							f < f128 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h64, hp_0 = 0;
								h < h64 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w64, wp_0 = 0;
									w < w64 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 32
									// T (x, 34) (34 / 1)
									for (x = x96, xp_1 = x96_p_0, xp_0 = 0;
										x < x96 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
													c < c96 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1176);
													mem_vec_1176 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1177);
													mem_vec_1177 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1178);
													mem_vec_1178 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1179);
													mem_vec_1179 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1180);
													mem_vec_1180 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1181);
													mem_vec_1181 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1182);
													mem_vec_1182 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1183);
													mem_vec_1183 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1184);
													mem_vec_1184 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1185);
													mem_vec_1185 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1186);
													mem_vec_1186 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1187);
													mem_vec_1187 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1188);
													mem_vec_1188 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1189);
													mem_vec_1189 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1190);
													mem_vec_1190 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1191);
													mem_vec_1191 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1177);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1183);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1184);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1185);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1186);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1187);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1188);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1189);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1190);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1191);
									}
								}
							}
						}
					}
				}
				for (y = y64 + 8, yp_0 = 0;
					y < y64 + 8 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (x, 1) (34 / 34)
					for (x96 = x97, x96_p_0 = 0;
						x96 < x97 + 34;
						x96 += 34, x96_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (f, 1) (32 / 32)
						for (f = f128, fp_2 = f128_p_1, fp_1 = f128_p_0, fp_0 = 0;
							f < f128 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h64, hp_0 = 0;
								h < h64 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w64, wp_0 = 0;
									w < w64 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 32
									// T (x, 34) (34 / 1)
									for (x = x96, xp_1 = x96_p_0, xp_0 = 0;
										x < x96 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_1216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_1217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
													c < c96 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1192);
													mem_vec_1192 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1193);
													mem_vec_1193 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1194);
													mem_vec_1194 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1195);
													mem_vec_1195 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1196);
													mem_vec_1196 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1197);
													mem_vec_1197 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1198);
													mem_vec_1198 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1199);
													mem_vec_1199 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1200);
													mem_vec_1200 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1201);
													mem_vec_1201 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1202);
													mem_vec_1202 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1203);
													mem_vec_1203 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1204);
													mem_vec_1204 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1205);
													mem_vec_1205 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1206);
													mem_vec_1206 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1207);
													mem_vec_1207 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1208);
													mem_vec_1208 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1209);
													mem_vec_1209 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1210);
													mem_vec_1210 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1211);
													mem_vec_1211 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1212);
													mem_vec_1212 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1213);
													mem_vec_1213 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1214);
													mem_vec_1214 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1215);
													mem_vec_1215 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1216);
													mem_vec_1216 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1217);
													mem_vec_1217 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1192);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1193);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1194);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1195);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1196);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1197);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1198);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1199);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1200);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1201);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1202);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1203);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1204);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1205);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1206);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1217);
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