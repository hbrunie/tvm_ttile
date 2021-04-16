#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]; T (2, f);
  T (136, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x363_p_0, xp_1, x363, y, yp_0, y363_p_0, yp_1, y363;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y364 = 0;
IND_TYPE x364 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c270 = 0;
IND_TYPE f214 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5000 ,mem_vec_5001 ,mem_vec_5002 ,mem_vec_5003 ,mem_vec_5004 ,mem_vec_5005 ,mem_vec_5006 ,mem_vec_5007 ,mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,mem_vec_5015 ,mem_vec_5016 ,mem_vec_5017 ,mem_vec_5018 ,mem_vec_5019 ,mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,mem_vec_5032 ,mem_vec_5033 ,mem_vec_5034 ,mem_vec_5035 ,mem_vec_5036 ,mem_vec_5037 ,mem_vec_5038 ,mem_vec_5039 ,mem_vec_5040 ,mem_vec_5041 ,mem_vec_5042 ,mem_vec_5043 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y363 = y364, y363_p_0 = 0;
	y363 < y364 + 136;
	y363 += 34, y363_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x363 = x364, x363_p_0 = 0;
		x363 < x364 + 136;
		x363 += 1, x363_p_0 += 1){
		// y = 34, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f214, fp_0 = 0;
			f < f214 + 64;
			f += 32, fp_0 += 32){
				for (y = y363, yp_1 = y363_p_0, yp_0 = 0;
					y < y363 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x363, xp_1 = x363_p_0, xp_0 = 0;
						x < x363 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5000 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5001 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_5015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_5016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_5017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_5018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_5019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c270, cp_0 = 0;
									c < c270 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5000);
									mem_vec_5000 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5001);
									mem_vec_5001 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5002);
									mem_vec_5002 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5003);
									mem_vec_5003 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5004);
									mem_vec_5004 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5005);
									mem_vec_5005 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5006);
									mem_vec_5006 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5007);
									mem_vec_5007 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5008);
									mem_vec_5008 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5009);
									mem_vec_5009 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5010);
									mem_vec_5010 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5011);
									mem_vec_5011 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5012);
									mem_vec_5012 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5013);
									mem_vec_5013 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5014);
									mem_vec_5014 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5015);
									mem_vec_5015 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5016);
									mem_vec_5016 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5017);
									mem_vec_5017 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5018);
									mem_vec_5018 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5019);
									mem_vec_5019 = vec_31;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5000);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5001);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5002);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5003);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5004);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5005);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5006);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5007);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5008);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5009);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5010);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5011);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5012);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5013);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5014);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5015);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5016);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5017);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5018);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5019);
					}
				}
				for (y = y363 + 10, yp_1 = y363_p_0, yp_0 = 0;
					y < y363 + 10 + 24;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x363, xp_1 = x363_p_0, xp_0 = 0;
						x < x363 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5020 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5021 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_5035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_5036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_5037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_5038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_5039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_5040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_5041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_5042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_5043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c270, cp_0 = 0;
									c < c270 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5020);
									mem_vec_5020 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5021);
									mem_vec_5021 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5022);
									mem_vec_5022 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5023);
									mem_vec_5023 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5024);
									mem_vec_5024 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5025);
									mem_vec_5025 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5026);
									mem_vec_5026 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5027);
									mem_vec_5027 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5028);
									mem_vec_5028 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5029);
									mem_vec_5029 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5030);
									mem_vec_5030 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5031);
									mem_vec_5031 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5032);
									mem_vec_5032 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5033);
									mem_vec_5033 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5034);
									mem_vec_5034 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5035);
									mem_vec_5035 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5036);
									mem_vec_5036 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5037);
									mem_vec_5037 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5038);
									mem_vec_5038 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5039);
									mem_vec_5039 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5040);
									mem_vec_5040 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5041);
									mem_vec_5041 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5042);
									mem_vec_5042 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5043);
									mem_vec_5043 = vec_37;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5020);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5021);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5022);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5023);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5024);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5025);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5026);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5027);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5028);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5029);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5030);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5031);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5032);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5033);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5034);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5035);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5036);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5037);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5038);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5039);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5040);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5041);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5042);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5043);
					}
				}
		}
	}
}


}