#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (4, c); T (4, f); T (7, x); T (7, y); T (4, c)]
*/
IND_TYPE c, cp_0, c298_p_0, c299_p_0, cp_1, c298_p_1, cp_2, c298, c299, f, fp_0, h, hp_0, x, xp_0, x232_p_0, xp_1, x232, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y156 = 0;
IND_TYPE x233 = 0;
IND_TYPE h136 = 0;
IND_TYPE w = 0;
IND_TYPE c300 = 0;
IND_TYPE f242 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1250 ,mem_vec_1251 ,mem_vec_1252 ,mem_vec_1253 ,mem_vec_1254 ,mem_vec_1255 ,mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 4) (512 / 128)
for (c299 = c300, c299_p_0 = 0;
	c299 < c300 + 512;
	c299 += 128, c299_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 512
	// T (y, 7) (14 / 2)
	for (y = y156, yp_0 = 0;
		y < y156 + 14;
		y += 2, yp_0 += 2){
		// y = 2, x = 14, h = 3, w = 3, c = 128, f = 512
		// T (x, 7) (14 / 2)
		for (x232 = x233, x232_p_0 = 0;
			x232 < x233 + 14;
			x232 += 2, x232_p_0 += 2){
			// y = 2, x = 2, h = 3, w = 3, c = 128, f = 512
			// T (f, 4) (512 / 128)
			for (f = f242, fp_0 = 0;
				f < f242 + 512;
				f += 128, fp_0 += 128){
				// y = 2, x = 2, h = 3, w = 3, c = 128, f = 128
				// T (c, 4) (128 / 32)
				for (c298 = c299, c298_p_1 = c299_p_0, c298_p_0 = 0;
					c298 < c299 + 128;
					c298 += 32, c298_p_1 += 32, c298_p_0 += 32){
					// y = 2, x = 2, h = 3, w = 3, c = 32, f = 128
					// T (h, 3) (3 / 1)
					for (h = h136, hp_0 = 0;
						h < h136 + 3;
						h += 1, hp_0 += 1){
						// y = 2, x = 2, h = 1, w = 3, c = 32, f = 128
						// T (x, 2) (2 / 1)
						for (x = x232, xp_1 = x232_p_0, xp_0 = 0;
							x < x232 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1250 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1251 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
									mem_vec_1255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
									mem_vec_1256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
									mem_vec_1257 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
									mem_vec_1258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
									mem_vec_1263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
									mem_vec_1264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
									mem_vec_1265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
									// y = 2, x = 1, h = 1, w = 3, c = 32, f = 128
									// T (c, 32) (32 / 1)
									for (c = c298, cp_2 = c298_p_1, cp_1 = c298_p_0, cp_0 = 0;
										c < c298 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1250);
										mem_vec_1250 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1251);
										mem_vec_1251 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1252);
										mem_vec_1252 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1253);
										mem_vec_1253 = vec_7;

										vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

										vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_1254);
										mem_vec_1254 = vec_9;

										vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

										vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_1255);
										mem_vec_1255 = vec_11;

										vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

										vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_1256);
										mem_vec_1256 = vec_13;

										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

										vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_1257);
										mem_vec_1257 = vec_15;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_18 = _mm512_set1_ps(scal_1);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1258);
										mem_vec_1258 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1259);
										mem_vec_1259 = vec_19;



										vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_1260);
										mem_vec_1260 = vec_20;



										vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_1261);
										mem_vec_1261 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_1262);
										mem_vec_1262 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_1263);
										mem_vec_1263 = vec_23;



										vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_1264);
										mem_vec_1264 = vec_24;



										vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_1265);
										mem_vec_1265 = vec_25;
										scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_2);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1250);
										mem_vec_1250 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_1251);
										mem_vec_1251 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_1252);
										mem_vec_1252 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_1253);
										mem_vec_1253 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

										vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_1254);
										mem_vec_1254 = vec_35;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

										vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_1255);
										mem_vec_1255 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

										vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_1256);
										mem_vec_1256 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

										vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_1257);
										mem_vec_1257 = vec_41;
										scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_44 = _mm512_set1_ps(scal_3);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1258);
										mem_vec_1258 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1259);
										mem_vec_1259 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1260);
										mem_vec_1260 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_1261);
										mem_vec_1261 = vec_47;



										vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1262);
										mem_vec_1262 = vec_48;



										vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1263);
										mem_vec_1263 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1264);
										mem_vec_1264 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1265);
										mem_vec_1265 = vec_51;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_4);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_1250);
										mem_vec_1250 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_1251);
										mem_vec_1251 = vec_55;

										vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_1252);
										mem_vec_1252 = vec_57;

										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_1253);
										mem_vec_1253 = vec_59;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

										vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_1254);
										mem_vec_1254 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

										vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_1255);
										mem_vec_1255 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

										vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_1256);
										mem_vec_1256 = vec_65;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

										vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_1257);
										mem_vec_1257 = vec_67;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_70 = _mm512_set1_ps(scal_5);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_1258);
										mem_vec_1258 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_1259);
										mem_vec_1259 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_1260);
										mem_vec_1260 = vec_72;



										vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_1261);
										mem_vec_1261 = vec_73;



										vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_1262);
										mem_vec_1262 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_1263);
										mem_vec_1263 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_1264);
										mem_vec_1264 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_1265);
										mem_vec_1265 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_1254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_1255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_1256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_1257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_1262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_1263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_1264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_1265);
						}
					}
				}
			}
		}
	}
}


}