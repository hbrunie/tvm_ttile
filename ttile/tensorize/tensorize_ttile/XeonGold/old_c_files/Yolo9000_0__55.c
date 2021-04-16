#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (8, x); T (1, c);
  T (3, w); T (3, h); T (4, y); T (2, x); T (34, x); T (17, y)]
*/
IND_TYPE c, cp_0, c369_p_0, cp_1, c369, h, hp_0, w, wp_0, x, xp_0, x540_p_0, x541_p_0, xp_1, x540_p_1, xp_2, x540, x541, y, yp_0, y441_p_0, yp_1, y441;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y442 = 0;
IND_TYPE x542 = 0;
IND_TYPE h234 = 0;
IND_TYPE w270 = 0;
IND_TYPE c370 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_4112 ,mem_vec_4113 ,mem_vec_4114 ,mem_vec_4115 ,mem_vec_4116 ,mem_vec_4117 ,mem_vec_4118 ,mem_vec_4119 ,mem_vec_4120 ,mem_vec_4121 ,mem_vec_4122 ,mem_vec_4123 ,mem_vec_4124 ,mem_vec_4125 ,mem_vec_4126 ,mem_vec_4127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 17) (544 / 32)
for (y441 = y442, y441_p_0 = 0;
	y441 < y442 + 544;
	y441 += 32, y441_p_0 += 32){
	// y = 32, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 34) (544 / 16)
	for (x541 = x542, x541_p_0 = 0;
		x541 < x542 + 544;
		x541 += 16, x541_p_0 += 16){
		// y = 32, x = 16, h = 3, w = 3, c = 3, f = 32
		// T (x, 2) (16 / 8)
		for (x540 = x541, x540_p_1 = x541_p_0, x540_p_0 = 0;
			x540 < x541 + 16;
			x540 += 8, x540_p_1 += 8, x540_p_0 += 8){
			// y = 32, x = 8, h = 3, w = 3, c = 3, f = 32
			// T (y, 4) (32 / 8)
			for (y = y441, yp_1 = y441_p_0, yp_0 = 0;
				y < y441 + 32;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 8, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h234, hp_0 = 0;
					h < h234 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 8, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w270, wp_0 = 0;
						w < w270 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 8, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c369 = c370, c369_p_0 = 0;
							c369 < c370 + 3;
							c369 += 3, c369_p_0 += 3){
							// y = 8, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (x, 8) (8 / 1)
							for (x = x540, xp_2 = x540_p_1, xp_1 = x540_p_0, xp_0 = 0;
								x < x540 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c369, cp_1 = c369_p_0, cp_0 = 0;
											c < c369 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4112);
											mem_vec_4112 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4113);
											mem_vec_4113 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4114);
											mem_vec_4114 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4115);
											mem_vec_4115 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4116);
											mem_vec_4116 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4117);
											mem_vec_4117 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4118);
											mem_vec_4118 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4119);
											mem_vec_4119 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4120);
											mem_vec_4120 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4121);
											mem_vec_4121 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4122);
											mem_vec_4122 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4123);
											mem_vec_4123 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4124);
											mem_vec_4124 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4125);
											mem_vec_4125 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4126);
											mem_vec_4126 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4127);
											mem_vec_4127 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4127);
							}
						}
					}
				}
			}
		}
	}
}


}