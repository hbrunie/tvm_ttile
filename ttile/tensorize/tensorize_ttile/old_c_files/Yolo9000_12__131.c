#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, c); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (32, f);
  T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c776_p_0, c777_p_0, cp_1, c776_p_1, cp_2, c776, c777, f, fp_0, w, wp_0, x, xp_0, x776_p_0, x777_p_0, xp_1, x776_p_1, xp_2, x776, x777, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y472 = 0;
IND_TYPE x778 = 0;
IND_TYPE h = 0;
IND_TYPE w472 = 0;
IND_TYPE c778 = 0;
IND_TYPE f808 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8962 ,mem_vec_8963 ,mem_vec_8964 ,mem_vec_8965 ,mem_vec_8966 ,mem_vec_8967 ,mem_vec_8968 ,mem_vec_8969 ,mem_vec_8970 ,mem_vec_8971 ,mem_vec_8972 ,mem_vec_8973 ,mem_vec_8974 ,mem_vec_8975 ,mem_vec_8976 ,mem_vec_8977 ,mem_vec_8978 ,mem_vec_8979 ,mem_vec_8980 ,mem_vec_8981 ,mem_vec_8982 ,mem_vec_8983 ,mem_vec_8984 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (x, 1) (34 / 34)
for (x777 = x778, x777_p_0 = 0;
	x777 < x778 + 34;
	x777 += 34, x777_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 8) (256 / 32)
	for (c777 = c778, c777_p_0 = 0;
		c777 < c778 + 256;
		c777 += 32, c777_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 512
		// T (f, 32) (512 / 16)
		for (f = f808, fp_0 = 0;
			f < f808 + 512;
			f += 16, fp_0 += 16){
				for (y = y472, yp_0 = 0;
					y < y472 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 17) (34 / 2)
					for (x776 = x777, x776_p_1 = x777_p_0, x776_p_0 = 0;
						x776 < x777 + 34;
						x776 += 2, x776_p_1 += 2, x776_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c776 = c777, c776_p_1 = c777_p_0, c776_p_0 = 0;
							c776 < c777 + 32;
							c776 += 16, c776_p_1 += 16, c776_p_0 += 16){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w472, wp_0 = 0;
								w < w472 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 16
								// T (x, 2) (2 / 1)
								for (x = x776, xp_2 = x776_p_1, xp_1 = x776_p_0, xp_0 = 0;
									x < x776 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c776, cp_2 = c776_p_1, cp_1 = c776_p_0, cp_0 = 0;
												c < c776 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8962);
												mem_vec_8962 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8963);
												mem_vec_8963 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8964);
												mem_vec_8964 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8965);
												mem_vec_8965 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8966);
												mem_vec_8966 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8967);
												mem_vec_8967 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8968);
												mem_vec_8968 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);


												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8969);
												mem_vec_8969 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8970);
												mem_vec_8970 = vec_17;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_20 = _mm512_set1_ps(scal_9);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8971);
												mem_vec_8971 = vec_19;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_22 = _mm512_set1_ps(scal_10);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_8972);
												mem_vec_8972 = vec_21;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_11);
												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_8962);
												mem_vec_8962 = vec_23;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_8963);
												mem_vec_8963 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_8964);
												mem_vec_8964 = vec_28;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);


												vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_8965);
												mem_vec_8965 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_8966);
												mem_vec_8966 = vec_32;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_8967);
												mem_vec_8967 = vec_34;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_8968);
												mem_vec_8968 = vec_36;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_18);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_8969);
												mem_vec_8969 = vec_38;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_19);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_8970);
												mem_vec_8970 = vec_40;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_43 = _mm512_set1_ps(scal_20);


												vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_8971);
												mem_vec_8971 = vec_42;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_45 = _mm512_set1_ps(scal_21);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_8972);
												mem_vec_8972 = vec_44;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_47 = _mm512_set1_ps(scal_22);
												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_8962);
												mem_vec_8962 = vec_46;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_50 = _mm512_set1_ps(scal_23);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_8963);
												mem_vec_8963 = vec_49;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_24);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_8964);
												mem_vec_8964 = vec_51;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_8965);
												mem_vec_8965 = vec_53;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_8966);
												mem_vec_8966 = vec_55;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_27);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_8967);
												mem_vec_8967 = vec_57;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_60 = _mm512_set1_ps(scal_28);


												vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_8968);
												mem_vec_8968 = vec_59;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_62 = _mm512_set1_ps(scal_29);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_8969);
												mem_vec_8969 = vec_61;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_30);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_8970);
												mem_vec_8970 = vec_63;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_66 = _mm512_set1_ps(scal_31);


												vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_8971);
												mem_vec_8971 = vec_65;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_32);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_8972);
												mem_vec_8972 = vec_67;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8969);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8972);
								}
							}
						}
					}
				}
				for (y = y472 + 22, yp_0 = 0;
					y < y472 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 17) (34 / 2)
					for (x776 = x777, x776_p_1 = x777_p_0, x776_p_0 = 0;
						x776 < x777 + 34;
						x776 += 2, x776_p_1 += 2, x776_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c776 = c777, c776_p_1 = c777_p_0, c776_p_0 = 0;
							c776 < c777 + 32;
							c776 += 16, c776_p_1 += 16, c776_p_0 += 16){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w472, wp_0 = 0;
								w < w472 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 16
								// T (x, 2) (2 / 1)
								for (x = x776, xp_2 = x776_p_1, xp_1 = x776_p_0, xp_0 = 0;
									x < x776 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8973 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c776, cp_2 = c776_p_1, cp_1 = c776_p_0, cp_0 = 0;
												c < c776 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8973);
												mem_vec_8973 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8974);
												mem_vec_8974 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8975);
												mem_vec_8975 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8976);
												mem_vec_8976 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8977);
												mem_vec_8977 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8978);
												mem_vec_8978 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8979);
												mem_vec_8979 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);


												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8980);
												mem_vec_8980 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8981);
												mem_vec_8981 = vec_17;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_20 = _mm512_set1_ps(scal_9);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8982);
												mem_vec_8982 = vec_19;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_22 = _mm512_set1_ps(scal_10);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_8983);
												mem_vec_8983 = vec_21;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_24 = _mm512_set1_ps(scal_11);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8984);
												mem_vec_8984 = vec_23;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_26 = _mm512_set1_ps(scal_12);
												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_8973);
												mem_vec_8973 = vec_25;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_8974);
												mem_vec_8974 = vec_28;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);


												vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_8975);
												mem_vec_8975 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_8976);
												mem_vec_8976 = vec_32;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_8977);
												mem_vec_8977 = vec_34;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_8978);
												mem_vec_8978 = vec_36;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_18);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_8979);
												mem_vec_8979 = vec_38;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_19);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_8980);
												mem_vec_8980 = vec_40;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_43 = _mm512_set1_ps(scal_20);


												vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_8981);
												mem_vec_8981 = vec_42;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_45 = _mm512_set1_ps(scal_21);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_8982);
												mem_vec_8982 = vec_44;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_22);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_8983);
												mem_vec_8983 = vec_46;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_23);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_8984);
												mem_vec_8984 = vec_48;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_51 = _mm512_set1_ps(scal_24);
												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_8973);
												mem_vec_8973 = vec_50;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_8974);
												mem_vec_8974 = vec_53;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_8975);
												mem_vec_8975 = vec_55;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_27);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_8976);
												mem_vec_8976 = vec_57;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_60 = _mm512_set1_ps(scal_28);


												vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_8977);
												mem_vec_8977 = vec_59;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_62 = _mm512_set1_ps(scal_29);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_8978);
												mem_vec_8978 = vec_61;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_30);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_8979);
												mem_vec_8979 = vec_63;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_66 = _mm512_set1_ps(scal_31);


												vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_8980);
												mem_vec_8980 = vec_65;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_32);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_8981);
												mem_vec_8981 = vec_67;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_33);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_8982);
												mem_vec_8982 = vec_69;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_72 = _mm512_set1_ps(scal_34);


												vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_8983);
												mem_vec_8983 = vec_71;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_74 = _mm512_set1_ps(scal_35);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_8984);
												mem_vec_8984 = vec_73;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8973);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8974);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8975);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8976);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8977);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8978);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8979);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8980);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8981);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8982);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8983);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8984);
								}
							}
						}
					}
				}
		}
	}
}


}