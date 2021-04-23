#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (1, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0, y54_p_0, yp_1, y54;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y55 = 0;
IND_TYPE x74 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c55 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
for (y54 = y55, y54_p_0 = 0;
	y54 < y55 + 68;
	y54 += 34, y54_p_0 += 34){
	// y = 34, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 4) (68 / 17)
	for (x73 = x74, x73_p_0 = 0;
		x73 < x74 + 68;
		x73 += 17, x73_p_0 += 17){
			for (y = y54, yp_1 = y54_p_0, yp_0 = 0;
				y < y54 + 6;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
					x72 < x73 + 17;
					x72 += 17, x72_p_1 += 17, x72_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f36, fp_0 = 0;
						f < f36 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c54 = c55, c54_p_0 = 0;
							c54 < c55 + 256;
							c54 += 256, c54_p_0 += 256){
							// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
							// T (x, 17) (17 / 1)
							for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
								x < x72 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
											c < c54 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_936);
											mem_vec_936 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_937);
											mem_vec_937 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_938);
											mem_vec_938 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_939);
											mem_vec_939 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_940);
											mem_vec_940 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_941);
											mem_vec_941 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_942);
											mem_vec_942 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_943);
											mem_vec_943 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_944);
											mem_vec_944 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_945);
											mem_vec_945 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_946);
											mem_vec_946 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_947);
											mem_vec_947 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_948);
											mem_vec_948 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_949);
											mem_vec_949 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_950);
											mem_vec_950 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_951);
											mem_vec_951 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_952);
											mem_vec_952 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_953);
											mem_vec_953 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_954);
											mem_vec_954 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_955);
											mem_vec_955 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_956);
											mem_vec_956 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_957);
											mem_vec_957 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_958);
											mem_vec_958 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_959);
											mem_vec_959 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_939);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_945);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_946);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_947);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_948);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_949);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_951);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_952);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_953);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_954);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_955);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_956);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_957);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_959);
							}
						}
					}
				}
			}
			for (y = y54 + 6, yp_1 = y54_p_0, yp_0 = 0;
				y < y54 + 6 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
					x72 < x73 + 17;
					x72 += 17, x72_p_1 += 17, x72_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f36, fp_0 = 0;
						f < f36 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c54 = c55, c54_p_0 = 0;
							c54 < c55 + 256;
							c54 += 256, c54_p_0 += 256){
							// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
							// T (x, 17) (17 / 1)
							for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
								x < x72 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
											c < c54 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_960);
											mem_vec_960 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_961);
											mem_vec_961 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_962);
											mem_vec_962 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_963);
											mem_vec_963 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_964);
											mem_vec_964 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_965);
											mem_vec_965 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_966);
											mem_vec_966 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_967);
											mem_vec_967 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_968);
											mem_vec_968 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_969);
											mem_vec_969 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_970);
											mem_vec_970 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_971);
											mem_vec_971 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_972);
											mem_vec_972 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_973);
											mem_vec_973 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_974);
											mem_vec_974 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_975);
											mem_vec_975 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_976);
											mem_vec_976 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_977);
											mem_vec_977 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_978);
											mem_vec_978 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_979);
											mem_vec_979 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_980);
											mem_vec_980 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_981);
											mem_vec_981 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_982);
											mem_vec_982 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_983);
											mem_vec_983 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_984);
											mem_vec_984 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_985);
											mem_vec_985 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_986);
											mem_vec_986 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_987);
											mem_vec_987 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_987);
							}
						}
					}
				}
			}
	}
}


}