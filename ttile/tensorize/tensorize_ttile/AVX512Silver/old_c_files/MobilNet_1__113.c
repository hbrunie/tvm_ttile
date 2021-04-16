#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (112, x); T (1, y); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 7), (Arg 15))]]
*/
IND_TYPE c, cp_0, c222_p_0, cp_1, c222, w, wp_0, x, xp_0, y, yp_0, y183_p_0, yp_1, y183;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y184 = 0;
IND_TYPE x226 = 0;
IND_TYPE h = 0;
IND_TYPE w97 = 0;
IND_TYPE c223 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,mem_vec_1312 ,mem_vec_1313 ,mem_vec_1314 ,mem_vec_1315 ,mem_vec_1316 ,mem_vec_1317 ,mem_vec_1318 ,mem_vec_1319 ,mem_vec_1320 ,mem_vec_1321 ,mem_vec_1322 ,mem_vec_1323 ,mem_vec_1324 ,mem_vec_1325 ,mem_vec_1326 ,mem_vec_1327 ,mem_vec_1328 ,mem_vec_1329 ,mem_vec_1330 ,mem_vec_1331 ,mem_vec_1332 ,mem_vec_1333 ,mem_vec_1334 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y183 = y184, y183_p_0 = 0;
		y183 < y184 + 7;
		y183 += 7, y183_p_0 += 7){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c222 = c223, c222_p_0 = 0;
			c222 < c223 + 32;
			c222 += 32, c222_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y183, yp_1 = y183_p_0, yp_0 = 0;
				y < y183 + 7;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x226, xp_0 = 0;
					x < x226 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w97, wp_0 = 0;
						w < w97 + 3;
						w += 1, wp_0 += 1){
								mem_vec_1291 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1292 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
									c < c222 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1291);
									mem_vec_1291 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1292);
									mem_vec_1292 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1293);
									mem_vec_1293 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1294);
									mem_vec_1294 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1295);
									mem_vec_1295 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1296);
									mem_vec_1296 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1297);
									mem_vec_1297 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1298);
									mem_vec_1298 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1299);
									mem_vec_1299 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1300);
									mem_vec_1300 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1301);
									mem_vec_1301 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1302);
									mem_vec_1302 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1303);
									mem_vec_1303 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1304);
									mem_vec_1304 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_1291);
									mem_vec_1291 = vec_23;

									vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_1292);
									mem_vec_1292 = vec_26;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_29 = _mm512_set1_ps(scal_8);


									vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_1293);
									mem_vec_1293 = vec_28;



									vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_1294);
									mem_vec_1294 = vec_30;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_32 = _mm512_set1_ps(scal_9);


									vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_1295);
									mem_vec_1295 = vec_31;



									vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_1296);
									mem_vec_1296 = vec_33;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_10);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_1297);
									mem_vec_1297 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_1298);
									mem_vec_1298 = vec_36;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_1299);
									mem_vec_1299 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_1300);
									mem_vec_1300 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_1301);
									mem_vec_1301 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_1302);
									mem_vec_1302 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_1303);
									mem_vec_1303 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_1304);
									mem_vec_1304 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_47 = _mm512_set1_ps(scal_14);
									vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_1291);
									mem_vec_1291 = vec_46;

									vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_1292);
									mem_vec_1292 = vec_49;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_52 = _mm512_set1_ps(scal_15);


									vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_1293);
									mem_vec_1293 = vec_51;



									vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_1294);
									mem_vec_1294 = vec_53;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_55 = _mm512_set1_ps(scal_16);


									vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_1295);
									mem_vec_1295 = vec_54;



									vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_1296);
									mem_vec_1296 = vec_56;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_58 = _mm512_set1_ps(scal_17);


									vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_1297);
									mem_vec_1297 = vec_57;



									vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_1298);
									mem_vec_1298 = vec_59;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_61 = _mm512_set1_ps(scal_18);


									vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_1299);
									mem_vec_1299 = vec_60;



									vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_1300);
									mem_vec_1300 = vec_62;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_19);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_1301);
									mem_vec_1301 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_1302);
									mem_vec_1302 = vec_65;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_67 = _mm512_set1_ps(scal_20);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_1303);
									mem_vec_1303 = vec_66;



									vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_1304);
									mem_vec_1304 = vec_68;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1291);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1292);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1293);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1294);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1295);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1296);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1297);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1298);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1299);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1300);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1301);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1302);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1303);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1304);
					}
				}
			}
		}
	}
	for (y183 = y184 + 7, y183_p_0 = 0;
		y183 < y184 + 7 + 105;
		y183 += 15, y183_p_0 += 15){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c222 = c223, c222_p_0 = 0;
			c222 < c223 + 32;
			c222 += 32, c222_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y183, yp_1 = y183_p_0, yp_0 = 0;
				y < y183 + 15;
				y += 15, yp_1 += 15, yp_0 += 15){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x226, xp_0 = 0;
					x < x226 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w97, wp_0 = 0;
						w < w97 + 3;
						w += 1, wp_0 += 1){
								mem_vec_1305 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1306 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_1320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_1321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_1322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_1323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_1324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_1325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_1326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_1327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_1328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_1329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_1330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								mem_vec_1331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								mem_vec_1332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
								mem_vec_1333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
								mem_vec_1334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
									c < c222 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1305);
									mem_vec_1305 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1306);
									mem_vec_1306 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1307);
									mem_vec_1307 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1308);
									mem_vec_1308 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1309);
									mem_vec_1309 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1310);
									mem_vec_1310 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1311);
									mem_vec_1311 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1312);
									mem_vec_1312 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1313);
									mem_vec_1313 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1314);
									mem_vec_1314 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1315);
									mem_vec_1315 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1316);
									mem_vec_1316 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1317);
									mem_vec_1317 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1318);
									mem_vec_1318 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1319);
									mem_vec_1319 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1320);
									mem_vec_1320 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1321);
									mem_vec_1321 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1322);
									mem_vec_1322 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1323);
									mem_vec_1323 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1324);
									mem_vec_1324 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1325);
									mem_vec_1325 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1326);
									mem_vec_1326 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1327);
									mem_vec_1327 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1328);
									mem_vec_1328 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1329);
									mem_vec_1329 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1330);
									mem_vec_1330 = vec_40;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1331);
									mem_vec_1331 = vec_41;



									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1332);
									mem_vec_1332 = vec_43;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
									vec_45 = _mm512_set1_ps(scal_14);


									vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_1333);
									mem_vec_1333 = vec_44;



									vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_1334);
									mem_vec_1334 = vec_46;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_48 = _mm512_set1_ps(scal_15);
									vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_47 = _mm512_fmadd_ps(vec_48, vec_49, mem_vec_1305);
									mem_vec_1305 = vec_47;

									vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_50 = _mm512_fmadd_ps(vec_48, vec_51, mem_vec_1306);
									mem_vec_1306 = vec_50;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_1307);
									mem_vec_1307 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_1308);
									mem_vec_1308 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_49, mem_vec_1309);
									mem_vec_1309 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_51, mem_vec_1310);
									mem_vec_1310 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_49, mem_vec_1311);
									mem_vec_1311 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_51, mem_vec_1312);
									mem_vec_1312 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_1313);
									mem_vec_1313 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_1314);
									mem_vec_1314 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_65 = _mm512_set1_ps(scal_20);


									vec_64 = _mm512_fmadd_ps(vec_65, vec_49, mem_vec_1315);
									mem_vec_1315 = vec_64;



									vec_66 = _mm512_fmadd_ps(vec_65, vec_51, mem_vec_1316);
									mem_vec_1316 = vec_66;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_68 = _mm512_set1_ps(scal_21);


									vec_67 = _mm512_fmadd_ps(vec_68, vec_49, mem_vec_1317);
									mem_vec_1317 = vec_67;



									vec_69 = _mm512_fmadd_ps(vec_68, vec_51, mem_vec_1318);
									mem_vec_1318 = vec_69;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_71 = _mm512_set1_ps(scal_22);


									vec_70 = _mm512_fmadd_ps(vec_71, vec_49, mem_vec_1319);
									mem_vec_1319 = vec_70;



									vec_72 = _mm512_fmadd_ps(vec_71, vec_51, mem_vec_1320);
									mem_vec_1320 = vec_72;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_74 = _mm512_set1_ps(scal_23);


									vec_73 = _mm512_fmadd_ps(vec_74, vec_49, mem_vec_1321);
									mem_vec_1321 = vec_73;



									vec_75 = _mm512_fmadd_ps(vec_74, vec_51, mem_vec_1322);
									mem_vec_1322 = vec_75;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
									vec_77 = _mm512_set1_ps(scal_24);


									vec_76 = _mm512_fmadd_ps(vec_77, vec_49, mem_vec_1323);
									mem_vec_1323 = vec_76;



									vec_78 = _mm512_fmadd_ps(vec_77, vec_51, mem_vec_1324);
									mem_vec_1324 = vec_78;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
									vec_80 = _mm512_set1_ps(scal_25);


									vec_79 = _mm512_fmadd_ps(vec_80, vec_49, mem_vec_1325);
									mem_vec_1325 = vec_79;



									vec_81 = _mm512_fmadd_ps(vec_80, vec_51, mem_vec_1326);
									mem_vec_1326 = vec_81;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
									vec_83 = _mm512_set1_ps(scal_26);


									vec_82 = _mm512_fmadd_ps(vec_83, vec_49, mem_vec_1327);
									mem_vec_1327 = vec_82;



									vec_84 = _mm512_fmadd_ps(vec_83, vec_51, mem_vec_1328);
									mem_vec_1328 = vec_84;
									scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
									vec_86 = _mm512_set1_ps(scal_27);


									vec_85 = _mm512_fmadd_ps(vec_86, vec_49, mem_vec_1329);
									mem_vec_1329 = vec_85;



									vec_87 = _mm512_fmadd_ps(vec_86, vec_51, mem_vec_1330);
									mem_vec_1330 = vec_87;
									scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
									vec_89 = _mm512_set1_ps(scal_28);


									vec_88 = _mm512_fmadd_ps(vec_89, vec_49, mem_vec_1331);
									mem_vec_1331 = vec_88;



									vec_90 = _mm512_fmadd_ps(vec_89, vec_51, mem_vec_1332);
									mem_vec_1332 = vec_90;
									scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 1) + c];
									vec_92 = _mm512_set1_ps(scal_29);


									vec_91 = _mm512_fmadd_ps(vec_92, vec_49, mem_vec_1333);
									mem_vec_1333 = vec_91;



									vec_93 = _mm512_fmadd_ps(vec_92, vec_51, mem_vec_1334);
									mem_vec_1334 = vec_93;
									scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_95 = _mm512_set1_ps(scal_30);
									vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_94 = _mm512_fmadd_ps(vec_95, vec_96, mem_vec_1305);
									mem_vec_1305 = vec_94;

									vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_97 = _mm512_fmadd_ps(vec_95, vec_98, mem_vec_1306);
									mem_vec_1306 = vec_97;
									scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_100 = _mm512_set1_ps(scal_31);


									vec_99 = _mm512_fmadd_ps(vec_100, vec_96, mem_vec_1307);
									mem_vec_1307 = vec_99;



									vec_101 = _mm512_fmadd_ps(vec_100, vec_98, mem_vec_1308);
									mem_vec_1308 = vec_101;
									scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_103 = _mm512_set1_ps(scal_32);


									vec_102 = _mm512_fmadd_ps(vec_103, vec_96, mem_vec_1309);
									mem_vec_1309 = vec_102;



									vec_104 = _mm512_fmadd_ps(vec_103, vec_98, mem_vec_1310);
									mem_vec_1310 = vec_104;
									scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_106 = _mm512_set1_ps(scal_33);


									vec_105 = _mm512_fmadd_ps(vec_106, vec_96, mem_vec_1311);
									mem_vec_1311 = vec_105;



									vec_107 = _mm512_fmadd_ps(vec_106, vec_98, mem_vec_1312);
									mem_vec_1312 = vec_107;
									scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_109 = _mm512_set1_ps(scal_34);


									vec_108 = _mm512_fmadd_ps(vec_109, vec_96, mem_vec_1313);
									mem_vec_1313 = vec_108;



									vec_110 = _mm512_fmadd_ps(vec_109, vec_98, mem_vec_1314);
									mem_vec_1314 = vec_110;
									scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_112 = _mm512_set1_ps(scal_35);


									vec_111 = _mm512_fmadd_ps(vec_112, vec_96, mem_vec_1315);
									mem_vec_1315 = vec_111;



									vec_113 = _mm512_fmadd_ps(vec_112, vec_98, mem_vec_1316);
									mem_vec_1316 = vec_113;
									scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_115 = _mm512_set1_ps(scal_36);


									vec_114 = _mm512_fmadd_ps(vec_115, vec_96, mem_vec_1317);
									mem_vec_1317 = vec_114;



									vec_116 = _mm512_fmadd_ps(vec_115, vec_98, mem_vec_1318);
									mem_vec_1318 = vec_116;
									scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_118 = _mm512_set1_ps(scal_37);


									vec_117 = _mm512_fmadd_ps(vec_118, vec_96, mem_vec_1319);
									mem_vec_1319 = vec_117;



									vec_119 = _mm512_fmadd_ps(vec_118, vec_98, mem_vec_1320);
									mem_vec_1320 = vec_119;
									scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_121 = _mm512_set1_ps(scal_38);


									vec_120 = _mm512_fmadd_ps(vec_121, vec_96, mem_vec_1321);
									mem_vec_1321 = vec_120;



									vec_122 = _mm512_fmadd_ps(vec_121, vec_98, mem_vec_1322);
									mem_vec_1322 = vec_122;
									scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
									vec_124 = _mm512_set1_ps(scal_39);


									vec_123 = _mm512_fmadd_ps(vec_124, vec_96, mem_vec_1323);
									mem_vec_1323 = vec_123;



									vec_125 = _mm512_fmadd_ps(vec_124, vec_98, mem_vec_1324);
									mem_vec_1324 = vec_125;
									scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
									vec_127 = _mm512_set1_ps(scal_40);


									vec_126 = _mm512_fmadd_ps(vec_127, vec_96, mem_vec_1325);
									mem_vec_1325 = vec_126;



									vec_128 = _mm512_fmadd_ps(vec_127, vec_98, mem_vec_1326);
									mem_vec_1326 = vec_128;
									scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
									vec_130 = _mm512_set1_ps(scal_41);


									vec_129 = _mm512_fmadd_ps(vec_130, vec_96, mem_vec_1327);
									mem_vec_1327 = vec_129;



									vec_131 = _mm512_fmadd_ps(vec_130, vec_98, mem_vec_1328);
									mem_vec_1328 = vec_131;
									scal_42 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
									vec_133 = _mm512_set1_ps(scal_42);


									vec_132 = _mm512_fmadd_ps(vec_133, vec_96, mem_vec_1329);
									mem_vec_1329 = vec_132;



									vec_134 = _mm512_fmadd_ps(vec_133, vec_98, mem_vec_1330);
									mem_vec_1330 = vec_134;
									scal_43 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
									vec_136 = _mm512_set1_ps(scal_43);


									vec_135 = _mm512_fmadd_ps(vec_136, vec_96, mem_vec_1331);
									mem_vec_1331 = vec_135;



									vec_137 = _mm512_fmadd_ps(vec_136, vec_98, mem_vec_1332);
									mem_vec_1332 = vec_137;
									scal_44 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 2) + c];
									vec_139 = _mm512_set1_ps(scal_44);


									vec_138 = _mm512_fmadd_ps(vec_139, vec_96, mem_vec_1333);
									mem_vec_1333 = vec_138;



									vec_140 = _mm512_fmadd_ps(vec_139, vec_98, mem_vec_1334);
									mem_vec_1334 = vec_140;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1305);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1306);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1307);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1308);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1309);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1310);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1311);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1312);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1313);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1314);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1315);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1316);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1317);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1318);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1319);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1320);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1321);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1322);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1323);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1324);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1325);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1326);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1327);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1328);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1329);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1330);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1331);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1332);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_1333);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_1334);
					}
				}
			}
		}
	}


}