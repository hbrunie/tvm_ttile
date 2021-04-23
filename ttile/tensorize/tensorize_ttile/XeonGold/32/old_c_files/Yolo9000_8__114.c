#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (4, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, f116_p_0, f117_p_0, fp_1, f116_p_1, fp_2, f116, f117, h, hp_0, w, wp_0, x, xp_0, x87_p_0, xp_1, x87, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y58 = 0;
IND_TYPE x88 = 0;
IND_TYPE h58 = 0;
IND_TYPE w53 = 0;
IND_TYPE c88 = 0;
IND_TYPE f118 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,mem_vec_1088 ,mem_vec_1089 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f117 = f118, f117_p_0 = 0;
	f117 < f118 + 256;
	f117 += 64, f117_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f116 = f117, f116_p_1 = f117_p_0, f116_p_0 = 0;
		f116 < f117 + 64;
		f116 += 32, f116_p_1 += 32, f116_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x87 = x88, x87_p_0 = 0;
			x87 < x88 + 68;
			x87 += 17, x87_p_0 += 17){
				for (y = y58, yp_0 = 0;
					y < y58 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f116, fp_2 = f116_p_1, fp_1 = f116_p_0, fp_0 = 0;
						f < f116 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c87 = c88, c87_p_0 = 0;
							c87 < c88 + 128;
							c87 += 32, c87_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w53, wp_0 = 0;
								w < w53 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
									x < x87 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h58, hp_0 = 0;
										h < h58 + 3;
										h += 1, hp_0 += 1){
												mem_vec_1044 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1045 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
													c < c87 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1044);
													mem_vec_1044 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1045);
													mem_vec_1045 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1046);
													mem_vec_1046 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1047);
													mem_vec_1047 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1048);
													mem_vec_1048 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1049);
													mem_vec_1049 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1050);
													mem_vec_1050 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1051);
													mem_vec_1051 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1052);
													mem_vec_1052 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1053);
													mem_vec_1053 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1054);
													mem_vec_1054 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1055);
													mem_vec_1055 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1056);
													mem_vec_1056 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1057);
													mem_vec_1057 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1058);
													mem_vec_1058 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1059);
													mem_vec_1059 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1044);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1045);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1046);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1047);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1048);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1049);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1050);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1051);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1052);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1053);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1054);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1055);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1056);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1057);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1058);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1059);
									}
								}
							}
						}
					}
				}
				for (y = y58 + 8, yp_0 = 0;
					y < y58 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f116, fp_2 = f116_p_1, fp_1 = f116_p_0, fp_0 = 0;
						f < f116 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c87 = c88, c87_p_0 = 0;
							c87 < c88 + 128;
							c87 += 32, c87_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w53, wp_0 = 0;
								w < w53 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
									x < x87 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h58, hp_0 = 0;
										h < h58 + 3;
										h += 1, hp_0 += 1){
												mem_vec_1060 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1061 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_1084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_1085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_1086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_1087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_1088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_1089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
													c < c87 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1060);
													mem_vec_1060 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1061);
													mem_vec_1061 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1062);
													mem_vec_1062 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1063);
													mem_vec_1063 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1064);
													mem_vec_1064 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1065);
													mem_vec_1065 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1066);
													mem_vec_1066 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1067);
													mem_vec_1067 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1068);
													mem_vec_1068 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1069);
													mem_vec_1069 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1070);
													mem_vec_1070 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1071);
													mem_vec_1071 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1072);
													mem_vec_1072 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1073);
													mem_vec_1073 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1074);
													mem_vec_1074 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1075);
													mem_vec_1075 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1076);
													mem_vec_1076 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1077);
													mem_vec_1077 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1078);
													mem_vec_1078 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1079);
													mem_vec_1079 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1080);
													mem_vec_1080 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1081);
													mem_vec_1081 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1082);
													mem_vec_1082 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1083);
													mem_vec_1083 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1084);
													mem_vec_1084 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1085);
													mem_vec_1085 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1086);
													mem_vec_1086 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1087);
													mem_vec_1087 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_1088);
													mem_vec_1088 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_1089);
													mem_vec_1089 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1060);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1061);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1062);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1063);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1064);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1065);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1066);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1067);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1068);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1069);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1070);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1071);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1072);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1073);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1074);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1075);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1076);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1077);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1078);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1079);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1080);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1081);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1082);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1083);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1084);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1085);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1086);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1087);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_1088);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_1089);
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