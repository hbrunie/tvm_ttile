#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (4, f);
  T (1, c); T (4, x)]
*/
IND_TYPE c, cp_0, c1062_p_0, cp_1, c1062, f, fp_0, x, xp_0, x1416_p_0, x1417_p_0, xp_1, x1416_p_1, xp_2, x1416, x1417, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y708 = 0;
IND_TYPE x1418 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1063 = 0;
IND_TYPE f708 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13976 ,mem_vec_13977 ,mem_vec_13978 ,mem_vec_13979 ,mem_vec_13980 ,mem_vec_13981 ,mem_vec_13982 ,mem_vec_13983 ,mem_vec_13984 ,mem_vec_13985 ,mem_vec_13986 ,mem_vec_13987 ,mem_vec_13988 ,mem_vec_13989 ,mem_vec_13990 ,mem_vec_13991 ,mem_vec_13992 ,mem_vec_13993 ,mem_vec_13994 ,mem_vec_13995 ,mem_vec_13996 ,mem_vec_13997 ,mem_vec_13998 ,mem_vec_13999 ,mem_vec_14000 ,mem_vec_14001 ,mem_vec_14002 ,mem_vec_14003 ,mem_vec_14004 ,mem_vec_14005 ,mem_vec_14006 ,mem_vec_14007 ,mem_vec_14008 ,mem_vec_14009 ,mem_vec_14010 ,mem_vec_14011 ,mem_vec_14012 ,mem_vec_14013 ,mem_vec_14014 ,mem_vec_14015 ,mem_vec_14016 ,mem_vec_14017 ,mem_vec_14018 ,mem_vec_14019 ,mem_vec_14020 ,mem_vec_14021 ,mem_vec_14022 ,mem_vec_14023 ,mem_vec_14024 ,mem_vec_14025 ,mem_vec_14026 ,mem_vec_14027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 4) (68 / 17)
for (x1417 = x1418, x1417_p_0 = 0;
	x1417 < x1418 + 68;
	x1417 += 17, x1417_p_0 += 17){
	// y = 68, x = 17, h = 1, w = 1, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c1062 = c1063, c1062_p_0 = 0;
		c1062 < c1063 + 256;
		c1062 += 256, c1062_p_0 += 256){
		// y = 68, x = 17, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f708, fp_0 = 0;
			f < f708 + 128;
			f += 32, fp_0 += 32){
				for (y = y708, yp_0 = 0;
					y < y708 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
						x1416 < x1417 + 17;
						x1416 += 1, x1416_p_1 += 1, x1416_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
							x < x1416 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13976 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13977 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_13991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_13992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_13993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_13994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_13995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_13996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_13997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_13998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_13999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;
										c < c1062 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13976);
										mem_vec_13976 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13977);
										mem_vec_13977 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13978);
										mem_vec_13978 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13979);
										mem_vec_13979 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13980);
										mem_vec_13980 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13981);
										mem_vec_13981 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13982);
										mem_vec_13982 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13983);
										mem_vec_13983 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13984);
										mem_vec_13984 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13985);
										mem_vec_13985 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13986);
										mem_vec_13986 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13987);
										mem_vec_13987 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13988);
										mem_vec_13988 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13989);
										mem_vec_13989 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13990);
										mem_vec_13990 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13991);
										mem_vec_13991 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13992);
										mem_vec_13992 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13993);
										mem_vec_13993 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13994);
										mem_vec_13994 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13995);
										mem_vec_13995 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13996);
										mem_vec_13996 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13997);
										mem_vec_13997 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13998);
										mem_vec_13998 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13999);
										mem_vec_13999 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13976);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13977);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13978);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13979);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13981);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13982);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13983);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13984);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13985);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13986);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13987);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13988);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13989);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13990);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13991);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13992);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13993);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13994);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13995);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13996);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13997);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13998);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13999);
						}
					}
				}
				for (y = y708 + 12, yp_0 = 0;
					y < y708 + 12 + 56;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
						x1416 < x1417 + 17;
						x1416 += 1, x1416_p_1 += 1, x1416_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
							x < x1416 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14000 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14001 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_14026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_14027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;
										c < c1062 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14000);
										mem_vec_14000 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14001);
										mem_vec_14001 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14002);
										mem_vec_14002 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14003);
										mem_vec_14003 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14004);
										mem_vec_14004 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14005);
										mem_vec_14005 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14006);
										mem_vec_14006 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14007);
										mem_vec_14007 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14008);
										mem_vec_14008 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14009);
										mem_vec_14009 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14010);
										mem_vec_14010 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14011);
										mem_vec_14011 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14012);
										mem_vec_14012 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14013);
										mem_vec_14013 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14014);
										mem_vec_14014 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14015);
										mem_vec_14015 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14016);
										mem_vec_14016 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14017);
										mem_vec_14017 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14018);
										mem_vec_14018 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14019);
										mem_vec_14019 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14020);
										mem_vec_14020 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14021);
										mem_vec_14021 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14022);
										mem_vec_14022 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14023);
										mem_vec_14023 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14024);
										mem_vec_14024 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14025);
										mem_vec_14025 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_14026);
										mem_vec_14026 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_14027);
										mem_vec_14027 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14000);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14001);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14002);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14003);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14004);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14005);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14006);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14007);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14008);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14009);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14010);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14011);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14012);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14013);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14014);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14015);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14016);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14017);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14018);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14019);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14020);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14021);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14022);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14023);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14024);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14025);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_14026);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_14027);
						}
					}
				}
		}
	}
}


}