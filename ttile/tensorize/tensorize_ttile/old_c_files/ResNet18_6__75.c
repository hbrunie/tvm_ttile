#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, f); T (32, c); T (28, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (2, f)]
*/
IND_TYPE c, cp_0, c816_p_0, cp_1, c816, f, fp_0, f816_p_0, fp_1, f816, h, hp_0, w, wp_0, x, xp_0, x816_p_0, xp_1, x816, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y544 = 0;
IND_TYPE x817 = 0;
IND_TYPE h472 = 0;
IND_TYPE w504 = 0;
IND_TYPE c817 = 0;
IND_TYPE f817 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,mem_vec_8062 ,mem_vec_8063 ,mem_vec_8064 ,mem_vec_8065 ,mem_vec_8066 ,mem_vec_8067 ,mem_vec_8068 ,mem_vec_8069 ,mem_vec_8070 ,mem_vec_8071 ,mem_vec_8072 ,mem_vec_8073 ,mem_vec_8074 ,mem_vec_8075 ,mem_vec_8076 ,mem_vec_8077 ,mem_vec_8078 ,mem_vec_8079 ,mem_vec_8080 ,mem_vec_8081 ,mem_vec_8082 ,mem_vec_8083 ,mem_vec_8084 ,mem_vec_8085 ,mem_vec_8086 ,mem_vec_8087 ,mem_vec_8088 ,mem_vec_8089 ,mem_vec_8090 ,mem_vec_8091 ,mem_vec_8092 ,mem_vec_8093 ,mem_vec_8094 ,mem_vec_8095 ,mem_vec_8096 ,mem_vec_8097 ,mem_vec_8098 ,mem_vec_8099 ,mem_vec_8100 ,mem_vec_8101 ,mem_vec_8102 ,mem_vec_8103 ,mem_vec_8104 ,mem_vec_8105 ,mem_vec_8106 ,mem_vec_8107 ,mem_vec_8108 ,mem_vec_8109 ,mem_vec_8110 ,mem_vec_8111 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f816 = f817, f816_p_0 = 0;
	f816 < f817 + 128;
	f816 += 64, f816_p_0 += 64){
		for (y = y544, yp_0 = 0;
			y < y544 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 28;
				x816 += 1, x816_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 32) (128 / 4)
				for (c816 = c817, c816_p_0 = 0;
					c816 < c817 + 128;
					c816 += 4, c816_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (f, 2) (64 / 32)
					for (f = f816, fp_1 = f816_p_0, fp_0 = 0;
						f < f816 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h472, hp_0 = 0;
							h < h472 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w504, wp_0 = 0;
								w < w504 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
									x < x816 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8056 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8057 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_8080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_8081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c816, cp_1 = c816_p_0, cp_0 = 0;
												c < c816 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8056);
												mem_vec_8056 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8057);
												mem_vec_8057 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8058);
												mem_vec_8058 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8059);
												mem_vec_8059 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8060);
												mem_vec_8060 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8061);
												mem_vec_8061 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8062);
												mem_vec_8062 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8063);
												mem_vec_8063 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8064);
												mem_vec_8064 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8065);
												mem_vec_8065 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8066);
												mem_vec_8066 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8067);
												mem_vec_8067 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8068);
												mem_vec_8068 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8069);
												mem_vec_8069 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8070);
												mem_vec_8070 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8071);
												mem_vec_8071 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8072);
												mem_vec_8072 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8073);
												mem_vec_8073 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8074);
												mem_vec_8074 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8075);
												mem_vec_8075 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8076);
												mem_vec_8076 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8077);
												mem_vec_8077 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8078);
												mem_vec_8078 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8079);
												mem_vec_8079 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8080);
												mem_vec_8080 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8081);
												mem_vec_8081 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8056);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8057);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8058);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8059);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8061);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8071);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8075);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8081);
								}
							}
						}
					}
				}
			}
		}
		for (y = y544 + 13, yp_0 = 0;
			y < y544 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 28;
				x816 += 1, x816_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 32) (128 / 4)
				for (c816 = c817, c816_p_0 = 0;
					c816 < c817 + 128;
					c816 += 4, c816_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (f, 2) (64 / 32)
					for (f = f816, fp_1 = f816_p_0, fp_0 = 0;
						f < f816 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h472, hp_0 = 0;
							h < h472 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w504, wp_0 = 0;
								w < w504 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
									x < x816 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8082 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_8106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_8107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_8108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_8109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_8110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_8111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c816, cp_1 = c816_p_0, cp_0 = 0;
												c < c816 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8082);
												mem_vec_8082 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8083);
												mem_vec_8083 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8084);
												mem_vec_8084 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8085);
												mem_vec_8085 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8086);
												mem_vec_8086 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8087);
												mem_vec_8087 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8088);
												mem_vec_8088 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8089);
												mem_vec_8089 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8090);
												mem_vec_8090 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8091);
												mem_vec_8091 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8092);
												mem_vec_8092 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8093);
												mem_vec_8093 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8094);
												mem_vec_8094 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8095);
												mem_vec_8095 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8096);
												mem_vec_8096 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8097);
												mem_vec_8097 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8098);
												mem_vec_8098 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8099);
												mem_vec_8099 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8100);
												mem_vec_8100 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8101);
												mem_vec_8101 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8102);
												mem_vec_8102 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8103);
												mem_vec_8103 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8104);
												mem_vec_8104 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8105);
												mem_vec_8105 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8106);
												mem_vec_8106 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8107);
												mem_vec_8107 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8108);
												mem_vec_8108 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8109);
												mem_vec_8109 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8110);
												mem_vec_8110 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8111);
												mem_vec_8111 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8083);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8085);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8086);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8087);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8088);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8089);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8090);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8091);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8092);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8093);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8094);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8095);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8096);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8097);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8098);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8099);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_8110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_8111);
								}
							}
						}
					}
				}
			}
		}
}


}