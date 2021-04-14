#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (1, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (32, c); T (7, x); T (8, y); T (2, c)]
*/
IND_TYPE c, cp_0, c136_p_0, c137_p_0, cp_1, c136_p_1, cp_2, c136, c137, h, hp_0, w, wp_0, x, xp_0, x158_p_0, xp_1, x158, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y84 = 0;
IND_TYPE x159 = 0;
IND_TYPE h84 = 0;
IND_TYPE w84 = 0;
IND_TYPE c138 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c137 = c138, c137_p_0 = 0;
	c137 < c138 + 64;
	c137 += 32, c137_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 32, f = 64
	// T (y, 8) (56 / 7)
	for (y = y84, yp_0 = 0;
		y < y84 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 32, f = 64
		// T (x, 7) (56 / 8)
		for (x158 = x159, x158_p_0 = 0;
			x158 < x159 + 56;
			x158 += 8, x158_p_0 += 8){
			// y = 7, x = 8, h = 3, w = 3, c = 32, f = 64
			// T (c, 32) (32 / 1)
			for (c136 = c137, c136_p_1 = c137_p_0, c136_p_0 = 0;
				c136 < c137 + 32;
				c136 += 1, c136_p_1 += 1, c136_p_0 += 1){
				// y = 7, x = 8, h = 3, w = 3, c = 1, f = 64
				// T (h, 3) (3 / 1)
				for (h = h84, hp_0 = 0;
					h < h84 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 8, h = 1, w = 3, c = 1, f = 64
					// T (w, 3) (3 / 1)
					for (w = w84, wp_0 = 0;
						w < w84 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 8, h = 1, w = 1, c = 1, f = 64
						// T (x, 8) (8 / 1)
						for (x = x158, xp_1 = x158_p_0, xp_0 = 0;
							x < x158 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
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
									// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c136, cp_2 = c136_p_1, cp_1 = c136_p_0, cp_0 = 0;
										c < c136 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
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