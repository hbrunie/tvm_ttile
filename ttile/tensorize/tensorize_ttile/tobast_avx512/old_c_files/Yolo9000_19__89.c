#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1088_p_0, c1089_p_0, cp_1, c1088_p_1, cp_2, c1088, c1089, f, fp_0, x, xp_0, x816_p_0, xp_1, x816, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y544 = 0;
IND_TYPE x817 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1090 = 0;
IND_TYPE f544 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9096 ,mem_vec_9097 ,mem_vec_9098 ,mem_vec_9099 ,mem_vec_9100 ,mem_vec_9101 ,mem_vec_9102 ,mem_vec_9103 ,mem_vec_9104 ,mem_vec_9105 ,mem_vec_9106 ,mem_vec_9107 ,mem_vec_9108 ,mem_vec_9109 ,mem_vec_9110 ,mem_vec_9111 ,mem_vec_9112 ,mem_vec_9113 ,mem_vec_9114 ,mem_vec_9115 ,mem_vec_9116 ,mem_vec_9117 ,mem_vec_9118 ,mem_vec_9119 ,mem_vec_9120 ,mem_vec_9121 ,mem_vec_9122 ,mem_vec_9123 ,mem_vec_9124 ,mem_vec_9125 ,mem_vec_9126 ,mem_vec_9127 ,mem_vec_9128 ,mem_vec_9129 ,mem_vec_9130 ,mem_vec_9131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c1089 = c1090, c1089_p_0 = 0;
	c1089 < c1090 + 1024;
	c1089 += 128, c1089_p_0 += 128){
		for (y = y544, yp_0 = 0;
			y < y544 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 17;
				x816 += 17, x816_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f544, fp_0 = 0;
					f < f544 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
						c1088 < c1089 + 128;
						c1088 += 16, c1088_p_1 += 16, c1088_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
							x < x816 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9096 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9097 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9098 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9099 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9096);
										mem_vec_9096 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9097);
										mem_vec_9097 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9098);
										mem_vec_9098 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9099);
										mem_vec_9099 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9100);
										mem_vec_9100 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9101);
										mem_vec_9101 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9102);
										mem_vec_9102 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9103);
										mem_vec_9103 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9104);
										mem_vec_9104 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9105);
										mem_vec_9105 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9106);
										mem_vec_9106 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9107);
										mem_vec_9107 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9108);
										mem_vec_9108 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9109);
										mem_vec_9109 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9110);
										mem_vec_9110 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9111);
										mem_vec_9111 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9096);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9097);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9098);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9099);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9111);
						}
					}
				}
			}
		}
		for (y = y544 + 12, yp_0 = 0;
			y < y544 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 17;
				x816 += 17, x816_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f544, fp_0 = 0;
					f < f544 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
						c1088 < c1089 + 128;
						c1088 += 16, c1088_p_1 += 16, c1088_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
							x < x816 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9114 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9115 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_9128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_9131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9112);
										mem_vec_9112 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9113);
										mem_vec_9113 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9114);
										mem_vec_9114 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9115);
										mem_vec_9115 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9116);
										mem_vec_9116 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9117);
										mem_vec_9117 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9118);
										mem_vec_9118 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9119);
										mem_vec_9119 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9120);
										mem_vec_9120 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9121);
										mem_vec_9121 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9122);
										mem_vec_9122 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9123);
										mem_vec_9123 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9124);
										mem_vec_9124 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9125);
										mem_vec_9125 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9126);
										mem_vec_9126 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9127);
										mem_vec_9127 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9128);
										mem_vec_9128 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9129);
										mem_vec_9129 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9130);
										mem_vec_9130 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9131);
										mem_vec_9131 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9131);
						}
					}
				}
			}
		}
}


}