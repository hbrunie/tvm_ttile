#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (128, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, c); T (1, f); T (7, y); T (2, x); T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c468_p_0, cp_1, c468, f, fp_0, f556_p_0, f557_p_0, fp_1, f556_p_1, fp_2, f556, f557, h, hp_0, x, xp_0, x486_p_0, xp_1, x486, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y346 = 0;
IND_TYPE x487 = 0;
IND_TYPE h298 = 0;
IND_TYPE w = 0;
IND_TYPE c469 = 0;
IND_TYPE f558 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4290 ,mem_vec_4291 ,mem_vec_4292 ,mem_vec_4293 ,mem_vec_4294 ,mem_vec_4295 ,mem_vec_4296 ,mem_vec_4297 ,mem_vec_4298 ,mem_vec_4299 ,mem_vec_4300 ,mem_vec_4301 ,mem_vec_4302 ,mem_vec_4303 ,mem_vec_4304 ,mem_vec_4305 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f557 = f558, f557_p_0 = 0;
	f557 < f558 + 256;
	f557 += 256, f557_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 4) (256 / 64)
	for (f556 = f557, f556_p_1 = f557_p_0, f556_p_0 = 0;
		f556 < f557 + 256;
		f556 += 64, f556_p_1 += 64, f556_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
		// T (x, 2) (28 / 14)
		for (x486 = x487, x486_p_0 = 0;
			x486 < x487 + 28;
			x486 += 14, x486_p_0 += 14){
			// y = 28, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (y, 7) (28 / 4)
			for (y = y346, yp_0 = 0;
				y < y346 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 14, h = 3, w = 3, c = 256, f = 64
				// T (f, 1) (64 / 64)
				for (f = f556, fp_2 = f556_p_1, fp_1 = f556_p_0, fp_0 = 0;
					f < f556 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 14, h = 3, w = 3, c = 256, f = 64
					// T (c, 2) (256 / 128)
					for (c468 = c469, c468_p_0 = 0;
						c468 < c469 + 256;
						c468 += 128, c468_p_0 += 128){
						// y = 4, x = 14, h = 3, w = 3, c = 128, f = 64
						// T (h, 3) (3 / 1)
						for (h = h298, hp_0 = 0;
							h < h298 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 14, h = 1, w = 3, c = 128, f = 64
							// T (x, 14) (14 / 1)
							for (x = x486, xp_1 = x486_p_0, xp_0 = 0;
								x < x486 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4290 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4291 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4292 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_4293 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_4297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_4298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_4301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_4302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_4305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 3, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
											c < c468 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4290);
											mem_vec_4290 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4291);
											mem_vec_4291 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4292);
											mem_vec_4292 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4293);
											mem_vec_4293 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4294);
											mem_vec_4294 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4295);
											mem_vec_4295 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4296);
											mem_vec_4296 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4297);
											mem_vec_4297 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4298);
											mem_vec_4298 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4299);
											mem_vec_4299 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4300);
											mem_vec_4300 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4301);
											mem_vec_4301 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4302);
											mem_vec_4302 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4303);
											mem_vec_4303 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4304);
											mem_vec_4304 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4305);
											mem_vec_4305 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_4290);
											mem_vec_4290 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_4291);
											mem_vec_4291 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_4292);
											mem_vec_4292 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_4293);
											mem_vec_4293 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_4294);
											mem_vec_4294 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_4295);
											mem_vec_4295 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4296);
											mem_vec_4296 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4297);
											mem_vec_4297 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_4298);
											mem_vec_4298 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_4299);
											mem_vec_4299 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_4300);
											mem_vec_4300 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_4301);
											mem_vec_4301 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_4302);
											mem_vec_4302 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_4303);
											mem_vec_4303 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_4304);
											mem_vec_4304 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_4305);
											mem_vec_4305 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_4290);
											mem_vec_4290 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_4291);
											mem_vec_4291 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_4292);
											mem_vec_4292 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_4293);
											mem_vec_4293 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_4294);
											mem_vec_4294 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_4295);
											mem_vec_4295 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_4296);
											mem_vec_4296 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4297);
											mem_vec_4297 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_4298);
											mem_vec_4298 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_4299);
											mem_vec_4299 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_4300);
											mem_vec_4300 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_4301);
											mem_vec_4301 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_4302);
											mem_vec_4302 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_4303);
											mem_vec_4303 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_4304);
											mem_vec_4304 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_4305);
											mem_vec_4305 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4305);
							}
						}
					}
				}
			}
		}
	}
}


}