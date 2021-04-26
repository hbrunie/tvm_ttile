#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (3, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (1, f);
  T (1, y); T (16, c); T (589, f)]
*/
IND_TYPE c, cp_0, c284_p_0, c285_p_0, cp_1, c284_p_1, cp_2, c284, c285, f, fp_0, f213_p_0, fp_1, f213, x, xp_0, y, yp_0, y213_p_0, yp_1, y213;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y214 = 0;
IND_TYPE x142 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c286 = 0;
IND_TYPE f214 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_2961 ,mem_vec_2962 ,mem_vec_2963 ,mem_vec_2964 ,mem_vec_2965 ,mem_vec_2966 ,mem_vec_2967 ,mem_vec_2968 ,mem_vec_2969 ,mem_vec_2970 ,mem_vec_2971 ,mem_vec_2972 ,mem_vec_2973 ,mem_vec_2974 ,mem_vec_2975 ,mem_vec_2976 ,mem_vec_2977 ,mem_vec_2978 ,mem_vec_2979 ,mem_vec_2980 ,mem_vec_2981 ,mem_vec_2982 ,mem_vec_2983 ,mem_vec_2984 ,mem_vec_2985 ,mem_vec_2986 ,mem_vec_2987 ,mem_vec_2988 ,mem_vec_2989 ,mem_vec_2990 ,mem_vec_2991 ,mem_vec_2992 ,mem_vec_2993 ,mem_vec_2994 ,mem_vec_2995 ,mem_vec_2996 ,mem_vec_2997 ,mem_vec_2998 ,mem_vec_2999 ,mem_vec_3000 ,mem_vec_3001 ,mem_vec_3002 ,mem_vec_3003 ,mem_vec_3004 ,mem_vec_3005 ,mem_vec_3006 ,mem_vec_3007 ,mem_vec_3008 ,mem_vec_3009 ,mem_vec_3010 ,mem_vec_3011 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 589) (28272 / 48)
for (f213 = f214, f213_p_0 = 0;
	f213 < f214 + 28272;
	f213 += 48, f213_p_0 += 48){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 48
	// T (c, 16) (1024 / 64)
	for (c285 = c286, c285_p_0 = 0;
		c285 < c286 + 1024;
		c285 += 64, c285_p_0 += 64){
		// y = 17, x = 17, h = 1, w = 1, c = 64, f = 48
		// T (y, 1) (17 / 17)
		for (y213 = y214, y213_p_0 = 0;
			y213 < y214 + 17;
			y213 += 17, y213_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 64, f = 48
			// T (f, 1) (48 / 48)
			for (f = f213, fp_1 = f213_p_0, fp_0 = 0;
				f < f213 + 48;
				f += 48, fp_1 += 48, fp_0 += 48){
					for (y = y213, yp_1 = y213_p_0, yp_0 = 0;
						y < y213 + 8;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 48
						// T (c, 2) (64 / 32)
						for (c284 = c285, c284_p_1 = c285_p_0, c284_p_0 = 0;
							c284 < c285 + 64;
							c284 += 32, c284_p_1 += 32, c284_p_0 += 32){
							// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 48
							// T (x, 17) (17 / 1)
							for (x = x142, xp_0 = 0;
								x < x142 + 17;
								x += 1, xp_0 += 1){
										mem_vec_2961 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2963 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_2979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_2982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 48
										// T (c, 32) (32 / 1)
										for (c = c284, cp_2 = c284_p_1, cp_1 = c284_p_0, cp_0 = 0;
											c < c284 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2961);
											mem_vec_2961 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2962);
											mem_vec_2962 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2963);
											mem_vec_2963 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2964);
											mem_vec_2964 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_2965);
											mem_vec_2965 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_2966);
											mem_vec_2966 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2967);
											mem_vec_2967 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2968);
											mem_vec_2968 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_2969);
											mem_vec_2969 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2970);
											mem_vec_2970 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_2971);
											mem_vec_2971 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_2972);
											mem_vec_2972 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2973);
											mem_vec_2973 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2974);
											mem_vec_2974 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2975);
											mem_vec_2975 = vec_22;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_24 = _mm512_set1_ps(scal_5);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2976);
											mem_vec_2976 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2977);
											mem_vec_2977 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_6, mem_vec_2978);
											mem_vec_2978 = vec_26;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_28 = _mm512_set1_ps(scal_6);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_2979);
											mem_vec_2979 = vec_27;



											vec_29 = _mm512_fmadd_ps(vec_28, vec_4, mem_vec_2980);
											mem_vec_2980 = vec_29;



											vec_30 = _mm512_fmadd_ps(vec_28, vec_6, mem_vec_2981);
											mem_vec_2981 = vec_30;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_32 = _mm512_set1_ps(scal_7);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_2, mem_vec_2982);
											mem_vec_2982 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_4, mem_vec_2983);
											mem_vec_2983 = vec_33;



											vec_34 = _mm512_fmadd_ps(vec_32, vec_6, mem_vec_2984);
											mem_vec_2984 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 32], mem_vec_2984);
							}
						}
					}
					for (y = y213 + 8, yp_1 = y213_p_0, yp_0 = 0;
						y < y213 + 8 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 48
						// T (c, 2) (64 / 32)
						for (c284 = c285, c284_p_1 = c285_p_0, c284_p_0 = 0;
							c284 < c285 + 64;
							c284 += 32, c284_p_1 += 32, c284_p_0 += 32){
							// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 48
							// T (x, 17) (17 / 1)
							for (x = x142, xp_0 = 0;
								x < x142 + 17;
								x += 1, xp_0 += 1){
										mem_vec_2985 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2986 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2987 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_3003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_3006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 32]);
										mem_vec_3009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 48
										// T (c, 32) (32 / 1)
										for (c = c284, cp_2 = c284_p_1, cp_1 = c284_p_0, cp_0 = 0;
											c < c284 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2985);
											mem_vec_2985 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2986);
											mem_vec_2986 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2987);
											mem_vec_2987 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2988);
											mem_vec_2988 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_2989);
											mem_vec_2989 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_2990);
											mem_vec_2990 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2991);
											mem_vec_2991 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2992);
											mem_vec_2992 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_2993);
											mem_vec_2993 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2994);
											mem_vec_2994 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_2995);
											mem_vec_2995 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_2996);
											mem_vec_2996 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2997);
											mem_vec_2997 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2998);
											mem_vec_2998 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2999);
											mem_vec_2999 = vec_22;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_24 = _mm512_set1_ps(scal_5);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3000);
											mem_vec_3000 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3001);
											mem_vec_3001 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_6, mem_vec_3002);
											mem_vec_3002 = vec_26;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_28 = _mm512_set1_ps(scal_6);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_3003);
											mem_vec_3003 = vec_27;



											vec_29 = _mm512_fmadd_ps(vec_28, vec_4, mem_vec_3004);
											mem_vec_3004 = vec_29;



											vec_30 = _mm512_fmadd_ps(vec_28, vec_6, mem_vec_3005);
											mem_vec_3005 = vec_30;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_32 = _mm512_set1_ps(scal_7);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_2, mem_vec_3006);
											mem_vec_3006 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_4, mem_vec_3007);
											mem_vec_3007 = vec_33;



											vec_34 = _mm512_fmadd_ps(vec_32, vec_6, mem_vec_3008);
											mem_vec_3008 = vec_34;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_36 = _mm512_set1_ps(scal_8);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3009);
											mem_vec_3009 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3010);
											mem_vec_3010 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_36, vec_6, mem_vec_3011);
											mem_vec_3011 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2994);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2995);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2996);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2997);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2998);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2999);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3007);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 32], mem_vec_3008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 32], mem_vec_3011);
							}
						}
					}
			}
		}
	}
}


}