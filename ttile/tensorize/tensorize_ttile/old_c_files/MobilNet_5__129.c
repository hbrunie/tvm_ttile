#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))];
  T (1, f); T (32, c); T (2, f); T (2, c); T (14, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1412_p_0, c1413_p_0, cp_1, c1412_p_1, cp_2, c1412, c1413, f, fp_0, f1252_p_0, f1253_p_0, fp_1, f1252_p_1, fp_2, f1252, f1253, w, wp_0, x, xp_0, x1104_p_0, xp_1, x1104, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y736 = 0;
IND_TYPE x1105 = 0;
IND_TYPE h = 0;
IND_TYPE w708 = 0;
IND_TYPE c1414 = 0;
IND_TYPE f1254 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11222 ,mem_vec_11223 ,mem_vec_11224 ,mem_vec_11225 ,mem_vec_11226 ,mem_vec_11227 ,mem_vec_11228 ,mem_vec_11229 ,mem_vec_11230 ,mem_vec_11231 ,mem_vec_11232 ,mem_vec_11233 ,mem_vec_11234 ,mem_vec_11235 ,mem_vec_11236 ,mem_vec_11237 ,mem_vec_11238 ,mem_vec_11239 ,mem_vec_11240 ,mem_vec_11241 ,mem_vec_11242 ,mem_vec_11243 ,mem_vec_11244 ,mem_vec_11245 ,mem_vec_11246 ,mem_vec_11247 ,mem_vec_11248 ,mem_vec_11249 ,mem_vec_11250 ,mem_vec_11251 ,mem_vec_11252 ,mem_vec_11253 ,mem_vec_11254 ,mem_vec_11255 ,mem_vec_11256 ,mem_vec_11257 ,mem_vec_11258 ,mem_vec_11259 ,mem_vec_11260 ,mem_vec_11261 ,mem_vec_11262 ,mem_vec_11263 ,mem_vec_11264 ,mem_vec_11265 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f1253 = f1254, f1253_p_0 = 0;
	f1253 < f1254 + 256;
	f1253 += 128, f1253_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (x, 14) (28 / 2)
	for (x1104 = x1105, x1104_p_0 = 0;
		x1104 < x1105 + 28;
		x1104 += 2, x1104_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 128
		// T (c, 2) (256 / 128)
		for (c1413 = c1414, c1413_p_0 = 0;
			c1413 < c1414 + 256;
			c1413 += 128, c1413_p_0 += 128){
			// y = 28, x = 2, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f1252 = f1253, f1252_p_1 = f1253_p_0, f1252_p_0 = 0;
				f1252 < f1253 + 128;
				f1252 += 64, f1252_p_1 += 64, f1252_p_0 += 64){
				// y = 28, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (c, 32) (128 / 4)
				for (c1412 = c1413, c1412_p_1 = c1413_p_0, c1412_p_0 = 0;
					c1412 < c1413 + 128;
					c1412 += 4, c1412_p_1 += 4, c1412_p_0 += 4){
					// y = 28, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1252, fp_2 = f1252_p_1, fp_1 = f1252_p_0, fp_0 = 0;
						f < f1252 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							for (y = y736, yp_0 = 0;
								y < y736 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w708, wp_0 = 0;
									w < w708 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
										x < x1104 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1412, cp_2 = c1412_p_1, cp_1 = c1412_p_0, cp_0 = 0;
													c < c1412 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11222);
													mem_vec_11222 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11223);
													mem_vec_11223 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11224);
													mem_vec_11224 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11225);
													mem_vec_11225 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11226);
													mem_vec_11226 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11227);
													mem_vec_11227 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11228);
													mem_vec_11228 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11229);
													mem_vec_11229 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11230);
													mem_vec_11230 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11231);
													mem_vec_11231 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11232);
													mem_vec_11232 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11233);
													mem_vec_11233 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11234);
													mem_vec_11234 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11235);
													mem_vec_11235 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11236);
													mem_vec_11236 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11237);
													mem_vec_11237 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11238);
													mem_vec_11238 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11239);
													mem_vec_11239 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11240);
													mem_vec_11240 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11241);
													mem_vec_11241 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11222);
													mem_vec_11222 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11223);
													mem_vec_11223 = vec_32;

													vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11224);
													mem_vec_11224 = vec_34;

													vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11225);
													mem_vec_11225 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm512_set1_ps(scal_6);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11226);
													mem_vec_11226 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11227);
													mem_vec_11227 = vec_40;



													vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11228);
													mem_vec_11228 = vec_41;



													vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11229);
													mem_vec_11229 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11230);
													mem_vec_11230 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11231);
													mem_vec_11231 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11232);
													mem_vec_11232 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11233);
													mem_vec_11233 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11234);
													mem_vec_11234 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11235);
													mem_vec_11235 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11236);
													mem_vec_11236 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11237);
													mem_vec_11237 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11238);
													mem_vec_11238 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11239);
													mem_vec_11239 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11240);
													mem_vec_11240 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11241);
													mem_vec_11241 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm512_set1_ps(scal_10);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11222);
													mem_vec_11222 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11223);
													mem_vec_11223 = vec_61;

													vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11224);
													mem_vec_11224 = vec_63;

													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11225);
													mem_vec_11225 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm512_set1_ps(scal_11);


													vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11226);
													mem_vec_11226 = vec_67;



													vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11227);
													mem_vec_11227 = vec_69;



													vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11228);
													mem_vec_11228 = vec_70;



													vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11229);
													mem_vec_11229 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm512_set1_ps(scal_12);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11230);
													mem_vec_11230 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11231);
													mem_vec_11231 = vec_74;



													vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11232);
													mem_vec_11232 = vec_75;



													vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11233);
													mem_vec_11233 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11234);
													mem_vec_11234 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11235);
													mem_vec_11235 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11236);
													mem_vec_11236 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11237);
													mem_vec_11237 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11238);
													mem_vec_11238 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11239);
													mem_vec_11239 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11240);
													mem_vec_11240 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11241);
													mem_vec_11241 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11226);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11227);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11237);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11238);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11239);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11240);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11241);
									}
								}
							}
							for (y = y736 + 10, yp_0 = 0;
								y < y736 + 10 + 18;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w708, wp_0 = 0;
									w < w708 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
										x < x1104 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11242 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11243 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11244 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11245 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_11262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_11265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1412, cp_2 = c1412_p_1, cp_1 = c1412_p_0, cp_0 = 0;
													c < c1412 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11242);
													mem_vec_11242 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11243);
													mem_vec_11243 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11244);
													mem_vec_11244 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11245);
													mem_vec_11245 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11246);
													mem_vec_11246 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11247);
													mem_vec_11247 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11248);
													mem_vec_11248 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11249);
													mem_vec_11249 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11250);
													mem_vec_11250 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11251);
													mem_vec_11251 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11252);
													mem_vec_11252 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11253);
													mem_vec_11253 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11254);
													mem_vec_11254 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11255);
													mem_vec_11255 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11256);
													mem_vec_11256 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11257);
													mem_vec_11257 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11258);
													mem_vec_11258 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11259);
													mem_vec_11259 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11260);
													mem_vec_11260 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11261);
													mem_vec_11261 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11262);
													mem_vec_11262 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11263);
													mem_vec_11263 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11264);
													mem_vec_11264 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11265);
													mem_vec_11265 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11242);
													mem_vec_11242 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11243);
													mem_vec_11243 = vec_37;

													vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11244);
													mem_vec_11244 = vec_39;

													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11245);
													mem_vec_11245 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11246);
													mem_vec_11246 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11247);
													mem_vec_11247 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11248);
													mem_vec_11248 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11249);
													mem_vec_11249 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11250);
													mem_vec_11250 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11251);
													mem_vec_11251 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_11252);
													mem_vec_11252 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_11253);
													mem_vec_11253 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_11254);
													mem_vec_11254 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_11255);
													mem_vec_11255 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_11256);
													mem_vec_11256 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_11257);
													mem_vec_11257 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm512_set1_ps(scal_10);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11258);
													mem_vec_11258 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_11259);
													mem_vec_11259 = vec_60;



													vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11260);
													mem_vec_11260 = vec_61;



													vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11261);
													mem_vec_11261 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm512_set1_ps(scal_11);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_11262);
													mem_vec_11262 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_11263);
													mem_vec_11263 = vec_65;



													vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_11264);
													mem_vec_11264 = vec_66;



													vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_11265);
													mem_vec_11265 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm512_set1_ps(scal_12);
													vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11242);
													mem_vec_11242 = vec_68;

													vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11243);
													mem_vec_11243 = vec_71;

													vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11244);
													mem_vec_11244 = vec_73;

													vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11245);
													mem_vec_11245 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11246);
													mem_vec_11246 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11247);
													mem_vec_11247 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11248);
													mem_vec_11248 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11249);
													mem_vec_11249 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11250);
													mem_vec_11250 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11251);
													mem_vec_11251 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_11252);
													mem_vec_11252 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_11253);
													mem_vec_11253 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm512_set1_ps(scal_15);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_11254);
													mem_vec_11254 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11255);
													mem_vec_11255 = vec_89;



													vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11256);
													mem_vec_11256 = vec_90;



													vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_11257);
													mem_vec_11257 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm512_set1_ps(scal_16);


													vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_11258);
													mem_vec_11258 = vec_92;



													vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_11259);
													mem_vec_11259 = vec_94;



													vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_11260);
													mem_vec_11260 = vec_95;



													vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_11261);
													mem_vec_11261 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm512_set1_ps(scal_17);


													vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_11262);
													mem_vec_11262 = vec_97;



													vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_11263);
													mem_vec_11263 = vec_99;



													vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_11264);
													mem_vec_11264 = vec_100;



													vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_11265);
													mem_vec_11265 = vec_101;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11242);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11243);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11244);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11245);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11246);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11247);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11248);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11249);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11250);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11251);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11252);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11253);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11254);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11255);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11256);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11257);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11258);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11259);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11265);
									}
								}
							}
					}
				}
			}
		}
	}
}


}