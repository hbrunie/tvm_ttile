#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, f, fp_0, f540_p_0, fp_1, f540, h, hp_0, x, xp_0, x505_p_0, xp_1, x505, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y360 = 0;
IND_TYPE x506 = 0;
IND_TYPE h303 = 0;
IND_TYPE w = 0;
IND_TYPE c541 = 0;
IND_TYPE f541 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5225 ,mem_vec_5226 ,mem_vec_5227 ,mem_vec_5228 ,mem_vec_5229 ,mem_vec_5230 ,mem_vec_5231 ,mem_vec_5232 ,mem_vec_5233 ,mem_vec_5234 ,mem_vec_5235 ,mem_vec_5236 ,mem_vec_5237 ,mem_vec_5238 ,mem_vec_5239 ,mem_vec_5240 ,mem_vec_5241 ,mem_vec_5242 ,mem_vec_5243 ,mem_vec_5244 ,mem_vec_5245 ,mem_vec_5246 ,mem_vec_5247 ,mem_vec_5248 ,mem_vec_5249 ,mem_vec_5250 ,mem_vec_5251 ,mem_vec_5252 ,mem_vec_5253 ,mem_vec_5254 ,mem_vec_5255 ,mem_vec_5256 ,mem_vec_5257 ,mem_vec_5258 ,mem_vec_5259 ,mem_vec_5260 ,mem_vec_5261 ,mem_vec_5262 ,mem_vec_5263 ,mem_vec_5264 ,mem_vec_5265 ,mem_vec_5266 ,mem_vec_5267 ,mem_vec_5268 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f540 = f541, f540_p_0 = 0;
	f540 < f541 + 256;
	f540 += 128, f540_p_0 += 128){
		for (y = y360, yp_0 = 0;
			y < y360 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x505 = x506, x505_p_0 = 0;
				x505 < x506 + 28;
				x505 += 14, x505_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
					f < f540 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 1) (128 / 128)
					for (c540 = c541, c540_p_0 = 0;
						c540 < c541 + 128;
						c540 += 128, c540_p_0 += 128){
						// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
						// T (h, 3) (3 / 1)
						for (h = h303, hp_0 = 0;
							h < h303 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 128, f = 64
							// T (x, 14) (14 / 1)
							for (x = x505, xp_1 = x505_p_0, xp_0 = 0;
								x < x505 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5226 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5227 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5228 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5225);
											mem_vec_5225 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5226);
											mem_vec_5226 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5227);
											mem_vec_5227 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5228);
											mem_vec_5228 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5229);
											mem_vec_5229 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5230);
											mem_vec_5230 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5231);
											mem_vec_5231 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5232);
											mem_vec_5232 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5233);
											mem_vec_5233 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5234);
											mem_vec_5234 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5235);
											mem_vec_5235 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5236);
											mem_vec_5236 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5237);
											mem_vec_5237 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5238);
											mem_vec_5238 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5239);
											mem_vec_5239 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5240);
											mem_vec_5240 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5241);
											mem_vec_5241 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5242);
											mem_vec_5242 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5243);
											mem_vec_5243 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5244);
											mem_vec_5244 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5225);
											mem_vec_5225 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5226);
											mem_vec_5226 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5227);
											mem_vec_5227 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5228);
											mem_vec_5228 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5229);
											mem_vec_5229 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5230);
											mem_vec_5230 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5231);
											mem_vec_5231 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5232);
											mem_vec_5232 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5233);
											mem_vec_5233 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5234);
											mem_vec_5234 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5235);
											mem_vec_5235 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5236);
											mem_vec_5236 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5237);
											mem_vec_5237 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5238);
											mem_vec_5238 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5239);
											mem_vec_5239 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5240);
											mem_vec_5240 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5241);
											mem_vec_5241 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5242);
											mem_vec_5242 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5243);
											mem_vec_5243 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5244);
											mem_vec_5244 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5225);
											mem_vec_5225 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5226);
											mem_vec_5226 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5227);
											mem_vec_5227 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5228);
											mem_vec_5228 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5229);
											mem_vec_5229 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5230);
											mem_vec_5230 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5231);
											mem_vec_5231 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5232);
											mem_vec_5232 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5233);
											mem_vec_5233 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5234);
											mem_vec_5234 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5235);
											mem_vec_5235 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5236);
											mem_vec_5236 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5237);
											mem_vec_5237 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5238);
											mem_vec_5238 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5239);
											mem_vec_5239 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5240);
											mem_vec_5240 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5241);
											mem_vec_5241 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5242);
											mem_vec_5242 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5243);
											mem_vec_5243 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5244);
											mem_vec_5244 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5231);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5239);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5244);
							}
						}
					}
				}
			}
		}
		for (y = y360 + 10, yp_0 = 0;
			y < y360 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x505 = x506, x505_p_0 = 0;
				x505 < x506 + 28;
				x505 += 14, x505_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
					f < f540 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 1) (128 / 128)
					for (c540 = c541, c540_p_0 = 0;
						c540 < c541 + 128;
						c540 += 128, c540_p_0 += 128){
						// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
						// T (h, 3) (3 / 1)
						for (h = h303, hp_0 = 0;
							h < h303 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 128, f = 64
							// T (x, 14) (14 / 1)
							for (x = x505, xp_1 = x505_p_0, xp_0 = 0;
								x < x505 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5245 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5246 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5247 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5248 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5245);
											mem_vec_5245 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5246);
											mem_vec_5246 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5247);
											mem_vec_5247 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5248);
											mem_vec_5248 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5249);
											mem_vec_5249 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5250);
											mem_vec_5250 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5251);
											mem_vec_5251 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5252);
											mem_vec_5252 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5253);
											mem_vec_5253 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5254);
											mem_vec_5254 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5255);
											mem_vec_5255 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5256);
											mem_vec_5256 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5257);
											mem_vec_5257 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5258);
											mem_vec_5258 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5259);
											mem_vec_5259 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5260);
											mem_vec_5260 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5261);
											mem_vec_5261 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5262);
											mem_vec_5262 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5263);
											mem_vec_5263 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5264);
											mem_vec_5264 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5265);
											mem_vec_5265 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5266);
											mem_vec_5266 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5267);
											mem_vec_5267 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5268);
											mem_vec_5268 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5245);
											mem_vec_5245 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5246);
											mem_vec_5246 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5247);
											mem_vec_5247 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5248);
											mem_vec_5248 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5249);
											mem_vec_5249 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5250);
											mem_vec_5250 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5251);
											mem_vec_5251 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5252);
											mem_vec_5252 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5253);
											mem_vec_5253 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5254);
											mem_vec_5254 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5255);
											mem_vec_5255 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5256);
											mem_vec_5256 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5257);
											mem_vec_5257 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5258);
											mem_vec_5258 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5259);
											mem_vec_5259 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5260);
											mem_vec_5260 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5261);
											mem_vec_5261 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5262);
											mem_vec_5262 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5263);
											mem_vec_5263 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5264);
											mem_vec_5264 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5265);
											mem_vec_5265 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5266);
											mem_vec_5266 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5267);
											mem_vec_5267 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5268);
											mem_vec_5268 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5245);
											mem_vec_5245 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5246);
											mem_vec_5246 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5247);
											mem_vec_5247 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5248);
											mem_vec_5248 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5249);
											mem_vec_5249 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5250);
											mem_vec_5250 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5251);
											mem_vec_5251 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5252);
											mem_vec_5252 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5253);
											mem_vec_5253 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5254);
											mem_vec_5254 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5255);
											mem_vec_5255 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5256);
											mem_vec_5256 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5257);
											mem_vec_5257 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5258);
											mem_vec_5258 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5259);
											mem_vec_5259 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5260);
											mem_vec_5260 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5261);
											mem_vec_5261 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5262);
											mem_vec_5262 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5263);
											mem_vec_5263 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5264);
											mem_vec_5264 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5265);
											mem_vec_5265 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5266);
											mem_vec_5266 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5267);
											mem_vec_5267 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5268);
											mem_vec_5268 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5268);
							}
						}
					}
				}
			}
		}
}


}