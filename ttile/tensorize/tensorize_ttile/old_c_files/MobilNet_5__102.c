#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, y); T (4, f); T (1, c); T (1, f); T (128, c); T (14, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c296_p_0, c297_p_0, cp_1, c296_p_1, cp_2, c296, c297, f, fp_0, f284_p_0, f285_p_0, fp_1, f284_p_1, fp_2, f284, f285, h, hp_0, w, wp_0, x, xp_0, x222_p_0, xp_1, x222, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y148 = 0;
IND_TYPE x223 = 0;
IND_TYPE h148 = 0;
IND_TYPE w148 = 0;
IND_TYPE c298 = 0;
IND_TYPE f286 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2072 ,mem_vec_2073 ,mem_vec_2074 ,mem_vec_2075 ,mem_vec_2076 ,mem_vec_2077 ,mem_vec_2078 ,mem_vec_2079 ,mem_vec_2080 ,mem_vec_2081 ,mem_vec_2082 ,mem_vec_2083 ,mem_vec_2084 ,mem_vec_2085 ,mem_vec_2086 ,mem_vec_2087 ,mem_vec_2088 ,mem_vec_2089 ,mem_vec_2090 ,mem_vec_2091 ,mem_vec_2092 ,mem_vec_2093 ,mem_vec_2094 ,mem_vec_2095 ,mem_vec_2096 ,mem_vec_2097 ,mem_vec_2098 ,mem_vec_2099 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f285 = f286, f285_p_0 = 0;
	f285 < f286 + 256;
	f285 += 256, f285_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 14) (28 / 2)
	for (x222 = x223, x222_p_0 = 0;
		x222 < x223 + 28;
		x222 += 2, x222_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 256
		// T (c, 128) (256 / 2)
		for (c297 = c298, c297_p_0 = 0;
			c297 < c298 + 256;
			c297 += 2, c297_p_0 += 2){
			// y = 28, x = 2, h = 3, w = 3, c = 2, f = 256
			// T (f, 1) (256 / 256)
			for (f284 = f285, f284_p_1 = f285_p_0, f284_p_0 = 0;
				f284 < f285 + 256;
				f284 += 256, f284_p_1 += 256, f284_p_0 += 256){
				// y = 28, x = 2, h = 3, w = 3, c = 2, f = 256
				// T (c, 1) (2 / 2)
				for (c296 = c297, c296_p_1 = c297_p_0, c296_p_0 = 0;
					c296 < c297 + 2;
					c296 += 2, c296_p_1 += 2, c296_p_0 += 2){
					// y = 28, x = 2, h = 3, w = 3, c = 2, f = 256
					// T (f, 4) (256 / 64)
					for (f = f284, fp_2 = f284_p_1, fp_1 = f284_p_0, fp_0 = 0;
						f < f284 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 2, h = 3, w = 3, c = 2, f = 64
						// T (y, 4) (28 / 7)
						for (y = y148, yp_0 = 0;
							y < y148 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 2, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h148, hp_0 = 0;
								h < h148 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 2, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w148, wp_0 = 0;
									w < w148 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 2, h = 1, w = 1, c = 2, f = 64
									// T (x, 2) (2 / 1)
									for (x = x222, xp_1 = x222_p_0, xp_0 = 0;
										x < x222 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2072 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2073 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2074 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_2075 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_2076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_2079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_2080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_2083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_2084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_2087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_2088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_2091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_2092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_2095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_2096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_2099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c296, cp_2 = c296_p_1, cp_1 = c296_p_0, cp_0 = 0;
													c < c296 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2072);
													mem_vec_2072 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2073);
													mem_vec_2073 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2074);
													mem_vec_2074 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2075);
													mem_vec_2075 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2076);
													mem_vec_2076 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2077);
													mem_vec_2077 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2078);
													mem_vec_2078 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2079);
													mem_vec_2079 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2080);
													mem_vec_2080 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2081);
													mem_vec_2081 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2082);
													mem_vec_2082 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2083);
													mem_vec_2083 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2084);
													mem_vec_2084 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2085);
													mem_vec_2085 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2086);
													mem_vec_2086 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2087);
													mem_vec_2087 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2088);
													mem_vec_2088 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2089);
													mem_vec_2089 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2090);
													mem_vec_2090 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2091);
													mem_vec_2091 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2092);
													mem_vec_2092 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2093);
													mem_vec_2093 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2094);
													mem_vec_2094 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2095);
													mem_vec_2095 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2096);
													mem_vec_2096 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2097);
													mem_vec_2097 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2098);
													mem_vec_2098 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2099);
													mem_vec_2099 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2072);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2073);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2074);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2075);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2076);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2077);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2078);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2079);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2080);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2081);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2082);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2083);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2084);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2085);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2086);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2087);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2088);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2089);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2090);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2091);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2092);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2093);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2094);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2095);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2096);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2097);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2098);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2099);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


}