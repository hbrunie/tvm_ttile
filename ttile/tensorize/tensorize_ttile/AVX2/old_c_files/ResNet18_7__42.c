#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (14, x); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (16, c); T (8, f); T (1, c)]
*/
IND_TYPE c, cp_0, c188_p_0, c189_p_0, cp_1, c188_p_1, cp_2, c188, c189, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y94 = 0;
IND_TYPE x94 = 0;
IND_TYPE h69 = 0;
IND_TYPE w = 0;
IND_TYPE c190 = 0;
IND_TYPE f94 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,mem_vec_1544 ,mem_vec_1545 ,mem_vec_1546 ,mem_vec_1547 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c189 = c190, c189_p_0 = 0;
	c189 < c190 + 128;
	c189 += 128, c189_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f = f94, fp_0 = 0;
		f < f94 + 256;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
		// T (c, 16) (128 / 8)
		for (c188 = c189, c188_p_1 = c189_p_0, c188_p_0 = 0;
			c188 < c189 + 128;
			c188 += 8, c188_p_1 += 8, c188_p_0 += 8){
				for (y = y94, yp_0 = 0;
					y < y94 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (x, 14) (14 / 1)
					for (x = x94, xp_0 = 0;
						x < x94 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h69, hp_0 = 0;
							h < h69 + 3;
							h += 1, hp_0 += 1){
									mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c188, cp_2 = c188_p_1, cp_1 = c188_p_0, cp_0 = 0;
										c < c188 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1512);
										mem_vec_1512 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1513);
										mem_vec_1513 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1514);
										mem_vec_1514 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1515);
										mem_vec_1515 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1516);
										mem_vec_1516 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1517);
										mem_vec_1517 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1518);
										mem_vec_1518 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1519);
										mem_vec_1519 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1520);
										mem_vec_1520 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1521);
										mem_vec_1521 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1522);
										mem_vec_1522 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1523);
										mem_vec_1523 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1524);
										mem_vec_1524 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1525);
										mem_vec_1525 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1526);
										mem_vec_1526 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1527);
										mem_vec_1527 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1512);
										mem_vec_1512 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1513);
										mem_vec_1513 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1514);
										mem_vec_1514 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1515);
										mem_vec_1515 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1516);
										mem_vec_1516 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1517);
										mem_vec_1517 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1518);
										mem_vec_1518 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1519);
										mem_vec_1519 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1520);
										mem_vec_1520 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1521);
										mem_vec_1521 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1522);
										mem_vec_1522 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1523);
										mem_vec_1523 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1524);
										mem_vec_1524 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1525);
										mem_vec_1525 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1526);
										mem_vec_1526 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1527);
										mem_vec_1527 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1512);
										mem_vec_1512 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1513);
										mem_vec_1513 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1514);
										mem_vec_1514 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1515);
										mem_vec_1515 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1516);
										mem_vec_1516 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1517);
										mem_vec_1517 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1518);
										mem_vec_1518 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1519);
										mem_vec_1519 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1520);
										mem_vec_1520 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1521);
										mem_vec_1521 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1522);
										mem_vec_1522 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1523);
										mem_vec_1523 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1524);
										mem_vec_1524 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1525);
										mem_vec_1525 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1526);
										mem_vec_1526 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1527);
										mem_vec_1527 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1512);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1513);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1514);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1515);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1516);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1517);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1518);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1519);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1520);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1521);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1522);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1523);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1524);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1525);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1526);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1527);
						}
					}
				}
				for (y = y94 + 4, yp_0 = 0;
					y < y94 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (x, 14) (14 / 1)
					for (x = x94, xp_0 = 0;
						x < x94 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h69, hp_0 = 0;
							h < h69 + 3;
							h += 1, hp_0 += 1){
									mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c188, cp_2 = c188_p_1, cp_1 = c188_p_0, cp_0 = 0;
										c < c188 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1528);
										mem_vec_1528 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1529);
										mem_vec_1529 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1530);
										mem_vec_1530 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1531);
										mem_vec_1531 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1532);
										mem_vec_1532 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1533);
										mem_vec_1533 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1534);
										mem_vec_1534 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1535);
										mem_vec_1535 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1536);
										mem_vec_1536 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1537);
										mem_vec_1537 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1538);
										mem_vec_1538 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1539);
										mem_vec_1539 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1540);
										mem_vec_1540 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1541);
										mem_vec_1541 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1542);
										mem_vec_1542 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1543);
										mem_vec_1543 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1544);
										mem_vec_1544 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1545);
										mem_vec_1545 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1546);
										mem_vec_1546 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1547);
										mem_vec_1547 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);
										vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1528);
										mem_vec_1528 = vec_29;

										vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1529);
										mem_vec_1529 = vec_32;

										vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1530);
										mem_vec_1530 = vec_34;

										vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1531);
										mem_vec_1531 = vec_36;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1532);
										mem_vec_1532 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1533);
										mem_vec_1533 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1534);
										mem_vec_1534 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1535);
										mem_vec_1535 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1536);
										mem_vec_1536 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1537);
										mem_vec_1537 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1538);
										mem_vec_1538 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1539);
										mem_vec_1539 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1540);
										mem_vec_1540 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1541);
										mem_vec_1541 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1542);
										mem_vec_1542 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1543);
										mem_vec_1543 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1544);
										mem_vec_1544 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1545);
										mem_vec_1545 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1546);
										mem_vec_1546 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1547);
										mem_vec_1547 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_59 = _mm256_set1_ps(scal_10);
										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1528);
										mem_vec_1528 = vec_58;

										vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1529);
										mem_vec_1529 = vec_61;

										vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1530);
										mem_vec_1530 = vec_63;

										vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1531);
										mem_vec_1531 = vec_65;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1532);
										mem_vec_1532 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1533);
										mem_vec_1533 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1534);
										mem_vec_1534 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1535);
										mem_vec_1535 = vec_71;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_73 = _mm256_set1_ps(scal_12);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1536);
										mem_vec_1536 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1537);
										mem_vec_1537 = vec_74;



										vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1538);
										mem_vec_1538 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1539);
										mem_vec_1539 = vec_76;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_78 = _mm256_set1_ps(scal_13);


										vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1540);
										mem_vec_1540 = vec_77;



										vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1541);
										mem_vec_1541 = vec_79;



										vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1542);
										mem_vec_1542 = vec_80;



										vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1543);
										mem_vec_1543 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_83 = _mm256_set1_ps(scal_14);


										vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1544);
										mem_vec_1544 = vec_82;



										vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1545);
										mem_vec_1545 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1546);
										mem_vec_1546 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1547);
										mem_vec_1547 = vec_86;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1528);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1529);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1530);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1531);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1532);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1533);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1534);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1535);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1536);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1537);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1538);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1539);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1540);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1541);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1542);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1543);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1544);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1545);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1546);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1547);
						}
					}
				}
		}
	}
}


}