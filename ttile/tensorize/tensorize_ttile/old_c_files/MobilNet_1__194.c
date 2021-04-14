#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (56, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 3), (Arg 14))]; T (2, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, h, hp_0, w, wp_0, x, xp_0, x720_p_0, x721_p_0, xp_1, x720_p_1, xp_2, x720, x721, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y360 = 0;
IND_TYPE x722 = 0;
IND_TYPE h340 = 0;
IND_TYPE w360 = 0;
IND_TYPE c541 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6100 ,mem_vec_6101 ,mem_vec_6102 ,mem_vec_6103 ,mem_vec_6104 ,mem_vec_6105 ,mem_vec_6106 ,mem_vec_6107 ,mem_vec_6108 ,mem_vec_6109 ,mem_vec_6110 ,mem_vec_6111 ,mem_vec_6112 ,mem_vec_6113 ,mem_vec_6114 ,mem_vec_6115 ,mem_vec_6116 ,mem_vec_6117 ,mem_vec_6118 ,mem_vec_6119 ,mem_vec_6120 ,mem_vec_6121 ,mem_vec_6122 ,mem_vec_6123 ,mem_vec_6124 ,mem_vec_6125 ,mem_vec_6126 ,mem_vec_6127 ,mem_vec_6128 ,mem_vec_6129 ,mem_vec_6130 ,mem_vec_6131 ,mem_vec_6132 ,mem_vec_6133 ,mem_vec_6134 ,mem_vec_6135 ,mem_vec_6136 ,mem_vec_6137 ,mem_vec_6138 ,mem_vec_6139 ,mem_vec_6140 ,mem_vec_6141 ,mem_vec_6142 ,mem_vec_6143 ,mem_vec_6144 ,mem_vec_6145 ,mem_vec_6146 ,mem_vec_6147 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
for (x721 = x722, x721_p_0 = 0;
	x721 < x722 + 112;
	x721 += 56, x721_p_0 += 56){
	// y = 112, x = 56, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c540 = c541, c540_p_0 = 0;
		c540 < c541 + 32;
		c540 += 16, c540_p_0 += 16){
			for (y = y360, yp_0 = 0;
				y < y360 + 70;
				y += 10, yp_0 += 10){
				// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
				// T (x, 56) (56 / 1)
				for (x720 = x721, x720_p_1 = x721_p_0, x720_p_0 = 0;
					x720 < x721 + 56;
					x720 += 1, x720_p_1 += 1, x720_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h340, hp_0 = 0;
						h < h340 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w360, wp_0 = 0;
							w < w360 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x720, xp_2 = x720_p_1, xp_1 = x720_p_0, xp_0 = 0;
								x < x720 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6100 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6101 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_6118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6100);
											mem_vec_6100 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6101);
											mem_vec_6101 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6102);
											mem_vec_6102 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6103);
											mem_vec_6103 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6104);
											mem_vec_6104 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6105);
											mem_vec_6105 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6106);
											mem_vec_6106 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6107);
											mem_vec_6107 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6108);
											mem_vec_6108 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6109);
											mem_vec_6109 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6110);
											mem_vec_6110 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6111);
											mem_vec_6111 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6112);
											mem_vec_6112 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6113);
											mem_vec_6113 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6114);
											mem_vec_6114 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6115);
											mem_vec_6115 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6116);
											mem_vec_6116 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6117);
											mem_vec_6117 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6118);
											mem_vec_6118 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6119);
											mem_vec_6119 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6100);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6101);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6102);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6103);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6104);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6105);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6106);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6107);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6108);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6109);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6110);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6111);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6119);
							}
						}
					}
				}
			}
			for (y = y360 + 70, yp_0 = 0;
				y < y360 + 70 + 42;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
				// T (x, 56) (56 / 1)
				for (x720 = x721, x720_p_1 = x721_p_0, x720_p_0 = 0;
					x720 < x721 + 56;
					x720 += 1, x720_p_1 += 1, x720_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h340, hp_0 = 0;
						h < h340 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w360, wp_0 = 0;
							w < w360 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x720, xp_2 = x720_p_1, xp_1 = x720_p_0, xp_0 = 0;
								x < x720 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_6138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_6140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_6142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_6143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_6144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_6145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_6146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_6147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6120);
											mem_vec_6120 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6121);
											mem_vec_6121 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6122);
											mem_vec_6122 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6123);
											mem_vec_6123 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6124);
											mem_vec_6124 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6125);
											mem_vec_6125 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6126);
											mem_vec_6126 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6127);
											mem_vec_6127 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6128);
											mem_vec_6128 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6129);
											mem_vec_6129 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6130);
											mem_vec_6130 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6131);
											mem_vec_6131 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6132);
											mem_vec_6132 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6133);
											mem_vec_6133 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6134);
											mem_vec_6134 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6135);
											mem_vec_6135 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6136);
											mem_vec_6136 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6137);
											mem_vec_6137 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6138);
											mem_vec_6138 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6139);
											mem_vec_6139 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6140);
											mem_vec_6140 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6141);
											mem_vec_6141 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6142);
											mem_vec_6142 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6143);
											mem_vec_6143 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6144);
											mem_vec_6144 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6145);
											mem_vec_6145 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_6146);
											mem_vec_6146 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_6147);
											mem_vec_6147 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6127);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6131);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6132);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6133);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6134);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6135);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_6147);
							}
						}
					}
				}
			}
	}
}


}