#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, f); T (34, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, f);
  T (32, c); T (2, f)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, f104_p_0, f105_p_0, fp_1, f104_p_1, fp_2, f104, f105, h, hp_0, w, wp_0, x, xp_0, x78_p_0, xp_1, x78, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y52 = 0;
IND_TYPE x79 = 0;
IND_TYPE h52 = 0;
IND_TYPE w52 = 0;
IND_TYPE c79 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f105 = f106, f105_p_0 = 0;
	f105 < f106 + 512;
	f105 += 256, f105_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 32) (256 / 8)
	for (c78 = c79, c78_p_0 = 0;
		c78 < c79 + 256;
		c78 += 8, c78_p_0 += 8){
		// y = 34, x = 34, h = 3, w = 3, c = 8, f = 256
		// T (f, 2) (256 / 128)
		for (f104 = f105, f104_p_1 = f105_p_0, f104_p_0 = 0;
			f104 < f105 + 256;
			f104 += 128, f104_p_1 += 128, f104_p_0 += 128){
				for (y = y52, yp_0 = 0;
					y < y52 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
					// T (x, 34) (34 / 1)
					for (x78 = x79, x78_p_0 = 0;
						x78 < x79 + 34;
						x78 += 1, x78_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 128
						// T (f, 4) (128 / 32)
						for (f = f104, fp_2 = f104_p_1, fp_1 = f104_p_0, fp_0 = 0;
							f < f104 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x78, xp_1 = x78_p_0, xp_0 = 0;
										x < x78 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
													c < c78 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_936);
													mem_vec_936 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_937);
													mem_vec_937 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_938);
													mem_vec_938 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_939);
													mem_vec_939 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_940);
													mem_vec_940 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_941);
													mem_vec_941 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_942);
													mem_vec_942 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_943);
													mem_vec_943 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_944);
													mem_vec_944 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_945);
													mem_vec_945 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_946);
													mem_vec_946 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_947);
													mem_vec_947 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_948);
													mem_vec_948 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_949);
													mem_vec_949 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_950);
													mem_vec_950 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_951);
													mem_vec_951 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_936);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_937);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_938);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_939);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_940);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_941);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_942);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_943);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_944);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_945);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_946);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_947);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_948);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_949);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_950);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_951);
									}
								}
							}
						}
					}
				}
				for (y = y52 + 24, yp_0 = 0;
					y < y52 + 24 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
					// T (x, 34) (34 / 1)
					for (x78 = x79, x78_p_0 = 0;
						x78 < x79 + 34;
						x78 += 1, x78_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 128
						// T (f, 4) (128 / 32)
						for (f = f104, fp_2 = f104_p_1, fp_1 = f104_p_0, fp_0 = 0;
							f < f104 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x78, xp_1 = x78_p_0, xp_0 = 0;
										x < x78 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
													c < c78 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_952);
													mem_vec_952 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_953);
													mem_vec_953 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_954);
													mem_vec_954 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_955);
													mem_vec_955 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_956);
													mem_vec_956 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_957);
													mem_vec_957 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_958);
													mem_vec_958 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_959);
													mem_vec_959 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_960);
													mem_vec_960 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_961);
													mem_vec_961 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_962);
													mem_vec_962 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_963);
													mem_vec_963 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_964);
													mem_vec_964 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_965);
													mem_vec_965 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_966);
													mem_vec_966 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_967);
													mem_vec_967 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_968);
													mem_vec_968 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_969);
													mem_vec_969 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_970);
													mem_vec_970 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_971);
													mem_vec_971 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_952);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_953);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_954);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_955);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_956);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_957);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_958);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_959);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_960);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_961);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_962);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_963);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_964);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_965);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_966);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_967);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_968);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_969);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_970);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_971);
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