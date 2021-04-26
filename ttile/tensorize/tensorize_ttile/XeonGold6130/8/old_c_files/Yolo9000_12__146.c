#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (16, f);
  T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c552_p_0, cp_1, c552, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x554_p_0, x555_p_0, xp_1, x554_p_1, xp_2, x554, x555, y, yp_0, y402_p_0, yp_1, y402;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y403 = 0;
IND_TYPE x556 = 0;
IND_TYPE h342 = 0;
IND_TYPE w236 = 0;
IND_TYPE c553 = 0;
IND_TYPE f668 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8119 ,mem_vec_8120 ,mem_vec_8121 ,mem_vec_8122 ,mem_vec_8123 ,mem_vec_8124 ,mem_vec_8125 ,mem_vec_8126 ,mem_vec_8127 ,mem_vec_8128 ,mem_vec_8129 ,mem_vec_8130 ,mem_vec_8131 ,mem_vec_8132 ,mem_vec_8133 ,mem_vec_8134 ,mem_vec_8135 ,mem_vec_8136 ,mem_vec_8137 ,mem_vec_8138 ,mem_vec_8139 ,mem_vec_8140 ,mem_vec_8141 ,mem_vec_8142 ,mem_vec_8143 ,mem_vec_8144 ,mem_vec_8145 ,mem_vec_8146 ,mem_vec_8147 ,mem_vec_8148 ,mem_vec_8149 ,mem_vec_8150 ,mem_vec_8151 ,mem_vec_8152 ,mem_vec_8153 ,mem_vec_8154 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (y, 1) (34 / 34)
for (y402 = y403, y402_p_0 = 0;
	y402 < y403 + 34;
	y402 += 34, y402_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 2) (34 / 17)
	for (x555 = x556, x555_p_0 = 0;
		x555 < x556 + 34;
		x555 += 17, x555_p_0 += 17){
		// y = 34, x = 17, h = 3, w = 3, c = 256, f = 512
		// T (f, 16) (512 / 32)
		for (f = f668, fp_0 = 0;
			f < f668 + 512;
			f += 32, fp_0 += 32){
				for (y = y402, yp_1 = y402_p_0, yp_0 = 0;
					y < y402 + 24;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (17 / 17)
					for (x554 = x555, x554_p_1 = x555_p_0, x554_p_0 = 0;
						x554 < x555 + 17;
						x554 += 17, x554_p_1 += 17, x554_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c552 = c553, c552_p_0 = 0;
							c552 < c553 + 256;
							c552 += 32, c552_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w236, wp_0 = 0;
								w < w236 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x554, xp_2 = x554_p_1, xp_1 = x554_p_0, xp_0 = 0;
									x < x554 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h342, hp_0 = 0;
										h < h342 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
													c < c552 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8119);
													mem_vec_8119 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8120);
													mem_vec_8120 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8121);
													mem_vec_8121 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8122);
													mem_vec_8122 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8123);
													mem_vec_8123 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8124);
													mem_vec_8124 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8125);
													mem_vec_8125 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8126);
													mem_vec_8126 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8127);
													mem_vec_8127 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8128);
													mem_vec_8128 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8129);
													mem_vec_8129 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8130);
													mem_vec_8130 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8131);
													mem_vec_8131 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8132);
													mem_vec_8132 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8133);
													mem_vec_8133 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8134);
													mem_vec_8134 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8119);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8120);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8121);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8122);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8123);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8124);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8125);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8126);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8127);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8128);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8129);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8130);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8131);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8132);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8133);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8134);
									}
								}
							}
						}
					}
				}
				for (y = y402 + 24, yp_1 = y402_p_0, yp_0 = 0;
					y < y402 + 24 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (17 / 17)
					for (x554 = x555, x554_p_1 = x555_p_0, x554_p_0 = 0;
						x554 < x555 + 17;
						x554 += 17, x554_p_1 += 17, x554_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c552 = c553, c552_p_0 = 0;
							c552 < c553 + 256;
							c552 += 32, c552_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w236, wp_0 = 0;
								w < w236 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x554, xp_2 = x554_p_1, xp_1 = x554_p_0, xp_0 = 0;
									x < x554 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h342, hp_0 = 0;
										h < h342 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8135 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_8153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
													c < c552 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8135);
													mem_vec_8135 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8136);
													mem_vec_8136 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8137);
													mem_vec_8137 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8138);
													mem_vec_8138 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8139);
													mem_vec_8139 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8140);
													mem_vec_8140 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8141);
													mem_vec_8141 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8142);
													mem_vec_8142 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8143);
													mem_vec_8143 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8144);
													mem_vec_8144 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8145);
													mem_vec_8145 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8146);
													mem_vec_8146 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8147);
													mem_vec_8147 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8148);
													mem_vec_8148 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8149);
													mem_vec_8149 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8150);
													mem_vec_8150 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8151);
													mem_vec_8151 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8152);
													mem_vec_8152 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8153);
													mem_vec_8153 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8154);
													mem_vec_8154 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8135);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8136);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8137);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8153);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8154);
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