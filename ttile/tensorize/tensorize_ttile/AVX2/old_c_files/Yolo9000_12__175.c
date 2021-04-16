#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (32, c); T (16, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f12_p_0, f13_p_0, fp_1, f12_p_1, fp_2, f12, f13, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y9_p_0, yp_1, y9;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y10 = 0;
IND_TYPE x6 = 0;
IND_TYPE h6 = 0;
IND_TYPE w6 = 0;
IND_TYPE c10 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f13 = f14, f13_p_0 = 0;
	f13 < f14 + 512;
	f13 += 512, f13_p_0 += 512){
		for (y9 = y10, y9_p_0 = 0;
			y9 < y10 + 24;
			y9 += 8, y9_p_0 += 8){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (f, 16) (512 / 32)
			for (f12 = f13, f12_p_1 = f13_p_0, f12_p_0 = 0;
				f12 < f13 + 512;
				f12 += 32, f12_p_1 += 32, f12_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c9 = c10, c9_p_0 = 0;
					c9 < c10 + 256;
					c9 += 8, c9_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
						f < f12 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y9, yp_1 = y9_p_0, yp_0 = 0;
							y < y9 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x6, xp_0 = 0;
								x < x6 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h6, hp_0 = 0;
									h < h6 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w6, wp_0 = 0;
										w < w6 + 3;
										w += 1, wp_0 += 1){
												mem_vec_108 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_109 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_110 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_111 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_112 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_113 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_114 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_115 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
													c < c9 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_108);
													mem_vec_108 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_109);
													mem_vec_109 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_110);
													mem_vec_110 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_111);
													mem_vec_111 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_112);
													mem_vec_112 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_113);
													mem_vec_113 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_114);
													mem_vec_114 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_115);
													mem_vec_115 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_116);
													mem_vec_116 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_117);
													mem_vec_117 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_118);
													mem_vec_118 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_119);
													mem_vec_119 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_120);
													mem_vec_120 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_121);
													mem_vec_121 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_122);
													mem_vec_122 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_123);
													mem_vec_123 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_108);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_109);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_110);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_111);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_112);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_113);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_114);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_115);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_116);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_117);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_118);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_119);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_120);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_121);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_122);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_123);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y9 = y10 + 24, y9_p_0 = 0;
			y9 < y10 + 24 + 10;
			y9 += 10, y9_p_0 += 10){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (f, 16) (512 / 32)
			for (f12 = f13, f12_p_1 = f13_p_0, f12_p_0 = 0;
				f12 < f13 + 512;
				f12 += 32, f12_p_1 += 32, f12_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c9 = c10, c9_p_0 = 0;
					c9 < c10 + 256;
					c9 += 8, c9_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
						f < f12 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y9, yp_1 = y9_p_0, yp_0 = 0;
							y < y9 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x6, xp_0 = 0;
								x < x6 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h6, hp_0 = 0;
									h < h6 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w6, wp_0 = 0;
										w < w6 + 3;
										w += 1, wp_0 += 1){
												mem_vec_124 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_125 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_126 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_127 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
													c < c9 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_124);
													mem_vec_124 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_125);
													mem_vec_125 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_126);
													mem_vec_126 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_127);
													mem_vec_127 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_128);
													mem_vec_128 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_129);
													mem_vec_129 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_130);
													mem_vec_130 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_131);
													mem_vec_131 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_132);
													mem_vec_132 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_133);
													mem_vec_133 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_134);
													mem_vec_134 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_135);
													mem_vec_135 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_136);
													mem_vec_136 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_137);
													mem_vec_137 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_138);
													mem_vec_138 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_139);
													mem_vec_139 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_140);
													mem_vec_140 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_141);
													mem_vec_141 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_142);
													mem_vec_142 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_143);
													mem_vec_143 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_124);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_125);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_126);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_127);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_128);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_129);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_130);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_131);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_135);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_139);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_143);
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