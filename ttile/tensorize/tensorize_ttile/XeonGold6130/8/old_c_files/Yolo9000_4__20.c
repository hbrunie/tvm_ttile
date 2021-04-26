#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (136, x); T (2, y); T (1, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y60_p_0, yp_1, y60;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y61 = 0;
IND_TYPE x120 = 0;
IND_TYPE h = 0;
IND_TYPE w60 = 0;
IND_TYPE c91 = 0;
IND_TYPE f60 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,mem_vec_1244 ,mem_vec_1245 ,mem_vec_1246 ,mem_vec_1247 ,mem_vec_1248 ,mem_vec_1249 ,mem_vec_1250 ,mem_vec_1251 ,mem_vec_1252 ,mem_vec_1253 ,mem_vec_1254 ,mem_vec_1255 ,mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
	for (y60 = y61, y60_p_0 = 0;
		y60 < y61 + 24;
		y60 += 24, y60_p_0 += 24){
		// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
		// T (f, 8) (128 / 16)
		for (f = f60, fp_0 = 0;
			f < f60 + 128;
			f += 16, fp_0 += 16){
			// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
			// T (c, 1) (64 / 64)
			for (c90 = c91, c90_p_0 = 0;
				c90 < c91 + 64;
				c90 += 64, c90_p_0 += 64){
				// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
				// T (y, 2) (2 * ph_y / ph_y)
				for (y = y60, yp_1 = y60_p_0, yp_0 = 0;
					y < y60 + 24;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
					// T (x, 136) (136 / 1)
					for (x = x120, xp_0 = 0;
						x < x120 + 136;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w60, wp_0 = 0;
							w < w60 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1236 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_1245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_1246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_1247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
										c < c90 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1236);
										mem_vec_1236 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1237);
										mem_vec_1237 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1238);
										mem_vec_1238 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1239);
										mem_vec_1239 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1240);
										mem_vec_1240 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1241);
										mem_vec_1241 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1242);
										mem_vec_1242 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1243);
										mem_vec_1243 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1244);
										mem_vec_1244 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1245);
										mem_vec_1245 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_1246);
										mem_vec_1246 = vec_21;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_24 = _mm512_set1_ps(scal_11);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1247);
										mem_vec_1247 = vec_23;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_26 = _mm512_set1_ps(scal_12);
										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_1236);
										mem_vec_1236 = vec_25;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_1237);
										mem_vec_1237 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_1238);
										mem_vec_1238 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_1239);
										mem_vec_1239 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_1240);
										mem_vec_1240 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_1241);
										mem_vec_1241 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_1242);
										mem_vec_1242 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_1243);
										mem_vec_1243 = vec_40;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_1244);
										mem_vec_1244 = vec_42;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_1245);
										mem_vec_1245 = vec_44;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_22);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_1246);
										mem_vec_1246 = vec_46;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_23);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_1247);
										mem_vec_1247 = vec_48;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_51 = _mm512_set1_ps(scal_24);
										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_1236);
										mem_vec_1236 = vec_50;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_1237);
										mem_vec_1237 = vec_53;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_1238);
										mem_vec_1238 = vec_55;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_1239);
										mem_vec_1239 = vec_57;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_1240);
										mem_vec_1240 = vec_59;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_1241);
										mem_vec_1241 = vec_61;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_1242);
										mem_vec_1242 = vec_63;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);


										vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_1243);
										mem_vec_1243 = vec_65;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_1244);
										mem_vec_1244 = vec_67;
										scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_33);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_1245);
										mem_vec_1245 = vec_69;
										scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_72 = _mm512_set1_ps(scal_34);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_1246);
										mem_vec_1246 = vec_71;
										scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
										vec_74 = _mm512_set1_ps(scal_35);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_1247);
										mem_vec_1247 = vec_73;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1236);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1237);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1238);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1239);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1247);
						}
					}
				}
			}
		}
	}
	for (y60 = y61 + 24, y60_p_0 = 0;
		y60 < y61 + 24 + 112;
		y60 += 28, y60_p_0 += 28){
		// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
		// T (f, 8) (128 / 16)
		for (f = f60, fp_0 = 0;
			f < f60 + 128;
			f += 16, fp_0 += 16){
			// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
			// T (c, 1) (64 / 64)
			for (c90 = c91, c90_p_0 = 0;
				c90 < c91 + 64;
				c90 += 64, c90_p_0 += 64){
				// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
				// T (y, 2) (2 * ph_y / ph_y)
				for (y = y60, yp_1 = y60_p_0, yp_0 = 0;
					y < y60 + 28;
					y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 16
					// T (x, 136) (136 / 1)
					for (x = x120, xp_0 = 0;
						x < x120 + 136;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w60, wp_0 = 0;
							w < w60 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1248 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_1257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_1258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_1259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_1260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_1261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
										c < c90 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1248);
										mem_vec_1248 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1249);
										mem_vec_1249 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1250);
										mem_vec_1250 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1251);
										mem_vec_1251 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1252);
										mem_vec_1252 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1253);
										mem_vec_1253 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1254);
										mem_vec_1254 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1255);
										mem_vec_1255 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1256);
										mem_vec_1256 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1257);
										mem_vec_1257 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_1258);
										mem_vec_1258 = vec_21;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_24 = _mm512_set1_ps(scal_11);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1259);
										mem_vec_1259 = vec_23;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_26 = _mm512_set1_ps(scal_12);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_1260);
										mem_vec_1260 = vec_25;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_28 = _mm512_set1_ps(scal_13);


										vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_1261);
										mem_vec_1261 = vec_27;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_14);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_1248);
										mem_vec_1248 = vec_29;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_31, mem_vec_1249);
										mem_vec_1249 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_1250);
										mem_vec_1250 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_31, mem_vec_1251);
										mem_vec_1251 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_1252);
										mem_vec_1252 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_1253);
										mem_vec_1253 = vec_40;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_31, mem_vec_1254);
										mem_vec_1254 = vec_42;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_31, mem_vec_1255);
										mem_vec_1255 = vec_44;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_22);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_1256);
										mem_vec_1256 = vec_46;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_23);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_1257);
										mem_vec_1257 = vec_48;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_51 = _mm512_set1_ps(scal_24);


										vec_50 = _mm512_fmadd_ps(vec_51, vec_31, mem_vec_1258);
										mem_vec_1258 = vec_50;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_25);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_1259);
										mem_vec_1259 = vec_52;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
										vec_55 = _mm512_set1_ps(scal_26);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_31, mem_vec_1260);
										mem_vec_1260 = vec_54;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
										vec_57 = _mm512_set1_ps(scal_27);


										vec_56 = _mm512_fmadd_ps(vec_57, vec_31, mem_vec_1261);
										mem_vec_1261 = vec_56;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_28);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_1248);
										mem_vec_1248 = vec_58;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_60, mem_vec_1249);
										mem_vec_1249 = vec_61;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_1250);
										mem_vec_1250 = vec_63;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);


										vec_65 = _mm512_fmadd_ps(vec_66, vec_60, mem_vec_1251);
										mem_vec_1251 = vec_65;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_1252);
										mem_vec_1252 = vec_67;
										scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_33);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_1253);
										mem_vec_1253 = vec_69;
										scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_72 = _mm512_set1_ps(scal_34);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_60, mem_vec_1254);
										mem_vec_1254 = vec_71;
										scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_74 = _mm512_set1_ps(scal_35);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_60, mem_vec_1255);
										mem_vec_1255 = vec_73;
										scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_36);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_1256);
										mem_vec_1256 = vec_75;
										scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_37);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_1257);
										mem_vec_1257 = vec_77;
										scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_80 = _mm512_set1_ps(scal_38);


										vec_79 = _mm512_fmadd_ps(vec_80, vec_60, mem_vec_1258);
										mem_vec_1258 = vec_79;
										scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
										vec_82 = _mm512_set1_ps(scal_39);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_1259);
										mem_vec_1259 = vec_81;
										scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
										vec_84 = _mm512_set1_ps(scal_40);


										vec_83 = _mm512_fmadd_ps(vec_84, vec_60, mem_vec_1260);
										mem_vec_1260 = vec_83;
										scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
										vec_86 = _mm512_set1_ps(scal_41);


										vec_85 = _mm512_fmadd_ps(vec_86, vec_60, mem_vec_1261);
										mem_vec_1261 = vec_85;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1261);
						}
					}
				}
			}
		}
	}


}