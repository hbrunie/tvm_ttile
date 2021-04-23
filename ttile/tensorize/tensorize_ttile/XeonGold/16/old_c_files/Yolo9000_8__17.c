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
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (4, x);
  T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, f312_p_0, f313_p_0, fp_1, f312_p_1, fp_2, f312, f313, h, hp_0, w, wp_0, x, xp_0, x234_p_0, xp_1, x234, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y156 = 0;
IND_TYPE x235 = 0;
IND_TYPE h156 = 0;
IND_TYPE w142 = 0;
IND_TYPE c235 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3100 ,mem_vec_3101 ,mem_vec_3102 ,mem_vec_3103 ,mem_vec_3104 ,mem_vec_3105 ,mem_vec_3106 ,mem_vec_3107 ,mem_vec_3108 ,mem_vec_3109 ,mem_vec_3110 ,mem_vec_3111 ,mem_vec_3112 ,mem_vec_3113 ,mem_vec_3114 ,mem_vec_3115 ,mem_vec_3116 ,mem_vec_3117 ,mem_vec_3118 ,mem_vec_3119 ,mem_vec_3120 ,mem_vec_3121 ,mem_vec_3122 ,mem_vec_3123 ,mem_vec_3124 ,mem_vec_3125 ,mem_vec_3126 ,mem_vec_3127 ,mem_vec_3128 ,mem_vec_3129 ,mem_vec_3130 ,mem_vec_3131 ,mem_vec_3132 ,mem_vec_3133 ,mem_vec_3134 ,mem_vec_3135 ,mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f313 = f314, f313_p_0 = 0;
	f313 < f314 + 256;
	f313 += 256, f313_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f312 = f313, f312_p_1 = f313_p_0, f312_p_0 = 0;
		f312 < f313 + 256;
		f312 += 32, f312_p_1 += 32, f312_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x234 = x235, x234_p_0 = 0;
			x234 < x235 + 68;
			x234 += 17, x234_p_0 += 17){
				for (y = y156, yp_0 = 0;
					y < y156 + 55;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
						f < f312 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c234 = c235, c234_p_0 = 0;
							c234 < c235 + 128;
							c234 += 32, c234_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w142, wp_0 = 0;
								w < w142 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x234, xp_1 = x234_p_0, xp_0 = 0;
									x < x234 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h156, hp_0 = 0;
										h < h156 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3100 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3101 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_3120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3100);
													mem_vec_3100 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3101);
													mem_vec_3101 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3102);
													mem_vec_3102 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3103);
													mem_vec_3103 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3104);
													mem_vec_3104 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3105);
													mem_vec_3105 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3106);
													mem_vec_3106 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3107);
													mem_vec_3107 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3108);
													mem_vec_3108 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3109);
													mem_vec_3109 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3110);
													mem_vec_3110 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3111);
													mem_vec_3111 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3112);
													mem_vec_3112 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3113);
													mem_vec_3113 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3114);
													mem_vec_3114 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3115);
													mem_vec_3115 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3116);
													mem_vec_3116 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3117);
													mem_vec_3117 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3118);
													mem_vec_3118 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3119);
													mem_vec_3119 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3120);
													mem_vec_3120 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3121);
													mem_vec_3121 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3100);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3101);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3102);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3103);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3104);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3105);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3106);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3107);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3108);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3109);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3110);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3111);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3112);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3113);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3114);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3115);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3116);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3117);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3118);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3119);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3120);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3121);
									}
								}
							}
						}
					}
				}
				for (y = y156 + 55, yp_0 = 0;
					y < y156 + 55 + 13;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
						f < f312 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c234 = c235, c234_p_0 = 0;
							c234 < c235 + 128;
							c234 += 32, c234_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w142, wp_0 = 0;
								w < w142 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x234, xp_1 = x234_p_0, xp_0 = 0;
									x < x234 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h156, hp_0 = 0;
										h < h156 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_3142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_3144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_3145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_3146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_3147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3122);
													mem_vec_3122 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3123);
													mem_vec_3123 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3124);
													mem_vec_3124 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3125);
													mem_vec_3125 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3126);
													mem_vec_3126 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3127);
													mem_vec_3127 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3128);
													mem_vec_3128 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3129);
													mem_vec_3129 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3130);
													mem_vec_3130 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3131);
													mem_vec_3131 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3132);
													mem_vec_3132 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3133);
													mem_vec_3133 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3134);
													mem_vec_3134 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3135);
													mem_vec_3135 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3136);
													mem_vec_3136 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3137);
													mem_vec_3137 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3138);
													mem_vec_3138 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3139);
													mem_vec_3139 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3140);
													mem_vec_3140 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3141);
													mem_vec_3141 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3142);
													mem_vec_3142 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3143);
													mem_vec_3143 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3144);
													mem_vec_3144 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3145);
													mem_vec_3145 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3146);
													mem_vec_3146 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3147);
													mem_vec_3147 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3122);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3123);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3124);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3125);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3126);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3127);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3128);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3129);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3130);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3131);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3132);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3133);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3134);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3135);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3136);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3137);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3147);
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