#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (112, x); T (2, y); T (1, c);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, w, wp_0, x, xp_0, y, yp_0, y159_p_0, yp_1, y159;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y160 = 0;
IND_TYPE x106 = 0;
IND_TYPE h = 0;
IND_TYPE w106 = 0;
IND_TYPE c160 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2168 ,mem_vec_2169 ,mem_vec_2170 ,mem_vec_2171 ,mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,mem_vec_2186 ,mem_vec_2187 ,mem_vec_2188 ,mem_vec_2189 ,mem_vec_2190 ,mem_vec_2191 ,mem_vec_2192 ,mem_vec_2193 ,mem_vec_2194 ,mem_vec_2195 ,mem_vec_2196 ,mem_vec_2197 ,mem_vec_2198 ,mem_vec_2199 ,mem_vec_2200 ,mem_vec_2201 ,mem_vec_2202 ,mem_vec_2203 ,mem_vec_2204 ,mem_vec_2205 ,mem_vec_2206 ,mem_vec_2207 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y159 = y160, y159_p_0 = 0;
		y159 < y160 + 90;
		y159 += 18, y159_p_0 += 18){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c159 = c160, c159_p_0 = 0;
			c159 < c160 + 32;
			c159 += 32, c159_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y159, yp_1 = y159_p_0, yp_0 = 0;
				y < y159 + 18;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x106, xp_0 = 0;
					x < x106 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w106, wp_0 = 0;
						w < w106 + 3;
						w += 1, wp_0 += 1){
								mem_vec_2168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
									c < c159 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2168);
									mem_vec_2168 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2169);
									mem_vec_2169 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2170);
									mem_vec_2170 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2171);
									mem_vec_2171 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2172);
									mem_vec_2172 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2173);
									mem_vec_2173 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2174);
									mem_vec_2174 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2175);
									mem_vec_2175 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2176);
									mem_vec_2176 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2177);
									mem_vec_2177 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2178);
									mem_vec_2178 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2179);
									mem_vec_2179 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2180);
									mem_vec_2180 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2181);
									mem_vec_2181 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2182);
									mem_vec_2182 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2183);
									mem_vec_2183 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2184);
									mem_vec_2184 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2185);
									mem_vec_2185 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_2168);
									mem_vec_2168 = vec_29;

									vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_2169);
									mem_vec_2169 = vec_32;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_10);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_2170);
									mem_vec_2170 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_2171);
									mem_vec_2171 = vec_36;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_2172);
									mem_vec_2172 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_2173);
									mem_vec_2173 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_2174);
									mem_vec_2174 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_2175);
									mem_vec_2175 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_2176);
									mem_vec_2176 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_2177);
									mem_vec_2177 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_2178);
									mem_vec_2178 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_2179);
									mem_vec_2179 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_2180);
									mem_vec_2180 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_2181);
									mem_vec_2181 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_2182);
									mem_vec_2182 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_2183);
									mem_vec_2183 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_2184);
									mem_vec_2184 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_2185);
									mem_vec_2185 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_59 = _mm512_set1_ps(scal_18);
									vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_2168);
									mem_vec_2168 = vec_58;

									vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_2169);
									mem_vec_2169 = vec_61;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_19);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_2170);
									mem_vec_2170 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_2171);
									mem_vec_2171 = vec_65;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_67 = _mm512_set1_ps(scal_20);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_2172);
									mem_vec_2172 = vec_66;



									vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_2173);
									mem_vec_2173 = vec_68;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_70 = _mm512_set1_ps(scal_21);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_2174);
									mem_vec_2174 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_2175);
									mem_vec_2175 = vec_71;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_73 = _mm512_set1_ps(scal_22);


									vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_2176);
									mem_vec_2176 = vec_72;



									vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_2177);
									mem_vec_2177 = vec_74;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_2178);
									mem_vec_2178 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_2179);
									mem_vec_2179 = vec_77;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_79 = _mm512_set1_ps(scal_24);


									vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_2180);
									mem_vec_2180 = vec_78;



									vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_2181);
									mem_vec_2181 = vec_80;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_2182);
									mem_vec_2182 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_2183);
									mem_vec_2183 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_2184);
									mem_vec_2184 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_2185);
									mem_vec_2185 = vec_86;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2168);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2169);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2170);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2171);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2172);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2173);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2174);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2175);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2176);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2177);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2178);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2179);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2180);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2181);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2182);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2183);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2184);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2185);
					}
				}
			}
		}
	}
	for (y159 = y160 + 90, y159_p_0 = 0;
		y159 < y160 + 90 + 22;
		y159 += 22, y159_p_0 += 22){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c159 = c160, c159_p_0 = 0;
			c159 < c160 + 32;
			c159 += 32, c159_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y159, yp_1 = y159_p_0, yp_0 = 0;
				y < y159 + 22;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x106, xp_0 = 0;
					x < x106 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w106, wp_0 = 0;
						w < w106 + 3;
						w += 1, wp_0 += 1){
								mem_vec_2186 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_2204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_2205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_2206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_2207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
									c < c159 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2186);
									mem_vec_2186 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2187);
									mem_vec_2187 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2188);
									mem_vec_2188 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2189);
									mem_vec_2189 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2190);
									mem_vec_2190 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2191);
									mem_vec_2191 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2192);
									mem_vec_2192 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2193);
									mem_vec_2193 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2194);
									mem_vec_2194 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2195);
									mem_vec_2195 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2196);
									mem_vec_2196 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2197);
									mem_vec_2197 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2198);
									mem_vec_2198 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2199);
									mem_vec_2199 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2200);
									mem_vec_2200 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2201);
									mem_vec_2201 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2202);
									mem_vec_2202 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2203);
									mem_vec_2203 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2204);
									mem_vec_2204 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2205);
									mem_vec_2205 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2206);
									mem_vec_2206 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2207);
									mem_vec_2207 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_2186);
									mem_vec_2186 = vec_35;

									vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_2187);
									mem_vec_2187 = vec_38;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_2188);
									mem_vec_2188 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_2189);
									mem_vec_2189 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_2190);
									mem_vec_2190 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_2191);
									mem_vec_2191 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_2192);
									mem_vec_2192 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_2193);
									mem_vec_2193 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_2194);
									mem_vec_2194 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_2195);
									mem_vec_2195 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_2196);
									mem_vec_2196 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_2197);
									mem_vec_2197 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_2198);
									mem_vec_2198 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_2199);
									mem_vec_2199 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_2200);
									mem_vec_2200 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_2201);
									mem_vec_2201 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_2202);
									mem_vec_2202 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_2203);
									mem_vec_2203 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
									vec_65 = _mm512_set1_ps(scal_20);


									vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_2204);
									mem_vec_2204 = vec_64;



									vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_2205);
									mem_vec_2205 = vec_66;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
									vec_68 = _mm512_set1_ps(scal_21);


									vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_2206);
									mem_vec_2206 = vec_67;



									vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_2207);
									mem_vec_2207 = vec_69;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_71 = _mm512_set1_ps(scal_22);
									vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_2186);
									mem_vec_2186 = vec_70;

									vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_2187);
									mem_vec_2187 = vec_73;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_2188);
									mem_vec_2188 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_2189);
									mem_vec_2189 = vec_77;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_79 = _mm512_set1_ps(scal_24);


									vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_2190);
									mem_vec_2190 = vec_78;



									vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_2191);
									mem_vec_2191 = vec_80;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_2192);
									mem_vec_2192 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_2193);
									mem_vec_2193 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_2194);
									mem_vec_2194 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_2195);
									mem_vec_2195 = vec_86;
									scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_88 = _mm512_set1_ps(scal_27);


									vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_2196);
									mem_vec_2196 = vec_87;



									vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_2197);
									mem_vec_2197 = vec_89;
									scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_91 = _mm512_set1_ps(scal_28);


									vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_2198);
									mem_vec_2198 = vec_90;



									vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_2199);
									mem_vec_2199 = vec_92;
									scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_94 = _mm512_set1_ps(scal_29);


									vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_2200);
									mem_vec_2200 = vec_93;



									vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_2201);
									mem_vec_2201 = vec_95;
									scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_97 = _mm512_set1_ps(scal_30);


									vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_2202);
									mem_vec_2202 = vec_96;



									vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_2203);
									mem_vec_2203 = vec_98;
									scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
									vec_100 = _mm512_set1_ps(scal_31);


									vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_2204);
									mem_vec_2204 = vec_99;



									vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_2205);
									mem_vec_2205 = vec_101;
									scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
									vec_103 = _mm512_set1_ps(scal_32);


									vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_2206);
									mem_vec_2206 = vec_102;



									vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_2207);
									mem_vec_2207 = vec_104;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2186);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2187);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2188);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2189);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2190);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2191);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2192);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2193);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2194);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2195);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2196);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2197);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2198);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2199);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2200);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2201);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2202);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2203);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2204);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2205);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2206);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2207);
					}
				}
			}
		}
	}


}