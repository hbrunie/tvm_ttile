#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, c); T (4, f); T (2, x); T (7, y); T (32, c)]
*/
IND_TYPE c, cp_0, c290_p_0, c291_p_0, cp_1, c290_p_1, cp_2, c290, c291, f, fp_0, h, hp_0, x, xp_0, x226_p_0, xp_1, x226, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y152 = 0;
IND_TYPE x227 = 0;
IND_TYPE h132 = 0;
IND_TYPE w = 0;
IND_TYPE c292 = 0;
IND_TYPE f238 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 32) (512 / 16)
for (c291 = c292, c291_p_0 = 0;
	c291 < c292 + 512;
	c291 += 16, c291_p_0 += 16){
	// y = 14, x = 14, h = 3, w = 3, c = 16, f = 512
	// T (y, 7) (14 / 2)
	for (y = y152, yp_0 = 0;
		y < y152 + 14;
		y += 2, yp_0 += 2){
		// y = 2, x = 14, h = 3, w = 3, c = 16, f = 512
		// T (x, 2) (14 / 7)
		for (x226 = x227, x226_p_0 = 0;
			x226 < x227 + 14;
			x226 += 7, x226_p_0 += 7){
			// y = 2, x = 7, h = 3, w = 3, c = 16, f = 512
			// T (f, 4) (512 / 128)
			for (f = f238, fp_0 = 0;
				f < f238 + 512;
				f += 128, fp_0 += 128){
				// y = 2, x = 7, h = 3, w = 3, c = 16, f = 128
				// T (c, 4) (16 / 4)
				for (c290 = c291, c290_p_1 = c291_p_0, c290_p_0 = 0;
					c290 < c291 + 16;
					c290 += 4, c290_p_1 += 4, c290_p_0 += 4){
					// y = 2, x = 7, h = 3, w = 3, c = 4, f = 128
					// T (h, 3) (3 / 1)
					for (h = h132, hp_0 = 0;
						h < h132 + 3;
						h += 1, hp_0 += 1){
						// y = 2, x = 7, h = 1, w = 3, c = 4, f = 128
						// T (x, 7) (7 / 1)
						for (x = x226, xp_1 = x226_p_0, xp_0 = 0;
							x < x226 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1218 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1219 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1220 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1221 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_1223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_1224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_1225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_1226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_1231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_1232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_1233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									// y = 2, x = 1, h = 1, w = 3, c = 4, f = 128
									// T (c, 4) (4 / 1)
									for (c = c290, cp_2 = c290_p_1, cp_1 = c290_p_0, cp_0 = 0;
										c < c290 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1218);
										mem_vec_1218 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1219);
										mem_vec_1219 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1220);
										mem_vec_1220 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1221);
										mem_vec_1221 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_1222);
										mem_vec_1222 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_1223);
										mem_vec_1223 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_1224);
										mem_vec_1224 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_1225);
										mem_vec_1225 = vec_15;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1226);
										mem_vec_1226 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1227);
										mem_vec_1227 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_1228);
										mem_vec_1228 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_1229);
										mem_vec_1229 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_1230);
										mem_vec_1230 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_1231);
										mem_vec_1231 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_1232);
										mem_vec_1232 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_1233);
										mem_vec_1233 = vec_25;
										scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1218);
										mem_vec_1218 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_1219);
										mem_vec_1219 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_1220);
										mem_vec_1220 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_1221);
										mem_vec_1221 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_1222);
										mem_vec_1222 = vec_35;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_1223);
										mem_vec_1223 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_1224);
										mem_vec_1224 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_1225);
										mem_vec_1225 = vec_41;
										scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_44 = _mm512_set1_ps(scal_3);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1226);
										mem_vec_1226 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1227);
										mem_vec_1227 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1228);
										mem_vec_1228 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_1229);
										mem_vec_1229 = vec_47;



										vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1230);
										mem_vec_1230 = vec_48;



										vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1231);
										mem_vec_1231 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1232);
										mem_vec_1232 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1233);
										mem_vec_1233 = vec_51;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_1218);
										mem_vec_1218 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_1219);
										mem_vec_1219 = vec_55;

										vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_1220);
										mem_vec_1220 = vec_57;

										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_1221);
										mem_vec_1221 = vec_59;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_1222);
										mem_vec_1222 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_1223);
										mem_vec_1223 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_1224);
										mem_vec_1224 = vec_65;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_1225);
										mem_vec_1225 = vec_67;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_70 = _mm512_set1_ps(scal_5);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_1226);
										mem_vec_1226 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_1227);
										mem_vec_1227 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_1228);
										mem_vec_1228 = vec_72;



										vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_1229);
										mem_vec_1229 = vec_73;



										vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_1230);
										mem_vec_1230 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_1231);
										mem_vec_1231 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_1232);
										mem_vec_1232 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_1233);
										mem_vec_1233 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1218);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1219);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_1222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_1223);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_1224);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_1225);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1226);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1227);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1228);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1229);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_1230);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_1231);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_1232);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_1233);
						}
					}
				}
			}
		}
	}
}


}