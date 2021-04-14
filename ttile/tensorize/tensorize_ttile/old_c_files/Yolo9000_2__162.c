#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (4, c); T (2, x); T (34, x)]
*/
IND_TYPE c, cp_0, c1152_p_0, cp_1, c1152, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1920_p_0, x1921_p_0, x1922_p_0, xp_1, x1920_p_1, x1921_p_1, xp_2, x1920_p_2, xp_3, x1920, x1921, x1922, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y768 = 0;
IND_TYPE x1923 = 0;
IND_TYPE h768 = 0;
IND_TYPE w628 = 0;
IND_TYPE c1153 = 0;
IND_TYPE f628 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10008 ,mem_vec_10009 ,mem_vec_10010 ,mem_vec_10011 ,mem_vec_10012 ,mem_vec_10013 ,mem_vec_10014 ,mem_vec_10015 ,mem_vec_10016 ,mem_vec_10017 ,mem_vec_10018 ,mem_vec_10019 ,mem_vec_10020 ,mem_vec_10021 ,mem_vec_10022 ,mem_vec_10023 ,mem_vec_10024 ,mem_vec_10025 ,mem_vec_10026 ,mem_vec_10027 ,mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 34) (272 / 8)
for (x1922 = x1923, x1922_p_0 = 0;
	x1922 < x1923 + 272;
	x1922 += 8, x1922_p_0 += 8){
	// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (8 / 4)
	for (x1921 = x1922, x1921_p_1 = x1922_p_0, x1921_p_0 = 0;
		x1921 < x1922 + 8;
		x1921 += 4, x1921_p_1 += 4, x1921_p_0 += 4){
		// y = 272, x = 4, h = 3, w = 3, c = 32, f = 64
		// T (c, 4) (32 / 8)
		for (c1152 = c1153, c1152_p_0 = 0;
			c1152 < c1153 + 32;
			c1152 += 8, c1152_p_0 += 8){
			// y = 272, x = 4, h = 3, w = 3, c = 8, f = 64
			// T (f, 2) (64 / 32)
			for (f = f628, fp_0 = 0;
				f < f628 + 64;
				f += 32, fp_0 += 32){
					for (y = y768, yp_0 = 0;
						y < y768 + 182;
						y += 14, yp_0 += 14){
						// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
						// T (x, 2) (4 / 2)
						for (x1920 = x1921, x1920_p_2 = x1921_p_1, x1920_p_1 = x1921_p_0, x1920_p_0 = 0;
							x1920 < x1921 + 4;
							x1920 += 2, x1920_p_2 += 2, x1920_p_1 += 2, x1920_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h768, hp_0 = 0;
								h < h768 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w628, wp_0 = 0;
									w < w628 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1920, xp_3 = x1920_p_2, xp_2 = x1920_p_1, xp_1 = x1920_p_0, xp_0 = 0;
										x < x1920 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_10023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_10024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_10025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_10026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_10027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_10028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_10029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_10030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_10031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_10032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_10033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_10034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_10035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
													c < c1152 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10008);
													mem_vec_10008 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10009);
													mem_vec_10009 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10010);
													mem_vec_10010 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10011);
													mem_vec_10011 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10012);
													mem_vec_10012 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10013);
													mem_vec_10013 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10014);
													mem_vec_10014 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10015);
													mem_vec_10015 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10016);
													mem_vec_10016 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10017);
													mem_vec_10017 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10018);
													mem_vec_10018 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10019);
													mem_vec_10019 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10020);
													mem_vec_10020 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10021);
													mem_vec_10021 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10022);
													mem_vec_10022 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10023);
													mem_vec_10023 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10024);
													mem_vec_10024 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10025);
													mem_vec_10025 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10026);
													mem_vec_10026 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10027);
													mem_vec_10027 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10028);
													mem_vec_10028 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10029);
													mem_vec_10029 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10030);
													mem_vec_10030 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10031);
													mem_vec_10031 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10032);
													mem_vec_10032 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10033);
													mem_vec_10033 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_10034);
													mem_vec_10034 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_10035);
													mem_vec_10035 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10016);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10023);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10025);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10026);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10027);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10028);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10029);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10030);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10031);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10032);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10033);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_10034);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_10035);
									}
								}
							}
						}
					}
					for (y = y768 + 182, yp_0 = 0;
						y < y768 + 182 + 90;
						y += 15, yp_0 += 15){
						// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
						// T (x, 2) (4 / 2)
						for (x1920 = x1921, x1920_p_2 = x1921_p_1, x1920_p_1 = x1921_p_0, x1920_p_0 = 0;
							x1920 < x1921 + 4;
							x1920 += 2, x1920_p_2 += 2, x1920_p_1 += 2, x1920_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h768, hp_0 = 0;
								h < h768 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w628, wp_0 = 0;
									w < w628 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1920, xp_3 = x1920_p_2, xp_2 = x1920_p_1, xp_1 = x1920_p_0, xp_0 = 0;
										x < x1920 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10037 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_10051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_10052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_10053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_10054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_10055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_10056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_10057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_10058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_10059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_10060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_10061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_10062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_10063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_10064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_10065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
													c < c1152 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10036);
													mem_vec_10036 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10037);
													mem_vec_10037 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10038);
													mem_vec_10038 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10039);
													mem_vec_10039 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10040);
													mem_vec_10040 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10041);
													mem_vec_10041 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10042);
													mem_vec_10042 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10043);
													mem_vec_10043 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10044);
													mem_vec_10044 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10045);
													mem_vec_10045 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10046);
													mem_vec_10046 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10047);
													mem_vec_10047 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10048);
													mem_vec_10048 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10049);
													mem_vec_10049 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10050);
													mem_vec_10050 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10051);
													mem_vec_10051 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10052);
													mem_vec_10052 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10053);
													mem_vec_10053 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10054);
													mem_vec_10054 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10055);
													mem_vec_10055 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10056);
													mem_vec_10056 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10057);
													mem_vec_10057 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10058);
													mem_vec_10058 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10059);
													mem_vec_10059 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10060);
													mem_vec_10060 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10061);
													mem_vec_10061 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_10062);
													mem_vec_10062 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_10063);
													mem_vec_10063 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_10064);
													mem_vec_10064 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_10065);
													mem_vec_10065 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10036);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10037);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10038);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10039);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10040);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10041);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10042);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10043);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10044);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10045);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10046);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10047);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10048);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10049);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10050);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10051);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10052);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10053);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10054);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10055);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10056);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10057);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10058);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10059);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10060);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10061);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_10062);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_10063);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_10064);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_10065);
									}
								}
							}
						}
					}
			}
		}
	}
}


}