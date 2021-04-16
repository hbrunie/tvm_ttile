#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 7), (Arg 15))];
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c201_p_0, cp_1, c201, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y162_p_0, yp_1, y162;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y163 = 0;
IND_TYPE x212 = 0;
IND_TYPE h118 = 0;
IND_TYPE w83 = 0;
IND_TYPE c202 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 1) (112 / 112)
for (y162 = y163, y162_p_0 = 0;
	y162 < y163 + 112;
	y162 += 112, y162_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c201 = c202, c201_p_0 = 0;
		c201 < c202 + 32;
		c201 += 32, c201_p_0 += 32){
			for (y = y162, yp_1 = y162_p_0, yp_0 = 0;
				y < y162 + 7;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x212, xp_0 = 0;
					x < x212 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h118, hp_0 = 0;
						h < h118 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w83, wp_0 = 0;
							w < w83 + 3;
							w += 1, wp_0 += 1){
									mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c201, cp_1 = c201_p_0, cp_0 = 0;
										c < c201 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_943);
										mem_vec_943 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_944);
										mem_vec_944 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_945);
										mem_vec_945 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_946);
										mem_vec_946 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_947);
										mem_vec_947 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_948);
										mem_vec_948 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_949);
										mem_vec_949 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_950);
										mem_vec_950 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_951);
										mem_vec_951 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_952);
										mem_vec_952 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_953);
										mem_vec_953 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_954);
										mem_vec_954 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_955);
										mem_vec_955 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_956);
										mem_vec_956 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_945);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_953);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_956);
						}
					}
				}
			}
			for (y = y162 + 7, yp_1 = y162_p_0, yp_0 = 0;
				y < y162 + 7 + 105;
				y += 15, yp_1 += 15, yp_0 += 15){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x212, xp_0 = 0;
					x < x212 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h118, hp_0 = 0;
						h < h118 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w83, wp_0 = 0;
							w < w83 + 3;
							w += 1, wp_0 += 1){
									mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c201, cp_1 = c201_p_0, cp_0 = 0;
										c < c201 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_957);
										mem_vec_957 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_958);
										mem_vec_958 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_959);
										mem_vec_959 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_960);
										mem_vec_960 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_961);
										mem_vec_961 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_962);
										mem_vec_962 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_963);
										mem_vec_963 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_964);
										mem_vec_964 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_965);
										mem_vec_965 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_966);
										mem_vec_966 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_967);
										mem_vec_967 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_968);
										mem_vec_968 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_969);
										mem_vec_969 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_970);
										mem_vec_970 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_971);
										mem_vec_971 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_972);
										mem_vec_972 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_973);
										mem_vec_973 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_974);
										mem_vec_974 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_975);
										mem_vec_975 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_976);
										mem_vec_976 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_977);
										mem_vec_977 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_978);
										mem_vec_978 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_979);
										mem_vec_979 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_980);
										mem_vec_980 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_981);
										mem_vec_981 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_982);
										mem_vec_982 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_983);
										mem_vec_983 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_984);
										mem_vec_984 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_985);
										mem_vec_985 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_986);
										mem_vec_986 = vec_46;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_958);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_959);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_960);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_961);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_962);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_963);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_964);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_965);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_966);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_967);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_968);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_969);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_970);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_971);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_972);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_973);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_974);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_975);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_976);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_977);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_978);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_979);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_981);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_982);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_983);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_984);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_985);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_986);
						}
					}
				}
			}
	}
}


}