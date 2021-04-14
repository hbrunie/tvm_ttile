#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (4, c); T (8, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1396_p_0, c1397_p_0, cp_1, c1396_p_1, cp_2, c1396, c1397, f, fp_0, h, hp_0, x, xp_0, x1092_p_0, xp_1, x1092, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y728 = 0;
IND_TYPE x1093 = 0;
IND_TYPE h598 = 0;
IND_TYPE w = 0;
IND_TYPE c1398 = 0;
IND_TYPE f788 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10080 ,mem_vec_10081 ,mem_vec_10082 ,mem_vec_10083 ,mem_vec_10084 ,mem_vec_10085 ,mem_vec_10086 ,mem_vec_10087 ,mem_vec_10088 ,mem_vec_10089 ,mem_vec_10090 ,mem_vec_10091 ,mem_vec_10092 ,mem_vec_10093 ,mem_vec_10094 ,mem_vec_10095 ,mem_vec_10096 ,mem_vec_10097 ,mem_vec_10098 ,mem_vec_10099 ,mem_vec_10100 ,mem_vec_10101 ,mem_vec_10102 ,mem_vec_10103 ,mem_vec_10104 ,mem_vec_10105 ,mem_vec_10106 ,mem_vec_10107 ,mem_vec_10108 ,mem_vec_10109 ,mem_vec_10110 ,mem_vec_10111 ,mem_vec_10112 ,mem_vec_10113 ,mem_vec_10114 ,mem_vec_10115 ,mem_vec_10116 ,mem_vec_10117 ,mem_vec_10118 ,mem_vec_10119 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 2) (512 / 256)
for (c1397 = c1398, c1397_p_0 = 0;
	c1397 < c1398 + 512;
	c1397 += 256, c1397_p_0 += 256){
		for (y = y728, yp_0 = 0;
			y < y728 + 8;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 512
			// T (x, 7) (14 / 2)
			for (x1092 = x1093, x1092_p_0 = 0;
				x1092 < x1093 + 14;
				x1092 += 2, x1092_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f788, fp_0 = 0;
					f < f788 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c1396 = c1397, c1396_p_1 = c1397_p_0, c1396_p_0 = 0;
						c1396 < c1397 + 256;
						c1396 += 64, c1396_p_1 += 64, c1396_p_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h598, hp_0 = 0;
							h < h598 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1092, xp_1 = x1092_p_0, xp_0 = 0;
								x < x1092 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10080 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10081 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10082 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_10095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c1396, cp_2 = c1396_p_1, cp_1 = c1396_p_0, cp_0 = 0;
											c < c1396 + 64;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10080);
											mem_vec_10080 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10081);
											mem_vec_10081 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10082);
											mem_vec_10082 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10083);
											mem_vec_10083 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10084);
											mem_vec_10084 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10085);
											mem_vec_10085 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10086);
											mem_vec_10086 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10087);
											mem_vec_10087 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10088);
											mem_vec_10088 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10089);
											mem_vec_10089 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10090);
											mem_vec_10090 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10091);
											mem_vec_10091 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10092);
											mem_vec_10092 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10093);
											mem_vec_10093 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10094);
											mem_vec_10094 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10095);
											mem_vec_10095 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_10080);
											mem_vec_10080 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_10081);
											mem_vec_10081 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_10082);
											mem_vec_10082 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_10083);
											mem_vec_10083 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_10084);
											mem_vec_10084 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_10085);
											mem_vec_10085 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_10086);
											mem_vec_10086 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_10087);
											mem_vec_10087 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_10088);
											mem_vec_10088 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_10089);
											mem_vec_10089 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_10090);
											mem_vec_10090 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_10091);
											mem_vec_10091 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_10092);
											mem_vec_10092 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_10093);
											mem_vec_10093 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_10094);
											mem_vec_10094 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_10095);
											mem_vec_10095 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_10080);
											mem_vec_10080 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_10081);
											mem_vec_10081 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_10082);
											mem_vec_10082 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_10083);
											mem_vec_10083 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_10084);
											mem_vec_10084 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_10085);
											mem_vec_10085 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_10086);
											mem_vec_10086 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_10087);
											mem_vec_10087 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_10088);
											mem_vec_10088 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_10089);
											mem_vec_10089 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_10090);
											mem_vec_10090 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_10091);
											mem_vec_10091 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_10092);
											mem_vec_10092 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_10093);
											mem_vec_10093 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_10094);
											mem_vec_10094 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_10095);
											mem_vec_10095 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10081);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10082);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10083);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10084);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10085);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10086);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10087);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10088);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10089);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10090);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10091);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10092);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10093);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10094);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10095);
							}
						}
					}
				}
			}
		}
		for (y = y728 + 8, yp_0 = 0;
			y < y728 + 8 + 6;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 512
			// T (x, 7) (14 / 2)
			for (x1092 = x1093, x1092_p_0 = 0;
				x1092 < x1093 + 14;
				x1092 += 2, x1092_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f788, fp_0 = 0;
					f < f788 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c1396 = c1397, c1396_p_1 = c1397_p_0, c1396_p_0 = 0;
						c1396 < c1397 + 256;
						c1396 += 64, c1396_p_1 += 64, c1396_p_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h598, hp_0 = 0;
							h < h598 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1092, xp_1 = x1092_p_0, xp_0 = 0;
								x < x1092 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10096 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10097 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10098 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10099 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_10111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_10112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_10115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_10116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_10119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c1396, cp_2 = c1396_p_1, cp_1 = c1396_p_0, cp_0 = 0;
											c < c1396 + 64;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10096);
											mem_vec_10096 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10097);
											mem_vec_10097 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10098);
											mem_vec_10098 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10099);
											mem_vec_10099 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10100);
											mem_vec_10100 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10101);
											mem_vec_10101 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10102);
											mem_vec_10102 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10103);
											mem_vec_10103 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10104);
											mem_vec_10104 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10105);
											mem_vec_10105 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10106);
											mem_vec_10106 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10107);
											mem_vec_10107 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10108);
											mem_vec_10108 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10109);
											mem_vec_10109 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10110);
											mem_vec_10110 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10111);
											mem_vec_10111 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10112);
											mem_vec_10112 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10113);
											mem_vec_10113 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10114);
											mem_vec_10114 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10115);
											mem_vec_10115 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10116);
											mem_vec_10116 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10117);
											mem_vec_10117 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10118);
											mem_vec_10118 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10119);
											mem_vec_10119 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_10096);
											mem_vec_10096 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_10097);
											mem_vec_10097 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_10098);
											mem_vec_10098 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_10099);
											mem_vec_10099 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_10100);
											mem_vec_10100 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_10101);
											mem_vec_10101 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10102);
											mem_vec_10102 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10103);
											mem_vec_10103 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_10104);
											mem_vec_10104 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_10105);
											mem_vec_10105 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_10106);
											mem_vec_10106 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_10107);
											mem_vec_10107 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_10108);
											mem_vec_10108 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_10109);
											mem_vec_10109 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_10110);
											mem_vec_10110 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_10111);
											mem_vec_10111 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_10112);
											mem_vec_10112 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_10113);
											mem_vec_10113 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10114);
											mem_vec_10114 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10115);
											mem_vec_10115 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_10116);
											mem_vec_10116 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_10117);
											mem_vec_10117 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_10118);
											mem_vec_10118 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_10119);
											mem_vec_10119 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_10096);
											mem_vec_10096 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_10097);
											mem_vec_10097 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_10098);
											mem_vec_10098 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_10099);
											mem_vec_10099 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_10100);
											mem_vec_10100 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_10101);
											mem_vec_10101 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_10102);
											mem_vec_10102 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_10103);
											mem_vec_10103 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_10104);
											mem_vec_10104 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_10105);
											mem_vec_10105 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_10106);
											mem_vec_10106 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_10107);
											mem_vec_10107 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_10108);
											mem_vec_10108 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10109);
											mem_vec_10109 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10110);
											mem_vec_10110 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_10111);
											mem_vec_10111 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_10112);
											mem_vec_10112 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_10113);
											mem_vec_10113 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_10114);
											mem_vec_10114 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_10115);
											mem_vec_10115 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_10116);
											mem_vec_10116 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_10117);
											mem_vec_10117 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_10118);
											mem_vec_10118 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_10119);
											mem_vec_10119 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10096);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10097);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10098);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10099);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10100);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10101);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10102);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10103);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10104);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10105);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10106);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10107);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10108);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10109);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10110);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10111);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10115);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10119);
							}
						}
					}
				}
			}
		}
}


}