#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (16, c); T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c117_p_0, cp_1, c117, f, fp_0, f156_p_0, f157_p_0, fp_1, f156_p_1, fp_2, f156, f157, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y78 = 0;
IND_TYPE x78 = 0;
IND_TYPE h57 = 0;
IND_TYPE w = 0;
IND_TYPE c118 = 0;
IND_TYPE f158 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1552 ,mem_vec_1553 ,mem_vec_1554 ,mem_vec_1555 ,mem_vec_1556 ,mem_vec_1557 ,mem_vec_1558 ,mem_vec_1559 ,mem_vec_1560 ,mem_vec_1561 ,mem_vec_1562 ,mem_vec_1563 ,mem_vec_1564 ,mem_vec_1565 ,mem_vec_1566 ,mem_vec_1567 ,mem_vec_1568 ,mem_vec_1569 ,mem_vec_1570 ,mem_vec_1571 ,mem_vec_1572 ,mem_vec_1573 ,mem_vec_1574 ,mem_vec_1575 ,mem_vec_1576 ,mem_vec_1577 ,mem_vec_1578 ,mem_vec_1579 ,mem_vec_1580 ,mem_vec_1581 ,mem_vec_1582 ,mem_vec_1583 ,mem_vec_1584 ,mem_vec_1585 ,mem_vec_1586 ,mem_vec_1587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f157 = f158, f157_p_0 = 0;
	f157 < f158 + 1024;
	f157 += 256, f157_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 1) (256 / 256)
	for (f156 = f157, f156_p_1 = f157_p_0, f156_p_0 = 0;
		f156 < f157 + 256;
		f156 += 256, f156_p_1 += 256, f156_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
		// T (c, 16) (512 / 32)
		for (c117 = c118, c117_p_0 = 0;
			c117 < c118 + 512;
			c117 += 32, c117_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 256
			// T (f, 8) (256 / 32)
			for (f = f156, fp_2 = f156_p_1, fp_1 = f156_p_0, fp_0 = 0;
				f < f156 + 256;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y78, yp_0 = 0;
						y < y78 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x78, xp_0 = 0;
							x < x78 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h57, hp_0 = 0;
								h < h57 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1552 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1553 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1554 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1555 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c117, cp_1 = c117_p_0, cp_0 = 0;
											c < c117 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1552);
											mem_vec_1552 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1553);
											mem_vec_1553 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1554);
											mem_vec_1554 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1555);
											mem_vec_1555 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1556);
											mem_vec_1556 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1557);
											mem_vec_1557 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1558);
											mem_vec_1558 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1559);
											mem_vec_1559 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1560);
											mem_vec_1560 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1561);
											mem_vec_1561 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1562);
											mem_vec_1562 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1563);
											mem_vec_1563 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1564);
											mem_vec_1564 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1565);
											mem_vec_1565 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1566);
											mem_vec_1566 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1567);
											mem_vec_1567 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1552);
											mem_vec_1552 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1553);
											mem_vec_1553 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1554);
											mem_vec_1554 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1555);
											mem_vec_1555 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1556);
											mem_vec_1556 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1557);
											mem_vec_1557 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1558);
											mem_vec_1558 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1559);
											mem_vec_1559 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1560);
											mem_vec_1560 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1561);
											mem_vec_1561 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1562);
											mem_vec_1562 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1563);
											mem_vec_1563 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1564);
											mem_vec_1564 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1565);
											mem_vec_1565 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1566);
											mem_vec_1566 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1567);
											mem_vec_1567 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1552);
											mem_vec_1552 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1553);
											mem_vec_1553 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1554);
											mem_vec_1554 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1555);
											mem_vec_1555 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1556);
											mem_vec_1556 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1557);
											mem_vec_1557 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1558);
											mem_vec_1558 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1559);
											mem_vec_1559 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1560);
											mem_vec_1560 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1561);
											mem_vec_1561 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1562);
											mem_vec_1562 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1563);
											mem_vec_1563 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1564);
											mem_vec_1564 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1565);
											mem_vec_1565 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1566);
											mem_vec_1566 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1567);
											mem_vec_1567 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1552);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1553);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1554);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1555);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1556);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1557);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1558);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1559);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1560);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1561);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1562);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1563);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1564);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1565);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1566);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1567);
							}
						}
					}
					for (y = y78 + 12, yp_0 = 0;
						y < y78 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x78, xp_0 = 0;
							x < x78 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h57, hp_0 = 0;
								h < h57 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1568 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1569 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1570 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1571 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c117, cp_1 = c117_p_0, cp_0 = 0;
											c < c117 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1568);
											mem_vec_1568 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1569);
											mem_vec_1569 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1570);
											mem_vec_1570 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1571);
											mem_vec_1571 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1572);
											mem_vec_1572 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1573);
											mem_vec_1573 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1574);
											mem_vec_1574 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1575);
											mem_vec_1575 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1576);
											mem_vec_1576 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1577);
											mem_vec_1577 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1578);
											mem_vec_1578 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1579);
											mem_vec_1579 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1580);
											mem_vec_1580 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1581);
											mem_vec_1581 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1582);
											mem_vec_1582 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1583);
											mem_vec_1583 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1584);
											mem_vec_1584 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1585);
											mem_vec_1585 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1586);
											mem_vec_1586 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1587);
											mem_vec_1587 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1568);
											mem_vec_1568 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1569);
											mem_vec_1569 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1570);
											mem_vec_1570 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1571);
											mem_vec_1571 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1572);
											mem_vec_1572 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1573);
											mem_vec_1573 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1574);
											mem_vec_1574 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1575);
											mem_vec_1575 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1576);
											mem_vec_1576 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1577);
											mem_vec_1577 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1578);
											mem_vec_1578 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1579);
											mem_vec_1579 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1580);
											mem_vec_1580 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1581);
											mem_vec_1581 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1582);
											mem_vec_1582 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1583);
											mem_vec_1583 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1584);
											mem_vec_1584 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1585);
											mem_vec_1585 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1586);
											mem_vec_1586 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1587);
											mem_vec_1587 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1568);
											mem_vec_1568 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1569);
											mem_vec_1569 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1570);
											mem_vec_1570 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1571);
											mem_vec_1571 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1572);
											mem_vec_1572 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1573);
											mem_vec_1573 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1574);
											mem_vec_1574 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1575);
											mem_vec_1575 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1576);
											mem_vec_1576 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1577);
											mem_vec_1577 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1578);
											mem_vec_1578 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1579);
											mem_vec_1579 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1580);
											mem_vec_1580 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1581);
											mem_vec_1581 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1582);
											mem_vec_1582 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1583);
											mem_vec_1583 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1584);
											mem_vec_1584 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1585);
											mem_vec_1585 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1586);
											mem_vec_1586 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1587);
											mem_vec_1587 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1568);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1569);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1570);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1571);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1572);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1573);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1574);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1575);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1576);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1577);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1578);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1579);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1580);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1581);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1582);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1583);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1584);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1585);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1586);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1587);
							}
						}
					}
			}
		}
	}
}


}