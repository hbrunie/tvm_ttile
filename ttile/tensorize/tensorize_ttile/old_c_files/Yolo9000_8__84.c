#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (4, f); T (16, c); T (1, f); T (68, x); T (2, f)]
*/
IND_TYPE c, cp_0, c990_p_0, cp_1, c990, f, fp_0, f1320_p_0, f1321_p_0, fp_1, f1320_p_1, fp_2, f1320, f1321, h, hp_0, w, wp_0, x, xp_0, x1042_p_0, xp_1, x1042, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y660 = 0;
IND_TYPE x1043 = 0;
IND_TYPE h660 = 0;
IND_TYPE w608 = 0;
IND_TYPE c991 = 0;
IND_TYPE f1322 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13112 ,mem_vec_13113 ,mem_vec_13114 ,mem_vec_13115 ,mem_vec_13116 ,mem_vec_13117 ,mem_vec_13118 ,mem_vec_13119 ,mem_vec_13120 ,mem_vec_13121 ,mem_vec_13122 ,mem_vec_13123 ,mem_vec_13124 ,mem_vec_13125 ,mem_vec_13126 ,mem_vec_13127 ,mem_vec_13128 ,mem_vec_13129 ,mem_vec_13130 ,mem_vec_13131 ,mem_vec_13132 ,mem_vec_13133 ,mem_vec_13134 ,mem_vec_13135 ,mem_vec_13136 ,mem_vec_13137 ,mem_vec_13138 ,mem_vec_13139 ,mem_vec_13140 ,mem_vec_13141 ,mem_vec_13142 ,mem_vec_13143 ,mem_vec_13144 ,mem_vec_13145 ,mem_vec_13146 ,mem_vec_13147 ,mem_vec_13148 ,mem_vec_13149 ,mem_vec_13150 ,mem_vec_13151 ,mem_vec_13152 ,mem_vec_13153 ,mem_vec_13154 ,mem_vec_13155 ,mem_vec_13156 ,mem_vec_13157 ,mem_vec_13158 ,mem_vec_13159 ,mem_vec_13160 ,mem_vec_13161 ,mem_vec_13162 ,mem_vec_13163 ,mem_vec_13164 ,mem_vec_13165 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1321 = f1322, f1321_p_0 = 0;
	f1321 < f1322 + 256;
	f1321 += 128, f1321_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 68) (68 / 1)
	for (x1042 = x1043, x1042_p_0 = 0;
		x1042 < x1043 + 68;
		x1042 += 1, x1042_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 128, f = 128
		// T (f, 1) (128 / 128)
		for (f1320 = f1321, f1320_p_1 = f1321_p_0, f1320_p_0 = 0;
			f1320 < f1321 + 128;
			f1320 += 128, f1320_p_1 += 128, f1320_p_0 += 128){
			// y = 68, x = 1, h = 3, w = 3, c = 128, f = 128
			// T (c, 16) (128 / 8)
			for (c990 = c991, c990_p_0 = 0;
				c990 < c991 + 128;
				c990 += 8, c990_p_0 += 8){
				// y = 68, x = 1, h = 3, w = 3, c = 8, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1320, fp_2 = f1320_p_1, fp_1 = f1320_p_0, fp_0 = 0;
					f < f1320 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y660, yp_0 = 0;
							y < y660 + 26;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h660, hp_0 = 0;
								h < h660 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w608, wp_0 = 0;
									w < w608 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1042, xp_1 = x1042_p_0, xp_0 = 0;
										x < x1042 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_13125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_13126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_13127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_13128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_13129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_13130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_13131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_13132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_13133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_13134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_13135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_13136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_13137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
													c < c990 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13112);
													mem_vec_13112 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13113);
													mem_vec_13113 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13114);
													mem_vec_13114 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13115);
													mem_vec_13115 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13116);
													mem_vec_13116 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13117);
													mem_vec_13117 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13118);
													mem_vec_13118 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13119);
													mem_vec_13119 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13120);
													mem_vec_13120 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13121);
													mem_vec_13121 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13122);
													mem_vec_13122 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13123);
													mem_vec_13123 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13124);
													mem_vec_13124 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13125);
													mem_vec_13125 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13126);
													mem_vec_13126 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13127);
													mem_vec_13127 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13128);
													mem_vec_13128 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13129);
													mem_vec_13129 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13130);
													mem_vec_13130 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13131);
													mem_vec_13131 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13132);
													mem_vec_13132 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13133);
													mem_vec_13133 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13134);
													mem_vec_13134 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13135);
													mem_vec_13135 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13136);
													mem_vec_13136 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13137);
													mem_vec_13137 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13112);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13113);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13114);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13115);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13116);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13117);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13118);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13119);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13120);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13121);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13122);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13123);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13124);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13125);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13126);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13127);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13128);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13129);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13130);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13131);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13132);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13133);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13134);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13135);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13136);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13137);
									}
								}
							}
						}
						for (y = y660 + 26, yp_0 = 0;
							y < y660 + 26 + 42;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h660, hp_0 = 0;
								h < h660 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w608, wp_0 = 0;
									w < w608 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1042, xp_1 = x1042_p_0, xp_0 = 0;
										x < x1042 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_13151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_13152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_13153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_13154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_13155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_13156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_13157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_13158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_13159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_13160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_13161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_13162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_13163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_13164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_13165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
													c < c990 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13138);
													mem_vec_13138 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13139);
													mem_vec_13139 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13140);
													mem_vec_13140 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13141);
													mem_vec_13141 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13142);
													mem_vec_13142 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13143);
													mem_vec_13143 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13144);
													mem_vec_13144 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13145);
													mem_vec_13145 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13146);
													mem_vec_13146 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13147);
													mem_vec_13147 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13148);
													mem_vec_13148 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13149);
													mem_vec_13149 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13150);
													mem_vec_13150 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13151);
													mem_vec_13151 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13152);
													mem_vec_13152 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13153);
													mem_vec_13153 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13154);
													mem_vec_13154 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13155);
													mem_vec_13155 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13156);
													mem_vec_13156 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13157);
													mem_vec_13157 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13158);
													mem_vec_13158 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13159);
													mem_vec_13159 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13160);
													mem_vec_13160 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13161);
													mem_vec_13161 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13162);
													mem_vec_13162 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13163);
													mem_vec_13163 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_13164);
													mem_vec_13164 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_13165);
													mem_vec_13165 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13153);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13157);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_13164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_13165);
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