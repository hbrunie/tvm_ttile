#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (112, x); T (4, y); T (1, c); T (4, y)]
*/
IND_TYPE c, cp_0, c357_p_0, cp_1, c357, h, hp_0, x, xp_0, y, yp_0, y318_p_0, yp_1, y318;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y319 = 0;
IND_TYPE x316 = 0;
IND_TYPE h193 = 0;
IND_TYPE w = 0;
IND_TYPE c358 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3071 ,mem_vec_3072 ,mem_vec_3073 ,mem_vec_3074 ,mem_vec_3075 ,mem_vec_3076 ,mem_vec_3077 ,mem_vec_3078 ,mem_vec_3079 ,mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 4) (112 / 28)
for (y318 = y319, y318_p_0 = 0;
	y318 < y319 + 112;
	y318 += 28, y318_p_0 += 28){
	// y = 28, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c357 = c358, c357_p_0 = 0;
		c357 < c358 + 32;
		c357 += 32, c357_p_0 += 32){
		// y = 28, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (y, 4) (28 / 7)
		for (y = y318, yp_1 = y318_p_0, yp_0 = 0;
			y < y318 + 28;
			y += 7, yp_1 += 7, yp_0 += 7){
			// y = 7, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (x, 112) (112 / 1)
			for (x = x316, xp_0 = 0;
				x < x316 + 112;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h193, hp_0 = 0;
					h < h193 + 3;
					h += 1, hp_0 += 1){
							mem_vec_3071 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_3072 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_3073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_3074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_3075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_3076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_3077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_3078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_3079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_3080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_3081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_3082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_3083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_3084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
							// T (c, 32) (32 / 1)
							for (c = c357, cp_1 = c357_p_0, cp_0 = 0;
								c < c357 + 32;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3071);
								mem_vec_3071 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3072);
								mem_vec_3072 = vec_3;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3073);
								mem_vec_3073 = vec_5;



								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3074);
								mem_vec_3074 = vec_7;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);


								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3075);
								mem_vec_3075 = vec_8;



								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3076);
								mem_vec_3076 = vec_10;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3077);
								mem_vec_3077 = vec_11;



								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3078);
								mem_vec_3078 = vec_13;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3079);
								mem_vec_3079 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3080);
								mem_vec_3080 = vec_16;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);


								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3081);
								mem_vec_3081 = vec_17;



								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3082);
								mem_vec_3082 = vec_19;
								scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3083);
								mem_vec_3083 = vec_20;



								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3084);
								mem_vec_3084 = vec_22;
								scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
								vec_24 = _mm512_set1_ps(scal_7);
								vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

								vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_3071);
								mem_vec_3071 = vec_23;

								vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

								vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_3072);
								mem_vec_3072 = vec_26;
								scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
								vec_29 = _mm512_set1_ps(scal_8);


								vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_3073);
								mem_vec_3073 = vec_28;



								vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_3074);
								mem_vec_3074 = vec_30;
								scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
								vec_32 = _mm512_set1_ps(scal_9);


								vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_3075);
								mem_vec_3075 = vec_31;



								vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_3076);
								mem_vec_3076 = vec_33;
								scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
								vec_35 = _mm512_set1_ps(scal_10);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_3077);
								mem_vec_3077 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_3078);
								mem_vec_3078 = vec_36;
								scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
								vec_38 = _mm512_set1_ps(scal_11);


								vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_3079);
								mem_vec_3079 = vec_37;



								vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_3080);
								mem_vec_3080 = vec_39;
								scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
								vec_41 = _mm512_set1_ps(scal_12);


								vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_3081);
								mem_vec_3081 = vec_40;



								vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_3082);
								mem_vec_3082 = vec_42;
								scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
								vec_44 = _mm512_set1_ps(scal_13);


								vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_3083);
								mem_vec_3083 = vec_43;



								vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_3084);
								mem_vec_3084 = vec_45;
								scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
								vec_47 = _mm512_set1_ps(scal_14);
								vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

								vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_3071);
								mem_vec_3071 = vec_46;

								vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

								vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_3072);
								mem_vec_3072 = vec_49;
								scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
								vec_52 = _mm512_set1_ps(scal_15);


								vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_3073);
								mem_vec_3073 = vec_51;



								vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_3074);
								mem_vec_3074 = vec_53;
								scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
								vec_55 = _mm512_set1_ps(scal_16);


								vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_3075);
								mem_vec_3075 = vec_54;



								vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_3076);
								mem_vec_3076 = vec_56;
								scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
								vec_58 = _mm512_set1_ps(scal_17);


								vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_3077);
								mem_vec_3077 = vec_57;



								vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_3078);
								mem_vec_3078 = vec_59;
								scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
								vec_61 = _mm512_set1_ps(scal_18);


								vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_3079);
								mem_vec_3079 = vec_60;



								vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_3080);
								mem_vec_3080 = vec_62;
								scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
								vec_64 = _mm512_set1_ps(scal_19);


								vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_3081);
								mem_vec_3081 = vec_63;



								vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_3082);
								mem_vec_3082 = vec_65;
								scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
								vec_67 = _mm512_set1_ps(scal_20);


								vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_3083);
								mem_vec_3083 = vec_66;



								vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_3084);
								mem_vec_3084 = vec_68;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3071);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3072);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3073);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3074);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3075);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3076);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3077);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3078);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3079);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3080);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3081);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3082);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3083);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3084);
				}
			}
		}
	}
}


}