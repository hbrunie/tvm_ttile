#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))];
  T (1, f); T (4, c); T (2, f); T (2, x); T (4, f)]
*/
IND_TYPE c, cp_0, c804_p_0, cp_1, c804, f, fp_0, f1072_p_0, f1073_p_0, fp_1, f1072_p_1, fp_2, f1072, f1073, h, hp_0, w, wp_0, x, xp_0, x856_p_0, xp_1, x856, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y536 = 0;
IND_TYPE x857 = 0;
IND_TYPE h536 = 0;
IND_TYPE w484 = 0;
IND_TYPE c805 = 0;
IND_TYPE f1074 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9948 ,mem_vec_9949 ,mem_vec_9950 ,mem_vec_9951 ,mem_vec_9952 ,mem_vec_9953 ,mem_vec_9954 ,mem_vec_9955 ,mem_vec_9956 ,mem_vec_9957 ,mem_vec_9958 ,mem_vec_9959 ,mem_vec_9960 ,mem_vec_9961 ,mem_vec_9962 ,mem_vec_9963 ,mem_vec_9964 ,mem_vec_9965 ,mem_vec_9966 ,mem_vec_9967 ,mem_vec_9968 ,mem_vec_9969 ,mem_vec_9970 ,mem_vec_9971 ,mem_vec_9972 ,mem_vec_9973 ,mem_vec_9974 ,mem_vec_9975 ,mem_vec_9976 ,mem_vec_9977 ,mem_vec_9978 ,mem_vec_9979 ,mem_vec_9980 ,mem_vec_9981 ,mem_vec_9982 ,mem_vec_9983 ,mem_vec_9984 ,mem_vec_9985 ,mem_vec_9986 ,mem_vec_9987 ,mem_vec_9988 ,mem_vec_9989 ,mem_vec_9990 ,mem_vec_9991 ,mem_vec_9992 ,mem_vec_9993 ,mem_vec_9994 ,mem_vec_9995 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f1073 = f1074, f1073_p_0 = 0;
	f1073 < f1074 + 256;
	f1073 += 64, f1073_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 2) (68 / 34)
	for (x856 = x857, x856_p_0 = 0;
		x856 < x857 + 68;
		x856 += 34, x856_p_0 += 34){
		// y = 68, x = 34, h = 3, w = 3, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f1072 = f1073, f1072_p_1 = f1073_p_0, f1072_p_0 = 0;
			f1072 < f1073 + 64;
			f1072 += 32, f1072_p_1 += 32, f1072_p_0 += 32){
			// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
			// T (c, 4) (128 / 32)
			for (c804 = c805, c804_p_0 = 0;
				c804 < c805 + 128;
				c804 += 32, c804_p_0 += 32){
				// y = 68, x = 34, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1072, fp_2 = f1072_p_1, fp_1 = f1072_p_0, fp_0 = 0;
					f < f1072 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y536, yp_0 = 0;
							y < y536 + 55;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h536, hp_0 = 0;
								h < h536 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w484, wp_0 = 0;
									w < w484 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 32
									// T (x, 34) (34 / 1)
									for (x = x856, xp_1 = x856_p_0, xp_0 = 0;
										x < x856 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9948 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9949 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c804, cp_1 = c804_p_0, cp_0 = 0;
													c < c804 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9948);
													mem_vec_9948 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9949);
													mem_vec_9949 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9950);
													mem_vec_9950 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9951);
													mem_vec_9951 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9952);
													mem_vec_9952 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9953);
													mem_vec_9953 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9954);
													mem_vec_9954 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9955);
													mem_vec_9955 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9956);
													mem_vec_9956 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9957);
													mem_vec_9957 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9958);
													mem_vec_9958 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9959);
													mem_vec_9959 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9960);
													mem_vec_9960 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9961);
													mem_vec_9961 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9962);
													mem_vec_9962 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9963);
													mem_vec_9963 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9964);
													mem_vec_9964 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9965);
													mem_vec_9965 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9966);
													mem_vec_9966 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9967);
													mem_vec_9967 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9968);
													mem_vec_9968 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9969);
													mem_vec_9969 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9948);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9949);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9950);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9951);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9952);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9953);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9954);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9955);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9956);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9957);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9958);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9959);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9960);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9961);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9962);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9963);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9964);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9965);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9966);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9967);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9968);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9969);
									}
								}
							}
						}
						for (y = y536 + 55, yp_0 = 0;
							y < y536 + 55 + 13;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h536, hp_0 = 0;
								h < h536 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w484, wp_0 = 0;
									w < w484 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 32
									// T (x, 34) (34 / 1)
									for (x = x856, xp_1 = x856_p_0, xp_0 = 0;
										x < x856 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9970 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9971 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c804, cp_1 = c804_p_0, cp_0 = 0;
													c < c804 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9970);
													mem_vec_9970 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9971);
													mem_vec_9971 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9972);
													mem_vec_9972 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9973);
													mem_vec_9973 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9974);
													mem_vec_9974 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9975);
													mem_vec_9975 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9976);
													mem_vec_9976 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9977);
													mem_vec_9977 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9978);
													mem_vec_9978 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9979);
													mem_vec_9979 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9980);
													mem_vec_9980 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9981);
													mem_vec_9981 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9982);
													mem_vec_9982 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9983);
													mem_vec_9983 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9984);
													mem_vec_9984 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9985);
													mem_vec_9985 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9986);
													mem_vec_9986 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9987);
													mem_vec_9987 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9988);
													mem_vec_9988 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9989);
													mem_vec_9989 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9990);
													mem_vec_9990 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9991);
													mem_vec_9991 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9992);
													mem_vec_9992 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9993);
													mem_vec_9993 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9994);
													mem_vec_9994 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9995);
													mem_vec_9995 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9970);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9971);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9972);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9973);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9974);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9975);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9976);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9977);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9978);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9979);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9980);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9981);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9982);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9983);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9984);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9985);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9986);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9987);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9988);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9989);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9990);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9991);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9992);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9993);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9994);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9995);
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