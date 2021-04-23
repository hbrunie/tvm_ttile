#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (8, x);
  T (3, w); T (4, c); T (4, f); T (17, x);
  Lambda_apply y [((Iter 11), (Arg 11)); ((Iter 1), (Arg 15))]; T (1, x)]
*/
IND_TYPE c, cp_0, c555_p_0, cp_1, c555, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x640_p_0, x641_p_0, xp_1, x640_p_1, xp_2, x640, x641, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y418 = 0;
IND_TYPE x642 = 0;
IND_TYPE h314 = 0;
IND_TYPE w366 = 0;
IND_TYPE c556 = 0;
IND_TYPE f370 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7062 ,mem_vec_7063 ,mem_vec_7064 ,mem_vec_7065 ,mem_vec_7066 ,mem_vec_7067 ,mem_vec_7068 ,mem_vec_7069 ,mem_vec_7070 ,mem_vec_7071 ,mem_vec_7072 ,mem_vec_7073 ,mem_vec_7074 ,mem_vec_7075 ,mem_vec_7076 ,mem_vec_7077 ,mem_vec_7078 ,mem_vec_7079 ,mem_vec_7080 ,mem_vec_7081 ,mem_vec_7082 ,mem_vec_7083 ,mem_vec_7084 ,mem_vec_7085 ,mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,mem_vec_7096 ,mem_vec_7097 ,mem_vec_7098 ,mem_vec_7099 ,mem_vec_7100 ,mem_vec_7101 ,mem_vec_7102 ,mem_vec_7103 ,mem_vec_7104 ,mem_vec_7105 ,mem_vec_7106 ,mem_vec_7107 ,mem_vec_7108 ,mem_vec_7109 ,mem_vec_7110 ,mem_vec_7111 ,mem_vec_7112 ,mem_vec_7113 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x641 = x642, x641_p_0 = 0;
	x641 < x642 + 136;
	x641 += 136, x641_p_0 += 136){
		for (y = y418, yp_0 = 0;
			y < y418 + 121;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 17) (136 / 8)
			for (x640 = x641, x640_p_1 = x641_p_0, x640_p_0 = 0;
				x640 < x641 + 136;
				x640 += 8, x640_p_1 += 8, x640_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f370, fp_0 = 0;
					f < f370 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c555 = c556, c555_p_0 = 0;
						c555 < c556 + 64;
						c555 += 16, c555_p_0 += 16){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w366, wp_0 = 0;
							w < w366 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
							// T (x, 8) (8 / 1)
							for (x = x640, xp_2 = x640_p_1, xp_1 = x640_p_0, xp_0 = 0;
								x < x640 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h314, hp_0 = 0;
									h < h314 + 3;
									h += 1, hp_0 += 1){
											mem_vec_7062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c555, cp_1 = c555_p_0, cp_0 = 0;
												c < c555 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7062);
												mem_vec_7062 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7063);
												mem_vec_7063 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7064);
												mem_vec_7064 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7065);
												mem_vec_7065 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7066);
												mem_vec_7066 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7067);
												mem_vec_7067 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7068);
												mem_vec_7068 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7069);
												mem_vec_7069 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7070);
												mem_vec_7070 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7071);
												mem_vec_7071 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7072);
												mem_vec_7072 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7073);
												mem_vec_7073 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7074);
												mem_vec_7074 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7075);
												mem_vec_7075 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7076);
												mem_vec_7076 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7077);
												mem_vec_7077 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7078);
												mem_vec_7078 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7079);
												mem_vec_7079 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7080);
												mem_vec_7080 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7081);
												mem_vec_7081 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7082);
												mem_vec_7082 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7083);
												mem_vec_7083 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7071);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7075);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7081);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7083);
								}
							}
						}
					}
				}
			}
		}
		for (y = y418 + 121, yp_0 = 0;
			y < y418 + 121 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 17) (136 / 8)
			for (x640 = x641, x640_p_1 = x641_p_0, x640_p_0 = 0;
				x640 < x641 + 136;
				x640 += 8, x640_p_1 += 8, x640_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f370, fp_0 = 0;
					f < f370 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c555 = c556, c555_p_0 = 0;
						c555 < c556 + 64;
						c555 += 16, c555_p_0 += 16){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w366, wp_0 = 0;
							w < w366 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
							// T (x, 8) (8 / 1)
							for (x = x640, xp_2 = x640_p_1, xp_1 = x640_p_0, xp_0 = 0;
								x < x640 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h314, hp_0 = 0;
									h < h314 + 3;
									h += 1, hp_0 += 1){
											mem_vec_7084 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7085 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_7110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_7111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_7112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_7113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c555, cp_1 = c555_p_0, cp_0 = 0;
												c < c555 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7084);
												mem_vec_7084 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7085);
												mem_vec_7085 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7086);
												mem_vec_7086 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7087);
												mem_vec_7087 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7088);
												mem_vec_7088 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7089);
												mem_vec_7089 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7090);
												mem_vec_7090 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7091);
												mem_vec_7091 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7092);
												mem_vec_7092 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7093);
												mem_vec_7093 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7094);
												mem_vec_7094 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7095);
												mem_vec_7095 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7096);
												mem_vec_7096 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7097);
												mem_vec_7097 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7098);
												mem_vec_7098 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7099);
												mem_vec_7099 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7100);
												mem_vec_7100 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7101);
												mem_vec_7101 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7102);
												mem_vec_7102 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7103);
												mem_vec_7103 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7104);
												mem_vec_7104 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7105);
												mem_vec_7105 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7106);
												mem_vec_7106 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7107);
												mem_vec_7107 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7108);
												mem_vec_7108 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7109);
												mem_vec_7109 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7110);
												mem_vec_7110 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7111);
												mem_vec_7111 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7112);
												mem_vec_7112 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7113);
												mem_vec_7113 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7085);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7086);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7087);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7088);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7089);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7090);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7091);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7092);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7093);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7094);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7095);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7096);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7097);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7098);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7099);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7111);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7113);
								}
							}
						}
					}
				}
			}
		}
}


}