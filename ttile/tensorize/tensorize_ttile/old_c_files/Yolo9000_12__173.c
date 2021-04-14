#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (4, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c926_p_0, cp_1, c926, f, fp_0, f928_p_0, f929_p_0, fp_1, f928_p_1, fp_2, f928, f929, w, wp_0, x, xp_0, x926_p_0, xp_1, x926, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y556 = 0;
IND_TYPE x927 = 0;
IND_TYPE h = 0;
IND_TYPE w556 = 0;
IND_TYPE c927 = 0;
IND_TYPE f930 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10310 ,mem_vec_10311 ,mem_vec_10312 ,mem_vec_10313 ,mem_vec_10314 ,mem_vec_10315 ,mem_vec_10316 ,mem_vec_10317 ,mem_vec_10318 ,mem_vec_10319 ,mem_vec_10320 ,mem_vec_10321 ,mem_vec_10322 ,mem_vec_10323 ,mem_vec_10324 ,mem_vec_10325 ,mem_vec_10326 ,mem_vec_10327 ,mem_vec_10328 ,mem_vec_10329 ,mem_vec_10330 ,mem_vec_10331 ,mem_vec_10332 ,mem_vec_10333 ,mem_vec_10334 ,mem_vec_10335 ,mem_vec_10336 ,mem_vec_10337 ,mem_vec_10338 ,mem_vec_10339 ,mem_vec_10340 ,mem_vec_10341 ,mem_vec_10342 ,mem_vec_10343 ,mem_vec_10344 ,mem_vec_10345 ,mem_vec_10346 ,mem_vec_10347 ,mem_vec_10348 ,mem_vec_10349 ,mem_vec_10350 ,mem_vec_10351 ,mem_vec_10352 ,mem_vec_10353 ,mem_vec_10354 ,mem_vec_10355 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f929 = f930, f929_p_0 = 0;
	f929 < f930 + 512;
	f929 += 256, f929_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 2) (256 / 128)
	for (c926 = c927, c926_p_0 = 0;
		c926 < c927 + 256;
		c926 += 128, c926_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 256
		// T (f, 2) (256 / 128)
		for (f928 = f929, f928_p_1 = f929_p_0, f928_p_0 = 0;
			f928 < f929 + 256;
			f928 += 128, f928_p_1 += 128, f928_p_0 += 128){
				for (y = y556, yp_0 = 0;
					y < y556 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (x, 1) (34 / 34)
					for (x926 = x927, x926_p_0 = 0;
						x926 < x927 + 34;
						x926 += 34, x926_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
						// T (f, 4) (128 / 32)
						for (f = f928, fp_2 = f928_p_1, fp_1 = f928_p_0, fp_0 = 0;
							f < f928 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w556, wp_0 = 0;
								w < w556 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 128, f = 32
								// T (x, 34) (34 / 1)
								for (x = x926, xp_1 = x926_p_0, xp_0 = 0;
									x < x926 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10310 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10311 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_10321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_10322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_10323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_10324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_10325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_10326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_10327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_10328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_10329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_10330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_10331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c926, cp_1 = c926_p_0, cp_0 = 0;
												c < c926 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10310);
												mem_vec_10310 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10311);
												mem_vec_10311 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10312);
												mem_vec_10312 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10313);
												mem_vec_10313 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10314);
												mem_vec_10314 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10315);
												mem_vec_10315 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10316);
												mem_vec_10316 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10317);
												mem_vec_10317 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10318);
												mem_vec_10318 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10319);
												mem_vec_10319 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10320);
												mem_vec_10320 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10321);
												mem_vec_10321 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10322);
												mem_vec_10322 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10323);
												mem_vec_10323 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10324);
												mem_vec_10324 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10325);
												mem_vec_10325 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10326);
												mem_vec_10326 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10327);
												mem_vec_10327 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10328);
												mem_vec_10328 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10329);
												mem_vec_10329 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10330);
												mem_vec_10330 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10331);
												mem_vec_10331 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_10310);
												mem_vec_10310 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_10311);
												mem_vec_10311 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_10312);
												mem_vec_10312 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_10313);
												mem_vec_10313 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10314);
												mem_vec_10314 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_10315);
												mem_vec_10315 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_10316);
												mem_vec_10316 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_10317);
												mem_vec_10317 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_10318);
												mem_vec_10318 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_10319);
												mem_vec_10319 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_10320);
												mem_vec_10320 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_10321);
												mem_vec_10321 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_10322);
												mem_vec_10322 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_10323);
												mem_vec_10323 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_10324);
												mem_vec_10324 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_10325);
												mem_vec_10325 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_10326);
												mem_vec_10326 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_10327);
												mem_vec_10327 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_10328);
												mem_vec_10328 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_10329);
												mem_vec_10329 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_10330);
												mem_vec_10330 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_10331);
												mem_vec_10331 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm512_set1_ps(scal_22);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_10310);
												mem_vec_10310 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_10311);
												mem_vec_10311 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_10312);
												mem_vec_10312 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_10313);
												mem_vec_10313 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_10314);
												mem_vec_10314 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_10315);
												mem_vec_10315 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_10316);
												mem_vec_10316 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_10317);
												mem_vec_10317 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_10318);
												mem_vec_10318 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_10319);
												mem_vec_10319 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10320);
												mem_vec_10320 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10321);
												mem_vec_10321 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_10322);
												mem_vec_10322 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_10323);
												mem_vec_10323 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_10324);
												mem_vec_10324 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_10325);
												mem_vec_10325 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_10326);
												mem_vec_10326 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_10327);
												mem_vec_10327 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_10328);
												mem_vec_10328 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_10329);
												mem_vec_10329 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_10330);
												mem_vec_10330 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_10331);
												mem_vec_10331 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10315);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10316);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10317);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10318);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10319);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10320);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10321);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10322);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10323);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10324);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10325);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10326);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10327);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10328);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10329);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10330);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10331);
								}
							}
						}
					}
				}
				for (y = y556 + 22, yp_0 = 0;
					y < y556 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (x, 1) (34 / 34)
					for (x926 = x927, x926_p_0 = 0;
						x926 < x927 + 34;
						x926 += 34, x926_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 128
						// T (f, 4) (128 / 32)
						for (f = f928, fp_2 = f928_p_1, fp_1 = f928_p_0, fp_0 = 0;
							f < f928 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w556, wp_0 = 0;
								w < w556 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 128, f = 32
								// T (x, 34) (34 / 1)
								for (x = x926, xp_1 = x926_p_0, xp_0 = 0;
									x < x926 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10332 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10333 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_10343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_10344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_10345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_10346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_10347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_10348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_10349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_10350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_10351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_10352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_10353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_10354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_10355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c926, cp_1 = c926_p_0, cp_0 = 0;
												c < c926 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10332);
												mem_vec_10332 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10333);
												mem_vec_10333 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10334);
												mem_vec_10334 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10335);
												mem_vec_10335 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10336);
												mem_vec_10336 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10337);
												mem_vec_10337 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10338);
												mem_vec_10338 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10339);
												mem_vec_10339 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10340);
												mem_vec_10340 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10341);
												mem_vec_10341 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10342);
												mem_vec_10342 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10343);
												mem_vec_10343 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10344);
												mem_vec_10344 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10345);
												mem_vec_10345 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10346);
												mem_vec_10346 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10347);
												mem_vec_10347 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10348);
												mem_vec_10348 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10349);
												mem_vec_10349 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10350);
												mem_vec_10350 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10351);
												mem_vec_10351 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10352);
												mem_vec_10352 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10353);
												mem_vec_10353 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10354);
												mem_vec_10354 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10355);
												mem_vec_10355 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_10332);
												mem_vec_10332 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_10333);
												mem_vec_10333 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10334);
												mem_vec_10334 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10335);
												mem_vec_10335 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_10336);
												mem_vec_10336 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_10337);
												mem_vec_10337 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_10338);
												mem_vec_10338 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_10339);
												mem_vec_10339 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_10340);
												mem_vec_10340 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_10341);
												mem_vec_10341 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_10342);
												mem_vec_10342 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_10343);
												mem_vec_10343 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10344);
												mem_vec_10344 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10345);
												mem_vec_10345 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_10346);
												mem_vec_10346 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_10347);
												mem_vec_10347 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_10348);
												mem_vec_10348 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_10349);
												mem_vec_10349 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_10350);
												mem_vec_10350 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_10351);
												mem_vec_10351 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm512_set1_ps(scal_22);


												vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_10352);
												mem_vec_10352 = vec_70;



												vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_10353);
												mem_vec_10353 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_23);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_10354);
												mem_vec_10354 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_10355);
												mem_vec_10355 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm512_set1_ps(scal_24);
												vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_10332);
												mem_vec_10332 = vec_76;

												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_10333);
												mem_vec_10333 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_10334);
												mem_vec_10334 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_10335);
												mem_vec_10335 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_10336);
												mem_vec_10336 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_10337);
												mem_vec_10337 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_10338);
												mem_vec_10338 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10339);
												mem_vec_10339 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_10340);
												mem_vec_10340 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_10341);
												mem_vec_10341 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_10342);
												mem_vec_10342 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_10343);
												mem_vec_10343 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_10344);
												mem_vec_10344 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_10345);
												mem_vec_10345 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_10346);
												mem_vec_10346 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_10347);
												mem_vec_10347 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_10348);
												mem_vec_10348 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10349);
												mem_vec_10349 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm512_set1_ps(scal_33);


												vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_10350);
												mem_vec_10350 = vec_105;



												vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_10351);
												mem_vec_10351 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm512_set1_ps(scal_34);


												vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_10352);
												mem_vec_10352 = vec_108;



												vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_10353);
												mem_vec_10353 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm512_set1_ps(scal_35);


												vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_10354);
												mem_vec_10354 = vec_111;



												vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_10355);
												mem_vec_10355 = vec_113;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10332);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10333);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10334);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10335);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10336);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10337);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10338);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10339);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10340);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10341);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10342);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10343);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10344);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10345);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10346);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10347);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10348);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10349);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10350);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10351);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10352);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10353);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10354);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10355);
								}
							}
						}
					}
				}
		}
	}
}


}