#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (256, c); Hoist_vars [c]; T (7, x); T (1, c);
  T (1, f); T (1, y); T (8, f)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, f5_p_0, fp_1, f5, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y3 = 0;
IND_TYPE x5 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f6 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f5 = f6, f5_p_0 = 0;
	f5 < f6 + 512;
	f5 += 64, f5_p_0 += 64){
	// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
	// T (y, 1) (7 / 7)
	for (y = y3, yp_0 = 0;
		y < y3 + 7;
		y += 7, yp_0 += 7){
		// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
		// T (f, 1) (64 / 64)
		for (f = f5, fp_1 = f5_p_0, fp_0 = 0;
			f < f5 + 64;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
			// T (c, 1) (256 / 256)
			for (c6 = c7, c6_p_0 = 0;
				c6 < c7 + 256;
				c6 += 256, c6_p_0 += 256){
				// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
				// T (x, 7) (7 / 1)
				for (x = x5, xp_0 = 0;
					x < x5 + 7;
					x += 1, xp_0 += 1){
							mem_vec_42 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_43 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_44 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_45 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_46 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_47 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_48 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_49 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_50 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_51 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_52 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_53 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_54 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_55 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_56 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_57 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_58 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_59 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_60 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_61 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_62 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_63 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_64 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_65 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							mem_vec_66 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_67 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_68 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
							mem_vec_69 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
							// y = 7, x = 1, h = 1, w = 1, c = 256, f = 64
							// T (c, 256) (256 / 1)
							for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
								c < c6 + 256;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_42);
								mem_vec_42 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_43);
								mem_vec_43 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_44);
								mem_vec_44 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_45);
								mem_vec_45 = vec_7;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_46);
								mem_vec_46 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_47);
								mem_vec_47 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_48);
								mem_vec_48 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_49);
								mem_vec_49 = vec_13;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_50);
								mem_vec_50 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_51);
								mem_vec_51 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_52);
								mem_vec_52 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_53);
								mem_vec_53 = vec_18;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_54);
								mem_vec_54 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_55);
								mem_vec_55 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_56);
								mem_vec_56 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_57);
								mem_vec_57 = vec_23;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_58);
								mem_vec_58 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_59);
								mem_vec_59 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_60);
								mem_vec_60 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_61);
								mem_vec_61 = vec_28;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_62);
								mem_vec_62 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_63);
								mem_vec_63 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_64);
								mem_vec_64 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_65);
								mem_vec_65 = vec_33;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_66);
								mem_vec_66 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_67);
								mem_vec_67 = vec_36;



								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_68);
								mem_vec_68 = vec_37;



								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_69);
								mem_vec_69 = vec_38;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_42);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_43);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_44);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_45);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_46);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_47);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_48);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_49);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_50);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_51);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_52);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_53);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_54);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_55);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_56);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_57);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_58);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_59);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_60);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_61);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_62);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_63);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_64);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_65);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_66);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_67);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_68);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_69);
				}
			}
		}
	}
}


}