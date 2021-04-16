#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (2, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c588_p_0, cp_1, c588, f, fp_0, f784_p_0, f785_p_0, fp_1, f784_p_1, fp_2, f784, f785, h, hp_0, w, wp_0, x, xp_0, x588_p_0, xp_1, x588, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y392 = 0;
IND_TYPE x589 = 0;
IND_TYPE h280 = 0;
IND_TYPE w265 = 0;
IND_TYPE c589 = 0;
IND_TYPE f786 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8128 ,mem_vec_8129 ,mem_vec_8130 ,mem_vec_8131 ,mem_vec_8132 ,mem_vec_8133 ,mem_vec_8134 ,mem_vec_8135 ,mem_vec_8136 ,mem_vec_8137 ,mem_vec_8138 ,mem_vec_8139 ,mem_vec_8140 ,mem_vec_8141 ,mem_vec_8142 ,mem_vec_8143 ,mem_vec_8144 ,mem_vec_8145 ,mem_vec_8146 ,mem_vec_8147 ,mem_vec_8148 ,mem_vec_8149 ,mem_vec_8150 ,mem_vec_8151 ,mem_vec_8152 ,mem_vec_8153 ,mem_vec_8154 ,mem_vec_8155 ,mem_vec_8156 ,mem_vec_8157 ,mem_vec_8158 ,mem_vec_8159 ,mem_vec_8160 ,mem_vec_8161 ,mem_vec_8162 ,mem_vec_8163 ,mem_vec_8164 ,mem_vec_8165 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f785 = f786, f785_p_0 = 0;
	f785 < f786 + 256;
	f785 += 128, f785_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 1) (128 / 128)
	for (f784 = f785, f784_p_1 = f785_p_0, f784_p_0 = 0;
		f784 < f785 + 128;
		f784 += 128, f784_p_1 += 128, f784_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (68 / 34)
		for (x588 = x589, x588_p_0 = 0;
			x588 < x589 + 68;
			x588 += 34, x588_p_0 += 34){
				for (y = y392, yp_0 = 0;
					y < y392 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f784, fp_2 = f784_p_1, fp_1 = f784_p_0, fp_0 = 0;
						f < f784 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c588 = c589, c588_p_0 = 0;
							c588 < c589 + 128;
							c588 += 16, c588_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w265, wp_0 = 0;
								w < w265 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x588, xp_1 = x588_p_0, xp_0 = 0;
									x < x588 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h280, hp_0 = 0;
										h < h280 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8128 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8129 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c588, cp_1 = c588_p_0, cp_0 = 0;
													c < c588 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8128);
													mem_vec_8128 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8129);
													mem_vec_8129 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8130);
													mem_vec_8130 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8131);
													mem_vec_8131 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8132);
													mem_vec_8132 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8133);
													mem_vec_8133 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8134);
													mem_vec_8134 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8135);
													mem_vec_8135 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8136);
													mem_vec_8136 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8137);
													mem_vec_8137 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8138);
													mem_vec_8138 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8139);
													mem_vec_8139 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8140);
													mem_vec_8140 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8141);
													mem_vec_8141 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8142);
													mem_vec_8142 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8143);
													mem_vec_8143 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8144);
													mem_vec_8144 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8145);
													mem_vec_8145 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8128);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8129);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8130);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8131);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8132);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8133);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8134);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8135);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8136);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8137);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8145);
									}
								}
							}
						}
					}
				}
				for (y = y392 + 18, yp_0 = 0;
					y < y392 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f784, fp_2 = f784_p_1, fp_1 = f784_p_0, fp_0 = 0;
						f < f784 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c588 = c589, c588_p_0 = 0;
							c588 < c589 + 128;
							c588 += 16, c588_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w265, wp_0 = 0;
								w < w265 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x588, xp_1 = x588_p_0, xp_0 = 0;
									x < x588 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h280, hp_0 = 0;
										h < h280 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8146 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8147 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_8164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c588, cp_1 = c588_p_0, cp_0 = 0;
													c < c588 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8146);
													mem_vec_8146 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8147);
													mem_vec_8147 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8148);
													mem_vec_8148 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8149);
													mem_vec_8149 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8150);
													mem_vec_8150 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8151);
													mem_vec_8151 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8152);
													mem_vec_8152 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8153);
													mem_vec_8153 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8154);
													mem_vec_8154 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8155);
													mem_vec_8155 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8156);
													mem_vec_8156 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8157);
													mem_vec_8157 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8158);
													mem_vec_8158 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8159);
													mem_vec_8159 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8160);
													mem_vec_8160 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8161);
													mem_vec_8161 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8162);
													mem_vec_8162 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8163);
													mem_vec_8163 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8164);
													mem_vec_8164 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8165);
													mem_vec_8165 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8153);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8157);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8165);
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