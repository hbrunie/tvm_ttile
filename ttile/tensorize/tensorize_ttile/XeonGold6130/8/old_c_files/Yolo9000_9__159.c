#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (4, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (17, x);
  T (1, y)]
*/
IND_TYPE c, cp_0, c180_p_0, cp_1, c180, f, fp_0, x, xp_0, x240_p_0, x241_p_0, xp_1, x240_p_1, xp_2, x240, x241, y, yp_0, y180_p_0, yp_1, y180;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y181 = 0;
IND_TYPE x242 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c181 = 0;
IND_TYPE f120 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3036 ,mem_vec_3037 ,mem_vec_3038 ,mem_vec_3039 ,mem_vec_3040 ,mem_vec_3041 ,mem_vec_3042 ,mem_vec_3043 ,mem_vec_3044 ,mem_vec_3045 ,mem_vec_3046 ,mem_vec_3047 ,mem_vec_3048 ,mem_vec_3049 ,mem_vec_3050 ,mem_vec_3051 ,mem_vec_3052 ,mem_vec_3053 ,mem_vec_3054 ,mem_vec_3055 ,mem_vec_3056 ,mem_vec_3057 ,mem_vec_3058 ,mem_vec_3059 ,mem_vec_3060 ,mem_vec_3061 ,mem_vec_3062 ,mem_vec_3063 ,mem_vec_3064 ,mem_vec_3065 ,mem_vec_3066 ,mem_vec_3067 ,mem_vec_3068 ,mem_vec_3069 ,mem_vec_3070 ,mem_vec_3071 ,mem_vec_3072 ,mem_vec_3073 ,mem_vec_3074 ,mem_vec_3075 ,mem_vec_3076 ,mem_vec_3077 ,mem_vec_3078 ,mem_vec_3079 ,mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,mem_vec_3085 ,mem_vec_3086 ,mem_vec_3087 ,mem_vec_3088 ,mem_vec_3089 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 1) (68 / 68)
for (y180 = y181, y180_p_0 = 0;
	y180 < y181 + 68;
	y180 += 68, y180_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 17) (68 / 4)
	for (x241 = x242, x241_p_0 = 0;
		x241 < x242 + 68;
		x241 += 4, x241_p_0 += 4){
			for (y = y180, yp_1 = y180_p_0, yp_0 = 0;
				y < y180 + 26;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (4 / 4)
				for (x240 = x241, x240_p_1 = x241_p_0, x240_p_0 = 0;
					x240 < x241 + 4;
					x240 += 4, x240_p_1 += 4, x240_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f120, fp_0 = 0;
						f < f120 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c180 = c181, c180_p_0 = 0;
							c180 < c181 + 256;
							c180 += 256, c180_p_0 += 256){
							// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
							// T (x, 4) (4 / 1)
							for (x = x240, xp_2 = x240_p_1, xp_1 = x240_p_0, xp_0 = 0;
								x < x240 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3037 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c180, cp_1 = c180_p_0, cp_0 = 0;
											c < c180 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3036);
											mem_vec_3036 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3037);
											mem_vec_3037 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3038);
											mem_vec_3038 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3039);
											mem_vec_3039 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3040);
											mem_vec_3040 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3041);
											mem_vec_3041 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3042);
											mem_vec_3042 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3043);
											mem_vec_3043 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3044);
											mem_vec_3044 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3045);
											mem_vec_3045 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3046);
											mem_vec_3046 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3047);
											mem_vec_3047 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3048);
											mem_vec_3048 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3049);
											mem_vec_3049 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3050);
											mem_vec_3050 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3051);
											mem_vec_3051 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3052);
											mem_vec_3052 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3053);
											mem_vec_3053 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3054);
											mem_vec_3054 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3055);
											mem_vec_3055 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3056);
											mem_vec_3056 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3057);
											mem_vec_3057 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3058);
											mem_vec_3058 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3059);
											mem_vec_3059 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3060);
											mem_vec_3060 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3061);
											mem_vec_3061 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3036);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3037);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3038);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3039);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3040);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3041);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3042);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3043);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3044);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3045);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3049);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3050);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3051);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3052);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3053);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3054);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3055);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3056);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3057);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3058);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3059);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3060);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3061);
							}
						}
					}
				}
			}
			for (y = y180 + 26, yp_1 = y180_p_0, yp_0 = 0;
				y < y180 + 26 + 42;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (4 / 4)
				for (x240 = x241, x240_p_1 = x241_p_0, x240_p_0 = 0;
					x240 < x241 + 4;
					x240 += 4, x240_p_1 += 4, x240_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f120, fp_0 = 0;
						f < f120 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c180 = c181, c180_p_0 = 0;
							c180 < c181 + 256;
							c180 += 256, c180_p_0 += 256){
							// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
							// T (x, 4) (4 / 1)
							for (x = x240, xp_2 = x240_p_1, xp_1 = x240_p_0, xp_0 = 0;
								x < x240 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_3088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_3089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c180, cp_1 = c180_p_0, cp_0 = 0;
											c < c180 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3062);
											mem_vec_3062 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3063);
											mem_vec_3063 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3064);
											mem_vec_3064 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3065);
											mem_vec_3065 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3066);
											mem_vec_3066 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3067);
											mem_vec_3067 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3068);
											mem_vec_3068 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3069);
											mem_vec_3069 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3070);
											mem_vec_3070 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3071);
											mem_vec_3071 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3072);
											mem_vec_3072 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3073);
											mem_vec_3073 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3074);
											mem_vec_3074 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3075);
											mem_vec_3075 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3076);
											mem_vec_3076 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3077);
											mem_vec_3077 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3078);
											mem_vec_3078 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3079);
											mem_vec_3079 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3080);
											mem_vec_3080 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3081);
											mem_vec_3081 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3082);
											mem_vec_3082 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3083);
											mem_vec_3083 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3084);
											mem_vec_3084 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3085);
											mem_vec_3085 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3086);
											mem_vec_3086 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3087);
											mem_vec_3087 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3088);
											mem_vec_3088 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3089);
											mem_vec_3089 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3062);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3063);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3064);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3065);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3066);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3067);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3068);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3069);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3070);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3071);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3072);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3073);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3074);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3075);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3076);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3077);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3078);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3079);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3081);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3082);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3083);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3084);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3085);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3086);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3087);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3088);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3089);
							}
						}
					}
				}
			}
	}
}


}