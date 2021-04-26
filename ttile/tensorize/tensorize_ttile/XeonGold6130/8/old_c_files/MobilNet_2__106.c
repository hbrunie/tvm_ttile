#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (1, c); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (1, x)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, h, hp_0, x, xp_0, x152_p_0, x153_p_0, xp_1, x152_p_1, xp_2, x152, x153, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y84 = 0;
IND_TYPE x154 = 0;
IND_TYPE h70 = 0;
IND_TYPE w = 0;
IND_TYPE c121 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,mem_vec_1284 ,mem_vec_1285 ,mem_vec_1286 ,mem_vec_1287 ,mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x153 = x154, x153_p_0 = 0;
	x153 < x154 + 56;
	x153 += 56, x153_p_0 += 56){
		for (y = y84, yp_0 = 0;
			y < y84 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 2) (56 / 28)
			for (x152 = x153, x152_p_1 = x153_p_0, x152_p_0 = 0;
				x152 < x153 + 56;
				x152 += 28, x152_p_1 += 28, x152_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c120 = c121, c120_p_0 = 0;
					c120 < c121 + 64;
					c120 += 64, c120_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
					// T (h, 3) (3 / 1)
					for (h = h70, hp_0 = 0;
						h < h70 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 64
						// T (x, 28) (28 / 1)
						for (x = x152, xp_2 = x152_p_1, xp_1 = x152_p_0, xp_0 = 0;
							x < x152 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1260 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1261 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_1271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_1272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_1275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_1276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_1279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_1280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_1283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1260);
										mem_vec_1260 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1261);
										mem_vec_1261 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1262);
										mem_vec_1262 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1263);
										mem_vec_1263 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1264);
										mem_vec_1264 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1265);
										mem_vec_1265 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1266);
										mem_vec_1266 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1267);
										mem_vec_1267 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1268);
										mem_vec_1268 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1269);
										mem_vec_1269 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1270);
										mem_vec_1270 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1271);
										mem_vec_1271 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1272);
										mem_vec_1272 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1273);
										mem_vec_1273 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1274);
										mem_vec_1274 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1275);
										mem_vec_1275 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1276);
										mem_vec_1276 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1277);
										mem_vec_1277 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1278);
										mem_vec_1278 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1279);
										mem_vec_1279 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1280);
										mem_vec_1280 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1281);
										mem_vec_1281 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1282);
										mem_vec_1282 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1283);
										mem_vec_1283 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_1260);
										mem_vec_1260 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_1261);
										mem_vec_1261 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_1262);
										mem_vec_1262 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_1263);
										mem_vec_1263 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1264);
										mem_vec_1264 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1265);
										mem_vec_1265 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1266);
										mem_vec_1266 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1267);
										mem_vec_1267 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_1268);
										mem_vec_1268 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_1269);
										mem_vec_1269 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_1270);
										mem_vec_1270 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_1271);
										mem_vec_1271 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_1272);
										mem_vec_1272 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_1273);
										mem_vec_1273 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_1274);
										mem_vec_1274 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_1275);
										mem_vec_1275 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_1276);
										mem_vec_1276 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_1277);
										mem_vec_1277 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_1278);
										mem_vec_1278 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_1279);
										mem_vec_1279 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_1280);
										mem_vec_1280 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_1281);
										mem_vec_1281 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_1282);
										mem_vec_1282 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_1283);
										mem_vec_1283 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_1260);
										mem_vec_1260 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_1261);
										mem_vec_1261 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_1262);
										mem_vec_1262 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_1263);
										mem_vec_1263 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_1264);
										mem_vec_1264 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_1265);
										mem_vec_1265 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_1266);
										mem_vec_1266 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_1267);
										mem_vec_1267 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_1268);
										mem_vec_1268 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_1269);
										mem_vec_1269 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_1270);
										mem_vec_1270 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_1271);
										mem_vec_1271 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_1272);
										mem_vec_1272 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_1273);
										mem_vec_1273 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_1274);
										mem_vec_1274 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_1275);
										mem_vec_1275 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_1276);
										mem_vec_1276 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_1277);
										mem_vec_1277 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_1278);
										mem_vec_1278 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_1279);
										mem_vec_1279 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_1280);
										mem_vec_1280 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_1281);
										mem_vec_1281 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_1282);
										mem_vec_1282 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_1283);
										mem_vec_1283 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1283);
						}
					}
				}
			}
		}
		for (y = y84 + 42, yp_0 = 0;
			y < y84 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 2) (56 / 28)
			for (x152 = x153, x152_p_1 = x153_p_0, x152_p_0 = 0;
				x152 < x153 + 56;
				x152 += 28, x152_p_1 += 28, x152_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c120 = c121, c120_p_0 = 0;
					c120 < c121 + 64;
					c120 += 64, c120_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
					// T (h, 3) (3 / 1)
					for (h = h70, hp_0 = 0;
						h < h70 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 64
						// T (x, 28) (28 / 1)
						for (x = x152, xp_2 = x152_p_1, xp_1 = x152_p_0, xp_0 = 0;
							x < x152 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1284 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1285 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1286 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1287 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_1295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_1296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_1299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_1300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_1303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_1304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_1307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_1308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_1311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1284);
										mem_vec_1284 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1285);
										mem_vec_1285 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1286);
										mem_vec_1286 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1287);
										mem_vec_1287 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1288);
										mem_vec_1288 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1289);
										mem_vec_1289 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1290);
										mem_vec_1290 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1291);
										mem_vec_1291 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1292);
										mem_vec_1292 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1293);
										mem_vec_1293 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1294);
										mem_vec_1294 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1295);
										mem_vec_1295 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1296);
										mem_vec_1296 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1297);
										mem_vec_1297 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1298);
										mem_vec_1298 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1299);
										mem_vec_1299 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1300);
										mem_vec_1300 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1301);
										mem_vec_1301 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1302);
										mem_vec_1302 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1303);
										mem_vec_1303 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1304);
										mem_vec_1304 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1305);
										mem_vec_1305 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1306);
										mem_vec_1306 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1307);
										mem_vec_1307 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1308);
										mem_vec_1308 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1309);
										mem_vec_1309 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1310);
										mem_vec_1310 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1311);
										mem_vec_1311 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_1284);
										mem_vec_1284 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_1285);
										mem_vec_1285 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_1286);
										mem_vec_1286 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_1287);
										mem_vec_1287 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_1288);
										mem_vec_1288 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_1289);
										mem_vec_1289 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_1290);
										mem_vec_1290 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_1291);
										mem_vec_1291 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_1292);
										mem_vec_1292 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_1293);
										mem_vec_1293 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_1294);
										mem_vec_1294 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_1295);
										mem_vec_1295 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_1296);
										mem_vec_1296 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_1297);
										mem_vec_1297 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_1298);
										mem_vec_1298 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_1299);
										mem_vec_1299 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_1300);
										mem_vec_1300 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_1301);
										mem_vec_1301 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_1302);
										mem_vec_1302 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_1303);
										mem_vec_1303 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_1304);
										mem_vec_1304 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_1305);
										mem_vec_1305 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_1306);
										mem_vec_1306 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_1307);
										mem_vec_1307 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_1308);
										mem_vec_1308 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_1309);
										mem_vec_1309 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_1310);
										mem_vec_1310 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_1311);
										mem_vec_1311 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_1284);
										mem_vec_1284 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_1285);
										mem_vec_1285 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_1286);
										mem_vec_1286 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_1287);
										mem_vec_1287 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_1288);
										mem_vec_1288 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_1289);
										mem_vec_1289 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_1290);
										mem_vec_1290 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_1291);
										mem_vec_1291 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_1292);
										mem_vec_1292 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_1293);
										mem_vec_1293 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_1294);
										mem_vec_1294 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_1295);
										mem_vec_1295 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_1296);
										mem_vec_1296 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_1297);
										mem_vec_1297 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_1298);
										mem_vec_1298 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_1299);
										mem_vec_1299 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_1300);
										mem_vec_1300 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_1301);
										mem_vec_1301 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_1302);
										mem_vec_1302 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_1303);
										mem_vec_1303 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_1304);
										mem_vec_1304 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_1305);
										mem_vec_1305 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_1306);
										mem_vec_1306 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_1307);
										mem_vec_1307 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_1308);
										mem_vec_1308 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_1309);
										mem_vec_1309 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_1310);
										mem_vec_1310 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_1311);
										mem_vec_1311 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1285);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1287);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1305);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1306);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1307);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1308);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1309);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1310);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1311);
						}
					}
				}
			}
		}
}


}