#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, f174_p_0, f175_p_0, fp_1, f174_p_1, fp_2, f174, f175, h, hp_0, x, xp_0, x143_p_0, xp_1, x143, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y97 = 0;
IND_TYPE x144 = 0;
IND_TYPE h92 = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f176 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2106 ,mem_vec_2107 ,mem_vec_2108 ,mem_vec_2109 ,mem_vec_2110 ,mem_vec_2111 ,mem_vec_2112 ,mem_vec_2113 ,mem_vec_2114 ,mem_vec_2115 ,mem_vec_2116 ,mem_vec_2117 ,mem_vec_2118 ,mem_vec_2119 ,mem_vec_2120 ,mem_vec_2121 ,mem_vec_2122 ,mem_vec_2123 ,mem_vec_2124 ,mem_vec_2125 ,mem_vec_2126 ,mem_vec_2127 ,mem_vec_2128 ,mem_vec_2129 ,mem_vec_2130 ,mem_vec_2131 ,mem_vec_2132 ,mem_vec_2133 ,mem_vec_2134 ,mem_vec_2135 ,mem_vec_2136 ,mem_vec_2137 ,mem_vec_2138 ,mem_vec_2139 ,mem_vec_2140 ,mem_vec_2141 ,mem_vec_2142 ,mem_vec_2143 ,mem_vec_2144 ,mem_vec_2145 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f175 = f176, f175_p_0 = 0;
	f175 < f176 + 512;
	f175 += 512, f175_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (f, 4) (512 / 128)
	for (f174 = f175, f174_p_1 = f175_p_0, f174_p_0 = 0;
		f174 < f175 + 512;
		f174 += 128, f174_p_1 += 128, f174_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (x, 2) (34 / 17)
		for (x143 = x144, x143_p_0 = 0;
			x143 < x144 + 34;
			x143 += 17, x143_p_0 += 17){
				for (y = y97, yp_0 = 0;
					y < y97 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f174, fp_2 = f174_p_1, fp_1 = f174_p_0, fp_0 = 0;
						f < f174 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c138 = c139, c138_p_0 = 0;
							c138 < c139 + 256;
							c138 += 256, c138_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h92, hp_0 = 0;
								h < h92 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x143, xp_1 = x143_p_0, xp_0 = 0;
									x < x143 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2106 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2107 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2108 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_2109 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_2110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_2113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_2114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_2117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_2118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_2121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
												c < c138 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2106);
												mem_vec_2106 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2107);
												mem_vec_2107 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2108);
												mem_vec_2108 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2109);
												mem_vec_2109 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2110);
												mem_vec_2110 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2111);
												mem_vec_2111 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2112);
												mem_vec_2112 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2113);
												mem_vec_2113 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2114);
												mem_vec_2114 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2115);
												mem_vec_2115 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2116);
												mem_vec_2116 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2117);
												mem_vec_2117 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2118);
												mem_vec_2118 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2119);
												mem_vec_2119 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2120);
												mem_vec_2120 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2121);
												mem_vec_2121 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_2106);
												mem_vec_2106 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_2107);
												mem_vec_2107 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_2108);
												mem_vec_2108 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_2109);
												mem_vec_2109 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_2110);
												mem_vec_2110 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2111);
												mem_vec_2111 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2112);
												mem_vec_2112 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2113);
												mem_vec_2113 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_2114);
												mem_vec_2114 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_2115);
												mem_vec_2115 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_2116);
												mem_vec_2116 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_2117);
												mem_vec_2117 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_2118);
												mem_vec_2118 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2119);
												mem_vec_2119 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2120);
												mem_vec_2120 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2121);
												mem_vec_2121 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_2106);
												mem_vec_2106 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_2107);
												mem_vec_2107 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_2108);
												mem_vec_2108 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_2109);
												mem_vec_2109 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_2110);
												mem_vec_2110 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2111);
												mem_vec_2111 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2112);
												mem_vec_2112 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2113);
												mem_vec_2113 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_2114);
												mem_vec_2114 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_2115);
												mem_vec_2115 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_2116);
												mem_vec_2116 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_2117);
												mem_vec_2117 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_2118);
												mem_vec_2118 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2119);
												mem_vec_2119 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_2120);
												mem_vec_2120 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2121);
												mem_vec_2121 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2111);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2115);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2116);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2117);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2118);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2119);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2120);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2121);
								}
							}
						}
					}
				}
				for (y = y97 + 4, yp_0 = 0;
					y < y97 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f174, fp_2 = f174_p_1, fp_1 = f174_p_0, fp_0 = 0;
						f < f174 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c138 = c139, c138_p_0 = 0;
							c138 < c139 + 256;
							c138 += 256, c138_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h92, hp_0 = 0;
								h < h92 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x143, xp_1 = x143_p_0, xp_0 = 0;
									x < x143 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2124 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_2125 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_2126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_2129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_2130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_2133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_2134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_2137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_2138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_2141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_2142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_2145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
												c < c138 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2122);
												mem_vec_2122 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2123);
												mem_vec_2123 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2124);
												mem_vec_2124 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2125);
												mem_vec_2125 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2126);
												mem_vec_2126 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2127);
												mem_vec_2127 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2128);
												mem_vec_2128 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2129);
												mem_vec_2129 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2130);
												mem_vec_2130 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2131);
												mem_vec_2131 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2132);
												mem_vec_2132 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2133);
												mem_vec_2133 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2134);
												mem_vec_2134 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2135);
												mem_vec_2135 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2136);
												mem_vec_2136 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2137);
												mem_vec_2137 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2138);
												mem_vec_2138 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2139);
												mem_vec_2139 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2140);
												mem_vec_2140 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2141);
												mem_vec_2141 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2142);
												mem_vec_2142 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2143);
												mem_vec_2143 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2144);
												mem_vec_2144 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2145);
												mem_vec_2145 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2122);
												mem_vec_2122 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_2123);
												mem_vec_2123 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_2124);
												mem_vec_2124 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_2125);
												mem_vec_2125 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2126);
												mem_vec_2126 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_2127);
												mem_vec_2127 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_2128);
												mem_vec_2128 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_2129);
												mem_vec_2129 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_2130);
												mem_vec_2130 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_2131);
												mem_vec_2131 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_2132);
												mem_vec_2132 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2133);
												mem_vec_2133 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_2134);
												mem_vec_2134 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_2135);
												mem_vec_2135 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_2136);
												mem_vec_2136 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_2137);
												mem_vec_2137 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_2138);
												mem_vec_2138 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_2139);
												mem_vec_2139 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_2140);
												mem_vec_2140 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_2141);
												mem_vec_2141 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_2142);
												mem_vec_2142 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_2143);
												mem_vec_2143 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_2144);
												mem_vec_2144 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_2145);
												mem_vec_2145 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_2122);
												mem_vec_2122 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_2123);
												mem_vec_2123 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_2124);
												mem_vec_2124 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_2125);
												mem_vec_2125 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_2126);
												mem_vec_2126 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_2127);
												mem_vec_2127 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_2128);
												mem_vec_2128 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_2129);
												mem_vec_2129 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_2130);
												mem_vec_2130 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_2131);
												mem_vec_2131 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_2132);
												mem_vec_2132 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_2133);
												mem_vec_2133 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_2134);
												mem_vec_2134 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_2135);
												mem_vec_2135 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_2136);
												mem_vec_2136 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_2137);
												mem_vec_2137 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_2138);
												mem_vec_2138 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_2139);
												mem_vec_2139 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_2140);
												mem_vec_2140 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_2141);
												mem_vec_2141 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_2142);
												mem_vec_2142 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_2143);
												mem_vec_2143 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_2144);
												mem_vec_2144 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_2145);
												mem_vec_2145 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2123);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2124);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2125);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2133);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2135);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2136);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2137);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2139);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2145);
								}
							}
						}
					}
				}
		}
	}
}


}