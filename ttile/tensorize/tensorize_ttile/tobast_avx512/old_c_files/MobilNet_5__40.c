#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (64, c); T (4, f); T (7, x); T (4, y); T (2, c)]
*/
IND_TYPE c, cp_0, c24_p_0, c25_p_0, cp_1, c24_p_1, cp_2, c24, c25, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c26 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (c, 2) (256 / 128)
for (c25 = c26, c25_p_0 = 0;
	c25 < c26 + 256;
	c25 += 128, c25_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
	// T (y, 4) (28 / 7)
	for (y = y12, yp_0 = 0;
		y < y12 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 256
		// T (x, 7) (28 / 4)
		for (x18 = x19, x18_p_0 = 0;
			x18 < x19 + 28;
			x18 += 4, x18_p_0 += 4){
			// y = 7, x = 4, h = 3, w = 3, c = 128, f = 256
			// T (f, 4) (256 / 64)
			for (f = f12, fp_0 = 0;
				f < f12 + 256;
				f += 64, fp_0 += 64){
				// y = 7, x = 4, h = 3, w = 3, c = 128, f = 64
				// T (c, 64) (128 / 2)
				for (c24 = c25, c24_p_1 = c25_p_0, c24_p_0 = 0;
					c24 < c25 + 128;
					c24 += 2, c24_p_1 += 2, c24_p_0 += 2){
					// y = 7, x = 4, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h12, hp_0 = 0;
						h < h12 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 4, h = 1, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w12, wp_0 = 0;
							w < w12 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 4, h = 1, w = 1, c = 2, f = 64
							// T (x, 4) (4 / 1)
							for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
								x < x18 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c24, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;
											c < c24 + 2;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_96);
											mem_vec_96 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_97);
											mem_vec_97 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_98);
											mem_vec_98 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_99);
											mem_vec_99 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_100);
											mem_vec_100 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_101);
											mem_vec_101 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_102);
											mem_vec_102 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_103);
											mem_vec_103 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_104);
											mem_vec_104 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_105);
											mem_vec_105 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_106);
											mem_vec_106 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_107);
											mem_vec_107 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_108);
											mem_vec_108 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_109);
											mem_vec_109 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_110);
											mem_vec_110 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_111);
											mem_vec_111 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_112);
											mem_vec_112 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_113);
											mem_vec_113 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_114);
											mem_vec_114 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_115);
											mem_vec_115 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_116);
											mem_vec_116 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_117);
											mem_vec_117 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_118);
											mem_vec_118 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_119);
											mem_vec_119 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_120);
											mem_vec_120 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_121);
											mem_vec_121 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_122);
											mem_vec_122 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_123);
											mem_vec_123 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_96);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_97);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_98);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_99);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_100);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_101);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_102);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_103);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_104);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_105);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_106);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_107);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_108);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_109);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_110);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_111);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_123);
							}
						}
					}
				}
			}
		}
	}
}


}