#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (1, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1182_p_0, cp_1, c1182, f, fp_0, x, xp_0, x1576_p_0, x1577_p_0, xp_1, x1576_p_1, xp_2, x1576, x1577, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y788 = 0;
IND_TYPE x1578 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1183 = 0;
IND_TYPE f788 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_16116 ,mem_vec_16117 ,mem_vec_16118 ,mem_vec_16119 ,mem_vec_16120 ,mem_vec_16121 ,mem_vec_16122 ,mem_vec_16123 ,mem_vec_16124 ,mem_vec_16125 ,mem_vec_16126 ,mem_vec_16127 ,mem_vec_16128 ,mem_vec_16129 ,mem_vec_16130 ,mem_vec_16131 ,mem_vec_16132 ,mem_vec_16133 ,mem_vec_16134 ,mem_vec_16135 ,mem_vec_16136 ,mem_vec_16137 ,mem_vec_16138 ,mem_vec_16139 ,mem_vec_16140 ,mem_vec_16141 ,mem_vec_16142 ,mem_vec_16143 ,mem_vec_16144 ,mem_vec_16145 ,mem_vec_16146 ,mem_vec_16147 ,mem_vec_16148 ,mem_vec_16149 ,mem_vec_16150 ,mem_vec_16151 ,mem_vec_16152 ,mem_vec_16153 ,mem_vec_16154 ,mem_vec_16155 ,mem_vec_16156 ,mem_vec_16157 ,mem_vec_16158 ,mem_vec_16159 ,mem_vec_16160 ,mem_vec_16161 ,mem_vec_16162 ,mem_vec_16163 ,mem_vec_16164 ,mem_vec_16165 ,mem_vec_16166 ,mem_vec_16167 ,mem_vec_16168 ,mem_vec_16169 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 34) (68 / 2)
for (x1577 = x1578, x1577_p_0 = 0;
	x1577 < x1578 + 68;
	x1577 += 2, x1577_p_0 += 2){
	// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c1182 = c1183, c1182_p_0 = 0;
		c1182 < c1183 + 256;
		c1182 += 256, c1182_p_0 += 256){
		// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f788, fp_0 = 0;
			f < f788 + 128;
			f += 32, fp_0 += 32){
				for (y = y788, yp_0 = 0;
					y < y788 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
					// T (x, 2) (2 / 1)
					for (x1576 = x1577, x1576_p_1 = x1577_p_0, x1576_p_0 = 0;
						x1576 < x1577 + 2;
						x1576 += 1, x1576_p_1 += 1, x1576_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1576, xp_2 = x1576_p_1, xp_1 = x1576_p_0, xp_0 = 0;
							x < x1576 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_16131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_16132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_16133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_16134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_16135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_16136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_16137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_16138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_16139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_16140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_16141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
										c < c1182 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16116);
										mem_vec_16116 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16117);
										mem_vec_16117 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_16118);
										mem_vec_16118 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_16119);
										mem_vec_16119 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_16120);
										mem_vec_16120 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_16121);
										mem_vec_16121 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_16122);
										mem_vec_16122 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_16123);
										mem_vec_16123 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16124);
										mem_vec_16124 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16125);
										mem_vec_16125 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_16126);
										mem_vec_16126 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_16127);
										mem_vec_16127 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_16128);
										mem_vec_16128 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_16129);
										mem_vec_16129 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_16130);
										mem_vec_16130 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_16131);
										mem_vec_16131 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_16132);
										mem_vec_16132 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_16133);
										mem_vec_16133 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16134);
										mem_vec_16134 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16135);
										mem_vec_16135 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_16136);
										mem_vec_16136 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_16137);
										mem_vec_16137 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_16138);
										mem_vec_16138 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_16139);
										mem_vec_16139 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_16140);
										mem_vec_16140 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_16141);
										mem_vec_16141 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_16130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_16131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_16132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_16133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_16134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_16135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_16136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_16137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_16138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_16139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_16140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_16141);
						}
					}
				}
				for (y = y788 + 26, yp_0 = 0;
					y < y788 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
					// T (x, 2) (2 / 1)
					for (x1576 = x1577, x1576_p_1 = x1577_p_0, x1576_p_0 = 0;
						x1576 < x1577 + 2;
						x1576 += 1, x1576_p_1 += 1, x1576_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1576, xp_2 = x1576_p_1, xp_1 = x1576_p_0, xp_0 = 0;
							x < x1576 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16142 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16143 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_16157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_16158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_16159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_16160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_16161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_16162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_16163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_16164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_16165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_16166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_16167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_16168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_16169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
										c < c1182 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16142);
										mem_vec_16142 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16143);
										mem_vec_16143 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_16144);
										mem_vec_16144 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_16145);
										mem_vec_16145 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_16146);
										mem_vec_16146 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_16147);
										mem_vec_16147 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_16148);
										mem_vec_16148 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_16149);
										mem_vec_16149 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16150);
										mem_vec_16150 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16151);
										mem_vec_16151 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_16152);
										mem_vec_16152 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_16153);
										mem_vec_16153 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_16154);
										mem_vec_16154 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_16155);
										mem_vec_16155 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_16156);
										mem_vec_16156 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_16157);
										mem_vec_16157 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_16158);
										mem_vec_16158 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_16159);
										mem_vec_16159 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16160);
										mem_vec_16160 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16161);
										mem_vec_16161 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_16162);
										mem_vec_16162 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_16163);
										mem_vec_16163 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_16164);
										mem_vec_16164 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_16165);
										mem_vec_16165 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_16166);
										mem_vec_16166 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_16167);
										mem_vec_16167 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_16168);
										mem_vec_16168 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_16169);
										mem_vec_16169 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_16156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_16157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_16158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_16159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_16160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_16161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_16162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_16163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_16164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_16165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_16166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_16167);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_16168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_16169);
						}
					}
				}
		}
	}
}


}