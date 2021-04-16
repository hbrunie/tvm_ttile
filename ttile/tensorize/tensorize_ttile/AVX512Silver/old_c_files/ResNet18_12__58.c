#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (7, x); T (32, c); T (4, f); T (4, f)]
*/
IND_TYPE c, cp_0, c219_p_0, cp_1, c219, f, fp_0, f141_p_0, fp_1, f141, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x120 = 0;
IND_TYPE h = 0;
IND_TYPE w100 = 0;
IND_TYPE c220 = 0;
IND_TYPE f142 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f141 = f142, f141_p_0 = 0;
	f141 < f142 + 512;
	f141 += 128, f141_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 128
	// T (f, 4) (128 / 32)
	for (f = f141, fp_1 = f141_p_0, fp_0 = 0;
		f < f141 + 128;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 32) (512 / 16)
		for (c219 = c220, c219_p_0 = 0;
			c219 < c220 + 512;
			c219 += 16, c219_p_0 += 16){
			// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
			// T (x, 7) (7 / 1)
			for (x = x120, xp_0 = 0;
				x < x120 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 16, f = 32
				// T (w, 3) (3 / 1)
				for (w = w100, wp_0 = 0;
					w < w100 + 3;
					w += 1, wp_0 += 1){
							mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (c, 16) (16 / 1)
							for (c = c219, cp_1 = c219_p_0, cp_0 = 0;
								c < c219 + 16;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_945);
								mem_vec_945 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_946);
								mem_vec_946 = vec_3;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_947);
								mem_vec_947 = vec_5;



								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_948);
								mem_vec_948 = vec_7;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);


								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_949);
								mem_vec_949 = vec_8;



								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_950);
								mem_vec_950 = vec_10;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_951);
								mem_vec_951 = vec_11;



								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_952);
								mem_vec_952 = vec_13;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_953);
								mem_vec_953 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_954);
								mem_vec_954 = vec_16;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);


								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_955);
								mem_vec_955 = vec_17;



								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_956);
								mem_vec_956 = vec_19;
								scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_957);
								mem_vec_957 = vec_20;



								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_958);
								mem_vec_958 = vec_22;
								scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
								vec_24 = _mm512_set1_ps(scal_7);
								vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

								vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_945);
								mem_vec_945 = vec_23;

								vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

								vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_946);
								mem_vec_946 = vec_26;
								scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
								vec_29 = _mm512_set1_ps(scal_8);


								vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_947);
								mem_vec_947 = vec_28;



								vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_948);
								mem_vec_948 = vec_30;
								scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
								vec_32 = _mm512_set1_ps(scal_9);


								vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_949);
								mem_vec_949 = vec_31;



								vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_950);
								mem_vec_950 = vec_33;
								scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
								vec_35 = _mm512_set1_ps(scal_10);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_951);
								mem_vec_951 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_952);
								mem_vec_952 = vec_36;
								scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
								vec_38 = _mm512_set1_ps(scal_11);


								vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_953);
								mem_vec_953 = vec_37;



								vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_954);
								mem_vec_954 = vec_39;
								scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
								vec_41 = _mm512_set1_ps(scal_12);


								vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_955);
								mem_vec_955 = vec_40;



								vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_956);
								mem_vec_956 = vec_42;
								scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
								vec_44 = _mm512_set1_ps(scal_13);


								vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_957);
								mem_vec_957 = vec_43;



								vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_958);
								mem_vec_958 = vec_45;
								scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
								vec_47 = _mm512_set1_ps(scal_14);
								vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

								vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_945);
								mem_vec_945 = vec_46;

								vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

								vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_946);
								mem_vec_946 = vec_49;
								scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
								vec_52 = _mm512_set1_ps(scal_15);


								vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_947);
								mem_vec_947 = vec_51;



								vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_948);
								mem_vec_948 = vec_53;
								scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
								vec_55 = _mm512_set1_ps(scal_16);


								vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_949);
								mem_vec_949 = vec_54;



								vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_950);
								mem_vec_950 = vec_56;
								scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
								vec_58 = _mm512_set1_ps(scal_17);


								vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_951);
								mem_vec_951 = vec_57;



								vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_952);
								mem_vec_952 = vec_59;
								scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
								vec_61 = _mm512_set1_ps(scal_18);


								vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_953);
								mem_vec_953 = vec_60;



								vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_954);
								mem_vec_954 = vec_62;
								scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
								vec_64 = _mm512_set1_ps(scal_19);


								vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_955);
								mem_vec_955 = vec_63;



								vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_956);
								mem_vec_956 = vec_65;
								scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
								vec_67 = _mm512_set1_ps(scal_20);


								vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_957);
								mem_vec_957 = vec_66;



								vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_958);
								mem_vec_958 = vec_68;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_945);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_946);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_947);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_948);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_949);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_950);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_951);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_952);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_953);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_954);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_955);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_956);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_957);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_958);
				}
			}
		}
	}
}


}