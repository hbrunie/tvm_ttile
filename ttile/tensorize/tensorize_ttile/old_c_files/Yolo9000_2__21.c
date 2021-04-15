#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (4, c);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (272, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x87_p_0, xp_1, x87, y, yp_0, y87_p_0, yp_1, y87;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y88 = 0;
IND_TYPE x88 = 0;
IND_TYPE h43 = 0;
IND_TYPE w52 = 0;
IND_TYPE c79 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,mem_vec_988 ,mem_vec_989 ,mem_vec_990 ,mem_vec_991 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 2) (272 / 136)
for (y87 = y88, y87_p_0 = 0;
	y87 < y88 + 272;
	y87 += 136, y87_p_0 += 136){
	// y = 136, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x87 = x88, x87_p_0 = 0;
		x87 < x88 + 272;
		x87 += 1, x87_p_0 += 1){
			for (y = y87, yp_1 = y87_p_0, yp_0 = 0;
				y < y87 + 84;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c78 = c79, c78_p_0 = 0;
					c78 < c79 + 32;
					c78 += 8, c78_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f52, fp_0 = 0;
						f < f52 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
							x < x87 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h43, hp_0 = 0;
								h < h43 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
											mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_949);
												mem_vec_949 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_950);
												mem_vec_950 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_951);
												mem_vec_951 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_952);
												mem_vec_952 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_953);
												mem_vec_953 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_954);
												mem_vec_954 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_955);
												mem_vec_955 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_956);
												mem_vec_956 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_957);
												mem_vec_957 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_958);
												mem_vec_958 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_959);
												mem_vec_959 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_960);
												mem_vec_960 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_961);
												mem_vec_961 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_962);
												mem_vec_962 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_963);
												mem_vec_963 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_964);
												mem_vec_964 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_965);
												mem_vec_965 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_966);
												mem_vec_966 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_967);
												mem_vec_967 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_968);
												mem_vec_968 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_969);
												mem_vec_969 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_970);
												mem_vec_970 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_971);
												mem_vec_971 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_972);
												mem_vec_972 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_969);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_972);
								}
							}
						}
					}
				}
			}
			for (y = y87 + 84, yp_1 = y87_p_0, yp_0 = 0;
				y < y87 + 84 + 52;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c78 = c79, c78_p_0 = 0;
					c78 < c79 + 32;
					c78 += 8, c78_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f52, fp_0 = 0;
						f < f52 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
							x < x87 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h43, hp_0 = 0;
								h < h43 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
											mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_973);
												mem_vec_973 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_974);
												mem_vec_974 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_975);
												mem_vec_975 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_976);
												mem_vec_976 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_977);
												mem_vec_977 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_978);
												mem_vec_978 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_979);
												mem_vec_979 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_980);
												mem_vec_980 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_981);
												mem_vec_981 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_982);
												mem_vec_982 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_983);
												mem_vec_983 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_984);
												mem_vec_984 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_985);
												mem_vec_985 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_986);
												mem_vec_986 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_987);
												mem_vec_987 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_988);
												mem_vec_988 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_989);
												mem_vec_989 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_990);
												mem_vec_990 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_991);
												mem_vec_991 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_992);
												mem_vec_992 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_993);
												mem_vec_993 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_994);
												mem_vec_994 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_995);
												mem_vec_995 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_996);
												mem_vec_996 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_997);
												mem_vec_997 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_998);
												mem_vec_998 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_973);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_974);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_975);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_976);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_977);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_978);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_979);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_980);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_981);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_982);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_983);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_984);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_985);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_986);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_987);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_988);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_989);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_990);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_991);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_992);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_993);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_994);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_995);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_996);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_997);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_998);
								}
							}
						}
					}
				}
			}
	}
}


}