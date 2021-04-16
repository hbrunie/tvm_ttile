#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (7, w); T (7, h);
  T (112, x); T (1, y); T (1, c); T (28, y)]
*/
IND_TYPE c, cp_0, c126_p_0, cp_1, c126, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y126_p_0, yp_1, y126;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y127 = 0;
IND_TYPE x116 = 0;
IND_TYPE h84 = 0;
IND_TYPE w84 = 0;
IND_TYPE c127 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,mem_vec_1128 ,mem_vec_1129 ,mem_vec_1130 ,mem_vec_1131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (y, 28) (112 / 4)
for (y126 = y127, y126_p_0 = 0;
	y126 < y127 + 112;
	y126 += 4, y126_p_0 += 4){
	// y = 4, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (c, 1) (3 / 3)
	for (c126 = c127, c126_p_0 = 0;
		c126 < c127 + 3;
		c126 += 3, c126_p_0 += 3){
		// y = 4, x = 112, h = 7, w = 7, c = 3, f = 64
		// T (y, 1) (4 / 4)
		for (y = y126, yp_1 = y126_p_0, yp_0 = 0;
			y < y126 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 112, h = 7, w = 7, c = 3, f = 64
			// T (x, 112) (112 / 1)
			for (x = x116, xp_0 = 0;
				x < x116 + 112;
				x += 1, xp_0 += 1){
				// y = 4, x = 1, h = 7, w = 7, c = 3, f = 64
				// T (h, 7) (7 / 1)
				for (h = h84, hp_0 = 0;
					h < h84 + 7;
					h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 7, c = 3, f = 64
					// T (w, 7) (7 / 1)
					for (w = w84, wp_0 = 0;
						w < w84 + 7;
						w += 1, wp_0 += 1){
								mem_vec_1116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_1119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_1120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_1123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_1124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_1127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_1128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_1131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 3, f = 64
								// T (c, 3) (3 / 1)
								for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
									c < c126 + 3;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1116);
									mem_vec_1116 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1117);
									mem_vec_1117 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1118);
									mem_vec_1118 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1119);
									mem_vec_1119 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1120);
									mem_vec_1120 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1121);
									mem_vec_1121 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1122);
									mem_vec_1122 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1123);
									mem_vec_1123 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1124);
									mem_vec_1124 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1125);
									mem_vec_1125 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1126);
									mem_vec_1126 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1127);
									mem_vec_1127 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1128);
									mem_vec_1128 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1129);
									mem_vec_1129 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1130);
									mem_vec_1130 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1131);
									mem_vec_1131 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1116);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1117);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1118);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1119);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1120);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1121);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1122);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1123);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1124);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1125);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1126);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1127);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1128);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1129);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1130);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1131);
					}
				}
			}
		}
	}
}


}