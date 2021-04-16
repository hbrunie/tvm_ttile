#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (256, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, x, xp_0, x81_p_0, xp_1, x81, y, yp_0, y81_p_0, yp_1, y81;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y82 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c82 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,mem_vec_988 ,mem_vec_989 ,mem_vec_990 ,mem_vec_991 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,mem_vec_999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y81 = y82, y81_p_0 = 0;
	y81 < y82 + 17;
	y81 += 17, y81_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x81 = x82, x81_p_0 = 0;
		x81 < x82 + 17;
		x81 += 17, x81_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 256) (1024 / 4)
		for (c81 = c82, c81_p_0 = 0;
			c81 < c82 + 1024;
			c81 += 4, c81_p_0 += 4){
			// y = 17, x = 17, h = 1, w = 1, c = 4, f = 512
			// T (f, 16) (512 / 32)
			for (f = f54, fp_0 = 0;
				f < f54 + 512;
				f += 32, fp_0 += 32){
					for (y = y81, yp_1 = y81_p_0, yp_0 = 0;
						y < y81 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x81, xp_1 = x81_p_0, xp_0 = 0;
							x < x81 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_972 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_973 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_974 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_975 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
										c < c81 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_972);
										mem_vec_972 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_973);
										mem_vec_973 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_974);
										mem_vec_974 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_975);
										mem_vec_975 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_976);
										mem_vec_976 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_977);
										mem_vec_977 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_978);
										mem_vec_978 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_979);
										mem_vec_979 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_980);
										mem_vec_980 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_981);
										mem_vec_981 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_982);
										mem_vec_982 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_983);
										mem_vec_983 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_984);
										mem_vec_984 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_985);
										mem_vec_985 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_986);
										mem_vec_986 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_987);
										mem_vec_987 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_972);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_973);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_974);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_975);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_976);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_977);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_978);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_979);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_980);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_981);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_982);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_983);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_984);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_985);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_986);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_987);
						}
					}
					for (y = y81 + 12, yp_1 = y81_p_0, yp_0 = 0;
						y < y81 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x81, xp_1 = x81_p_0, xp_0 = 0;
							x < x81 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_988 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_989 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_990 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_991 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1000 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1001 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1002 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1003 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1004 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1005 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1006 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1007 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
										c < c81 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_988);
										mem_vec_988 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_989);
										mem_vec_989 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_990);
										mem_vec_990 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_991);
										mem_vec_991 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_992);
										mem_vec_992 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_993);
										mem_vec_993 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_994);
										mem_vec_994 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_995);
										mem_vec_995 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_996);
										mem_vec_996 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_997);
										mem_vec_997 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_998);
										mem_vec_998 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_999);
										mem_vec_999 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1000);
										mem_vec_1000 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1001);
										mem_vec_1001 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1002);
										mem_vec_1002 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1003);
										mem_vec_1003 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1004);
										mem_vec_1004 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1005);
										mem_vec_1005 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1006);
										mem_vec_1006 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1007);
										mem_vec_1007 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_988);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_989);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_990);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_991);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_992);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_993);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_994);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_995);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_996);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_997);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_998);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_999);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1000);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1001);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1002);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1003);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1004);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1005);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1006);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1007);
						}
					}
			}
		}
	}
}


}