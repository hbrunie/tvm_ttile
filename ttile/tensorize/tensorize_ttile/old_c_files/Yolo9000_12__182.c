#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, f); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c986_p_0, cp_1, c986, f, fp_0, f1008_p_0, f1009_p_0, fp_1, f1008_p_1, fp_2, f1008, f1009, w, wp_0, x, xp_0, x986_p_0, xp_1, x986, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y596 = 0;
IND_TYPE x987 = 0;
IND_TYPE h = 0;
IND_TYPE w596 = 0;
IND_TYPE c987 = 0;
IND_TYPE f1010 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11230 ,mem_vec_11231 ,mem_vec_11232 ,mem_vec_11233 ,mem_vec_11234 ,mem_vec_11235 ,mem_vec_11236 ,mem_vec_11237 ,mem_vec_11238 ,mem_vec_11239 ,mem_vec_11240 ,mem_vec_11241 ,mem_vec_11242 ,mem_vec_11243 ,mem_vec_11244 ,mem_vec_11245 ,mem_vec_11246 ,mem_vec_11247 ,mem_vec_11248 ,mem_vec_11249 ,mem_vec_11250 ,mem_vec_11251 ,mem_vec_11252 ,mem_vec_11253 ,mem_vec_11254 ,mem_vec_11255 ,mem_vec_11256 ,mem_vec_11257 ,mem_vec_11258 ,mem_vec_11259 ,mem_vec_11260 ,mem_vec_11261 ,mem_vec_11262 ,mem_vec_11263 ,mem_vec_11264 ,mem_vec_11265 ,mem_vec_11266 ,mem_vec_11267 ,mem_vec_11268 ,mem_vec_11269 ,mem_vec_11270 ,mem_vec_11271 ,mem_vec_11272 ,mem_vec_11273 ,mem_vec_11274 ,mem_vec_11275 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f1009 = f1010, f1009_p_0 = 0;
	f1009 < f1010 + 512;
	f1009 += 256, f1009_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 4) (256 / 64)
	for (c986 = c987, c986_p_0 = 0;
		c986 < c987 + 256;
		c986 += 64, c986_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 256
		// T (f, 2) (256 / 128)
		for (f1008 = f1009, f1008_p_1 = f1009_p_0, f1008_p_0 = 0;
			f1008 < f1009 + 256;
			f1008 += 128, f1008_p_1 += 128, f1008_p_0 += 128){
				for (y = y596, yp_0 = 0;
					y < y596 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
					// T (x, 34) (34 / 1)
					for (x986 = x987, x986_p_0 = 0;
						x986 < x987 + 34;
						x986 += 1, x986_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1008, fp_2 = f1008_p_1, fp_1 = f1008_p_0, fp_0 = 0;
							f < f1008 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w596, wp_0 = 0;
								w < w596 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x986, xp_1 = x986_p_0, xp_0 = 0;
									x < x986 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11230 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11231 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_11242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_11243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_11244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_11245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_11246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_11247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_11248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_11249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_11250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_11251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c986, cp_1 = c986_p_0, cp_0 = 0;
												c < c986 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11230);
												mem_vec_11230 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11231);
												mem_vec_11231 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11232);
												mem_vec_11232 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11233);
												mem_vec_11233 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11234);
												mem_vec_11234 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11235);
												mem_vec_11235 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11236);
												mem_vec_11236 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11237);
												mem_vec_11237 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11238);
												mem_vec_11238 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11239);
												mem_vec_11239 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11240);
												mem_vec_11240 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11241);
												mem_vec_11241 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11242);
												mem_vec_11242 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11243);
												mem_vec_11243 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11244);
												mem_vec_11244 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11245);
												mem_vec_11245 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11246);
												mem_vec_11246 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11247);
												mem_vec_11247 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11248);
												mem_vec_11248 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11249);
												mem_vec_11249 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11250);
												mem_vec_11250 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11251);
												mem_vec_11251 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_11230);
												mem_vec_11230 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_11231);
												mem_vec_11231 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_11232);
												mem_vec_11232 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_11233);
												mem_vec_11233 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11234);
												mem_vec_11234 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_11235);
												mem_vec_11235 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_11236);
												mem_vec_11236 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_11237);
												mem_vec_11237 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_11238);
												mem_vec_11238 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_11239);
												mem_vec_11239 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_11240);
												mem_vec_11240 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_11241);
												mem_vec_11241 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_11242);
												mem_vec_11242 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_11243);
												mem_vec_11243 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_11244);
												mem_vec_11244 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_11245);
												mem_vec_11245 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_11246);
												mem_vec_11246 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_11247);
												mem_vec_11247 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_11248);
												mem_vec_11248 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_11249);
												mem_vec_11249 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_11250);
												mem_vec_11250 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_11251);
												mem_vec_11251 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm512_set1_ps(scal_22);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_11230);
												mem_vec_11230 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_11231);
												mem_vec_11231 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_11232);
												mem_vec_11232 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_11233);
												mem_vec_11233 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_11234);
												mem_vec_11234 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_11235);
												mem_vec_11235 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_11236);
												mem_vec_11236 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_11237);
												mem_vec_11237 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_11238);
												mem_vec_11238 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_11239);
												mem_vec_11239 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11240);
												mem_vec_11240 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11241);
												mem_vec_11241 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_11242);
												mem_vec_11242 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_11243);
												mem_vec_11243 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_11244);
												mem_vec_11244 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_11245);
												mem_vec_11245 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_11246);
												mem_vec_11246 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_11247);
												mem_vec_11247 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_11248);
												mem_vec_11248 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_11249);
												mem_vec_11249 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_11250);
												mem_vec_11250 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_11251);
												mem_vec_11251 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11230);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11231);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11232);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11233);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11234);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11235);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11236);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11237);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11238);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11239);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11240);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11241);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11242);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11243);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11244);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11245);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11246);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11247);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11248);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11249);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11250);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11251);
								}
							}
						}
					}
				}
				for (y = y596 + 22, yp_0 = 0;
					y < y596 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
					// T (x, 34) (34 / 1)
					for (x986 = x987, x986_p_0 = 0;
						x986 < x987 + 34;
						x986 += 1, x986_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1008, fp_2 = f1008_p_1, fp_1 = f1008_p_0, fp_0 = 0;
							f < f1008 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w596, wp_0 = 0;
								w < w596 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x986, xp_1 = x986_p_0, xp_0 = 0;
									x < x986 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_11264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_11265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_11266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_11267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_11268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_11269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_11270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_11271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_11272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_11273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_11274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_11275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c986, cp_1 = c986_p_0, cp_0 = 0;
												c < c986 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11252);
												mem_vec_11252 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11253);
												mem_vec_11253 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11254);
												mem_vec_11254 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11255);
												mem_vec_11255 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11256);
												mem_vec_11256 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11257);
												mem_vec_11257 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11258);
												mem_vec_11258 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11259);
												mem_vec_11259 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11260);
												mem_vec_11260 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11261);
												mem_vec_11261 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11262);
												mem_vec_11262 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11263);
												mem_vec_11263 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11264);
												mem_vec_11264 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11265);
												mem_vec_11265 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11266);
												mem_vec_11266 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11267);
												mem_vec_11267 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11268);
												mem_vec_11268 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11269);
												mem_vec_11269 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11270);
												mem_vec_11270 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11271);
												mem_vec_11271 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11272);
												mem_vec_11272 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11273);
												mem_vec_11273 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11274);
												mem_vec_11274 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11275);
												mem_vec_11275 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_11252);
												mem_vec_11252 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_11253);
												mem_vec_11253 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11254);
												mem_vec_11254 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11255);
												mem_vec_11255 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_11256);
												mem_vec_11256 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_11257);
												mem_vec_11257 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_11258);
												mem_vec_11258 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_11259);
												mem_vec_11259 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_11260);
												mem_vec_11260 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_11261);
												mem_vec_11261 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_11262);
												mem_vec_11262 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_11263);
												mem_vec_11263 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11264);
												mem_vec_11264 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11265);
												mem_vec_11265 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_11266);
												mem_vec_11266 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_11267);
												mem_vec_11267 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_11268);
												mem_vec_11268 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_11269);
												mem_vec_11269 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_11270);
												mem_vec_11270 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_11271);
												mem_vec_11271 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm512_set1_ps(scal_22);


												vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_11272);
												mem_vec_11272 = vec_70;



												vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_11273);
												mem_vec_11273 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_23);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_11274);
												mem_vec_11274 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_11275);
												mem_vec_11275 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm512_set1_ps(scal_24);
												vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_11252);
												mem_vec_11252 = vec_76;

												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_11253);
												mem_vec_11253 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_11254);
												mem_vec_11254 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_11255);
												mem_vec_11255 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_11256);
												mem_vec_11256 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_11257);
												mem_vec_11257 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_11258);
												mem_vec_11258 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_11259);
												mem_vec_11259 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_11260);
												mem_vec_11260 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_11261);
												mem_vec_11261 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_11262);
												mem_vec_11262 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_11263);
												mem_vec_11263 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_11264);
												mem_vec_11264 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_11265);
												mem_vec_11265 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_11266);
												mem_vec_11266 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_11267);
												mem_vec_11267 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_11268);
												mem_vec_11268 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_11269);
												mem_vec_11269 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm512_set1_ps(scal_33);


												vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_11270);
												mem_vec_11270 = vec_105;



												vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_11271);
												mem_vec_11271 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm512_set1_ps(scal_34);


												vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_11272);
												mem_vec_11272 = vec_108;



												vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_11273);
												mem_vec_11273 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm512_set1_ps(scal_35);


												vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_11274);
												mem_vec_11274 = vec_111;



												vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_11275);
												mem_vec_11275 = vec_113;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11252);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11253);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11254);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11255);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11256);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11257);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11258);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11259);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11260);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11261);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11262);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11263);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11264);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11265);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11266);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11267);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11268);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11269);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11270);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11271);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11272);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11273);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11274);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11275);
								}
							}
						}
					}
				}
		}
	}
}


}