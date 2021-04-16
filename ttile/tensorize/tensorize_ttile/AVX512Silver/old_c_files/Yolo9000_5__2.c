#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (8, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, f);
  T (17, x); T (8, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x591_p_0, xp_1, x591, y, yp_0, y591_p_0, yp_1, y591;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y592 = 0;
IND_TYPE x592 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c441 = 0;
IND_TYPE f347 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7994 ,mem_vec_7995 ,mem_vec_7996 ,mem_vec_7997 ,mem_vec_7998 ,mem_vec_7999 ,mem_vec_8000 ,mem_vec_8001 ,mem_vec_8002 ,mem_vec_8003 ,mem_vec_8004 ,mem_vec_8005 ,mem_vec_8006 ,mem_vec_8007 ,mem_vec_8008 ,mem_vec_8009 ,mem_vec_8010 ,mem_vec_8011 ,mem_vec_8012 ,mem_vec_8013 ,mem_vec_8014 ,mem_vec_8015 ,mem_vec_8016 ,mem_vec_8017 ,mem_vec_8018 ,mem_vec_8019 ,mem_vec_8020 ,mem_vec_8021 ,mem_vec_8022 ,mem_vec_8023 ,mem_vec_8024 ,mem_vec_8025 ,mem_vec_8026 ,mem_vec_8027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 8) (136 / 17)
for (y591 = y592, y591_p_0 = 0;
	y591 < y592 + 136;
	y591 += 17, y591_p_0 += 17){
	// y = 17, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 17) (136 / 8)
	for (x591 = x592, x591_p_0 = 0;
		x591 < x592 + 136;
		x591 += 8, x591_p_0 += 8){
		// y = 17, x = 8, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f347, fp_0 = 0;
			f < f347 + 64;
			f += 32, fp_0 += 32){
				for (y = y591, yp_1 = y591_p_0, yp_0 = 0;
					y < y591 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (x, 8) (8 / 1)
					for (x = x591, xp_1 = x591_p_0, xp_0 = 0;
						x < x591 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_7994 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_7995 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_7996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_7997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_7998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_7999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_8000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_8001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_8002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_8003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_8004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_8005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_8006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_8007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_8008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_8009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c441, cp_0 = 0;
									c < c441 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7994);
									mem_vec_7994 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7995);
									mem_vec_7995 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7996);
									mem_vec_7996 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7997);
									mem_vec_7997 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7998);
									mem_vec_7998 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7999);
									mem_vec_7999 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8000);
									mem_vec_8000 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8001);
									mem_vec_8001 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8002);
									mem_vec_8002 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8003);
									mem_vec_8003 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8004);
									mem_vec_8004 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8005);
									mem_vec_8005 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8006);
									mem_vec_8006 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8007);
									mem_vec_8007 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8008);
									mem_vec_8008 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8009);
									mem_vec_8009 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7994);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7995);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7996);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7997);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7998);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7999);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8000);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8001);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8002);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8003);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8004);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8005);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8006);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8007);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8008);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8009);
					}
				}
				for (y = y591 + 8, yp_1 = y591_p_0, yp_0 = 0;
					y < y591 + 8 + 9;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (x, 8) (8 / 1)
					for (x = x591, xp_1 = x591_p_0, xp_0 = 0;
						x < x591 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_8010 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_8011 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_8012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_8013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_8014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_8015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_8016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_8017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_8018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_8019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_8020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_8021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_8022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_8023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_8024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_8025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_8026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_8027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c441, cp_0 = 0;
									c < c441 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8010);
									mem_vec_8010 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8011);
									mem_vec_8011 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8012);
									mem_vec_8012 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8013);
									mem_vec_8013 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8014);
									mem_vec_8014 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8015);
									mem_vec_8015 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8016);
									mem_vec_8016 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8017);
									mem_vec_8017 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8018);
									mem_vec_8018 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8019);
									mem_vec_8019 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8020);
									mem_vec_8020 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8021);
									mem_vec_8021 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8022);
									mem_vec_8022 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8023);
									mem_vec_8023 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8024);
									mem_vec_8024 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8025);
									mem_vec_8025 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8026);
									mem_vec_8026 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8027);
									mem_vec_8027 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8010);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8011);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8012);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8013);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8014);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8015);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8016);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8017);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8018);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8019);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8020);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8021);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8022);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8023);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8024);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8025);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8026);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8027);
					}
				}
		}
	}
}


}