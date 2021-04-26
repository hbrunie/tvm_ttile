#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (32, c); T (1, y); T (16, f); T (1, c); T (4, c)]
*/
IND_TYPE c, cp_0, c175_p_0, c176_p_0, c177_p_0, cp_1, c175_p_1, c176_p_1, cp_2, c175_p_2, cp_3, c175, c176, c177, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y70 = 0;
IND_TYPE x70 = 0;
IND_TYPE h61 = 0;
IND_TYPE w61 = 0;
IND_TYPE c178 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_980 ,mem_vec_981 ,mem_vec_982 ,mem_vec_983 ,mem_vec_984 ,mem_vec_985 ,mem_vec_986 ,mem_vec_987 ,mem_vec_988 ,mem_vec_989 ,mem_vec_990 ,mem_vec_991 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,mem_vec_999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
for (c177 = c178, c177_p_0 = 0;
	c177 < c178 + 1024;
	c177 += 256, c177_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
	// T (c, 1) (256 / 256)
	for (c176 = c177, c176_p_1 = c177_p_0, c176_p_0 = 0;
		c176 < c177 + 256;
		c176 += 256, c176_p_1 += 256, c176_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f70, fp_0 = 0;
			f < f70 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
			// T (y, 1) (7 / 7)
			for (y = y70, yp_0 = 0;
				y < y70 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
				// T (c, 32) (256 / 8)
				for (c175 = c176, c175_p_2 = c176_p_1, c175_p_1 = c176_p_0, c175_p_0 = 0;
					c175 < c176 + 256;
					c175 += 8, c175_p_2 += 8, c175_p_1 += 8, c175_p_0 += 8){
					// y = 7, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (x, 7) (7 / 1)
					for (x = x70, xp_0 = 0;
						x < x70 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h61, hp_0 = 0;
							h < h61 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 8, f = 64
							// T (w, 3) (3 / 1)
							for (w = w61, wp_0 = 0;
								w < w61 + 3;
								w += 1, wp_0 += 1){
										mem_vec_980 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_981 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_982 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_983 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_1000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_1003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_1004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_1007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c175, cp_3 = c175_p_2, cp_2 = c175_p_1, cp_1 = c175_p_0, cp_0 = 0;
											c < c175 + 8;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_980);
											mem_vec_980 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_981);
											mem_vec_981 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_982);
											mem_vec_982 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_983);
											mem_vec_983 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_984);
											mem_vec_984 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_985);
											mem_vec_985 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_986);
											mem_vec_986 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_987);
											mem_vec_987 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_988);
											mem_vec_988 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_989);
											mem_vec_989 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_990);
											mem_vec_990 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_991);
											mem_vec_991 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_992);
											mem_vec_992 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_993);
											mem_vec_993 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_994);
											mem_vec_994 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_995);
											mem_vec_995 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_996);
											mem_vec_996 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_997);
											mem_vec_997 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_998);
											mem_vec_998 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_999);
											mem_vec_999 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1000);
											mem_vec_1000 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1001);
											mem_vec_1001 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1002);
											mem_vec_1002 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1003);
											mem_vec_1003 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1004);
											mem_vec_1004 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1005);
											mem_vec_1005 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1006);
											mem_vec_1006 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1007);
											mem_vec_1007 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_994);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_995);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_996);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_997);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_998);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_999);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1007);
							}
						}
					}
				}
			}
		}
	}
}


}