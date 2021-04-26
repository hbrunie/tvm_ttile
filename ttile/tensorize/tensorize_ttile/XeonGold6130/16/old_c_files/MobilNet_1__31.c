#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (112, x); T (4, y); T (1, c);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c153_p_0, cp_1, c153, w, wp_0, x, xp_0, y, yp_0, y153_p_0, yp_1, y153;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y154 = 0;
IND_TYPE x102 = 0;
IND_TYPE h = 0;
IND_TYPE w102 = 0;
IND_TYPE c154 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2090 ,mem_vec_2091 ,mem_vec_2092 ,mem_vec_2093 ,mem_vec_2094 ,mem_vec_2095 ,mem_vec_2096 ,mem_vec_2097 ,mem_vec_2098 ,mem_vec_2099 ,mem_vec_2100 ,mem_vec_2101 ,mem_vec_2102 ,mem_vec_2103 ,mem_vec_2104 ,mem_vec_2105 ,mem_vec_2106 ,mem_vec_2107 ,mem_vec_2108 ,mem_vec_2109 ,mem_vec_2110 ,mem_vec_2111 ,mem_vec_2112 ,mem_vec_2113 ,mem_vec_2114 ,mem_vec_2115 ,mem_vec_2116 ,mem_vec_2117 ,mem_vec_2118 ,mem_vec_2119 ,mem_vec_2120 ,mem_vec_2121 ,mem_vec_2122 ,mem_vec_2123 ,mem_vec_2124 ,mem_vec_2125 ,mem_vec_2126 ,mem_vec_2127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
	for (y153 = y154, y153_p_0 = 0;
		y153 < y154 + 72;
		y153 += 36, y153_p_0 += 36){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c153 = c154, c153_p_0 = 0;
			c153 < c154 + 32;
			c153 += 32, c153_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y153, yp_1 = y153_p_0, yp_0 = 0;
				y < y153 + 36;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x102, xp_0 = 0;
					x < x102 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w102, wp_0 = 0;
						w < w102 + 3;
						w += 1, wp_0 += 1){
								mem_vec_2090 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2091 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c153, cp_1 = c153_p_0, cp_0 = 0;
									c < c153 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2090);
									mem_vec_2090 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2091);
									mem_vec_2091 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2092);
									mem_vec_2092 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2093);
									mem_vec_2093 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2094);
									mem_vec_2094 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2095);
									mem_vec_2095 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2096);
									mem_vec_2096 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2097);
									mem_vec_2097 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2098);
									mem_vec_2098 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2099);
									mem_vec_2099 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2100);
									mem_vec_2100 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2101);
									mem_vec_2101 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2102);
									mem_vec_2102 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2103);
									mem_vec_2103 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2104);
									mem_vec_2104 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2105);
									mem_vec_2105 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2106);
									mem_vec_2106 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2107);
									mem_vec_2107 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_2090);
									mem_vec_2090 = vec_29;

									vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_2091);
									mem_vec_2091 = vec_32;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_10);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_2092);
									mem_vec_2092 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_2093);
									mem_vec_2093 = vec_36;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_2094);
									mem_vec_2094 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_2095);
									mem_vec_2095 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_2096);
									mem_vec_2096 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_2097);
									mem_vec_2097 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_2098);
									mem_vec_2098 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_2099);
									mem_vec_2099 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_2100);
									mem_vec_2100 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_2101);
									mem_vec_2101 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_2102);
									mem_vec_2102 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_2103);
									mem_vec_2103 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_2104);
									mem_vec_2104 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_2105);
									mem_vec_2105 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_2106);
									mem_vec_2106 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_2107);
									mem_vec_2107 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_59 = _mm512_set1_ps(scal_18);
									vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_2090);
									mem_vec_2090 = vec_58;

									vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_2091);
									mem_vec_2091 = vec_61;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_19);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_2092);
									mem_vec_2092 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_2093);
									mem_vec_2093 = vec_65;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_67 = _mm512_set1_ps(scal_20);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_2094);
									mem_vec_2094 = vec_66;



									vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_2095);
									mem_vec_2095 = vec_68;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_70 = _mm512_set1_ps(scal_21);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_2096);
									mem_vec_2096 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_2097);
									mem_vec_2097 = vec_71;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_73 = _mm512_set1_ps(scal_22);


									vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_2098);
									mem_vec_2098 = vec_72;



									vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_2099);
									mem_vec_2099 = vec_74;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_2100);
									mem_vec_2100 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_2101);
									mem_vec_2101 = vec_77;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_79 = _mm512_set1_ps(scal_24);


									vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_2102);
									mem_vec_2102 = vec_78;



									vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_2103);
									mem_vec_2103 = vec_80;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_2104);
									mem_vec_2104 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_2105);
									mem_vec_2105 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_2106);
									mem_vec_2106 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_2107);
									mem_vec_2107 = vec_86;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2090);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2091);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2092);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2093);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2094);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2095);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2096);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2097);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2098);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2099);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2100);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2101);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2102);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2103);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2104);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2105);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2106);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2107);
					}
				}
			}
		}
	}
	for (y153 = y154 + 72, y153_p_0 = 0;
		y153 < y154 + 72 + 40;
		y153 += 40, y153_p_0 += 40){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c153 = c154, c153_p_0 = 0;
			c153 < c154 + 32;
			c153 += 32, c153_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y153, yp_1 = y153_p_0, yp_0 = 0;
				y < y153 + 40;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x102, xp_0 = 0;
					x < x102 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w102, wp_0 = 0;
						w < w102 + 3;
						w += 1, wp_0 += 1){
								mem_vec_2108 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2109 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_2126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_2127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c153, cp_1 = c153_p_0, cp_0 = 0;
									c < c153 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2108);
									mem_vec_2108 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2109);
									mem_vec_2109 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2110);
									mem_vec_2110 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2111);
									mem_vec_2111 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2112);
									mem_vec_2112 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2113);
									mem_vec_2113 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2114);
									mem_vec_2114 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2115);
									mem_vec_2115 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2116);
									mem_vec_2116 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2117);
									mem_vec_2117 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2118);
									mem_vec_2118 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2119);
									mem_vec_2119 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2120);
									mem_vec_2120 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2121);
									mem_vec_2121 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2122);
									mem_vec_2122 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2123);
									mem_vec_2123 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2124);
									mem_vec_2124 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2125);
									mem_vec_2125 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2126);
									mem_vec_2126 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2127);
									mem_vec_2127 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_2108);
									mem_vec_2108 = vec_32;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_2109);
									mem_vec_2109 = vec_35;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_2110);
									mem_vec_2110 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_2111);
									mem_vec_2111 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_2112);
									mem_vec_2112 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_2113);
									mem_vec_2113 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_2114);
									mem_vec_2114 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2115);
									mem_vec_2115 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_2116);
									mem_vec_2116 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_2117);
									mem_vec_2117 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_2118);
									mem_vec_2118 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_2119);
									mem_vec_2119 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_2120);
									mem_vec_2120 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_2121);
									mem_vec_2121 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_2122);
									mem_vec_2122 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_2123);
									mem_vec_2123 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_2124);
									mem_vec_2124 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_2125);
									mem_vec_2125 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_2126);
									mem_vec_2126 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_2127);
									mem_vec_2127 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_65 = _mm512_set1_ps(scal_20);
									vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_2108);
									mem_vec_2108 = vec_64;

									vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_2109);
									mem_vec_2109 = vec_67;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_70 = _mm512_set1_ps(scal_21);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_2110);
									mem_vec_2110 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_2111);
									mem_vec_2111 = vec_71;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_73 = _mm512_set1_ps(scal_22);


									vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_2112);
									mem_vec_2112 = vec_72;



									vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_2113);
									mem_vec_2113 = vec_74;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_2114);
									mem_vec_2114 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_2115);
									mem_vec_2115 = vec_77;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_79 = _mm512_set1_ps(scal_24);


									vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_2116);
									mem_vec_2116 = vec_78;



									vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_2117);
									mem_vec_2117 = vec_80;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_82 = _mm512_set1_ps(scal_25);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_2118);
									mem_vec_2118 = vec_81;



									vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_2119);
									mem_vec_2119 = vec_83;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_85 = _mm512_set1_ps(scal_26);


									vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_2120);
									mem_vec_2120 = vec_84;



									vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_2121);
									mem_vec_2121 = vec_86;
									scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_88 = _mm512_set1_ps(scal_27);


									vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_2122);
									mem_vec_2122 = vec_87;



									vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_2123);
									mem_vec_2123 = vec_89;
									scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_91 = _mm512_set1_ps(scal_28);


									vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_2124);
									mem_vec_2124 = vec_90;



									vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_2125);
									mem_vec_2125 = vec_92;
									scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
									vec_94 = _mm512_set1_ps(scal_29);


									vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_2126);
									mem_vec_2126 = vec_93;



									vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_2127);
									mem_vec_2127 = vec_95;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2108);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2109);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2110);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2111);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2112);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2113);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2114);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2115);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2116);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2117);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2118);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2119);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2120);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2121);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2122);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2123);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2124);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2125);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2126);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2127);
					}
				}
			}
		}
	}


}