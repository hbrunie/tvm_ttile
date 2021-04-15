#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (2, x); T (136, y); T (16, c); T (2, x); T (17, x)]
*/
IND_TYPE c, cp_0, c240_p_0, cp_1, c240, w, wp_0, x, xp_0, x400_p_0, x401_p_0, x402_p_0, xp_1, x400_p_1, x401_p_1, xp_2, x400_p_2, xp_3, x400, x401, x402, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y160 = 0;
IND_TYPE x403 = 0;
IND_TYPE h = 0;
IND_TYPE w160 = 0;
IND_TYPE c241 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 17) (272 / 16)
for (x402 = x403, x402_p_0 = 0;
	x402 < x403 + 272;
	x402 += 16, x402_p_0 += 16){
	// y = 272, x = 16, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (16 / 8)
	for (x401 = x402, x401_p_1 = x402_p_0, x401_p_0 = 0;
		x401 < x402 + 16;
		x401 += 8, x401_p_1 += 8, x401_p_0 += 8){
		// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
		// T (c, 16) (32 / 2)
		for (c240 = c241, c240_p_0 = 0;
			c240 < c241 + 32;
			c240 += 2, c240_p_0 += 2){
			// y = 272, x = 8, h = 3, w = 3, c = 2, f = 64
			// T (y, 136) (272 / 2)
			for (y = y160, yp_0 = 0;
				y < y160 + 272;
				y += 2, yp_0 += 2){
				// y = 2, x = 8, h = 3, w = 3, c = 2, f = 64
				// T (x, 2) (8 / 4)
				for (x400 = x401, x400_p_2 = x401_p_1, x400_p_1 = x401_p_0, x400_p_0 = 0;
					x400 < x401 + 8;
					x400 += 4, x400_p_2 += 4, x400_p_1 += 4, x400_p_0 += 4){
					// y = 2, x = 4, h = 3, w = 3, c = 2, f = 64
					// T (w, 3) (3 / 1)
					for (w = w160, wp_0 = 0;
						w < w160 + 3;
						w += 1, wp_0 += 1){
						// y = 2, x = 4, h = 3, w = 1, c = 2, f = 64
						// T (x, 4) (4 / 1)
						for (x = x400, xp_3 = x400_p_2, xp_2 = x400_p_1, xp_1 = x400_p_0, xp_0 = 0;
							x < x400 + 4;
							x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = 2, x = 1, h = 3, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c240, cp_1 = c240_p_0, cp_0 = 0;
										c < c240 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_976);
										mem_vec_976 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_977);
										mem_vec_977 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_978);
										mem_vec_978 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_979);
										mem_vec_979 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_980);
										mem_vec_980 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_981);
										mem_vec_981 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_982);
										mem_vec_982 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_983);
										mem_vec_983 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_976);
										mem_vec_976 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_977);
										mem_vec_977 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_978);
										mem_vec_978 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_979);
										mem_vec_979 = vec_21;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_980);
										mem_vec_980 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_981);
										mem_vec_981 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_982);
										mem_vec_982 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_983);
										mem_vec_983 = vec_27;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_976);
										mem_vec_976 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_977);
										mem_vec_977 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_978);
										mem_vec_978 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_979);
										mem_vec_979 = vec_35;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_980);
										mem_vec_980 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_981);
										mem_vec_981 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_982);
										mem_vec_982 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_983);
										mem_vec_983 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_976);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_977);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_978);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_979);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_981);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_982);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_983);
						}
					}
				}
			}
		}
	}
}


}