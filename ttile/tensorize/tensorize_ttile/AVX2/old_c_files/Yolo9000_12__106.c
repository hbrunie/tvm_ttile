#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (1, c); T (32, f); T (2, c);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (1, c)]
*/
IND_TYPE c, cp_0, c744_p_0, c745_p_0, c746_p_0, cp_1, c744_p_1, c745_p_1, cp_2, c744_p_2, cp_3, c744, c745, c746, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y403 = 0;
IND_TYPE x372 = 0;
IND_TYPE h = 0;
IND_TYPE w316 = 0;
IND_TYPE c747 = 0;
IND_TYPE f558 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8232 ,mem_vec_8233 ,mem_vec_8234 ,mem_vec_8235 ,mem_vec_8236 ,mem_vec_8237 ,mem_vec_8238 ,mem_vec_8239 ,mem_vec_8240 ,mem_vec_8241 ,mem_vec_8242 ,mem_vec_8243 ,mem_vec_8244 ,mem_vec_8245 ,mem_vec_8246 ,mem_vec_8247 ,mem_vec_8248 ,mem_vec_8249 ,mem_vec_8250 ,mem_vec_8251 ,mem_vec_8252 ,mem_vec_8253 ,mem_vec_8254 ,mem_vec_8255 ,mem_vec_8256 ,mem_vec_8257 ,mem_vec_8258 ,mem_vec_8259 ,mem_vec_8260 ,mem_vec_8261 ,mem_vec_8262 ,mem_vec_8263 ,mem_vec_8264 ,mem_vec_8265 ,mem_vec_8266 ,mem_vec_8267 ,mem_vec_8268 ,mem_vec_8269 ,mem_vec_8270 ,mem_vec_8271 ,mem_vec_8272 ,mem_vec_8273 ,mem_vec_8274 ,mem_vec_8275 ,mem_vec_8276 ,mem_vec_8277 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c746 = c747, c746_p_0 = 0;
	c746 < c747 + 256;
	c746 += 256, c746_p_0 += 256){
		for (y = y403, yp_0 = 0;
			y < y403 + 22;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (c, 2) (256 / 128)
			for (c745 = c746, c745_p_1 = c746_p_0, c745_p_0 = 0;
				c745 < c746 + 256;
				c745 += 128, c745_p_1 += 128, c745_p_0 += 128){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 512
				// T (f, 32) (512 / 16)
				for (f = f558, fp_0 = 0;
					f < f558 + 512;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
					// T (c, 1) (128 / 128)
					for (c744 = c745, c744_p_2 = c745_p_1, c744_p_1 = c745_p_0, c744_p_0 = 0;
						c744 < c745 + 128;
						c744 += 128, c744_p_2 += 128, c744_p_1 += 128, c744_p_0 += 128){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 34) (34 / 1)
						for (x = x372, xp_0 = 0;
							x < x372 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (w, 3) (3 / 1)
							for (w = w316, wp_0 = 0;
								w < w316 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8232 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8233 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_8252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c744, cp_3 = c744_p_2, cp_2 = c744_p_1, cp_1 = c744_p_0, cp_0 = 0;
											c < c744 + 128;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8232);
											mem_vec_8232 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8233);
											mem_vec_8233 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8234);
											mem_vec_8234 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8235);
											mem_vec_8235 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8236);
											mem_vec_8236 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8237);
											mem_vec_8237 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8238);
											mem_vec_8238 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8239);
											mem_vec_8239 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8240);
											mem_vec_8240 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8241);
											mem_vec_8241 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8242);
											mem_vec_8242 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8243);
											mem_vec_8243 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8244);
											mem_vec_8244 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8245);
											mem_vec_8245 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8246);
											mem_vec_8246 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8247);
											mem_vec_8247 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8248);
											mem_vec_8248 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8249);
											mem_vec_8249 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8250);
											mem_vec_8250 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8251);
											mem_vec_8251 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8252);
											mem_vec_8252 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8253);
											mem_vec_8253 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_8232);
											mem_vec_8232 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_8233);
											mem_vec_8233 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_8234);
											mem_vec_8234 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_8235);
											mem_vec_8235 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8236);
											mem_vec_8236 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_8237);
											mem_vec_8237 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_8238);
											mem_vec_8238 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_8239);
											mem_vec_8239 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_8240);
											mem_vec_8240 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_8241);
											mem_vec_8241 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_8242);
											mem_vec_8242 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_8243);
											mem_vec_8243 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_8244);
											mem_vec_8244 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_8245);
											mem_vec_8245 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_8246);
											mem_vec_8246 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_8247);
											mem_vec_8247 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_8248);
											mem_vec_8248 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_8249);
											mem_vec_8249 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_8250);
											mem_vec_8250 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_8251);
											mem_vec_8251 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_8252);
											mem_vec_8252 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_8253);
											mem_vec_8253 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_8232);
											mem_vec_8232 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_8233);
											mem_vec_8233 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_8234);
											mem_vec_8234 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_8235);
											mem_vec_8235 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_8236);
											mem_vec_8236 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_8237);
											mem_vec_8237 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_8238);
											mem_vec_8238 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_8239);
											mem_vec_8239 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_8240);
											mem_vec_8240 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_8241);
											mem_vec_8241 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8242);
											mem_vec_8242 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8243);
											mem_vec_8243 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_8244);
											mem_vec_8244 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_8245);
											mem_vec_8245 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_8246);
											mem_vec_8246 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_8247);
											mem_vec_8247 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_8248);
											mem_vec_8248 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_8249);
											mem_vec_8249 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_8250);
											mem_vec_8250 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_8251);
											mem_vec_8251 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_8252);
											mem_vec_8252 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_8253);
											mem_vec_8253 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8232);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8233);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8234);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8235);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8236);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8237);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8238);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8239);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8240);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8241);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8242);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8243);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8244);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8245);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8246);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8247);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8248);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8249);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8250);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8251);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8252);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8253);
							}
						}
					}
				}
			}
		}
		for (y = y403 + 22, yp_0 = 0;
			y < y403 + 22 + 12;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (c, 2) (256 / 128)
			for (c745 = c746, c745_p_1 = c746_p_0, c745_p_0 = 0;
				c745 < c746 + 256;
				c745 += 128, c745_p_1 += 128, c745_p_0 += 128){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 512
				// T (f, 32) (512 / 16)
				for (f = f558, fp_0 = 0;
					f < f558 + 512;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
					// T (c, 1) (128 / 128)
					for (c744 = c745, c744_p_2 = c745_p_1, c744_p_1 = c745_p_0, c744_p_0 = 0;
						c744 < c745 + 128;
						c744 += 128, c744_p_2 += 128, c744_p_1 += 128, c744_p_0 += 128){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 34) (34 / 1)
						for (x = x372, xp_0 = 0;
							x < x372 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (w, 3) (3 / 1)
							for (w = w316, wp_0 = 0;
								w < w316 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8254 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8255 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_8274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_8276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c744, cp_3 = c744_p_2, cp_2 = c744_p_1, cp_1 = c744_p_0, cp_0 = 0;
											c < c744 + 128;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8254);
											mem_vec_8254 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8255);
											mem_vec_8255 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8256);
											mem_vec_8256 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8257);
											mem_vec_8257 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8258);
											mem_vec_8258 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8259);
											mem_vec_8259 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8260);
											mem_vec_8260 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8261);
											mem_vec_8261 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8262);
											mem_vec_8262 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8263);
											mem_vec_8263 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8264);
											mem_vec_8264 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8265);
											mem_vec_8265 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8266);
											mem_vec_8266 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8267);
											mem_vec_8267 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8268);
											mem_vec_8268 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8269);
											mem_vec_8269 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8270);
											mem_vec_8270 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8271);
											mem_vec_8271 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8272);
											mem_vec_8272 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8273);
											mem_vec_8273 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8274);
											mem_vec_8274 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8275);
											mem_vec_8275 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_8276);
											mem_vec_8276 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_8277);
											mem_vec_8277 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_8254);
											mem_vec_8254 = vec_38;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_8255);
											mem_vec_8255 = vec_41;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8256);
											mem_vec_8256 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8257);
											mem_vec_8257 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_8258);
											mem_vec_8258 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_8259);
											mem_vec_8259 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_8260);
											mem_vec_8260 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_8261);
											mem_vec_8261 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_8262);
											mem_vec_8262 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_8263);
											mem_vec_8263 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_8264);
											mem_vec_8264 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_8265);
											mem_vec_8265 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8266);
											mem_vec_8266 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8267);
											mem_vec_8267 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_8268);
											mem_vec_8268 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_8269);
											mem_vec_8269 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_8270);
											mem_vec_8270 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_8271);
											mem_vec_8271 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_8272);
											mem_vec_8272 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_8273);
											mem_vec_8273 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_8274);
											mem_vec_8274 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_8275);
											mem_vec_8275 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_8276);
											mem_vec_8276 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_8277);
											mem_vec_8277 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_77 = _mm256_set1_ps(scal_24);
											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_8254);
											mem_vec_8254 = vec_76;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_8255);
											mem_vec_8255 = vec_79;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_8256);
											mem_vec_8256 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_8257);
											mem_vec_8257 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_8258);
											mem_vec_8258 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_8259);
											mem_vec_8259 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_8260);
											mem_vec_8260 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8261);
											mem_vec_8261 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_8262);
											mem_vec_8262 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_8263);
											mem_vec_8263 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_8264);
											mem_vec_8264 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_8265);
											mem_vec_8265 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_8266);
											mem_vec_8266 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_8267);
											mem_vec_8267 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_8268);
											mem_vec_8268 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_8269);
											mem_vec_8269 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_8270);
											mem_vec_8270 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_8271);
											mem_vec_8271 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_8272);
											mem_vec_8272 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_8273);
											mem_vec_8273 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_8274);
											mem_vec_8274 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_8275);
											mem_vec_8275 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_8276);
											mem_vec_8276 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_8277);
											mem_vec_8277 = vec_113;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8254);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8255);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8256);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8257);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8258);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8259);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8260);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8261);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8262);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8263);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8264);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8265);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8266);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8267);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8268);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8269);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8270);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8271);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8272);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8273);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8274);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8275);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8276);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_8277);
							}
						}
					}
				}
			}
		}
}


}