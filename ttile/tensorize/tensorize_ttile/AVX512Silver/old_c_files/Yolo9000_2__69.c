#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (1, x); T (17, y); T (2, f); T (4, c); T (1, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c348_p_0, cp_1, c348, f, fp_0, h, hp_0, x, xp_0, x468_p_0, xp_1, x468, y, yp_0, y458_p_0, y459_p_0, yp_1, y458_p_1, yp_2, y458, y459;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y460 = 0;
IND_TYPE x469 = 0;
IND_TYPE h172 = 0;
IND_TYPE w = 0;
IND_TYPE c349 = 0;
IND_TYPE f124 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
for (y459 = y460, y459_p_0 = 0;
	y459 < y460 + 272;
	y459 += 68, y459_p_0 += 68){
	// y = 68, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x468 = x469, x468_p_0 = 0;
		x468 < x469 + 272;
		x468 += 1, x468_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 1) (68 / 68)
		for (y458 = y459, y458_p_1 = y459_p_0, y458_p_0 = 0;
			y458 < y459 + 68;
			y458 += 68, y458_p_1 += 68, y458_p_0 += 68){
			// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (c, 4) (32 / 8)
			for (c348 = c349, c348_p_0 = 0;
				c348 < c349 + 32;
				c348 += 8, c348_p_0 += 8){
				// y = 68, x = 1, h = 3, w = 3, c = 8, f = 64
				// T (f, 2) (64 / 32)
				for (f = f124, fp_0 = 0;
					f < f124 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 3, w = 3, c = 8, f = 32
					// T (y, 17) (68 / 4)
					for (y = y458, yp_2 = y458_p_1, yp_1 = y458_p_0, yp_0 = 0;
						y < y458 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x468, xp_1 = x468_p_0, xp_0 = 0;
							x < x468 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h172, hp_0 = 0;
								h < h172 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1000 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1001 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c348, cp_1 = c348_p_0, cp_0 = 0;
											c < c348 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1000);
											mem_vec_1000 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1001);
											mem_vec_1001 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1002);
											mem_vec_1002 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1003);
											mem_vec_1003 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1004);
											mem_vec_1004 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1005);
											mem_vec_1005 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1006);
											mem_vec_1006 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1007);
											mem_vec_1007 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1000);
											mem_vec_1000 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1001);
											mem_vec_1001 = vec_17;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_20 = _mm512_set1_ps(scal_5);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_1002);
											mem_vec_1002 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_1003);
											mem_vec_1003 = vec_21;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_1004);
											mem_vec_1004 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_1005);
											mem_vec_1005 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_1006);
											mem_vec_1006 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_1007);
											mem_vec_1007 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1000);
											mem_vec_1000 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1001);
											mem_vec_1001 = vec_31;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_9);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_1002);
											mem_vec_1002 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1003);
											mem_vec_1003 = vec_35;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_37 = _mm512_set1_ps(scal_10);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_1004);
											mem_vec_1004 = vec_36;



											vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_1005);
											mem_vec_1005 = vec_38;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_1006);
											mem_vec_1006 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_1007);
											mem_vec_1007 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1007);
							}
						}
					}
				}
			}
		}
	}
}


}