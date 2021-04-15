#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 6), (Arg 7)); ((Iter 7), (Arg 10))]; T (16, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c192_p_0, cp_1, c192, h, hp_0, w, wp_0, x, xp_0, x256_p_0, x257_p_0, xp_1, x256_p_1, xp_2, x256, x257, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y128 = 0;
IND_TYPE x258 = 0;
IND_TYPE h84 = 0;
IND_TYPE w94 = 0;
IND_TYPE c193 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
for (x257 = x258, x257_p_0 = 0;
	x257 < x258 + 112;
	x257 += 28, x257_p_0 += 28){
	// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c192 = c193, c192_p_0 = 0;
		c192 < c193 + 32;
		c192 += 2, c192_p_0 += 2){
			for (y = y128, yp_0 = 0;
				y < y128 + 42;
				y += 7, yp_0 += 7){
				// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
				// T (x, 28) (28 / 1)
				for (x256 = x257, x256_p_1 = x257_p_0, x256_p_0 = 0;
					x256 < x257 + 28;
					x256 += 1, x256_p_1 += 1, x256_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h84, hp_0 = 0;
						h < h84 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w94, wp_0 = 0;
							w < w94 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (x, 1) (1 / 1)
							for (x = x256, xp_2 = x256_p_1, xp_1 = x256_p_0, xp_0 = 0;
								x < x256 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
											c < c192 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_918);
											mem_vec_918 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_919);
											mem_vec_919 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_920);
											mem_vec_920 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_921);
											mem_vec_921 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_922);
											mem_vec_922 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_923);
											mem_vec_923 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_924);
											mem_vec_924 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_925);
											mem_vec_925 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_926);
											mem_vec_926 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_927);
											mem_vec_927 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_928);
											mem_vec_928 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_929);
											mem_vec_929 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_930);
											mem_vec_930 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_931);
											mem_vec_931 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_918);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_919);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_920);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_921);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_931);
							}
						}
					}
				}
			}
			for (y = y128 + 42, yp_0 = 0;
				y < y128 + 42 + 70;
				y += 10, yp_0 += 10){
				// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
				// T (x, 28) (28 / 1)
				for (x256 = x257, x256_p_1 = x257_p_0, x256_p_0 = 0;
					x256 < x257 + 28;
					x256 += 1, x256_p_1 += 1, x256_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h84, hp_0 = 0;
						h < h84 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w94, wp_0 = 0;
							w < w94 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (x, 1) (1 / 1)
							for (x = x256, xp_2 = x256_p_1, xp_1 = x256_p_0, xp_0 = 0;
								x < x256 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
											c < c192 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_932);
											mem_vec_932 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_933);
											mem_vec_933 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_934);
											mem_vec_934 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_935);
											mem_vec_935 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_936);
											mem_vec_936 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_937);
											mem_vec_937 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_938);
											mem_vec_938 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_939);
											mem_vec_939 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_940);
											mem_vec_940 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_941);
											mem_vec_941 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_942);
											mem_vec_942 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_943);
											mem_vec_943 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_944);
											mem_vec_944 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_945);
											mem_vec_945 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_946);
											mem_vec_946 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_947);
											mem_vec_947 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_948);
											mem_vec_948 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_949);
											mem_vec_949 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_950);
											mem_vec_950 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_951);
											mem_vec_951 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_934);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_935);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_939);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_945);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_946);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_947);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_948);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_949);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_951);
							}
						}
					}
				}
			}
	}
}


}