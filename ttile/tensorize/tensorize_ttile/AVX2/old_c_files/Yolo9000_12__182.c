#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (32, c); T (4, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (4, f)]
*/
IND_TYPE c, cp_0, c191_p_0, cp_1, c191, f, fp_0, f152_p_0, f153_p_0, fp_1, f152_p_1, fp_2, f152, f153, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y112_p_0, yp_1, y112;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y113 = 0;
IND_TYPE x98 = 0;
IND_TYPE h75 = 0;
IND_TYPE w86 = 0;
IND_TYPE c192 = 0;
IND_TYPE f154 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2132 ,mem_vec_2133 ,mem_vec_2134 ,mem_vec_2135 ,mem_vec_2136 ,mem_vec_2137 ,mem_vec_2138 ,mem_vec_2139 ,mem_vec_2140 ,mem_vec_2141 ,mem_vec_2142 ,mem_vec_2143 ,mem_vec_2144 ,mem_vec_2145 ,mem_vec_2146 ,mem_vec_2147 ,mem_vec_2148 ,mem_vec_2149 ,mem_vec_2150 ,mem_vec_2151 ,mem_vec_2152 ,mem_vec_2153 ,mem_vec_2154 ,mem_vec_2155 ,mem_vec_2156 ,mem_vec_2157 ,mem_vec_2158 ,mem_vec_2159 ,mem_vec_2160 ,mem_vec_2161 ,mem_vec_2162 ,mem_vec_2163 ,mem_vec_2164 ,mem_vec_2165 ,mem_vec_2166 ,mem_vec_2167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f153 = f154, f153_p_0 = 0;
	f153 < f154 + 512;
	f153 += 128, f153_p_0 += 128){
		for (y112 = y113, y112_p_0 = 0;
			y112 < y113 + 24;
			y112 += 8, y112_p_0 += 8){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 128
			// T (f, 4) (128 / 32)
			for (f152 = f153, f152_p_1 = f153_p_0, f152_p_0 = 0;
				f152 < f153 + 128;
				f152 += 32, f152_p_1 += 32, f152_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c191 = c192, c191_p_0 = 0;
					c191 < c192 + 256;
					c191 += 8, c191_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f152, fp_2 = f152_p_1, fp_1 = f152_p_0, fp_0 = 0;
						f < f152 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y112, yp_1 = y112_p_0, yp_0 = 0;
							y < y112 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x98, xp_0 = 0;
								x < x98 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h75, hp_0 = 0;
									h < h75 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w86, wp_0 = 0;
										w < w86 + 3;
										w += 1, wp_0 += 1){
												mem_vec_2132 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2133 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2134 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2135 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c191, cp_1 = c191_p_0, cp_0 = 0;
													c < c191 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2132);
													mem_vec_2132 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2133);
													mem_vec_2133 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2134);
													mem_vec_2134 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2135);
													mem_vec_2135 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2136);
													mem_vec_2136 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2137);
													mem_vec_2137 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2138);
													mem_vec_2138 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2139);
													mem_vec_2139 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2140);
													mem_vec_2140 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2141);
													mem_vec_2141 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2142);
													mem_vec_2142 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2143);
													mem_vec_2143 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2144);
													mem_vec_2144 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2145);
													mem_vec_2145 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2146);
													mem_vec_2146 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2147);
													mem_vec_2147 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2135);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2139);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2143);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2144);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2145);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2146);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2147);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y112 = y113 + 24, y112_p_0 = 0;
			y112 < y113 + 24 + 10;
			y112 += 10, y112_p_0 += 10){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 128
			// T (f, 4) (128 / 32)
			for (f152 = f153, f152_p_1 = f153_p_0, f152_p_0 = 0;
				f152 < f153 + 128;
				f152 += 32, f152_p_1 += 32, f152_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c191 = c192, c191_p_0 = 0;
					c191 < c192 + 256;
					c191 += 8, c191_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f152, fp_2 = f152_p_1, fp_1 = f152_p_0, fp_0 = 0;
						f < f152 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y112, yp_1 = y112_p_0, yp_0 = 0;
							y < y112 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x98, xp_0 = 0;
								x < x98 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h75, hp_0 = 0;
									h < h75 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w86, wp_0 = 0;
										w < w86 + 3;
										w += 1, wp_0 += 1){
												mem_vec_2148 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2149 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2150 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2151 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_2164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c191, cp_1 = c191_p_0, cp_0 = 0;
													c < c191 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2148);
													mem_vec_2148 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2149);
													mem_vec_2149 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2150);
													mem_vec_2150 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2151);
													mem_vec_2151 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2152);
													mem_vec_2152 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2153);
													mem_vec_2153 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2154);
													mem_vec_2154 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2155);
													mem_vec_2155 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2156);
													mem_vec_2156 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2157);
													mem_vec_2157 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2158);
													mem_vec_2158 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2159);
													mem_vec_2159 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2160);
													mem_vec_2160 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2161);
													mem_vec_2161 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2162);
													mem_vec_2162 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2163);
													mem_vec_2163 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2164);
													mem_vec_2164 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2165);
													mem_vec_2165 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2166);
													mem_vec_2166 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2167);
													mem_vec_2167 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2148);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2149);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2150);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2151);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2152);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2153);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2154);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2155);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2156);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2157);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2158);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2159);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2167);
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