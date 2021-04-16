#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (14, x); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (8, c); T (8, f); T (1, c)]
*/
IND_TYPE c, cp_0, c156_p_0, c157_p_0, cp_1, c156_p_1, cp_2, c156, c157, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y78 = 0;
IND_TYPE x78 = 0;
IND_TYPE h = 0;
IND_TYPE w61 = 0;
IND_TYPE c158 = 0;
IND_TYPE f78 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c157 = c158, c157_p_0 = 0;
	c157 < c158 + 128;
	c157 += 128, c157_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f = f78, fp_0 = 0;
		f < f78 + 256;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
		// T (c, 8) (128 / 16)
		for (c156 = c157, c156_p_1 = c157_p_0, c156_p_0 = 0;
			c156 < c157 + 128;
			c156 += 16, c156_p_1 += 16, c156_p_0 += 16){
				for (y = y78, yp_0 = 0;
					y < y78 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x = x78, xp_0 = 0;
						x < x78 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w61, wp_0 = 0;
							w < w61 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1208 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1209 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1210 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1211 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c156, cp_2 = c156_p_1, cp_1 = c156_p_0, cp_0 = 0;
										c < c156 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1208);
										mem_vec_1208 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1209);
										mem_vec_1209 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1210);
										mem_vec_1210 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1211);
										mem_vec_1211 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1212);
										mem_vec_1212 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1213);
										mem_vec_1213 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1214);
										mem_vec_1214 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1215);
										mem_vec_1215 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1216);
										mem_vec_1216 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1217);
										mem_vec_1217 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1218);
										mem_vec_1218 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1219);
										mem_vec_1219 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1220);
										mem_vec_1220 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1221);
										mem_vec_1221 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1222);
										mem_vec_1222 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1223);
										mem_vec_1223 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1208);
										mem_vec_1208 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1209);
										mem_vec_1209 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1210);
										mem_vec_1210 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1211);
										mem_vec_1211 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1212);
										mem_vec_1212 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1213);
										mem_vec_1213 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1214);
										mem_vec_1214 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1215);
										mem_vec_1215 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1216);
										mem_vec_1216 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1217);
										mem_vec_1217 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1218);
										mem_vec_1218 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1219);
										mem_vec_1219 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1220);
										mem_vec_1220 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1221);
										mem_vec_1221 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1222);
										mem_vec_1222 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1223);
										mem_vec_1223 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1208);
										mem_vec_1208 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1209);
										mem_vec_1209 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1210);
										mem_vec_1210 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1211);
										mem_vec_1211 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1212);
										mem_vec_1212 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1213);
										mem_vec_1213 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1214);
										mem_vec_1214 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1215);
										mem_vec_1215 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1216);
										mem_vec_1216 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1217);
										mem_vec_1217 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1218);
										mem_vec_1218 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1219);
										mem_vec_1219 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1220);
										mem_vec_1220 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1221);
										mem_vec_1221 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1222);
										mem_vec_1222 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1223);
										mem_vec_1223 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1208);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1209);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1210);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1211);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1212);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1213);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1214);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1215);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1216);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1217);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1218);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1219);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1220);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1221);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1222);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1223);
						}
					}
				}
				for (y = y78 + 4, yp_0 = 0;
					y < y78 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x = x78, xp_0 = 0;
						x < x78 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w61, wp_0 = 0;
							w < w61 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c156, cp_2 = c156_p_1, cp_1 = c156_p_0, cp_0 = 0;
										c < c156 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1224);
										mem_vec_1224 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1225);
										mem_vec_1225 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1226);
										mem_vec_1226 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1227);
										mem_vec_1227 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1228);
										mem_vec_1228 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1229);
										mem_vec_1229 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1230);
										mem_vec_1230 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1231);
										mem_vec_1231 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1232);
										mem_vec_1232 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1233);
										mem_vec_1233 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1234);
										mem_vec_1234 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1235);
										mem_vec_1235 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1236);
										mem_vec_1236 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1237);
										mem_vec_1237 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1238);
										mem_vec_1238 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1239);
										mem_vec_1239 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1240);
										mem_vec_1240 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1241);
										mem_vec_1241 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1242);
										mem_vec_1242 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1243);
										mem_vec_1243 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_30 = _mm256_set1_ps(scal_5);
										vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1224);
										mem_vec_1224 = vec_29;

										vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1225);
										mem_vec_1225 = vec_32;

										vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1226);
										mem_vec_1226 = vec_34;

										vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1227);
										mem_vec_1227 = vec_36;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1228);
										mem_vec_1228 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1229);
										mem_vec_1229 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1230);
										mem_vec_1230 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1231);
										mem_vec_1231 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1232);
										mem_vec_1232 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1233);
										mem_vec_1233 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1234);
										mem_vec_1234 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1235);
										mem_vec_1235 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1236);
										mem_vec_1236 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1237);
										mem_vec_1237 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1238);
										mem_vec_1238 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1239);
										mem_vec_1239 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1240);
										mem_vec_1240 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1241);
										mem_vec_1241 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1242);
										mem_vec_1242 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1243);
										mem_vec_1243 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_59 = _mm256_set1_ps(scal_10);
										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1224);
										mem_vec_1224 = vec_58;

										vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1225);
										mem_vec_1225 = vec_61;

										vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1226);
										mem_vec_1226 = vec_63;

										vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1227);
										mem_vec_1227 = vec_65;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1228);
										mem_vec_1228 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1229);
										mem_vec_1229 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1230);
										mem_vec_1230 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1231);
										mem_vec_1231 = vec_71;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_73 = _mm256_set1_ps(scal_12);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1232);
										mem_vec_1232 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1233);
										mem_vec_1233 = vec_74;



										vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1234);
										mem_vec_1234 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1235);
										mem_vec_1235 = vec_76;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_78 = _mm256_set1_ps(scal_13);


										vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1236);
										mem_vec_1236 = vec_77;



										vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1237);
										mem_vec_1237 = vec_79;



										vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1238);
										mem_vec_1238 = vec_80;



										vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1239);
										mem_vec_1239 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_83 = _mm256_set1_ps(scal_14);


										vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1240);
										mem_vec_1240 = vec_82;



										vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1241);
										mem_vec_1241 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1242);
										mem_vec_1242 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1243);
										mem_vec_1243 = vec_86;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1224);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1225);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1226);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1227);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1228);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1229);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1230);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1231);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1232);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1233);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1234);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1235);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1236);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1237);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1238);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1239);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1240);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1241);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1242);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1243);
						}
					}
				}
		}
	}
}


}