#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (128, c); Hoist_vars [c]; T (7, x); T (2, c);
  T (8, f); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f8_p_0, fp_1, f8, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y5 = 0;
IND_TYPE x7 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f9 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_70 ,mem_vec_71 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,mem_vec_76 ,mem_vec_77 ,mem_vec_78 ,mem_vec_79 ,mem_vec_80 ,mem_vec_81 ,mem_vec_82 ,mem_vec_83 ,mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f8 = f9, f8_p_0 = 0;
	f8 < f9 + 512;
	f8 += 512, f8_p_0 += 512){
	// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
	// T (y, 1) (7 / 7)
	for (y = y5, yp_0 = 0;
		y < y5 + 7;
		y += 7, yp_0 += 7){
		// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
		// T (f, 8) (512 / 64)
		for (f = f8, fp_1 = f8_p_0, fp_0 = 0;
			f < f8 + 512;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
			// T (c, 2) (256 / 128)
			for (c9 = c10, c9_p_0 = 0;
				c9 < c10 + 256;
				c9 += 128, c9_p_0 += 128){
				// y = 7, x = 7, h = 1, w = 1, c = 128, f = 64
				// T (x, 7) (7 / 1)
				for (x = x7, xp_0 = 0;
					x < x7 + 7;
					x += 1, xp_0 += 1){
							mem_vec_70 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_71 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_72 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_73 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_74 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_75 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_76 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_77 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_78 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_79 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_80 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_81 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_82 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_83 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_84 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_85 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_86 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_87 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
							mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
							// y = 7, x = 1, h = 1, w = 1, c = 128, f = 64
							// T (c, 128) (128 / 1)
							for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
								c < c9 + 128;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_70);
								mem_vec_70 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_71);
								mem_vec_71 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_72);
								mem_vec_72 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_73);
								mem_vec_73 = vec_7;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_74);
								mem_vec_74 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_75);
								mem_vec_75 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_76);
								mem_vec_76 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_77);
								mem_vec_77 = vec_13;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_78);
								mem_vec_78 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_79);
								mem_vec_79 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_80);
								mem_vec_80 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_81);
								mem_vec_81 = vec_18;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_82);
								mem_vec_82 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_83);
								mem_vec_83 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_84);
								mem_vec_84 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_85);
								mem_vec_85 = vec_23;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_86);
								mem_vec_86 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_87);
								mem_vec_87 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_88);
								mem_vec_88 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_89);
								mem_vec_89 = vec_28;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_90);
								mem_vec_90 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_91);
								mem_vec_91 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_92);
								mem_vec_92 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_93);
								mem_vec_93 = vec_33;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_94);
								mem_vec_94 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_95);
								mem_vec_95 = vec_36;



								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_96);
								mem_vec_96 = vec_37;



								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_97);
								mem_vec_97 = vec_38;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_70);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_71);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_72);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_73);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_74);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_75);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_76);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_77);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_78);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_79);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_80);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_81);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_82);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_83);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_84);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_85);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_86);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_87);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_88);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_89);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_90);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_91);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_92);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_93);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_94);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_95);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_96);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_97);
				}
			}
		}
	}
}


}