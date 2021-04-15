#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))];
  T (4, f); T (32, c); T (2, f); T (34, x); T (1, f)]
*/
IND_TYPE c, cp_0, c924_p_0, cp_1, c924, f, fp_0, f1232_p_0, f1233_p_0, fp_1, f1232_p_1, fp_2, f1232, f1233, h, hp_0, w, wp_0, x, xp_0, x976_p_0, xp_1, x976, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y616 = 0;
IND_TYPE x977 = 0;
IND_TYPE h616 = 0;
IND_TYPE w564 = 0;
IND_TYPE c925 = 0;
IND_TYPE f1234 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11940 ,mem_vec_11941 ,mem_vec_11942 ,mem_vec_11943 ,mem_vec_11944 ,mem_vec_11945 ,mem_vec_11946 ,mem_vec_11947 ,mem_vec_11948 ,mem_vec_11949 ,mem_vec_11950 ,mem_vec_11951 ,mem_vec_11952 ,mem_vec_11953 ,mem_vec_11954 ,mem_vec_11955 ,mem_vec_11956 ,mem_vec_11957 ,mem_vec_11958 ,mem_vec_11959 ,mem_vec_11960 ,mem_vec_11961 ,mem_vec_11962 ,mem_vec_11963 ,mem_vec_11964 ,mem_vec_11965 ,mem_vec_11966 ,mem_vec_11967 ,mem_vec_11968 ,mem_vec_11969 ,mem_vec_11970 ,mem_vec_11971 ,mem_vec_11972 ,mem_vec_11973 ,mem_vec_11974 ,mem_vec_11975 ,mem_vec_11976 ,mem_vec_11977 ,mem_vec_11978 ,mem_vec_11979 ,mem_vec_11980 ,mem_vec_11981 ,mem_vec_11982 ,mem_vec_11983 ,mem_vec_11984 ,mem_vec_11985 ,mem_vec_11986 ,mem_vec_11987 ,mem_vec_11988 ,mem_vec_11989 ,mem_vec_11990 ,mem_vec_11991 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1233 = f1234, f1233_p_0 = 0;
	f1233 < f1234 + 256;
	f1233 += 256, f1233_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 34) (68 / 2)
	for (x976 = x977, x976_p_0 = 0;
		x976 < x977 + 68;
		x976 += 2, x976_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (f, 2) (256 / 128)
		for (f1232 = f1233, f1232_p_1 = f1233_p_0, f1232_p_0 = 0;
			f1232 < f1233 + 256;
			f1232 += 128, f1232_p_1 += 128, f1232_p_0 += 128){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
			// T (c, 32) (128 / 4)
			for (c924 = c925, c924_p_0 = 0;
				c924 < c925 + 128;
				c924 += 4, c924_p_0 += 4){
				// y = 68, x = 2, h = 3, w = 3, c = 4, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1232, fp_2 = f1232_p_1, fp_1 = f1232_p_0, fp_0 = 0;
					f < f1232 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y616, yp_0 = 0;
							y < y616 + 12;
							y += 12, yp_0 += 12){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h616, hp_0 = 0;
								h < h616 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w564, wp_0 = 0;
									w < w564 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x976, xp_1 = x976_p_0, xp_0 = 0;
										x < x976 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11940 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11941 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c924, cp_1 = c924_p_0, cp_0 = 0;
													c < c924 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11940);
													mem_vec_11940 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11941);
													mem_vec_11941 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11942);
													mem_vec_11942 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11943);
													mem_vec_11943 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11944);
													mem_vec_11944 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11945);
													mem_vec_11945 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11946);
													mem_vec_11946 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11947);
													mem_vec_11947 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11948);
													mem_vec_11948 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11949);
													mem_vec_11949 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11950);
													mem_vec_11950 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11951);
													mem_vec_11951 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11952);
													mem_vec_11952 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11953);
													mem_vec_11953 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11954);
													mem_vec_11954 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11955);
													mem_vec_11955 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11956);
													mem_vec_11956 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11957);
													mem_vec_11957 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11958);
													mem_vec_11958 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11959);
													mem_vec_11959 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11960);
													mem_vec_11960 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11961);
													mem_vec_11961 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11962);
													mem_vec_11962 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11963);
													mem_vec_11963 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11940);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11941);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11942);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11943);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11944);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11945);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11946);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11947);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11948);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11949);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11950);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11951);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11952);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11953);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11954);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11955);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11956);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11957);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11958);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11959);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11960);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11961);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11962);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11963);
									}
								}
							}
						}
						for (y = y616 + 12, yp_0 = 0;
							y < y616 + 12 + 56;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h616, hp_0 = 0;
								h < h616 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w564, wp_0 = 0;
									w < w564 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x976, xp_1 = x976_p_0, xp_0 = 0;
										x < x976 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11964 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11965 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_11988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_11989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_11990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_11991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c924, cp_1 = c924_p_0, cp_0 = 0;
													c < c924 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11964);
													mem_vec_11964 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11965);
													mem_vec_11965 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11966);
													mem_vec_11966 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11967);
													mem_vec_11967 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11968);
													mem_vec_11968 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11969);
													mem_vec_11969 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11970);
													mem_vec_11970 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11971);
													mem_vec_11971 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11972);
													mem_vec_11972 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11973);
													mem_vec_11973 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11974);
													mem_vec_11974 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11975);
													mem_vec_11975 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11976);
													mem_vec_11976 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11977);
													mem_vec_11977 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11978);
													mem_vec_11978 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11979);
													mem_vec_11979 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11980);
													mem_vec_11980 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11981);
													mem_vec_11981 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11982);
													mem_vec_11982 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11983);
													mem_vec_11983 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11984);
													mem_vec_11984 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11985);
													mem_vec_11985 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11986);
													mem_vec_11986 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11987);
													mem_vec_11987 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11988);
													mem_vec_11988 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11989);
													mem_vec_11989 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11990);
													mem_vec_11990 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11991);
													mem_vec_11991 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11964);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11965);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11966);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11967);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11968);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11969);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11970);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11971);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11972);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11973);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11974);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11975);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11976);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11977);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11978);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11979);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11980);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11981);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11982);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11983);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11984);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11985);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11986);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11987);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11988);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11989);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_11990);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_11991);
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