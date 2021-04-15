#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (4, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, c); T (16, f); T (8, c); T (2, f); T (8, c)]
*/
IND_TYPE c, cp_0, c40_p_0, c41_p_0, c42_p_0, cp_1, c40_p_1, c41_p_1, cp_2, c40_p_2, cp_3, c40, c41, c42, f, fp_0, f24_p_0, fp_1, f24, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y = 0;
IND_TYPE x16 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c43 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c42 = c43, c42_p_0 = 0;
	c42 < c43 + 1024;
	c42 += 128, c42_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 2) (1024 / 512)
	for (f24 = f25, f24_p_0 = 0;
		f24 < f25 + 1024;
		f24 += 512, f24_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 512
		// T (c, 8) (128 / 16)
		for (c41 = c42, c41_p_1 = c42_p_0, c41_p_0 = 0;
			c41 < c42 + 128;
			c41 += 16, c41_p_1 += 16, c41_p_0 += 16){
			// y = 7, x = 7, h = 3, w = 3, c = 16, f = 512
			// T (f, 16) (512 / 32)
			for (f = f24, fp_1 = f24_p_0, fp_0 = 0;
				f < f24 + 512;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
				// T (c, 4) (16 / 4)
				for (c40 = c41, c40_p_2 = c41_p_1, c40_p_1 = c41_p_0, c40_p_0 = 0;
					c40 < c41 + 16;
					c40 += 4, c40_p_2 += 4, c40_p_1 += 4, c40_p_0 += 4){
					// y = 7, x = 7, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h16, hp_0 = 0;
						h < h16 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 4, f = 32
							// T (x, 7) (7 / 1)
							for (x = x16, xp_0 = 0;
								x < x16 + 7;
								x += 1, xp_0 += 1){
										mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c40, cp_3 = c40_p_2, cp_2 = c40_p_1, cp_1 = c40_p_0, cp_0 = 0;
											c < c40 + 4;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_112);
											mem_vec_112 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_113);
											mem_vec_113 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_114);
											mem_vec_114 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_115);
											mem_vec_115 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_116);
											mem_vec_116 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_117);
											mem_vec_117 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_118);
											mem_vec_118 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_119);
											mem_vec_119 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_120);
											mem_vec_120 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_121);
											mem_vec_121 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_122);
											mem_vec_122 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_123);
											mem_vec_123 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_124);
											mem_vec_124 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_125);
											mem_vec_125 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_125);
							}
						}
					}
				}
			}
		}
	}
}


}