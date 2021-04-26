#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x69_p_0, xp_1, x69, y, yp_0, y69_p_0, yp_1, y69;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y70 = 0;
IND_TYPE x70 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,mem_vec_988 ,mem_vec_989 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y69 = y70, y69_p_0 = 0;
	y69 < y70 + 136;
	y69 += 68, y69_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x69 = x70, x69_p_0 = 0;
		x69 < x70 + 136;
		x69 += 2, x69_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f46, fp_0 = 0;
			f < f46 + 64;
			f += 32, fp_0 += 32){
				for (y = y69, yp_1 = y69_p_0, yp_0 = 0;
					y < y69 + 54;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x69, xp_1 = x69_p_0, xp_0 = 0;
						x < x69 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c46, cp_0 = 0;
									c < c46 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_944);
									mem_vec_944 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_945);
									mem_vec_945 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_946);
									mem_vec_946 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_947);
									mem_vec_947 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_948);
									mem_vec_948 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_949);
									mem_vec_949 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_950);
									mem_vec_950 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_951);
									mem_vec_951 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_952);
									mem_vec_952 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_953);
									mem_vec_953 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_954);
									mem_vec_954 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_955);
									mem_vec_955 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_956);
									mem_vec_956 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_957);
									mem_vec_957 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_958);
									mem_vec_958 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_959);
									mem_vec_959 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_960);
									mem_vec_960 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_961);
									mem_vec_961 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_944);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_945);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_946);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_947);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_948);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_949);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_950);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_951);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_952);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_953);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_954);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_955);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_956);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_957);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_958);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_959);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_960);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_961);
					}
				}
				for (y = y69 + 54, yp_1 = y69_p_0, yp_0 = 0;
					y < y69 + 54 + 14;
					y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x69, xp_1 = x69_p_0, xp_0 = 0;
						x < x69 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								mem_vec_988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								mem_vec_989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c46, cp_0 = 0;
									c < c46 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_962);
									mem_vec_962 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_963);
									mem_vec_963 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_964);
									mem_vec_964 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_965);
									mem_vec_965 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_966);
									mem_vec_966 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_967);
									mem_vec_967 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_968);
									mem_vec_968 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_969);
									mem_vec_969 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_970);
									mem_vec_970 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_971);
									mem_vec_971 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_972);
									mem_vec_972 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_973);
									mem_vec_973 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_974);
									mem_vec_974 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_975);
									mem_vec_975 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_976);
									mem_vec_976 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_977);
									mem_vec_977 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_978);
									mem_vec_978 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_979);
									mem_vec_979 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_980);
									mem_vec_980 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_981);
									mem_vec_981 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_982);
									mem_vec_982 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_983);
									mem_vec_983 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_984);
									mem_vec_984 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_985);
									mem_vec_985 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_986);
									mem_vec_986 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_987);
									mem_vec_987 = vec_40;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_988);
									mem_vec_988 = vec_41;



									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_989);
									mem_vec_989 = vec_43;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_962);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_963);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_964);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_965);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_966);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_967);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_968);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_969);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_970);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_971);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_972);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_973);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_974);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_975);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_976);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_977);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_978);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_979);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_980);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_981);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_982);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_983);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_984);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_985);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_986);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_987);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_988);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_989);
					}
				}
		}
	}
}


}