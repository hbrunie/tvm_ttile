#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (8, f);
  T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f112_p_0, f113_p_0, fp_1, f112_p_1, fp_2, f112, f113, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f114 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1008 ,mem_vec_1009 ,mem_vec_1010 ,mem_vec_1011 ,mem_vec_1012 ,mem_vec_1013 ,mem_vec_1014 ,mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_1036 ,mem_vec_1037 ,mem_vec_1038 ,mem_vec_1039 ,mem_vec_1040 ,mem_vec_1041 ,mem_vec_1042 ,mem_vec_1043 ,mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f113 = f114, f113_p_0 = 0;
	f113 < f114 + 512;
	f113 += 256, f113_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 1) (256 / 256)
	for (c84 = c85, c84_p_0 = 0;
		c84 < c85 + 256;
		c84 += 256, c84_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f112 = f113, f112_p_1 = f113_p_0, f112_p_0 = 0;
			f112 < f113 + 256;
			f112 += 32, f112_p_1 += 32, f112_p_0 += 32){
				for (y = y56, yp_0 = 0;
					y < y56 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x84 = x85, x84_p_0 = 0;
						x84 < x85 + 34;
						x84 += 34, x84_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
							f < f112 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 32
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
									// T (x, 34) (34 / 1)
									for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
										x < x84 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
													c < c84 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1008);
													mem_vec_1008 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1009);
													mem_vec_1009 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1010);
													mem_vec_1010 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1011);
													mem_vec_1011 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1012);
													mem_vec_1012 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1013);
													mem_vec_1013 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1014);
													mem_vec_1014 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1015);
													mem_vec_1015 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1016);
													mem_vec_1016 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1017);
													mem_vec_1017 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1018);
													mem_vec_1018 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1019);
													mem_vec_1019 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1020);
													mem_vec_1020 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1021);
													mem_vec_1021 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1022);
													mem_vec_1022 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1023);
													mem_vec_1023 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1016);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1023);
									}
								}
							}
						}
					}
				}
				for (y = y56 + 8, yp_0 = 0;
					y < y56 + 8 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x84 = x85, x84_p_0 = 0;
						x84 < x85 + 34;
						x84 += 34, x84_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
							f < f112 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 32
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
									// T (x, 34) (34 / 1)
									for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
										x < x84 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1024 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1025 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_1048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_1049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
													c < c84 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1024);
													mem_vec_1024 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1025);
													mem_vec_1025 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1026);
													mem_vec_1026 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1027);
													mem_vec_1027 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1028);
													mem_vec_1028 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1029);
													mem_vec_1029 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1030);
													mem_vec_1030 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1031);
													mem_vec_1031 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1032);
													mem_vec_1032 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1033);
													mem_vec_1033 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1034);
													mem_vec_1034 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1035);
													mem_vec_1035 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1036);
													mem_vec_1036 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1037);
													mem_vec_1037 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1038);
													mem_vec_1038 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1039);
													mem_vec_1039 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1040);
													mem_vec_1040 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1041);
													mem_vec_1041 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1042);
													mem_vec_1042 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1043);
													mem_vec_1043 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1044);
													mem_vec_1044 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1045);
													mem_vec_1045 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1046);
													mem_vec_1046 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1047);
													mem_vec_1047 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1048);
													mem_vec_1048 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1049);
													mem_vec_1049 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1025);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1026);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1027);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1028);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1029);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1030);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1031);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1032);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1033);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1034);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1035);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1036);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1037);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1038);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1039);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1040);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1041);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1042);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1043);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1044);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1045);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1046);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1047);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1048);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1049);
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