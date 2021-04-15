#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (128, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c888_p_0, c889_p_0, cp_1, c888_p_1, cp_2, c888, c889, f, fp_0, x, xp_0, x666_p_0, xp_1, x666, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y444 = 0;
IND_TYPE x667 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c890 = 0;
IND_TYPE f444 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7112 ,mem_vec_7113 ,mem_vec_7114 ,mem_vec_7115 ,mem_vec_7116 ,mem_vec_7117 ,mem_vec_7118 ,mem_vec_7119 ,mem_vec_7120 ,mem_vec_7121 ,mem_vec_7122 ,mem_vec_7123 ,mem_vec_7124 ,mem_vec_7125 ,mem_vec_7126 ,mem_vec_7127 ,mem_vec_7128 ,mem_vec_7129 ,mem_vec_7130 ,mem_vec_7131 ,mem_vec_7132 ,mem_vec_7133 ,mem_vec_7134 ,mem_vec_7135 ,mem_vec_7136 ,mem_vec_7137 ,mem_vec_7138 ,mem_vec_7139 ,mem_vec_7140 ,mem_vec_7141 ,mem_vec_7142 ,mem_vec_7143 ,mem_vec_7144 ,mem_vec_7145 ,mem_vec_7146 ,mem_vec_7147 ,mem_vec_7148 ,mem_vec_7149 ,mem_vec_7150 ,mem_vec_7151 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 2) (1024 / 512)
for (c889 = c890, c889_p_0 = 0;
	c889 < c890 + 1024;
	c889 += 512, c889_p_0 += 512){
		for (y = y444, yp_0 = 0;
			y < y444 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 1) (17 / 17)
			for (x666 = x667, x666_p_0 = 0;
				x666 < x667 + 17;
				x666 += 17, x666_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f444, fp_0 = 0;
					f < f444 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 128) (512 / 4)
					for (c888 = c889, c888_p_1 = c889_p_0, c888_p_0 = 0;
						c888 < c889 + 512;
						c888 += 4, c888_p_1 += 4, c888_p_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 64
						// T (x, 17) (17 / 1)
						for (x = x666, xp_1 = x666_p_0, xp_0 = 0;
							x < x666 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7114 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7115 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c888, cp_2 = c888_p_1, cp_1 = c888_p_0, cp_0 = 0;
										c < c888 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7112);
										mem_vec_7112 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7113);
										mem_vec_7113 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7114);
										mem_vec_7114 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7115);
										mem_vec_7115 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7116);
										mem_vec_7116 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7117);
										mem_vec_7117 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7118);
										mem_vec_7118 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7119);
										mem_vec_7119 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7120);
										mem_vec_7120 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7121);
										mem_vec_7121 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7122);
										mem_vec_7122 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7123);
										mem_vec_7123 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7123);
						}
					}
				}
			}
		}
		for (y = y444 + 3, yp_0 = 0;
			y < y444 + 3 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 1) (17 / 17)
			for (x666 = x667, x666_p_0 = 0;
				x666 < x667 + 17;
				x666 += 17, x666_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f444, fp_0 = 0;
					f < f444 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 128) (512 / 4)
					for (c888 = c889, c888_p_1 = c889_p_0, c888_p_0 = 0;
						c888 < c889 + 512;
						c888 += 4, c888_p_1 += 4, c888_p_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 64
						// T (x, 17) (17 / 1)
						for (x = x666, xp_1 = x666_p_0, xp_0 = 0;
							x < x666 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7124 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7125 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7126 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7127 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_7139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_7140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_7143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_7144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_7147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_7148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_7151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c888, cp_2 = c888_p_1, cp_1 = c888_p_0, cp_0 = 0;
										c < c888 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7124);
										mem_vec_7124 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7125);
										mem_vec_7125 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7126);
										mem_vec_7126 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7127);
										mem_vec_7127 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7128);
										mem_vec_7128 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7129);
										mem_vec_7129 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7130);
										mem_vec_7130 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7131);
										mem_vec_7131 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7132);
										mem_vec_7132 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7133);
										mem_vec_7133 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7134);
										mem_vec_7134 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7135);
										mem_vec_7135 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7136);
										mem_vec_7136 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7137);
										mem_vec_7137 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7138);
										mem_vec_7138 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7139);
										mem_vec_7139 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7140);
										mem_vec_7140 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7141);
										mem_vec_7141 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7142);
										mem_vec_7142 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7143);
										mem_vec_7143 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7144);
										mem_vec_7144 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7145);
										mem_vec_7145 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7146);
										mem_vec_7146 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7147);
										mem_vec_7147 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7148);
										mem_vec_7148 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7149);
										mem_vec_7149 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7150);
										mem_vec_7150 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7151);
										mem_vec_7151 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7151);
						}
					}
				}
			}
		}
}


}