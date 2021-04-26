#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (2, f);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 2), (Arg 14))]; T (4, x);
  T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c393_p_0, cp_1, c393, f, fp_0, f518_p_0, f519_p_0, fp_1, f518_p_1, fp_2, f518, f519, h, hp_0, w, wp_0, x, xp_0, x393_p_0, xp_1, x393, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y265 = 0;
IND_TYPE x394 = 0;
IND_TYPE h259 = 0;
IND_TYPE w239 = 0;
IND_TYPE c394 = 0;
IND_TYPE f520 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,mem_vec_5015 ,mem_vec_5016 ,mem_vec_5017 ,mem_vec_5018 ,mem_vec_5019 ,mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,mem_vec_5032 ,mem_vec_5033 ,mem_vec_5034 ,mem_vec_5035 ,mem_vec_5036 ,mem_vec_5037 ,mem_vec_5038 ,mem_vec_5039 ,mem_vec_5040 ,mem_vec_5041 ,mem_vec_5042 ,mem_vec_5043 ,mem_vec_5044 ,mem_vec_5045 ,mem_vec_5046 ,mem_vec_5047 ,mem_vec_5048 ,mem_vec_5049 ,mem_vec_5050 ,mem_vec_5051 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f519 = f520, f519_p_0 = 0;
	f519 < f520 + 256;
	f519 += 128, f519_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 2) (128 / 64)
	for (f518 = f519, f518_p_1 = f519_p_0, f518_p_0 = 0;
		f518 < f519 + 128;
		f518 += 64, f518_p_1 += 64, f518_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 4) (68 / 17)
		for (x393 = x394, x393_p_0 = 0;
			x393 < x394 + 68;
			x393 += 17, x393_p_0 += 17){
				for (y = y265, yp_0 = 0;
					y < y265 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f518, fp_2 = f518_p_1, fp_1 = f518_p_0, fp_0 = 0;
						f < f518 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c393 = c394, c393_p_0 = 0;
							c393 < c394 + 128;
							c393 += 32, c393_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w239, wp_0 = 0;
								w < w239 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x393, xp_1 = x393_p_0, xp_0 = 0;
									x < x393 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h259, hp_0 = 0;
										h < h259 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c393, cp_1 = c393_p_0, cp_0 = 0;
													c < c393 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5008);
													mem_vec_5008 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5009);
													mem_vec_5009 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5010);
													mem_vec_5010 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5011);
													mem_vec_5011 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5012);
													mem_vec_5012 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5013);
													mem_vec_5013 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5014);
													mem_vec_5014 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5015);
													mem_vec_5015 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5016);
													mem_vec_5016 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5017);
													mem_vec_5017 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5018);
													mem_vec_5018 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5019);
													mem_vec_5019 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5020);
													mem_vec_5020 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5021);
													mem_vec_5021 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5022);
													mem_vec_5022 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5023);
													mem_vec_5023 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5016);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5023);
									}
								}
							}
						}
					}
				}
				for (y = y265 + 40, yp_0 = 0;
					y < y265 + 40 + 28;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f518, fp_2 = f518_p_1, fp_1 = f518_p_0, fp_0 = 0;
						f < f518 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c393 = c394, c393_p_0 = 0;
							c393 < c394 + 128;
							c393 += 32, c393_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w239, wp_0 = 0;
								w < w239 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x393, xp_1 = x393_p_0, xp_0 = 0;
									x < x393 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h259, hp_0 = 0;
										h < h259 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5024 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5025 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_5044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_5045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_5046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_5047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_5048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_5049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_5050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_5051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c393, cp_1 = c393_p_0, cp_0 = 0;
													c < c393 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5024);
													mem_vec_5024 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5025);
													mem_vec_5025 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5026);
													mem_vec_5026 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5027);
													mem_vec_5027 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5028);
													mem_vec_5028 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5029);
													mem_vec_5029 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5030);
													mem_vec_5030 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5031);
													mem_vec_5031 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5032);
													mem_vec_5032 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5033);
													mem_vec_5033 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5034);
													mem_vec_5034 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5035);
													mem_vec_5035 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5036);
													mem_vec_5036 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5037);
													mem_vec_5037 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5038);
													mem_vec_5038 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5039);
													mem_vec_5039 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5040);
													mem_vec_5040 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5041);
													mem_vec_5041 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5042);
													mem_vec_5042 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5043);
													mem_vec_5043 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5044);
													mem_vec_5044 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5045);
													mem_vec_5045 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5046);
													mem_vec_5046 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5047);
													mem_vec_5047 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5048);
													mem_vec_5048 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5049);
													mem_vec_5049 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5050);
													mem_vec_5050 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5051);
													mem_vec_5051 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5025);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5026);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5027);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5028);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5029);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5030);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5031);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5032);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5033);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5034);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5035);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5036);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5037);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5038);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5039);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5040);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5041);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5042);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5043);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5044);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5045);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5046);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5047);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5048);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5049);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5050);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5051);
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