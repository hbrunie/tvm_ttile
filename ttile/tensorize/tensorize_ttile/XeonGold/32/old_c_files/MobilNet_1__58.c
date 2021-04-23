#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (1, y); T (1, c);
  Lambda_apply y [((Iter 11), (Arg 9)); ((Iter 1), (Arg 13))]]
*/
IND_TYPE c, cp_0, c147_p_0, cp_1, c147, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y147_p_0, yp_1, y147;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y148 = 0;
IND_TYPE x98 = 0;
IND_TYPE h92 = 0;
IND_TYPE w98 = 0;
IND_TYPE c148 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2008 ,mem_vec_2009 ,mem_vec_2010 ,mem_vec_2011 ,mem_vec_2012 ,mem_vec_2013 ,mem_vec_2014 ,mem_vec_2015 ,mem_vec_2016 ,mem_vec_2017 ,mem_vec_2018 ,mem_vec_2019 ,mem_vec_2020 ,mem_vec_2021 ,mem_vec_2022 ,mem_vec_2023 ,mem_vec_2024 ,mem_vec_2025 ,mem_vec_2026 ,mem_vec_2027 ,mem_vec_2028 ,mem_vec_2029 ,mem_vec_2030 ,mem_vec_2031 ,mem_vec_2032 ,mem_vec_2033 ,mem_vec_2034 ,mem_vec_2035 ,mem_vec_2036 ,mem_vec_2037 ,mem_vec_2038 ,mem_vec_2039 ,mem_vec_2040 ,mem_vec_2041 ,mem_vec_2042 ,mem_vec_2043 ,mem_vec_2044 ,mem_vec_2045 ,mem_vec_2046 ,mem_vec_2047 ,mem_vec_2048 ,mem_vec_2049 ,mem_vec_2050 ,mem_vec_2051 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y147 = y148, y147_p_0 = 0;
		y147 < y148 + 99;
		y147 += 9, y147_p_0 += 9){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c147 = c148, c147_p_0 = 0;
			c147 < c148 + 32;
			c147 += 32, c147_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y147, yp_1 = y147_p_0, yp_0 = 0;
				y < y147 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x98, xp_0 = 0;
					x < x98 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h92, hp_0 = 0;
						h < h92 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w98, wp_0 = 0;
							w < w98 + 3;
							w += 1, wp_0 += 1){
									mem_vec_2008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_2023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_2024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_2025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c147, cp_1 = c147_p_0, cp_0 = 0;
										c < c147 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2008);
										mem_vec_2008 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2009);
										mem_vec_2009 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2010);
										mem_vec_2010 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2011);
										mem_vec_2011 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2012);
										mem_vec_2012 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2013);
										mem_vec_2013 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2014);
										mem_vec_2014 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2015);
										mem_vec_2015 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2016);
										mem_vec_2016 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2017);
										mem_vec_2017 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2018);
										mem_vec_2018 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2019);
										mem_vec_2019 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2020);
										mem_vec_2020 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2021);
										mem_vec_2021 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2022);
										mem_vec_2022 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2023);
										mem_vec_2023 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2024);
										mem_vec_2024 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2025);
										mem_vec_2025 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2008);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2009);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2010);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2011);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2012);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2013);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2014);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2015);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2016);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2017);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2018);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2019);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2020);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2021);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2022);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2023);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2024);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2025);
						}
					}
				}
			}
		}
	}
	for (y147 = y148 + 99, y147_p_0 = 0;
		y147 < y148 + 99 + 13;
		y147 += 13, y147_p_0 += 13){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c147 = c148, c147_p_0 = 0;
			c147 < c148 + 32;
			c147 += 32, c147_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y147, yp_1 = y147_p_0, yp_0 = 0;
				y < y147 + 13;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x98, xp_0 = 0;
					x < x98 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h92, hp_0 = 0;
						h < h92 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w98, wp_0 = 0;
							w < w98 + 3;
							w += 1, wp_0 += 1){
									mem_vec_2026 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2027 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_2041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_2042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_2043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_2044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_2045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_2046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_2047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_2048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_2049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_2050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_2051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c147, cp_1 = c147_p_0, cp_0 = 0;
										c < c147 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2026);
										mem_vec_2026 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2027);
										mem_vec_2027 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2028);
										mem_vec_2028 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2029);
										mem_vec_2029 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2030);
										mem_vec_2030 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2031);
										mem_vec_2031 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2032);
										mem_vec_2032 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2033);
										mem_vec_2033 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2034);
										mem_vec_2034 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2035);
										mem_vec_2035 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2036);
										mem_vec_2036 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2037);
										mem_vec_2037 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2038);
										mem_vec_2038 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2039);
										mem_vec_2039 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2040);
										mem_vec_2040 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2041);
										mem_vec_2041 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2042);
										mem_vec_2042 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2043);
										mem_vec_2043 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2044);
										mem_vec_2044 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2045);
										mem_vec_2045 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2046);
										mem_vec_2046 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2047);
										mem_vec_2047 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2048);
										mem_vec_2048 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2049);
										mem_vec_2049 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2050);
										mem_vec_2050 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2051);
										mem_vec_2051 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2026);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2027);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2028);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2029);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2030);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2031);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2035);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2041);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2042);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2043);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2044);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2045);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2046);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2047);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2048);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2049);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2050);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2051);
						}
					}
				}
			}
		}
	}


}