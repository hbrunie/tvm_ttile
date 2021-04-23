#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (16, c); T (1, c)]
*/
IND_TYPE c, cp_0, c510_p_0, c511_p_0, c512_p_0, cp_1, c510_p_1, c511_p_1, cp_2, c510_p_2, cp_3, c510, c511, c512, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y204 = 0;
IND_TYPE x204 = 0;
IND_TYPE h168 = 0;
IND_TYPE w = 0;
IND_TYPE c513 = 0;
IND_TYPE f204 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4244 ,mem_vec_4245 ,mem_vec_4246 ,mem_vec_4247 ,mem_vec_4248 ,mem_vec_4249 ,mem_vec_4250 ,mem_vec_4251 ,mem_vec_4252 ,mem_vec_4253 ,mem_vec_4254 ,mem_vec_4255 ,mem_vec_4256 ,mem_vec_4257 ,mem_vec_4258 ,mem_vec_4259 ,mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c512 = c513, c512_p_0 = 0;
	c512 < c513 + 512;
	c512 += 512, c512_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 16) (512 / 32)
	for (c511 = c512, c511_p_1 = c512_p_0, c511_p_0 = 0;
		c511 < c512 + 512;
		c511 += 32, c511_p_1 += 32, c511_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f204, fp_0 = 0;
			f < f204 + 1024;
			f += 64, fp_0 += 64){
				for (y = y204, yp_0 = 0;
					y < y204 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c510 = c511, c510_p_2 = c511_p_1, c510_p_1 = c511_p_0, c510_p_0 = 0;
						c510 < c511 + 32;
						c510 += 16, c510_p_2 += 16, c510_p_1 += 16, c510_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x204, xp_0 = 0;
							x < x204 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h168, hp_0 = 0;
								h < h168 + 3;
								h += 1, hp_0 += 1){
										mem_vec_4244 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4245 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4246 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_4247 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_4251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_4252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_4255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_4256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_4259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c510, cp_3 = c510_p_2, cp_2 = c510_p_1, cp_1 = c510_p_0, cp_0 = 0;
											c < c510 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4244);
											mem_vec_4244 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4245);
											mem_vec_4245 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4246);
											mem_vec_4246 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4247);
											mem_vec_4247 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4248);
											mem_vec_4248 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4249);
											mem_vec_4249 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4250);
											mem_vec_4250 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4251);
											mem_vec_4251 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4252);
											mem_vec_4252 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4253);
											mem_vec_4253 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4254);
											mem_vec_4254 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4255);
											mem_vec_4255 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4256);
											mem_vec_4256 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4257);
											mem_vec_4257 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4258);
											mem_vec_4258 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4259);
											mem_vec_4259 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_4244);
											mem_vec_4244 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_4245);
											mem_vec_4245 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_4246);
											mem_vec_4246 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_4247);
											mem_vec_4247 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_4248);
											mem_vec_4248 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_4249);
											mem_vec_4249 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4250);
											mem_vec_4250 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4251);
											mem_vec_4251 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_4252);
											mem_vec_4252 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_4253);
											mem_vec_4253 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_4254);
											mem_vec_4254 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_4255);
											mem_vec_4255 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_4256);
											mem_vec_4256 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_4257);
											mem_vec_4257 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_4258);
											mem_vec_4258 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_4259);
											mem_vec_4259 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_4244);
											mem_vec_4244 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_4245);
											mem_vec_4245 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_4246);
											mem_vec_4246 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_4247);
											mem_vec_4247 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_4248);
											mem_vec_4248 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_4249);
											mem_vec_4249 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_4250);
											mem_vec_4250 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4251);
											mem_vec_4251 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_4252);
											mem_vec_4252 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_4253);
											mem_vec_4253 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_4254);
											mem_vec_4254 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_4255);
											mem_vec_4255 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_4256);
											mem_vec_4256 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_4257);
											mem_vec_4257 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_4258);
											mem_vec_4258 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_4259);
											mem_vec_4259 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4259);
							}
						}
					}
				}
				for (y = y204 + 12, yp_0 = 0;
					y < y204 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c510 = c511, c510_p_2 = c511_p_1, c510_p_1 = c511_p_0, c510_p_0 = 0;
						c510 < c511 + 32;
						c510 += 16, c510_p_2 += 16, c510_p_1 += 16, c510_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x204, xp_0 = 0;
							x < x204 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h168, hp_0 = 0;
								h < h168 + 3;
								h += 1, hp_0 += 1){
										mem_vec_4260 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4261 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_4263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_4267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_4268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_4271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_4272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_4275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_4276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_4279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c510, cp_3 = c510_p_2, cp_2 = c510_p_1, cp_1 = c510_p_0, cp_0 = 0;
											c < c510 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4260);
											mem_vec_4260 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4261);
											mem_vec_4261 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4262);
											mem_vec_4262 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4263);
											mem_vec_4263 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4264);
											mem_vec_4264 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4265);
											mem_vec_4265 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4266);
											mem_vec_4266 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4267);
											mem_vec_4267 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4268);
											mem_vec_4268 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4269);
											mem_vec_4269 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4270);
											mem_vec_4270 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4271);
											mem_vec_4271 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4272);
											mem_vec_4272 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4273);
											mem_vec_4273 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4274);
											mem_vec_4274 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4275);
											mem_vec_4275 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4276);
											mem_vec_4276 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4277);
											mem_vec_4277 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4278);
											mem_vec_4278 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4279);
											mem_vec_4279 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_4260);
											mem_vec_4260 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_4261);
											mem_vec_4261 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_4262);
											mem_vec_4262 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_4263);
											mem_vec_4263 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_4264);
											mem_vec_4264 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_4265);
											mem_vec_4265 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_4266);
											mem_vec_4266 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_4267);
											mem_vec_4267 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_4268);
											mem_vec_4268 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_4269);
											mem_vec_4269 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_4270);
											mem_vec_4270 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_4271);
											mem_vec_4271 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_4272);
											mem_vec_4272 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_4273);
											mem_vec_4273 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_4274);
											mem_vec_4274 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_4275);
											mem_vec_4275 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_4276);
											mem_vec_4276 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_4277);
											mem_vec_4277 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_4278);
											mem_vec_4278 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_4279);
											mem_vec_4279 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_4260);
											mem_vec_4260 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_4261);
											mem_vec_4261 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_4262);
											mem_vec_4262 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_4263);
											mem_vec_4263 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_4264);
											mem_vec_4264 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_4265);
											mem_vec_4265 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_4266);
											mem_vec_4266 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_4267);
											mem_vec_4267 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_4268);
											mem_vec_4268 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_4269);
											mem_vec_4269 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_4270);
											mem_vec_4270 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4271);
											mem_vec_4271 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_4272);
											mem_vec_4272 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_4273);
											mem_vec_4273 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_4274);
											mem_vec_4274 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_4275);
											mem_vec_4275 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_4276);
											mem_vec_4276 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_4277);
											mem_vec_4277 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_4278);
											mem_vec_4278 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_4279);
											mem_vec_4279 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4271);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4272);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4273);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4274);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4275);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4276);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4277);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4278);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4279);
							}
						}
					}
				}
		}
	}
}


}