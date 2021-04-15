#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (4, f);
  T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f112_p_0, f113_p_0, fp_1, f112_p_1, fp_2, f112, f113, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f114 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_1008 ,mem_vec_1009 ,mem_vec_1010 ,mem_vec_1011 ,mem_vec_1012 ,mem_vec_1013 ,mem_vec_1014 ,mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_988 ,mem_vec_989 ,mem_vec_990 ,mem_vec_991 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,mem_vec_999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f113 = f114, f113_p_0 = 0;
	f113 < f114 + 1024;
	f113 += 512, f113_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 4) (512 / 128)
	for (c84 = c85, c84_p_0 = 0;
		c84 < c85 + 512;
		c84 += 128, c84_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 128, f = 512
		// T (f, 4) (512 / 128)
		for (f112 = f113, f112_p_1 = f113_p_0, f112_p_0 = 0;
			f112 < f113 + 512;
			f112 += 128, f112_p_1 += 128, f112_p_0 += 128){
				for (y = y56, yp_0 = 0;
					y < y56 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
					// T (x, 1) (17 / 17)
					for (x84 = x85, x84_p_0 = 0;
						x84 < x85 + 17;
						x84 += 17, x84_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
						// T (f, 2) (128 / 64)
						for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
							f < f112 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
									// T (x, 17) (17 / 1)
									for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
										x < x84 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_988 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_989 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_990 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_991 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_1000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_1003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_1004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_1007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
												// T (c, 128) (128 / 1)
												for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
													c < c84 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_988);
													mem_vec_988 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_989);
													mem_vec_989 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_990);
													mem_vec_990 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_991);
													mem_vec_991 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_992);
													mem_vec_992 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_993);
													mem_vec_993 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_994);
													mem_vec_994 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_995);
													mem_vec_995 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_996);
													mem_vec_996 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_997);
													mem_vec_997 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_998);
													mem_vec_998 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_999);
													mem_vec_999 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1000);
													mem_vec_1000 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1001);
													mem_vec_1001 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1002);
													mem_vec_1002 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1003);
													mem_vec_1003 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1004);
													mem_vec_1004 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1005);
													mem_vec_1005 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1006);
													mem_vec_1006 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1007);
													mem_vec_1007 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_988);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_989);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_990);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_991);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_992);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_993);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_994);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_995);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_996);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_997);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_998);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_999);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1000);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1001);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1002);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1003);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1004);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1005);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1006);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1007);
									}
								}
							}
						}
					}
				}
				for (y = y56 + 10, yp_0 = 0;
					y < y56 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
					// T (x, 1) (17 / 17)
					for (x84 = x85, x84_p_0 = 0;
						x84 < x85 + 17;
						x84 += 17, x84_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
						// T (f, 2) (128 / 64)
						for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
							f < f112 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
									// T (x, 17) (17 / 1)
									for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
										x < x84 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1010 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_1011 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_1012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_1015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_1016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_1019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_1020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_1023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_1024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_1027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_1028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_1031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_1032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_1035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
												// T (c, 128) (128 / 1)
												for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
													c < c84 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1008);
													mem_vec_1008 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1009);
													mem_vec_1009 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1010);
													mem_vec_1010 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1011);
													mem_vec_1011 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1012);
													mem_vec_1012 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1013);
													mem_vec_1013 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1014);
													mem_vec_1014 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1015);
													mem_vec_1015 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1016);
													mem_vec_1016 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1017);
													mem_vec_1017 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1018);
													mem_vec_1018 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1019);
													mem_vec_1019 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1020);
													mem_vec_1020 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1021);
													mem_vec_1021 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1022);
													mem_vec_1022 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1023);
													mem_vec_1023 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1024);
													mem_vec_1024 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1025);
													mem_vec_1025 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1026);
													mem_vec_1026 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1027);
													mem_vec_1027 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1028);
													mem_vec_1028 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1029);
													mem_vec_1029 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1030);
													mem_vec_1030 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1031);
													mem_vec_1031 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1032);
													mem_vec_1032 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1033);
													mem_vec_1033 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1034);
													mem_vec_1034 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1035);
													mem_vec_1035 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1016);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1023);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1025);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1026);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1027);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1028);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1029);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1030);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1031);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1032);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1033);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1034);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1035);
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