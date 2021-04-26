#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (3, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (64, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (1, f);
  T (1, y); T (1, c); T (589, f)]
*/
IND_TYPE c, cp_0, c540_p_0, c541_p_0, cp_1, c540_p_1, cp_2, c540, c541, f, fp_0, f405_p_0, fp_1, f405, x, xp_0, y, yp_0, y405_p_0, yp_1, y405;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y406 = 0;
IND_TYPE x270 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c542 = 0;
IND_TYPE f406 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_6099 ,mem_vec_6100 ,mem_vec_6101 ,mem_vec_6102 ,mem_vec_6103 ,mem_vec_6104 ,mem_vec_6105 ,mem_vec_6106 ,mem_vec_6107 ,mem_vec_6108 ,mem_vec_6109 ,mem_vec_6110 ,mem_vec_6111 ,mem_vec_6112 ,mem_vec_6113 ,mem_vec_6114 ,mem_vec_6115 ,mem_vec_6116 ,mem_vec_6117 ,mem_vec_6118 ,mem_vec_6119 ,mem_vec_6120 ,mem_vec_6121 ,mem_vec_6122 ,mem_vec_6123 ,mem_vec_6124 ,mem_vec_6125 ,mem_vec_6126 ,mem_vec_6127 ,mem_vec_6128 ,mem_vec_6129 ,mem_vec_6130 ,mem_vec_6131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 589) (28272 / 48)
for (f405 = f406, f405_p_0 = 0;
	f405 < f406 + 28272;
	f405 += 48, f405_p_0 += 48){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 48
	// T (c, 1) (1024 / 1024)
	for (c541 = c542, c541_p_0 = 0;
		c541 < c542 + 1024;
		c541 += 1024, c541_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 48
		// T (y, 1) (17 / 17)
		for (y405 = y406, y405_p_0 = 0;
			y405 < y406 + 17;
			y405 += 17, y405_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 48
			// T (f, 1) (48 / 48)
			for (f = f405, fp_1 = f405_p_0, fp_0 = 0;
				f < f405 + 48;
				f += 48, fp_1 += 48, fp_0 += 48){
					for (y = y405, yp_1 = y405_p_0, yp_0 = 0;
						y < y405 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
						// T (c, 64) (1024 / 16)
						for (c540 = c541, c540_p_1 = c541_p_0, c540_p_0 = 0;
							c540 < c541 + 1024;
							c540 += 16, c540_p_1 += 16, c540_p_0 += 16){
							// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 48
							// T (x, 17) (17 / 1)
							for (x = x270, xp_0 = 0;
								x < x270 + 17;
								x += 1, xp_0 += 1){
										mem_vec_6099 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6100 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6101 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 48
										// T (c, 16) (16 / 1)
										for (c = c540, cp_2 = c540_p_1, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6099);
											mem_vec_6099 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6100);
											mem_vec_6100 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6101);
											mem_vec_6101 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6102);
											mem_vec_6102 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_6103);
											mem_vec_6103 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_6104);
											mem_vec_6104 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6105);
											mem_vec_6105 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6106);
											mem_vec_6106 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_6107);
											mem_vec_6107 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6108);
											mem_vec_6108 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_6109);
											mem_vec_6109 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_6110);
											mem_vec_6110 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6111);
											mem_vec_6111 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6112);
											mem_vec_6112 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6113);
											mem_vec_6113 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6099);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6100);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6101);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6102);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6103);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6104);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6105);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6106);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6107);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6108);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6109);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6110);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6111);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6113);
							}
						}
					}
					for (y = y405 + 5, yp_1 = y405_p_0, yp_0 = 0;
						y < y405 + 5 + 12;
						y += 6, yp_1 += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
						// T (c, 64) (1024 / 16)
						for (c540 = c541, c540_p_1 = c541_p_0, c540_p_0 = 0;
							c540 < c541 + 1024;
							c540 += 16, c540_p_1 += 16, c540_p_0 += 16){
							// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 48
							// T (x, 17) (17 / 1)
							for (x = x270, xp_0 = 0;
								x < x270 + 17;
								x += 1, xp_0 += 1){
										mem_vec_6114 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6115 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 48
										// T (c, 16) (16 / 1)
										for (c = c540, cp_2 = c540_p_1, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6114);
											mem_vec_6114 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6115);
											mem_vec_6115 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6116);
											mem_vec_6116 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6117);
											mem_vec_6117 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_6118);
											mem_vec_6118 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_6119);
											mem_vec_6119 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6120);
											mem_vec_6120 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6121);
											mem_vec_6121 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_6122);
											mem_vec_6122 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6123);
											mem_vec_6123 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_6124);
											mem_vec_6124 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_6125);
											mem_vec_6125 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6126);
											mem_vec_6126 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6127);
											mem_vec_6127 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6128);
											mem_vec_6128 = vec_22;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_24 = _mm512_set1_ps(scal_5);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6129);
											mem_vec_6129 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6130);
											mem_vec_6130 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_6, mem_vec_6131);
											mem_vec_6131 = vec_26;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6127);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6131);
							}
						}
					}
			}
		}
	}
}


}