#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (3, w); T (3, h); T (4, y); T (136, x); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c348_p_0, cp_1, c348, h, hp_0, w, wp_0, x, xp_0, x512_p_0, x513_p_0, xp_1, x512_p_1, xp_2, x512, x513, y, yp_0, y420_p_0, yp_1, y420;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y421 = 0;
IND_TYPE x514 = 0;
IND_TYPE h220 = 0;
IND_TYPE w256 = 0;
IND_TYPE c349 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,mem_vec_4008 ,mem_vec_4009 ,mem_vec_4010 ,mem_vec_4011 ,mem_vec_4012 ,mem_vec_4013 ,mem_vec_4014 ,mem_vec_4015 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 17) (544 / 32)
for (y420 = y421, y420_p_0 = 0;
	y420 < y421 + 544;
	y420 += 32, y420_p_0 += 32){
	// y = 32, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 1) (544 / 544)
	for (x513 = x514, x513_p_0 = 0;
		x513 < x514 + 544;
		x513 += 544, x513_p_0 += 544){
		// y = 32, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 136) (544 / 4)
		for (x512 = x513, x512_p_1 = x513_p_0, x512_p_0 = 0;
			x512 < x513 + 544;
			x512 += 4, x512_p_1 += 4, x512_p_0 += 4){
			// y = 32, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 4) (32 / 8)
			for (y = y420, yp_1 = y420_p_0, yp_0 = 0;
				y < y420 + 32;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h220, hp_0 = 0;
					h < h220 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 4, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w256, wp_0 = 0;
						w < w256 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 4, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c348 = c349, c348_p_0 = 0;
							c348 < c349 + 3;
							c348 += 3, c348_p_0 += 3){
							// y = 8, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x512, xp_2 = x512_p_1, xp_1 = x512_p_0, xp_0 = 0;
								x < x512 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4000 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4001 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c348, cp_1 = c348_p_0, cp_0 = 0;
											c < c348 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4000);
											mem_vec_4000 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4001);
											mem_vec_4001 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4002);
											mem_vec_4002 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4003);
											mem_vec_4003 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4004);
											mem_vec_4004 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4005);
											mem_vec_4005 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4006);
											mem_vec_4006 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4007);
											mem_vec_4007 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4008);
											mem_vec_4008 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4009);
											mem_vec_4009 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4010);
											mem_vec_4010 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4011);
											mem_vec_4011 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4012);
											mem_vec_4012 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4013);
											mem_vec_4013 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4014);
											mem_vec_4014 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4015);
											mem_vec_4015 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4007);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4011);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4012);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4013);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4014);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4015);
							}
						}
					}
				}
			}
		}
	}
}


}