#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))];
  T (8, f); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c426_p_0, cp_1, c426, f, fp_0, x, xp_0, x568_p_0, x569_p_0, xp_1, x568_p_1, xp_2, x568, x569, y, yp_0, y418_p_0, yp_1, y418;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y419 = 0;
IND_TYPE x570 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c427 = 0;
IND_TYPE f284 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6008 ,mem_vec_6009 ,mem_vec_6010 ,mem_vec_6011 ,mem_vec_6012 ,mem_vec_6013 ,mem_vec_6014 ,mem_vec_6015 ,mem_vec_6016 ,mem_vec_6017 ,mem_vec_6018 ,mem_vec_6019 ,mem_vec_6020 ,mem_vec_6021 ,mem_vec_6022 ,mem_vec_6023 ,mem_vec_6024 ,mem_vec_6025 ,mem_vec_6026 ,mem_vec_6027 ,mem_vec_6028 ,mem_vec_6029 ,mem_vec_6030 ,mem_vec_6031 ,mem_vec_6032 ,mem_vec_6033 ,mem_vec_6034 ,mem_vec_6035 ,mem_vec_6036 ,mem_vec_6037 ,mem_vec_6038 ,mem_vec_6039 ,mem_vec_6040 ,mem_vec_6041 ,mem_vec_6042 ,mem_vec_6043 ,mem_vec_6044 ,mem_vec_6045 ,mem_vec_6046 ,mem_vec_6047 ,mem_vec_6048 ,mem_vec_6049 ,mem_vec_6050 ,mem_vec_6051 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (y, 1) (34 / 34)
for (y418 = y419, y418_p_0 = 0;
	y418 < y419 + 34;
	y418 += 34, y418_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (x, 2) (34 / 17)
	for (x569 = x570, x569_p_0 = 0;
		x569 < x570 + 34;
		x569 += 17, x569_p_0 += 17){
		// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
		// T (f, 8) (256 / 32)
		for (f = f284, fp_0 = 0;
			f < f284 + 256;
			f += 32, fp_0 += 32){
				for (y = y418, yp_1 = y418_p_0, yp_0 = 0;
					y < y418 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (17 / 1)
					for (x568 = x569, x568_p_1 = x569_p_0, x568_p_0 = 0;
						x568 < x569 + 17;
						x568 += 1, x568_p_1 += 1, x568_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c426 = c427, c426_p_0 = 0;
							c426 < c427 + 512;
							c426 += 512, c426_p_0 += 512){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
							// T (x, 1) (1 / 1)
							for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;
								x < x568 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_6026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c426, cp_1 = c426_p_0, cp_0 = 0;
											c < c426 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6008);
											mem_vec_6008 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6009);
											mem_vec_6009 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6010);
											mem_vec_6010 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6011);
											mem_vec_6011 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6012);
											mem_vec_6012 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6013);
											mem_vec_6013 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6014);
											mem_vec_6014 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6015);
											mem_vec_6015 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6016);
											mem_vec_6016 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6017);
											mem_vec_6017 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6018);
											mem_vec_6018 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6019);
											mem_vec_6019 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6020);
											mem_vec_6020 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6021);
											mem_vec_6021 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6022);
											mem_vec_6022 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6023);
											mem_vec_6023 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6024);
											mem_vec_6024 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6025);
											mem_vec_6025 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6026);
											mem_vec_6026 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6027);
											mem_vec_6027 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6011);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6012);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6013);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6014);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6015);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6016);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6017);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6018);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6019);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6020);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6021);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6022);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6023);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6024);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6025);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6026);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6027);
							}
						}
					}
				}
				for (y = y418 + 10, yp_1 = y418_p_0, yp_0 = 0;
					y < y418 + 10 + 24;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (17 / 1)
					for (x568 = x569, x568_p_1 = x569_p_0, x568_p_0 = 0;
						x568 < x569 + 17;
						x568 += 1, x568_p_1 += 1, x568_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c426 = c427, c426_p_0 = 0;
							c426 < c427 + 512;
							c426 += 512, c426_p_0 += 512){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
							// T (x, 1) (1 / 1)
							for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;
								x < x568 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6028 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6029 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_6046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_6048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_6050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_6051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c426, cp_1 = c426_p_0, cp_0 = 0;
											c < c426 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6028);
											mem_vec_6028 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6029);
											mem_vec_6029 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6030);
											mem_vec_6030 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6031);
											mem_vec_6031 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6032);
											mem_vec_6032 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6033);
											mem_vec_6033 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6034);
											mem_vec_6034 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6035);
											mem_vec_6035 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6036);
											mem_vec_6036 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6037);
											mem_vec_6037 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6038);
											mem_vec_6038 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6039);
											mem_vec_6039 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6040);
											mem_vec_6040 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6041);
											mem_vec_6041 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6042);
											mem_vec_6042 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6043);
											mem_vec_6043 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6044);
											mem_vec_6044 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6045);
											mem_vec_6045 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6046);
											mem_vec_6046 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6047);
											mem_vec_6047 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6048);
											mem_vec_6048 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6049);
											mem_vec_6049 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6050);
											mem_vec_6050 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6051);
											mem_vec_6051 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6028);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6029);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6030);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6031);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6032);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6033);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6034);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6035);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6036);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6037);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6038);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6039);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6040);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6041);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6042);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6043);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6044);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6045);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6049);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6050);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6051);
							}
						}
					}
				}
		}
	}
}


}