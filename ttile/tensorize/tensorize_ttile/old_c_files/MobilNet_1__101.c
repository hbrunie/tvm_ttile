#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (2, c);
  T (28, x)]
*/
IND_TYPE c, cp_0, c660_p_0, cp_1, c660, h, hp_0, w, wp_0, x, xp_0, x880_p_0, x881_p_0, xp_1, x880_p_1, xp_2, x880, x881, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y440 = 0;
IND_TYPE x882 = 0;
IND_TYPE h420 = 0;
IND_TYPE w440 = 0;
IND_TYPE c661 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8020 ,mem_vec_8021 ,mem_vec_8022 ,mem_vec_8023 ,mem_vec_8024 ,mem_vec_8025 ,mem_vec_8026 ,mem_vec_8027 ,mem_vec_8028 ,mem_vec_8029 ,mem_vec_8030 ,mem_vec_8031 ,mem_vec_8032 ,mem_vec_8033 ,mem_vec_8034 ,mem_vec_8035 ,mem_vec_8036 ,mem_vec_8037 ,mem_vec_8038 ,mem_vec_8039 ,mem_vec_8040 ,mem_vec_8041 ,mem_vec_8042 ,mem_vec_8043 ,mem_vec_8044 ,mem_vec_8045 ,mem_vec_8046 ,mem_vec_8047 ,mem_vec_8048 ,mem_vec_8049 ,mem_vec_8050 ,mem_vec_8051 ,mem_vec_8052 ,mem_vec_8053 ,mem_vec_8054 ,mem_vec_8055 ,mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,mem_vec_8062 ,mem_vec_8063 ,mem_vec_8064 ,mem_vec_8065 ,mem_vec_8066 ,mem_vec_8067 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 28) (112 / 4)
for (x881 = x882, x881_p_0 = 0;
	x881 < x882 + 112;
	x881 += 4, x881_p_0 += 4){
	// y = 112, x = 4, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c660 = c661, c660_p_0 = 0;
		c660 < c661 + 32;
		c660 += 16, c660_p_0 += 16){
			for (y = y440, yp_0 = 0;
				y < y440 + 99;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (4 / 4)
				for (x880 = x881, x880_p_1 = x881_p_0, x880_p_0 = 0;
					x880 < x881 + 4;
					x880 += 4, x880_p_1 += 4, x880_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h420, hp_0 = 0;
						h < h420 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w440, wp_0 = 0;
							w < w440 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x880, xp_2 = x880_p_1, xp_1 = x880_p_0, xp_0 = 0;
								x < x880 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8020 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8021 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c660, cp_1 = c660_p_0, cp_0 = 0;
											c < c660 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8020);
											mem_vec_8020 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8021);
											mem_vec_8021 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8022);
											mem_vec_8022 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8023);
											mem_vec_8023 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8024);
											mem_vec_8024 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8025);
											mem_vec_8025 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8026);
											mem_vec_8026 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8027);
											mem_vec_8027 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8028);
											mem_vec_8028 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8029);
											mem_vec_8029 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8030);
											mem_vec_8030 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8031);
											mem_vec_8031 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8032);
											mem_vec_8032 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8033);
											mem_vec_8033 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8034);
											mem_vec_8034 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8035);
											mem_vec_8035 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8036);
											mem_vec_8036 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8037);
											mem_vec_8037 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8038);
											mem_vec_8038 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8039);
											mem_vec_8039 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8040);
											mem_vec_8040 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8041);
											mem_vec_8041 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8020);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8021);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8022);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8023);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8024);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8025);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8026);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8027);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8028);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8029);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8030);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8031);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8032);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8033);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8034);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8035);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8036);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8037);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8038);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8039);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8040);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8041);
							}
						}
					}
				}
			}
			for (y = y440 + 99, yp_0 = 0;
				y < y440 + 99 + 13;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (4 / 4)
				for (x880 = x881, x880_p_1 = x881_p_0, x880_p_0 = 0;
					x880 < x881 + 4;
					x880 += 4, x880_p_1 += 4, x880_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h420, hp_0 = 0;
						h < h420 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w440, wp_0 = 0;
							w < w440 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x880, xp_2 = x880_p_1, xp_1 = x880_p_0, xp_0 = 0;
								x < x880 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8042 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8043 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_8066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c660, cp_1 = c660_p_0, cp_0 = 0;
											c < c660 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8042);
											mem_vec_8042 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8043);
											mem_vec_8043 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8044);
											mem_vec_8044 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8045);
											mem_vec_8045 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8046);
											mem_vec_8046 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8047);
											mem_vec_8047 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8048);
											mem_vec_8048 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8049);
											mem_vec_8049 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8050);
											mem_vec_8050 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8051);
											mem_vec_8051 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8052);
											mem_vec_8052 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8053);
											mem_vec_8053 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8054);
											mem_vec_8054 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8055);
											mem_vec_8055 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8056);
											mem_vec_8056 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8057);
											mem_vec_8057 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8058);
											mem_vec_8058 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8059);
											mem_vec_8059 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8060);
											mem_vec_8060 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8061);
											mem_vec_8061 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8062);
											mem_vec_8062 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8063);
											mem_vec_8063 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8064);
											mem_vec_8064 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8065);
											mem_vec_8065 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8066);
											mem_vec_8066 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8067);
											mem_vec_8067 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8042);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8043);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8044);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8045);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8049);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8050);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8051);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8052);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8053);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8054);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8055);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8056);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8057);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8058);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8059);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8060);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8061);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8062);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8063);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8064);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8065);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8066);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8067);
							}
						}
					}
				}
			}
	}
}


}