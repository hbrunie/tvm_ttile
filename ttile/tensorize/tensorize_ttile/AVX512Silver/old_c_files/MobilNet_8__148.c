#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (7, x); T (8, c); T (2, f); T (8, f)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, f156_p_0, fp_1, f156, h, hp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x130 = 0;
IND_TYPE h98 = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f157 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 8) (512 / 64)
for (f156 = f157, f156_p_0 = 0;
	f156 < f157 + 512;
	f156 += 64, f156_p_0 += 64){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
	// T (f, 2) (64 / 32)
	for (f = f156, fp_1 = f156_p_0, fp_0 = 0;
		f < f156 + 64;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 8) (512 / 64)
		for (c234 = c235, c234_p_0 = 0;
			c234 < c235 + 512;
			c234 += 64, c234_p_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
			// T (x, 7) (7 / 1)
			for (x = x130, xp_0 = 0;
				x < x130 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (h, 3) (3 / 1)
				for (h = h98, hp_0 = 0;
					h < h98 + 3;
					h += 1, hp_0 += 1){
							mem_vec_1015 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_1016 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_1017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_1018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_1019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_1020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_1021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_1022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_1023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_1024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_1025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_1026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_1027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_1028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							// y = 7, x = 1, h = 1, w = 3, c = 64, f = 32
							// T (c, 64) (64 / 1)
							for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
								c < c234 + 64;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1015);
								mem_vec_1015 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1016);
								mem_vec_1016 = vec_3;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1017);
								mem_vec_1017 = vec_5;



								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1018);
								mem_vec_1018 = vec_7;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);


								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1019);
								mem_vec_1019 = vec_8;



								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1020);
								mem_vec_1020 = vec_10;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1021);
								mem_vec_1021 = vec_11;



								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1022);
								mem_vec_1022 = vec_13;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1023);
								mem_vec_1023 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1024);
								mem_vec_1024 = vec_16;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);


								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1025);
								mem_vec_1025 = vec_17;



								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1026);
								mem_vec_1026 = vec_19;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1027);
								mem_vec_1027 = vec_20;



								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1028);
								mem_vec_1028 = vec_22;
								scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
								vec_24 = _mm512_set1_ps(scal_7);
								vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

								vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_1015);
								mem_vec_1015 = vec_23;

								vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

								vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_1016);
								mem_vec_1016 = vec_26;
								scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
								vec_29 = _mm512_set1_ps(scal_8);


								vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_1017);
								mem_vec_1017 = vec_28;



								vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_1018);
								mem_vec_1018 = vec_30;
								scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
								vec_32 = _mm512_set1_ps(scal_9);


								vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_1019);
								mem_vec_1019 = vec_31;



								vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_1020);
								mem_vec_1020 = vec_33;
								scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
								vec_35 = _mm512_set1_ps(scal_10);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_1021);
								mem_vec_1021 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_1022);
								mem_vec_1022 = vec_36;
								scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
								vec_38 = _mm512_set1_ps(scal_11);


								vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_1023);
								mem_vec_1023 = vec_37;



								vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_1024);
								mem_vec_1024 = vec_39;
								scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
								vec_41 = _mm512_set1_ps(scal_12);


								vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_1025);
								mem_vec_1025 = vec_40;



								vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_1026);
								mem_vec_1026 = vec_42;
								scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
								vec_44 = _mm512_set1_ps(scal_13);


								vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_1027);
								mem_vec_1027 = vec_43;



								vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_1028);
								mem_vec_1028 = vec_45;
								scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
								vec_47 = _mm512_set1_ps(scal_14);
								vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

								vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_1015);
								mem_vec_1015 = vec_46;

								vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

								vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_1016);
								mem_vec_1016 = vec_49;
								scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
								vec_52 = _mm512_set1_ps(scal_15);


								vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_1017);
								mem_vec_1017 = vec_51;



								vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_1018);
								mem_vec_1018 = vec_53;
								scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
								vec_55 = _mm512_set1_ps(scal_16);


								vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_1019);
								mem_vec_1019 = vec_54;



								vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_1020);
								mem_vec_1020 = vec_56;
								scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
								vec_58 = _mm512_set1_ps(scal_17);


								vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_1021);
								mem_vec_1021 = vec_57;



								vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_1022);
								mem_vec_1022 = vec_59;
								scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
								vec_61 = _mm512_set1_ps(scal_18);


								vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_1023);
								mem_vec_1023 = vec_60;



								vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_1024);
								mem_vec_1024 = vec_62;
								scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
								vec_64 = _mm512_set1_ps(scal_19);


								vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_1025);
								mem_vec_1025 = vec_63;



								vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_1026);
								mem_vec_1026 = vec_65;
								scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
								vec_67 = _mm512_set1_ps(scal_20);


								vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_1027);
								mem_vec_1027 = vec_66;



								vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_1028);
								mem_vec_1028 = vec_68;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1015);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1016);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1017);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1018);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1019);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1020);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1021);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1022);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1023);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1024);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1025);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1026);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1027);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1028);
				}
			}
		}
	}
}


}