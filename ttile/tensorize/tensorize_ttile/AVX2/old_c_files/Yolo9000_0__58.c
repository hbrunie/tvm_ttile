#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (272, x); T (8, y); T (1, y)]
*/
IND_TYPE c, cp_0, c244_p_0, cp_1, c244, h, hp_0, w, wp_0, x, xp_0, x296_p_0, xp_1, x296, y, yp_0, y334_p_0, y335_p_0, yp_1, y334_p_1, yp_2, y334, y335;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y336 = 0;
IND_TYPE x297 = 0;
IND_TYPE h137 = 0;
IND_TYPE w163 = 0;
IND_TYPE c245 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2000 ,mem_vec_2001 ,mem_vec_2002 ,mem_vec_2003 ,mem_vec_2004 ,mem_vec_2005 ,mem_vec_2006 ,mem_vec_2007 ,mem_vec_2008 ,mem_vec_2009 ,mem_vec_2010 ,mem_vec_2011 ,mem_vec_2012 ,mem_vec_2013 ,mem_vec_2014 ,mem_vec_2015 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
for (y335 = y336, y335_p_0 = 0;
	y335 < y336 + 544;
	y335 += 544, y335_p_0 += 544){
	// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 8) (544 / 68)
	for (y334 = y335, y334_p_1 = y335_p_0, y334_p_0 = 0;
		y334 < y335 + 544;
		y334 += 68, y334_p_1 += 68, y334_p_0 += 68){
		// y = 68, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 272) (544 / 2)
		for (x296 = x297, x296_p_0 = 0;
			x296 < x297 + 544;
			x296 += 2, x296_p_0 += 2){
			// y = 68, x = 2, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (68 / 4)
			for (y = y334, yp_2 = y334_p_1, yp_1 = y334_p_0, yp_0 = 0;
				y < y334 + 68;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h137, hp_0 = 0;
					h < h137 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 2, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w163, wp_0 = 0;
						w < w163 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c244 = c245, c244_p_0 = 0;
							c244 < c245 + 3;
							c244 += 3, c244_p_0 += 3){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (x, 2) (2 / 1)
							for (x = x296, xp_1 = x296_p_0, xp_0 = 0;
								x < x296 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2000 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2001 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2002 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2003 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_2004 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2005 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_2006 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2007 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_2008 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2009 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_2010 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2011 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_2012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_2014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c244, cp_1 = c244_p_0, cp_0 = 0;
											c < c244 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2000);
											mem_vec_2000 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2001);
											mem_vec_2001 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2002);
											mem_vec_2002 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2003);
											mem_vec_2003 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2004);
											mem_vec_2004 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2005);
											mem_vec_2005 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2006);
											mem_vec_2006 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2007);
											mem_vec_2007 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2008);
											mem_vec_2008 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2009);
											mem_vec_2009 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2010);
											mem_vec_2010 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2011);
											mem_vec_2011 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2012);
											mem_vec_2012 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2013);
											mem_vec_2013 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2014);
											mem_vec_2014 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2015);
											mem_vec_2015 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2000);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2001);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2002);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2003);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2004);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2005);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2006);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2007);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2008);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2009);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2010);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2011);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2012);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2013);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2014);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2015);
							}
						}
					}
				}
			}
		}
	}
}


}