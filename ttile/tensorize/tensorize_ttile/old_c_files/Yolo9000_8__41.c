#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (32, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (1, f); T (17, y); T (2, x); T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, f740_p_0, f741_p_0, fp_1, f740_p_1, fp_2, f740, f741, h, hp_0, x, xp_0, x591_p_0, xp_1, x591, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y418 = 0;
IND_TYPE x592 = 0;
IND_TYPE h360 = 0;
IND_TYPE w = 0;
IND_TYPE c592 = 0;
IND_TYPE f742 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7116 ,mem_vec_7117 ,mem_vec_7118 ,mem_vec_7119 ,mem_vec_7120 ,mem_vec_7121 ,mem_vec_7122 ,mem_vec_7123 ,mem_vec_7124 ,mem_vec_7125 ,mem_vec_7126 ,mem_vec_7127 ,mem_vec_7128 ,mem_vec_7129 ,mem_vec_7130 ,mem_vec_7131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f741 = f742, f741_p_0 = 0;
	f741 < f742 + 256;
	f741 += 256, f741_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 4) (256 / 64)
	for (f740 = f741, f740_p_1 = f741_p_0, f740_p_0 = 0;
		f740 < f741 + 256;
		f740 += 64, f740_p_1 += 64, f740_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (68 / 34)
		for (x591 = x592, x591_p_0 = 0;
			x591 < x592 + 68;
			x591 += 34, x591_p_0 += 34){
			// y = 68, x = 34, h = 3, w = 3, c = 128, f = 64
			// T (y, 17) (68 / 4)
			for (y = y418, yp_0 = 0;
				y < y418 + 68;
				y += 4, yp_0 += 4){
				// y = 4, x = 34, h = 3, w = 3, c = 128, f = 64
				// T (f, 1) (64 / 64)
				for (f = f740, fp_2 = f740_p_1, fp_1 = f740_p_0, fp_0 = 0;
					f < f740 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c591 = c592, c591_p_0 = 0;
						c591 < c592 + 128;
						c591 += 32, c591_p_0 += 32){
						// y = 4, x = 34, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h360, hp_0 = 0;
							h < h360 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 34, h = 1, w = 3, c = 32, f = 64
							// T (x, 34) (34 / 1)
							for (x = x591, xp_1 = x591_p_0, xp_0 = 0;
								x < x591 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
											c < c591 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7116);
											mem_vec_7116 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7117);
											mem_vec_7117 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7118);
											mem_vec_7118 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7119);
											mem_vec_7119 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7120);
											mem_vec_7120 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7121);
											mem_vec_7121 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7122);
											mem_vec_7122 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7123);
											mem_vec_7123 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7124);
											mem_vec_7124 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7125);
											mem_vec_7125 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7126);
											mem_vec_7126 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7127);
											mem_vec_7127 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7128);
											mem_vec_7128 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7129);
											mem_vec_7129 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7130);
											mem_vec_7130 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7131);
											mem_vec_7131 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7116);
											mem_vec_7116 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7117);
											mem_vec_7117 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7118);
											mem_vec_7118 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7119);
											mem_vec_7119 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7120);
											mem_vec_7120 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7121);
											mem_vec_7121 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7122);
											mem_vec_7122 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7123);
											mem_vec_7123 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7124);
											mem_vec_7124 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7125);
											mem_vec_7125 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7126);
											mem_vec_7126 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7127);
											mem_vec_7127 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7128);
											mem_vec_7128 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7129);
											mem_vec_7129 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7130);
											mem_vec_7130 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7131);
											mem_vec_7131 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7116);
											mem_vec_7116 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7117);
											mem_vec_7117 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7118);
											mem_vec_7118 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7119);
											mem_vec_7119 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7120);
											mem_vec_7120 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7121);
											mem_vec_7121 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7122);
											mem_vec_7122 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7123);
											mem_vec_7123 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7124);
											mem_vec_7124 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7125);
											mem_vec_7125 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7126);
											mem_vec_7126 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7127);
											mem_vec_7127 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7128);
											mem_vec_7128 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7129);
											mem_vec_7129 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7130);
											mem_vec_7130 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7131);
											mem_vec_7131 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7127);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7131);
							}
						}
					}
				}
			}
		}
	}
}


}