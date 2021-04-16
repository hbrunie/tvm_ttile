#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c489_p_0, cp_1, c489, f, fp_0, f625_p_0, f626_p_0, fp_1, f625_p_1, fp_2, f625, f626, w, wp_0, x, xp_0, x490_p_0, xp_1, x490, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y338 = 0;
IND_TYPE x491 = 0;
IND_TYPE h = 0;
IND_TYPE w260 = 0;
IND_TYPE c490 = 0;
IND_TYPE f627 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,mem_vec_6254 ,mem_vec_6255 ,mem_vec_6256 ,mem_vec_6257 ,mem_vec_6258 ,mem_vec_6259 ,mem_vec_6260 ,mem_vec_6261 ,mem_vec_6262 ,mem_vec_6263 ,mem_vec_6264 ,mem_vec_6265 ,mem_vec_6266 ,mem_vec_6267 ,mem_vec_6268 ,mem_vec_6269 ,mem_vec_6270 ,mem_vec_6271 ,mem_vec_6272 ,mem_vec_6273 ,mem_vec_6274 ,mem_vec_6275 ,mem_vec_6276 ,mem_vec_6277 ,mem_vec_6278 ,mem_vec_6279 ,mem_vec_6280 ,mem_vec_6281 ,mem_vec_6282 ,mem_vec_6283 ,mem_vec_6284 ,mem_vec_6285 ,mem_vec_6286 ,mem_vec_6287 ,mem_vec_6288 ,mem_vec_6289 ,mem_vec_6290 ,mem_vec_6291 ,mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f626 = f627, f626_p_0 = 0;
	f626 < f627 + 64;
	f626 += 64, f626_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f625 = f626, f625_p_1 = f626_p_0, f625_p_0 = 0;
		f625 < f626 + 64;
		f625 += 32, f625_p_1 += 32, f625_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 8) (56 / 7)
		for (x490 = x491, x490_p_0 = 0;
			x490 < x491 + 56;
			x490 += 7, x490_p_0 += 7){
				for (y = y338, yp_0 = 0;
					y < y338 + 42;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f625, fp_2 = f625_p_1, fp_1 = f625_p_0, fp_0 = 0;
						f < f625 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
						// T (c, 4) (64 / 16)
						for (c489 = c490, c489_p_0 = 0;
							c489 < c490 + 64;
							c489 += 16, c489_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w260, wp_0 = 0;
								w < w260 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x490, xp_1 = x490_p_0, xp_0 = 0;
									x < x490 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6248 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6249 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6250 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6251 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_6268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c489, cp_1 = c489_p_0, cp_0 = 0;
												c < c489 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6248);
												mem_vec_6248 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6249);
												mem_vec_6249 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6250);
												mem_vec_6250 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6251);
												mem_vec_6251 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6252);
												mem_vec_6252 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6253);
												mem_vec_6253 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6254);
												mem_vec_6254 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6255);
												mem_vec_6255 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6256);
												mem_vec_6256 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6257);
												mem_vec_6257 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6258);
												mem_vec_6258 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6259);
												mem_vec_6259 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6260);
												mem_vec_6260 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6261);
												mem_vec_6261 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6262);
												mem_vec_6262 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6263);
												mem_vec_6263 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6264);
												mem_vec_6264 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6265);
												mem_vec_6265 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6266);
												mem_vec_6266 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6267);
												mem_vec_6267 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6268);
												mem_vec_6268 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6269);
												mem_vec_6269 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6270);
												mem_vec_6270 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6271);
												mem_vec_6271 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6248);
												mem_vec_6248 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6249);
												mem_vec_6249 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6250);
												mem_vec_6250 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6251);
												mem_vec_6251 = vec_41;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6252);
												mem_vec_6252 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6253);
												mem_vec_6253 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6254);
												mem_vec_6254 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6255);
												mem_vec_6255 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6256);
												mem_vec_6256 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6257);
												mem_vec_6257 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6258);
												mem_vec_6258 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6259);
												mem_vec_6259 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6260);
												mem_vec_6260 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6261);
												mem_vec_6261 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6262);
												mem_vec_6262 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6263);
												mem_vec_6263 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6264);
												mem_vec_6264 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6265);
												mem_vec_6265 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6266);
												mem_vec_6266 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6267);
												mem_vec_6267 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6268);
												mem_vec_6268 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6269);
												mem_vec_6269 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6270);
												mem_vec_6270 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6271);
												mem_vec_6271 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6248);
												mem_vec_6248 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6249);
												mem_vec_6249 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6250);
												mem_vec_6250 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6251);
												mem_vec_6251 = vec_75;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6252);
												mem_vec_6252 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6253);
												mem_vec_6253 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6254);
												mem_vec_6254 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6255);
												mem_vec_6255 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6256);
												mem_vec_6256 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6257);
												mem_vec_6257 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6258);
												mem_vec_6258 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6259);
												mem_vec_6259 = vec_86;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6260);
												mem_vec_6260 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6261);
												mem_vec_6261 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6262);
												mem_vec_6262 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6263);
												mem_vec_6263 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6264);
												mem_vec_6264 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6265);
												mem_vec_6265 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6266);
												mem_vec_6266 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6267);
												mem_vec_6267 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6268);
												mem_vec_6268 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6269);
												mem_vec_6269 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6270);
												mem_vec_6270 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6271);
												mem_vec_6271 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6251);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6252);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6253);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6254);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6255);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6259);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6260);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6261);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6267);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6271);
								}
							}
						}
					}
				}
				for (y = y338 + 42, yp_0 = 0;
					y < y338 + 42 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f625, fp_2 = f625_p_1, fp_1 = f625_p_0, fp_0 = 0;
						f < f625 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
						// T (c, 4) (64 / 16)
						for (c489 = c490, c489_p_0 = 0;
							c489 < c490 + 64;
							c489 += 16, c489_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w260, wp_0 = 0;
								w < w260 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x490, xp_1 = x490_p_0, xp_0 = 0;
									x < x490 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_6292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_6296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c489, cp_1 = c489_p_0, cp_0 = 0;
												c < c489 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6272);
												mem_vec_6272 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6273);
												mem_vec_6273 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6274);
												mem_vec_6274 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6275);
												mem_vec_6275 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6276);
												mem_vec_6276 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6277);
												mem_vec_6277 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6278);
												mem_vec_6278 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6279);
												mem_vec_6279 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6280);
												mem_vec_6280 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6281);
												mem_vec_6281 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6282);
												mem_vec_6282 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6283);
												mem_vec_6283 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6284);
												mem_vec_6284 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6285);
												mem_vec_6285 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6286);
												mem_vec_6286 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6287);
												mem_vec_6287 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6288);
												mem_vec_6288 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6289);
												mem_vec_6289 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6290);
												mem_vec_6290 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6291);
												mem_vec_6291 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6292);
												mem_vec_6292 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6293);
												mem_vec_6293 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6294);
												mem_vec_6294 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6295);
												mem_vec_6295 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6296);
												mem_vec_6296 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6297);
												mem_vec_6297 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6298);
												mem_vec_6298 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6299);
												mem_vec_6299 = vec_38;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6272);
												mem_vec_6272 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6273);
												mem_vec_6273 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6274);
												mem_vec_6274 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6275);
												mem_vec_6275 = vec_46;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6276);
												mem_vec_6276 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6277);
												mem_vec_6277 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6278);
												mem_vec_6278 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6279);
												mem_vec_6279 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6280);
												mem_vec_6280 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6281);
												mem_vec_6281 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6282);
												mem_vec_6282 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6283);
												mem_vec_6283 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6284);
												mem_vec_6284 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6285);
												mem_vec_6285 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6286);
												mem_vec_6286 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6287);
												mem_vec_6287 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6288);
												mem_vec_6288 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6289);
												mem_vec_6289 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6290);
												mem_vec_6290 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6291);
												mem_vec_6291 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6292);
												mem_vec_6292 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6293);
												mem_vec_6293 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6294);
												mem_vec_6294 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6295);
												mem_vec_6295 = vec_72;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6296);
												mem_vec_6296 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6297);
												mem_vec_6297 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6298);
												mem_vec_6298 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6299);
												mem_vec_6299 = vec_77;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6272);
												mem_vec_6272 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6273);
												mem_vec_6273 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6274);
												mem_vec_6274 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6275);
												mem_vec_6275 = vec_85;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6276);
												mem_vec_6276 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6277);
												mem_vec_6277 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6278);
												mem_vec_6278 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6279);
												mem_vec_6279 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6280);
												mem_vec_6280 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6281);
												mem_vec_6281 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6282);
												mem_vec_6282 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6283);
												mem_vec_6283 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6284);
												mem_vec_6284 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6285);
												mem_vec_6285 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6286);
												mem_vec_6286 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6287);
												mem_vec_6287 = vec_101;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6288);
												mem_vec_6288 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6289);
												mem_vec_6289 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6290);
												mem_vec_6290 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6291);
												mem_vec_6291 = vec_106;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6292);
												mem_vec_6292 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6293);
												mem_vec_6293 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6294);
												mem_vec_6294 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6295);
												mem_vec_6295 = vec_111;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6296);
												mem_vec_6296 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6297);
												mem_vec_6297 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6298);
												mem_vec_6298 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6299);
												mem_vec_6299 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6272);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6273);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6274);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6275);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6277);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6295);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6299);
								}
							}
						}
					}
				}
		}
	}
}


}