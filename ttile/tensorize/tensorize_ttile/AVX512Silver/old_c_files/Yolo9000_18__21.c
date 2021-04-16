#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, f);
  T (32, c); T (16, f)]
*/
IND_TYPE c, cp_0, c148_p_0, c149_p_0, cp_1, c148_p_1, cp_2, c148, c149, f, fp_0, f111_p_0, fp_1, f111, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y74 = 0;
IND_TYPE x74 = 0;
IND_TYPE h54 = 0;
IND_TYPE w = 0;
IND_TYPE c150 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f111 = f112, f111_p_0 = 0;
	f111 < f112 + 1024;
	f111 += 64, f111_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 32) (512 / 16)
	for (c149 = c150, c149_p_0 = 0;
		c149 < c150 + 512;
		c149 += 16, c149_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f111, fp_1 = f111_p_0, fp_0 = 0;
			f < f111 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y74, yp_0 = 0;
					y < y74 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 2) (16 / 8)
					for (c148 = c149, c148_p_1 = c149_p_0, c148_p_0 = 0;
						c148 < c149 + 16;
						c148 += 8, c148_p_1 += 8, c148_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x74, xp_0 = 0;
							x < x74 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h54, hp_0 = 0;
								h < h54 + 3;
								h += 1, hp_0 += 1){
										mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c148, cp_2 = c148_p_1, cp_1 = c148_p_0, cp_0 = 0;
											c < c148 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_862);
											mem_vec_862 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_863);
											mem_vec_863 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_864);
											mem_vec_864 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_865);
											mem_vec_865 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_866);
											mem_vec_866 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_867);
											mem_vec_867 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_868);
											mem_vec_868 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_869);
											mem_vec_869 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_862);
											mem_vec_862 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_863);
											mem_vec_863 = vec_17;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_20 = _mm512_set1_ps(scal_5);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_864);
											mem_vec_864 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_865);
											mem_vec_865 = vec_21;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_866);
											mem_vec_866 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_867);
											mem_vec_867 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_868);
											mem_vec_868 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_869);
											mem_vec_869 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_862);
											mem_vec_862 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_863);
											mem_vec_863 = vec_31;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_9);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_864);
											mem_vec_864 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_865);
											mem_vec_865 = vec_35;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_37 = _mm512_set1_ps(scal_10);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_866);
											mem_vec_866 = vec_36;



											vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_867);
											mem_vec_867 = vec_38;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_868);
											mem_vec_868 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_869);
											mem_vec_869 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_869);
							}
						}
					}
				}
				for (y = y74 + 12, yp_0 = 0;
					y < y74 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 2) (16 / 8)
					for (c148 = c149, c148_p_1 = c149_p_0, c148_p_0 = 0;
						c148 < c149 + 16;
						c148 += 8, c148_p_1 += 8, c148_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x74, xp_0 = 0;
							x < x74 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h54, hp_0 = 0;
								h < h54 + 3;
								h += 1, hp_0 += 1){
										mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c148, cp_2 = c148_p_1, cp_1 = c148_p_0, cp_0 = 0;
											c < c148 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_870);
											mem_vec_870 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_871);
											mem_vec_871 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_872);
											mem_vec_872 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_873);
											mem_vec_873 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_874);
											mem_vec_874 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_875);
											mem_vec_875 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_876);
											mem_vec_876 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_877);
											mem_vec_877 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_878);
											mem_vec_878 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_879);
											mem_vec_879 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_870);
											mem_vec_870 = vec_17;

											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_871);
											mem_vec_871 = vec_20;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_872);
											mem_vec_872 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_873);
											mem_vec_873 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_874);
											mem_vec_874 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_875);
											mem_vec_875 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_876);
											mem_vec_876 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_877);
											mem_vec_877 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_878);
											mem_vec_878 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_879);
											mem_vec_879 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_870);
											mem_vec_870 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_871);
											mem_vec_871 = vec_37;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_872);
											mem_vec_872 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_873);
											mem_vec_873 = vec_41;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_43 = _mm512_set1_ps(scal_12);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_874);
											mem_vec_874 = vec_42;



											vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_875);
											mem_vec_875 = vec_44;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_876);
											mem_vec_876 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_877);
											mem_vec_877 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_878);
											mem_vec_878 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_879);
											mem_vec_879 = vec_50;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_879);
							}
						}
					}
				}
		}
	}
}


}