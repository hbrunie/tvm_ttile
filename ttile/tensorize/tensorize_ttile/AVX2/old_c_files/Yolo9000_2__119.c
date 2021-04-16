#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (1, x); T (16, y); T (1, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x)]
*/
IND_TYPE c, cp_0, c117_p_0, cp_1, c117, f, fp_0, w, wp_0, x, xp_0, x156_p_0, x157_p_0, xp_1, x156_p_1, xp_2, x156, x157, y, yp_0, y141_p_0, yp_1, y141;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y142 = 0;
IND_TYPE x158 = 0;
IND_TYPE h = 0;
IND_TYPE w72 = 0;
IND_TYPE c118 = 0;
IND_TYPE f75 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,mem_vec_1312 ,mem_vec_1313 ,mem_vec_1314 ,mem_vec_1315 ,mem_vec_1316 ,mem_vec_1317 ,mem_vec_1318 ,mem_vec_1319 ,mem_vec_1320 ,mem_vec_1321 ,mem_vec_1322 ,mem_vec_1323 ,mem_vec_1324 ,mem_vec_1325 ,mem_vec_1326 ,mem_vec_1327 ,mem_vec_1328 ,mem_vec_1329 ,mem_vec_1330 ,mem_vec_1331 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x157 = x158, x157_p_0 = 0;
	x157 < x158 + 272;
	x157 += 272, x157_p_0 += 272){
		for (y141 = y142, y141_p_0 = 0;
			y141 < y142 + 192;
			y141 += 64, y141_p_0 += 64){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x156 = x157, x156_p_1 = x157_p_0, x156_p_0 = 0;
				x156 < x157 + 272;
				x156 += 1, x156_p_1 += 1, x156_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f75, fp_0 = 0;
					f < f75 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 1) (32 / 32)
					for (c117 = c118, c117_p_0 = 0;
						c117 < c118 + 32;
						c117 += 32, c117_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y141, yp_1 = y141_p_0, yp_0 = 0;
							y < y141 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x156, xp_2 = x156_p_1, xp_1 = x156_p_0, xp_0 = 0;
								x < x156 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w72, wp_0 = 0;
									w < w72 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1296 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1297 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1298 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1299 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c117, cp_1 = c117_p_0, cp_0 = 0;
												c < c117 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1296);
												mem_vec_1296 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1297);
												mem_vec_1297 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1298);
												mem_vec_1298 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1299);
												mem_vec_1299 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1300);
												mem_vec_1300 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1301);
												mem_vec_1301 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1302);
												mem_vec_1302 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1303);
												mem_vec_1303 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1304);
												mem_vec_1304 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1305);
												mem_vec_1305 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1306);
												mem_vec_1306 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1307);
												mem_vec_1307 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1308);
												mem_vec_1308 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1309);
												mem_vec_1309 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1310);
												mem_vec_1310 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1311);
												mem_vec_1311 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1296);
												mem_vec_1296 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1297);
												mem_vec_1297 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1298);
												mem_vec_1298 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1299);
												mem_vec_1299 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1300);
												mem_vec_1300 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1301);
												mem_vec_1301 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1302);
												mem_vec_1302 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1303);
												mem_vec_1303 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1304);
												mem_vec_1304 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1305);
												mem_vec_1305 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1306);
												mem_vec_1306 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1307);
												mem_vec_1307 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1308);
												mem_vec_1308 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1309);
												mem_vec_1309 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1310);
												mem_vec_1310 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1311);
												mem_vec_1311 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1296);
												mem_vec_1296 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1297);
												mem_vec_1297 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1298);
												mem_vec_1298 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1299);
												mem_vec_1299 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1300);
												mem_vec_1300 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1301);
												mem_vec_1301 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1302);
												mem_vec_1302 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1303);
												mem_vec_1303 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1304);
												mem_vec_1304 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1305);
												mem_vec_1305 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1306);
												mem_vec_1306 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1307);
												mem_vec_1307 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1308);
												mem_vec_1308 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1309);
												mem_vec_1309 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1310);
												mem_vec_1310 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1311);
												mem_vec_1311 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1299);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1301);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1302);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1303);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1307);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1308);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1309);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1310);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1311);
								}
							}
						}
					}
				}
			}
		}
		for (y141 = y142 + 192, y141_p_0 = 0;
			y141 < y142 + 192 + 80;
			y141 += 80, y141_p_0 += 80){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x156 = x157, x156_p_1 = x157_p_0, x156_p_0 = 0;
				x156 < x157 + 272;
				x156 += 1, x156_p_1 += 1, x156_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f75, fp_0 = 0;
					f < f75 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 1) (32 / 32)
					for (c117 = c118, c117_p_0 = 0;
						c117 < c118 + 32;
						c117 += 32, c117_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y141, yp_1 = y141_p_0, yp_0 = 0;
							y < y141 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x156, xp_2 = x156_p_1, xp_1 = x156_p_0, xp_0 = 0;
								x < x156 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w72, wp_0 = 0;
									w < w72 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1312 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1313 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1314 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1315 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1328 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1329 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1330 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1331 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c117, cp_1 = c117_p_0, cp_0 = 0;
												c < c117 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1312);
												mem_vec_1312 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1313);
												mem_vec_1313 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1314);
												mem_vec_1314 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1315);
												mem_vec_1315 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1316);
												mem_vec_1316 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1317);
												mem_vec_1317 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1318);
												mem_vec_1318 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1319);
												mem_vec_1319 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1320);
												mem_vec_1320 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1321);
												mem_vec_1321 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1322);
												mem_vec_1322 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1323);
												mem_vec_1323 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1324);
												mem_vec_1324 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1325);
												mem_vec_1325 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1326);
												mem_vec_1326 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1327);
												mem_vec_1327 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1328);
												mem_vec_1328 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1329);
												mem_vec_1329 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1330);
												mem_vec_1330 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1331);
												mem_vec_1331 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1312);
												mem_vec_1312 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1313);
												mem_vec_1313 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1314);
												mem_vec_1314 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1315);
												mem_vec_1315 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1316);
												mem_vec_1316 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1317);
												mem_vec_1317 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1318);
												mem_vec_1318 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1319);
												mem_vec_1319 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1320);
												mem_vec_1320 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1321);
												mem_vec_1321 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1322);
												mem_vec_1322 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1323);
												mem_vec_1323 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1324);
												mem_vec_1324 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1325);
												mem_vec_1325 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1326);
												mem_vec_1326 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1327);
												mem_vec_1327 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1328);
												mem_vec_1328 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1329);
												mem_vec_1329 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1330);
												mem_vec_1330 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1331);
												mem_vec_1331 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1312);
												mem_vec_1312 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1313);
												mem_vec_1313 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1314);
												mem_vec_1314 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1315);
												mem_vec_1315 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1316);
												mem_vec_1316 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1317);
												mem_vec_1317 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1318);
												mem_vec_1318 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1319);
												mem_vec_1319 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1320);
												mem_vec_1320 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1321);
												mem_vec_1321 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1322);
												mem_vec_1322 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1323);
												mem_vec_1323 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1324);
												mem_vec_1324 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1325);
												mem_vec_1325 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1326);
												mem_vec_1326 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1327);
												mem_vec_1327 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1328);
												mem_vec_1328 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1329);
												mem_vec_1329 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1330);
												mem_vec_1330 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1331);
												mem_vec_1331 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1312);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1313);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1314);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1315);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1316);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1317);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1318);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1319);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1320);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1321);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1322);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1323);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1324);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1325);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1326);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1327);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1328);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1329);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1330);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1331);
								}
							}
						}
					}
				}
			}
		}
}


}