#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (1, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c255_p_0, cp_1, c255, f, fp_0, h, hp_0, x, xp_0, x275_p_0, xp_1, x275, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y170 = 0;
IND_TYPE x276 = 0;
IND_TYPE h123 = 0;
IND_TYPE w = 0;
IND_TYPE c256 = 0;
IND_TYPE f254 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2060 ,mem_vec_2061 ,mem_vec_2062 ,mem_vec_2063 ,mem_vec_2064 ,mem_vec_2065 ,mem_vec_2066 ,mem_vec_2067 ,mem_vec_2068 ,mem_vec_2069 ,mem_vec_2070 ,mem_vec_2071 ,mem_vec_2072 ,mem_vec_2073 ,mem_vec_2074 ,mem_vec_2075 ,mem_vec_2076 ,mem_vec_2077 ,mem_vec_2078 ,mem_vec_2079 ,mem_vec_2080 ,mem_vec_2081 ,mem_vec_2082 ,mem_vec_2083 ,mem_vec_2084 ,mem_vec_2085 ,mem_vec_2086 ,mem_vec_2087 ,mem_vec_2088 ,mem_vec_2089 ,mem_vec_2090 ,mem_vec_2091 ,mem_vec_2092 ,mem_vec_2093 ,mem_vec_2094 ,mem_vec_2095 ,mem_vec_2096 ,mem_vec_2097 ,mem_vec_2098 ,mem_vec_2099 ,mem_vec_2100 ,mem_vec_2101 ,mem_vec_2102 ,mem_vec_2103 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y = y170, yp_0 = 0;
		y < y170 + 28;
		y += 4, yp_0 += 4){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x275 = x276, x275_p_0 = 0;
			x275 < x276 + 56;
			x275 += 28, x275_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f254, fp_0 = 0;
				f < f254 + 128;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c255 = c256, c255_p_0 = 0;
					c255 < c256 + 128;
					c255 += 128, c255_p_0 += 128){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (h, 3) (3 / 1)
					for (h = h123, hp_0 = 0;
						h < h123 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 128, f = 64
						// T (x, 28) (28 / 1)
						for (x = x275, xp_1 = x275_p_0, xp_0 = 0;
							x < x275 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2060 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2061 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_2072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_2075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c255, cp_1 = c255_p_0, cp_0 = 0;
										c < c255 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2060);
										mem_vec_2060 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2061);
										mem_vec_2061 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2062);
										mem_vec_2062 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2063);
										mem_vec_2063 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2064);
										mem_vec_2064 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2065);
										mem_vec_2065 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2066);
										mem_vec_2066 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2067);
										mem_vec_2067 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2068);
										mem_vec_2068 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2069);
										mem_vec_2069 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2070);
										mem_vec_2070 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2071);
										mem_vec_2071 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2072);
										mem_vec_2072 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2073);
										mem_vec_2073 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2074);
										mem_vec_2074 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2075);
										mem_vec_2075 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_2060);
										mem_vec_2060 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_2061);
										mem_vec_2061 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_2062);
										mem_vec_2062 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_2063);
										mem_vec_2063 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_2064);
										mem_vec_2064 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2065);
										mem_vec_2065 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2066);
										mem_vec_2066 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2067);
										mem_vec_2067 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_2068);
										mem_vec_2068 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_2069);
										mem_vec_2069 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_2070);
										mem_vec_2070 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_2071);
										mem_vec_2071 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_2072);
										mem_vec_2072 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2073);
										mem_vec_2073 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2074);
										mem_vec_2074 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2075);
										mem_vec_2075 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_2060);
										mem_vec_2060 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_2061);
										mem_vec_2061 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_2062);
										mem_vec_2062 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_2063);
										mem_vec_2063 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_2064);
										mem_vec_2064 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2065);
										mem_vec_2065 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2066);
										mem_vec_2066 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2067);
										mem_vec_2067 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_2068);
										mem_vec_2068 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_2069);
										mem_vec_2069 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_2070);
										mem_vec_2070 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_2071);
										mem_vec_2071 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_2072);
										mem_vec_2072 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2073);
										mem_vec_2073 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_2074);
										mem_vec_2074 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2075);
										mem_vec_2075 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2060);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2061);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2062);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2063);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2064);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2065);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2066);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2067);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2068);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2069);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2070);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2071);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2072);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2073);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2074);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2075);
						}
					}
				}
			}
		}
	}
	for (y = y170 + 28, yp_0 = 0;
		y < y170 + 28 + 28;
		y += 7, yp_0 += 7){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x275 = x276, x275_p_0 = 0;
			x275 < x276 + 56;
			x275 += 28, x275_p_0 += 28){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f254, fp_0 = 0;
				f < f254 + 128;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c255 = c256, c255_p_0 = 0;
					c255 < c256 + 128;
					c255 += 128, c255_p_0 += 128){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (h, 3) (3 / 1)
					for (h = h123, hp_0 = 0;
						h < h123 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 3, c = 128, f = 64
						// T (x, 28) (28 / 1)
						for (x = x275, xp_1 = x275_p_0, xp_0 = 0;
							x < x275 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2076 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2077 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2078 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2079 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_2088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_2091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_2092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_2095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_2096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_2099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_2100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_2103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c255, cp_1 = c255_p_0, cp_0 = 0;
										c < c255 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2076);
										mem_vec_2076 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2077);
										mem_vec_2077 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2078);
										mem_vec_2078 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2079);
										mem_vec_2079 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2080);
										mem_vec_2080 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2081);
										mem_vec_2081 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2082);
										mem_vec_2082 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2083);
										mem_vec_2083 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2084);
										mem_vec_2084 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2085);
										mem_vec_2085 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2086);
										mem_vec_2086 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2087);
										mem_vec_2087 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2088);
										mem_vec_2088 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2089);
										mem_vec_2089 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2090);
										mem_vec_2090 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2091);
										mem_vec_2091 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2092);
										mem_vec_2092 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2093);
										mem_vec_2093 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2094);
										mem_vec_2094 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2095);
										mem_vec_2095 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2096);
										mem_vec_2096 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2097);
										mem_vec_2097 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2098);
										mem_vec_2098 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2099);
										mem_vec_2099 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2100);
										mem_vec_2100 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2101);
										mem_vec_2101 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2102);
										mem_vec_2102 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2103);
										mem_vec_2103 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_2076);
										mem_vec_2076 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_2077);
										mem_vec_2077 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_2078);
										mem_vec_2078 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_2079);
										mem_vec_2079 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_2080);
										mem_vec_2080 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_2081);
										mem_vec_2081 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_2082);
										mem_vec_2082 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_2083);
										mem_vec_2083 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_2084);
										mem_vec_2084 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_2085);
										mem_vec_2085 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_2086);
										mem_vec_2086 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_2087);
										mem_vec_2087 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_2088);
										mem_vec_2088 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_2089);
										mem_vec_2089 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_2090);
										mem_vec_2090 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_2091);
										mem_vec_2091 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_2092);
										mem_vec_2092 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_2093);
										mem_vec_2093 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_2094);
										mem_vec_2094 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_2095);
										mem_vec_2095 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_2096);
										mem_vec_2096 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_2097);
										mem_vec_2097 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_2098);
										mem_vec_2098 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_2099);
										mem_vec_2099 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_2100);
										mem_vec_2100 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_2101);
										mem_vec_2101 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_2102);
										mem_vec_2102 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_2103);
										mem_vec_2103 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_2076);
										mem_vec_2076 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_2077);
										mem_vec_2077 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_2078);
										mem_vec_2078 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_2079);
										mem_vec_2079 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_2080);
										mem_vec_2080 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_2081);
										mem_vec_2081 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_2082);
										mem_vec_2082 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_2083);
										mem_vec_2083 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_2084);
										mem_vec_2084 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_2085);
										mem_vec_2085 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_2086);
										mem_vec_2086 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_2087);
										mem_vec_2087 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_2088);
										mem_vec_2088 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_2089);
										mem_vec_2089 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_2090);
										mem_vec_2090 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_2091);
										mem_vec_2091 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_2092);
										mem_vec_2092 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_2093);
										mem_vec_2093 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_2094);
										mem_vec_2094 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_2095);
										mem_vec_2095 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_2096);
										mem_vec_2096 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_2097);
										mem_vec_2097 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_2098);
										mem_vec_2098 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_2099);
										mem_vec_2099 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_2100);
										mem_vec_2100 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_2101);
										mem_vec_2101 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_2102);
										mem_vec_2102 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_2103);
										mem_vec_2103 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2076);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2077);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2078);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2079);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2080);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2081);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2082);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2083);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2084);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2085);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2086);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2087);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2088);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2089);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2090);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2091);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2092);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2093);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2094);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2095);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2096);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2097);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2098);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2099);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2103);
						}
					}
				}
			}
		}
	}


}