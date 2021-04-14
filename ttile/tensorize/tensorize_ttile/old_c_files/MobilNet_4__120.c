#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, f); T (1, c); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (2, f)]
*/
IND_TYPE c, cp_0, c720_p_0, cp_1, c720, f, fp_0, f720_p_0, fp_1, f720, h, hp_0, w, wp_0, x, xp_0, x720_p_0, xp_1, x720, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y480 = 0;
IND_TYPE x721 = 0;
IND_TYPE h412 = 0;
IND_TYPE w450 = 0;
IND_TYPE c721 = 0;
IND_TYPE f721 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6948 ,mem_vec_6949 ,mem_vec_6950 ,mem_vec_6951 ,mem_vec_6952 ,mem_vec_6953 ,mem_vec_6954 ,mem_vec_6955 ,mem_vec_6956 ,mem_vec_6957 ,mem_vec_6958 ,mem_vec_6959 ,mem_vec_6960 ,mem_vec_6961 ,mem_vec_6962 ,mem_vec_6963 ,mem_vec_6964 ,mem_vec_6965 ,mem_vec_6966 ,mem_vec_6967 ,mem_vec_6968 ,mem_vec_6969 ,mem_vec_6970 ,mem_vec_6971 ,mem_vec_6972 ,mem_vec_6973 ,mem_vec_6974 ,mem_vec_6975 ,mem_vec_6976 ,mem_vec_6977 ,mem_vec_6978 ,mem_vec_6979 ,mem_vec_6980 ,mem_vec_6981 ,mem_vec_6982 ,mem_vec_6983 ,mem_vec_6984 ,mem_vec_6985 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f720 = f721, f720_p_0 = 0;
	f720 < f721 + 128;
	f720 += 64, f720_p_0 += 64){
		for (y = y480, yp_0 = 0;
			y < y480 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x720 = x721, x720_p_0 = 0;
				x720 < x721 + 28;
				x720 += 1, x720_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c720 = c721, c720_p_0 = 0;
					c720 < c721 + 128;
					c720 += 128, c720_p_0 += 128){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f720, fp_1 = f720_p_0, fp_0 = 0;
						f < f720 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h412, hp_0 = 0;
							h < h412 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w450, wp_0 = 0;
								w < w450 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x720, xp_1 = x720_p_0, xp_0 = 0;
									x < x720 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6948 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6949 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c720, cp_1 = c720_p_0, cp_0 = 0;
												c < c720 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6948);
												mem_vec_6948 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6949);
												mem_vec_6949 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6950);
												mem_vec_6950 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6951);
												mem_vec_6951 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6952);
												mem_vec_6952 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6953);
												mem_vec_6953 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6954);
												mem_vec_6954 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6955);
												mem_vec_6955 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6956);
												mem_vec_6956 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6957);
												mem_vec_6957 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6958);
												mem_vec_6958 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6959);
												mem_vec_6959 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6960);
												mem_vec_6960 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6961);
												mem_vec_6961 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6962);
												mem_vec_6962 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6963);
												mem_vec_6963 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6964);
												mem_vec_6964 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6965);
												mem_vec_6965 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6965);
								}
							}
						}
					}
				}
			}
		}
		for (y = y480 + 18, yp_0 = 0;
			y < y480 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x720 = x721, x720_p_0 = 0;
				x720 < x721 + 28;
				x720 += 1, x720_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c720 = c721, c720_p_0 = 0;
					c720 < c721 + 128;
					c720 += 128, c720_p_0 += 128){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f720, fp_1 = f720_p_0, fp_0 = 0;
						f < f720 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h412, hp_0 = 0;
							h < h412 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w450, wp_0 = 0;
								w < w450 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x720, xp_1 = x720_p_0, xp_0 = 0;
									x < x720 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6966 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6967 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c720, cp_1 = c720_p_0, cp_0 = 0;
												c < c720 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6966);
												mem_vec_6966 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6967);
												mem_vec_6967 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6968);
												mem_vec_6968 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6969);
												mem_vec_6969 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6970);
												mem_vec_6970 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6971);
												mem_vec_6971 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6972);
												mem_vec_6972 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6973);
												mem_vec_6973 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6974);
												mem_vec_6974 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6975);
												mem_vec_6975 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6976);
												mem_vec_6976 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6977);
												mem_vec_6977 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6978);
												mem_vec_6978 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6979);
												mem_vec_6979 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6980);
												mem_vec_6980 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6981);
												mem_vec_6981 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6982);
												mem_vec_6982 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6983);
												mem_vec_6983 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6984);
												mem_vec_6984 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6985);
												mem_vec_6985 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6969);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6972);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6973);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6974);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6975);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6976);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6977);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6978);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6979);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6980);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6981);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6982);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6983);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6984);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6985);
								}
							}
						}
					}
				}
			}
		}
}


}