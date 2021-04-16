#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (2, f);
  T (32, c); T (16, f)]
*/
IND_TYPE c, cp_0, c12_p_0, c13_p_0, cp_1, c12_p_1, cp_2, c12, c13, f, fp_0, f9_p_0, fp_1, f9, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y6 = 0;
IND_TYPE x6 = 0;
IND_TYPE h4 = 0;
IND_TYPE w6 = 0;
IND_TYPE c14 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f9 = f10, f9_p_0 = 0;
	f9 < f10 + 1024;
	f9 += 64, f9_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 32) (512 / 16)
	for (c13 = c14, c13_p_0 = 0;
		c13 < c14 + 512;
		c13 += 16, c13_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f9, fp_1 = f9_p_0, fp_0 = 0;
			f < f9 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y6, yp_0 = 0;
					y < y6 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c12 = c13, c12_p_1 = c13_p_0, c12_p_0 = 0;
						c12 < c13 + 16;
						c12 += 16, c12_p_1 += 16, c12_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x6, xp_0 = 0;
							x < x6 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h4, hp_0 = 0;
								h < h4 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w6, wp_0 = 0;
									w < w6 + 3;
									w += 1, wp_0 += 1){
											mem_vec_85 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_86 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_87 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c12, cp_2 = c12_p_1, cp_1 = c12_p_0, cp_0 = 0;
												c < c12 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_85);
												mem_vec_85 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_86);
												mem_vec_86 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_87);
												mem_vec_87 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_88);
												mem_vec_88 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_89);
												mem_vec_89 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_90);
												mem_vec_90 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_91);
												mem_vec_91 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_92);
												mem_vec_92 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_93);
												mem_vec_93 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_94);
												mem_vec_94 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_95);
												mem_vec_95 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_96);
												mem_vec_96 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_97);
												mem_vec_97 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_98);
												mem_vec_98 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_85);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_86);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_87);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_88);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_89);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_90);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_91);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_92);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_93);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_94);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_95);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_96);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_97);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_98);
								}
							}
						}
					}
				}
				for (y = y6 + 7, yp_0 = 0;
					y < y6 + 7 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c12 = c13, c12_p_1 = c13_p_0, c12_p_0 = 0;
						c12 < c13 + 16;
						c12 += 16, c12_p_1 += 16, c12_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x6, xp_0 = 0;
							x < x6 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h4, hp_0 = 0;
								h < h4 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w6, wp_0 = 0;
									w < w6 + 3;
									w += 1, wp_0 += 1){
											mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c12, cp_2 = c12_p_1, cp_1 = c12_p_0, cp_0 = 0;
												c < c12 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_99);
												mem_vec_99 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_100);
												mem_vec_100 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_101);
												mem_vec_101 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_102);
												mem_vec_102 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_103);
												mem_vec_103 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_104);
												mem_vec_104 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_105);
												mem_vec_105 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_106);
												mem_vec_106 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_107);
												mem_vec_107 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_108);
												mem_vec_108 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_109);
												mem_vec_109 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_110);
												mem_vec_110 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_111);
												mem_vec_111 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_112);
												mem_vec_112 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_113);
												mem_vec_113 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_114);
												mem_vec_114 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_115);
												mem_vec_115 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_116);
												mem_vec_116 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_117);
												mem_vec_117 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_118);
												mem_vec_118 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_99);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_111);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_115);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_116);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_117);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_118);
								}
							}
						}
					}
				}
		}
	}
}


}