#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (17, x); T (2, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c270_p_0, cp_1, c270, f, fp_0, x, xp_0, x360_p_0, x361_p_0, xp_1, x360_p_1, xp_2, x360, x361, y, yp_0, y262_p_0, yp_1, y262;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y263 = 0;
IND_TYPE x362 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c271 = 0;
IND_TYPE f180 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3996 ,mem_vec_3997 ,mem_vec_3998 ,mem_vec_3999 ,mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,mem_vec_4008 ,mem_vec_4009 ,mem_vec_4010 ,mem_vec_4011 ,mem_vec_4012 ,mem_vec_4013 ,mem_vec_4014 ,mem_vec_4015 ,mem_vec_4016 ,mem_vec_4017 ,mem_vec_4018 ,mem_vec_4019 ,mem_vec_4020 ,mem_vec_4021 ,mem_vec_4022 ,mem_vec_4023 ,mem_vec_4024 ,mem_vec_4025 ,mem_vec_4026 ,mem_vec_4027 ,mem_vec_4028 ,mem_vec_4029 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y262 = y263, y262_p_0 = 0;
		y262 < y263 + 16;
		y262 += 16, y262_p_0 += 16){
		// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x361 = x362, x361_p_0 = 0;
			x361 < x362 + 34;
			x361 += 34, x361_p_0 += 34){
			// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f180, fp_0 = 0;
				f < f180 + 256;
				f += 32, fp_0 += 32){
				// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 2) (2 * ph_y / ph_y)
				for (y = y262, yp_1 = y262_p_0, yp_0 = 0;
					y < y262 + 16;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x360 = x361, x360_p_1 = x361_p_0, x360_p_0 = 0;
						x360 < x361 + 34;
						x360 += 2, x360_p_1 += 2, x360_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 4) (512 / 128)
						for (c270 = c271, c270_p_0 = 0;
							c270 < c271 + 512;
							c270 += 128, c270_p_0 += 128){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x = x360, xp_2 = x360_p_1, xp_1 = x360_p_0, xp_0 = 0;
								x < x360 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3996 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3997 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c270, cp_1 = c270_p_0, cp_0 = 0;
											c < c270 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3996);
											mem_vec_3996 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3997);
											mem_vec_3997 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3998);
											mem_vec_3998 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3999);
											mem_vec_3999 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4000);
											mem_vec_4000 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4001);
											mem_vec_4001 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4002);
											mem_vec_4002 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4003);
											mem_vec_4003 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4004);
											mem_vec_4004 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4005);
											mem_vec_4005 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4006);
											mem_vec_4006 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4007);
											mem_vec_4007 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4008);
											mem_vec_4008 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4009);
											mem_vec_4009 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4010);
											mem_vec_4010 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4011);
											mem_vec_4011 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3996);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3997);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3998);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3999);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4007);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4011);
							}
						}
					}
				}
			}
		}
	}
	for (y262 = y263 + 16, y262_p_0 = 0;
		y262 < y263 + 16 + 18;
		y262 += 18, y262_p_0 += 18){
		// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x361 = x362, x361_p_0 = 0;
			x361 < x362 + 34;
			x361 += 34, x361_p_0 += 34){
			// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f180, fp_0 = 0;
				f < f180 + 256;
				f += 32, fp_0 += 32){
				// y = 2 * ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 2) (2 * ph_y / ph_y)
				for (y = y262, yp_1 = y262_p_0, yp_0 = 0;
					y < y262 + 18;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x360 = x361, x360_p_1 = x361_p_0, x360_p_0 = 0;
						x360 < x361 + 34;
						x360 += 2, x360_p_1 += 2, x360_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 4) (512 / 128)
						for (c270 = c271, c270_p_0 = 0;
							c270 < c271 + 512;
							c270 += 128, c270_p_0 += 128){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x = x360, xp_2 = x360_p_1, xp_1 = x360_p_0, xp_0 = 0;
								x < x360 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4012 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4013 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c270, cp_1 = c270_p_0, cp_0 = 0;
											c < c270 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4012);
											mem_vec_4012 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4013);
											mem_vec_4013 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4014);
											mem_vec_4014 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4015);
											mem_vec_4015 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4016);
											mem_vec_4016 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4017);
											mem_vec_4017 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4018);
											mem_vec_4018 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4019);
											mem_vec_4019 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4020);
											mem_vec_4020 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4021);
											mem_vec_4021 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4022);
											mem_vec_4022 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4023);
											mem_vec_4023 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4024);
											mem_vec_4024 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4025);
											mem_vec_4025 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4026);
											mem_vec_4026 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4027);
											mem_vec_4027 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4028);
											mem_vec_4028 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4029);
											mem_vec_4029 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4012);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4013);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4014);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4015);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4016);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4017);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4018);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4019);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4020);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4021);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4022);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4023);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4024);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4025);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4026);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4027);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4028);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4029);
							}
						}
					}
				}
			}
		}
	}


}