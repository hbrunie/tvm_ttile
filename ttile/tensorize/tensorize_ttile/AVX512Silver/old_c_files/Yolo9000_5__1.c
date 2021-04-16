#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (8, y);
  T (1, c); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c56_p_0, cp_1, c56, x, xp_0, x75_p_0, xp_1, x75, y, yp_0, y75_p_0, yp_1, y75;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y76 = 0;
IND_TYPE x76 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c57 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y75 = y76, y75_p_0 = 0;
		y75 < y76 + 96;
		y75 += 32, y75_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x75 = x76, x75_p_0 = 0;
			x75 < x76 + 136;
			x75 += 1, x75_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c56 = c57, c56_p_0 = 0;
				c56 < c57 + 128;
				c56 += 128, c56_p_0 += 128){
				// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y75, yp_1 = y75_p_0, yp_0 = 0;
					y < y75 + 32;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x75, xp_1 = x75_p_0, xp_0 = 0;
						x < x75 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c56, cp_1 = c56_p_0, cp_0 = 0;
									c < c56 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_928);
									mem_vec_928 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_929);
									mem_vec_929 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_930);
									mem_vec_930 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_931);
									mem_vec_931 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_932);
									mem_vec_932 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_933);
									mem_vec_933 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_934);
									mem_vec_934 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_935);
									mem_vec_935 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_936);
									mem_vec_936 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_937);
									mem_vec_937 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_938);
									mem_vec_938 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_939);
									mem_vec_939 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_940);
									mem_vec_940 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_941);
									mem_vec_941 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_942);
									mem_vec_942 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_943);
									mem_vec_943 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_928);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_929);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_930);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_931);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_932);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_933);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_934);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_935);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_936);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_937);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_938);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_939);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_940);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_941);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_942);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_943);
					}
				}
			}
		}
	}
	for (y75 = y76 + 96, y75_p_0 = 0;
		y75 < y76 + 96 + 40;
		y75 += 40, y75_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x75 = x76, x75_p_0 = 0;
			x75 < x76 + 136;
			x75 += 1, x75_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c56 = c57, c56_p_0 = 0;
				c56 < c57 + 128;
				c56 += 128, c56_p_0 += 128){
				// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y75, yp_1 = y75_p_0, yp_0 = 0;
					y < y75 + 40;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x75, xp_1 = x75_p_0, xp_0 = 0;
						x < x75 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c56, cp_1 = c56_p_0, cp_0 = 0;
									c < c56 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_944);
									mem_vec_944 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_945);
									mem_vec_945 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_946);
									mem_vec_946 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_947);
									mem_vec_947 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_948);
									mem_vec_948 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_949);
									mem_vec_949 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_950);
									mem_vec_950 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_951);
									mem_vec_951 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_952);
									mem_vec_952 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_953);
									mem_vec_953 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_954);
									mem_vec_954 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_955);
									mem_vec_955 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_956);
									mem_vec_956 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_957);
									mem_vec_957 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_958);
									mem_vec_958 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_959);
									mem_vec_959 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_960);
									mem_vec_960 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_961);
									mem_vec_961 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_962);
									mem_vec_962 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_963);
									mem_vec_963 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_944);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_945);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_946);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_947);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_948);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_949);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_950);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_951);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_952);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_953);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_954);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_955);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_956);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_957);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_958);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_959);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_960);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_961);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_962);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_963);
					}
				}
			}
		}
	}


}