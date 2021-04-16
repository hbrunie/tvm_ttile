#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (14, x); T (2, c);
  T (2, x); T (4, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c151_p_0, cp_1, c151, f, fp_0, f151_p_0, fp_1, f151, x, xp_0, x162_p_0, xp_1, x162, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y108 = 0;
IND_TYPE x163 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c152 = 0;
IND_TYPE f152 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_1008 ,mem_vec_1009 ,mem_vec_1010 ,mem_vec_1011 ,mem_vec_1012 ,mem_vec_1013 ,mem_vec_1014 ,mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,mem_vec_999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f151 = f152, f151_p_0 = 0;
	f151 < f152 + 128;
	f151 += 128, f151_p_0 += 128){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (f, 2) (128 / 64)
	for (f = f151, fp_1 = f151_p_0, fp_0 = 0;
		f < f151 + 128;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y108, yp_0 = 0;
			y < y108 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x162 = x163, x162_p_0 = 0;
				x162 < x163 + 28;
				x162 += 14, x162_p_0 += 14){
				// y = 7, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c151 = c152, c151_p_0 = 0;
					c151 < c152 + 64;
					c151 += 32, c151_p_0 += 32){
					// y = 7, x = 14, h = 1, w = 1, c = 32, f = 64
					// T (x, 14) (14 / 1)
					for (x = x162, xp_1 = x162_p_0, xp_0 = 0;
						x < x162 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_996 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_997 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_998 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_999 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_1000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_1003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_1004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_1007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_1008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_1011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_1012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_1015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_1016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_1019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_1020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_1023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c151, cp_1 = c151_p_0, cp_0 = 0;
									c < c151 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_996);
									mem_vec_996 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_997);
									mem_vec_997 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_998);
									mem_vec_998 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_999);
									mem_vec_999 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1000);
									mem_vec_1000 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1001);
									mem_vec_1001 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1002);
									mem_vec_1002 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1003);
									mem_vec_1003 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1004);
									mem_vec_1004 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1005);
									mem_vec_1005 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1006);
									mem_vec_1006 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1007);
									mem_vec_1007 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1008);
									mem_vec_1008 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1009);
									mem_vec_1009 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1010);
									mem_vec_1010 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1011);
									mem_vec_1011 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1012);
									mem_vec_1012 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1013);
									mem_vec_1013 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1014);
									mem_vec_1014 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1015);
									mem_vec_1015 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1016);
									mem_vec_1016 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1017);
									mem_vec_1017 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1018);
									mem_vec_1018 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1019);
									mem_vec_1019 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1020);
									mem_vec_1020 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1021);
									mem_vec_1021 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1022);
									mem_vec_1022 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1023);
									mem_vec_1023 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_996);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_997);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_998);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_999);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1000);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1001);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1002);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1003);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1004);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1005);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1006);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1007);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1008);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1009);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1010);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1011);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1012);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1013);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1014);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1015);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1016);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1017);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1018);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1019);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1020);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1021);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1022);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1023);
					}
				}
			}
		}
	}
}


}