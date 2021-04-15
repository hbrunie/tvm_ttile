#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (1, c);
  T (32, f); T (17, x); T (1, c)]
*/
IND_TYPE c, cp_0, c210_p_0, c211_p_0, c212_p_0, cp_1, c210_p_1, c211_p_1, cp_2, c210_p_2, cp_3, c210, c211, c212, f, fp_0, w, wp_0, x, xp_0, x168_p_0, x169_p_0, xp_1, x168_p_1, xp_2, x168, x169, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y84 = 0;
IND_TYPE x170 = 0;
IND_TYPE h = 0;
IND_TYPE w84 = 0;
IND_TYPE c213 = 0;
IND_TYPE f84 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,mem_vec_1544 ,mem_vec_1545 ,mem_vec_1546 ,mem_vec_1547 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c212 = c213, c212_p_0 = 0;
	c212 < c213 + 256;
	c212 += 256, c212_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 17) (34 / 2)
	for (x169 = x170, x169_p_0 = 0;
		x169 < x170 + 34;
		x169 += 2, x169_p_0 += 2){
		// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f84, fp_0 = 0;
			f < f84 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 2, h = 3, w = 3, c = 256, f = 16
			// T (c, 1) (256 / 256)
			for (c211 = c212, c211_p_1 = c212_p_0, c211_p_0 = 0;
				c211 < c212 + 256;
				c211 += 256, c211_p_1 += 256, c211_p_0 += 256){
					for (y = y84, yp_0 = 0;
						y < y84 + 24;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
						// T (x, 1) (2 / 2)
						for (x168 = x169, x168_p_1 = x169_p_0, x168_p_0 = 0;
							x168 < x169 + 2;
							x168 += 2, x168_p_1 += 2, x168_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
							// T (c, 1) (256 / 256)
							for (c210 = c211, c210_p_2 = c211_p_1, c210_p_1 = c211_p_0, c210_p_0 = 0;
								c210 < c211 + 256;
								c210 += 256, c210_p_2 += 256, c210_p_1 += 256, c210_p_0 += 256){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
								// T (w, 3) (3 / 1)
								for (w = w84, wp_0 = 0;
									w < w84 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 256, f = 16
									// T (x, 2) (2 / 1)
									for (x = x168, xp_2 = x168_p_1, xp_1 = x168_p_0, xp_0 = 0;
										x < x168 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 16
												// T (c, 256) (256 / 1)
												for (c = c210, cp_3 = c210_p_2, cp_2 = c210_p_1, cp_1 = c210_p_0, cp_0 = 0;
													c < c210 + 256;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1512);
													mem_vec_1512 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1513);
													mem_vec_1513 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1514);
													mem_vec_1514 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1515);
													mem_vec_1515 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1516);
													mem_vec_1516 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1517);
													mem_vec_1517 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1518);
													mem_vec_1518 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1519);
													mem_vec_1519 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1520);
													mem_vec_1520 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1521);
													mem_vec_1521 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1522);
													mem_vec_1522 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1523);
													mem_vec_1523 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1524);
													mem_vec_1524 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1525);
													mem_vec_1525 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1526);
													mem_vec_1526 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1527);
													mem_vec_1527 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_1512);
													mem_vec_1512 = vec_26;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_1513);
													mem_vec_1513 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);


													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_1514);
													mem_vec_1514 = vec_31;



													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_1515);
													mem_vec_1515 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_1516);
													mem_vec_1516 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_1517);
													mem_vec_1517 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_1518);
													mem_vec_1518 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_1519);
													mem_vec_1519 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_1520);
													mem_vec_1520 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_1521);
													mem_vec_1521 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1522);
													mem_vec_1522 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1523);
													mem_vec_1523 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_1524);
													mem_vec_1524 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_1525);
													mem_vec_1525 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_1526);
													mem_vec_1526 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_1527);
													mem_vec_1527 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_1512);
													mem_vec_1512 = vec_52;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_1513);
													mem_vec_1513 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1514);
													mem_vec_1514 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1515);
													mem_vec_1515 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);


													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_1516);
													mem_vec_1516 = vec_60;



													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_1517);
													mem_vec_1517 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_1518);
													mem_vec_1518 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_1519);
													mem_vec_1519 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);


													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_1520);
													mem_vec_1520 = vec_66;



													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_1521);
													mem_vec_1521 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_1522);
													mem_vec_1522 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_1523);
													mem_vec_1523 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_1524);
													mem_vec_1524 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_1525);
													mem_vec_1525 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_1526);
													mem_vec_1526 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_1527);
													mem_vec_1527 = vec_77;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1519);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1523);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1524);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1525);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1526);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1527);
									}
								}
							}
						}
					}
					for (y = y84 + 24, yp_0 = 0;
						y < y84 + 24 + 10;
						y += 10, yp_0 += 10){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
						// T (x, 1) (2 / 2)
						for (x168 = x169, x168_p_1 = x169_p_0, x168_p_0 = 0;
							x168 < x169 + 2;
							x168 += 2, x168_p_1 += 2, x168_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
							// T (c, 1) (256 / 256)
							for (c210 = c211, c210_p_2 = c211_p_1, c210_p_1 = c211_p_0, c210_p_0 = 0;
								c210 < c211 + 256;
								c210 += 256, c210_p_2 += 256, c210_p_1 += 256, c210_p_0 += 256){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 16
								// T (w, 3) (3 / 1)
								for (w = w84, wp_0 = 0;
									w < w84 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 256, f = 16
									// T (x, 2) (2 / 1)
									for (x = x168, xp_2 = x168_p_1, xp_1 = x168_p_0, xp_0 = 0;
										x < x168 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_1540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_1542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_1544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_1546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 16
												// T (c, 256) (256 / 1)
												for (c = c210, cp_3 = c210_p_2, cp_2 = c210_p_1, cp_1 = c210_p_0, cp_0 = 0;
													c < c210 + 256;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1528);
													mem_vec_1528 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1529);
													mem_vec_1529 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1530);
													mem_vec_1530 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1531);
													mem_vec_1531 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1532);
													mem_vec_1532 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1533);
													mem_vec_1533 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1534);
													mem_vec_1534 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1535);
													mem_vec_1535 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1536);
													mem_vec_1536 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1537);
													mem_vec_1537 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1538);
													mem_vec_1538 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1539);
													mem_vec_1539 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1540);
													mem_vec_1540 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1541);
													mem_vec_1541 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1542);
													mem_vec_1542 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1543);
													mem_vec_1543 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1544);
													mem_vec_1544 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1545);
													mem_vec_1545 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1546);
													mem_vec_1546 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1547);
													mem_vec_1547 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_1528);
													mem_vec_1528 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_1529);
													mem_vec_1529 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_1530);
													mem_vec_1530 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_1531);
													mem_vec_1531 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_1532);
													mem_vec_1532 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_1533);
													mem_vec_1533 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_1534);
													mem_vec_1534 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1535);
													mem_vec_1535 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_1536);
													mem_vec_1536 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_1537);
													mem_vec_1537 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_1538);
													mem_vec_1538 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_1539);
													mem_vec_1539 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_1540);
													mem_vec_1540 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_1541);
													mem_vec_1541 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_1542);
													mem_vec_1542 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_1543);
													mem_vec_1543 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_1544);
													mem_vec_1544 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1545);
													mem_vec_1545 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_1546);
													mem_vec_1546 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_1547);
													mem_vec_1547 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_1528);
													mem_vec_1528 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_1529);
													mem_vec_1529 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_1530);
													mem_vec_1530 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_1531);
													mem_vec_1531 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1532);
													mem_vec_1532 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_1533);
													mem_vec_1533 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_1534);
													mem_vec_1534 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_1535);
													mem_vec_1535 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_1536);
													mem_vec_1536 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_1537);
													mem_vec_1537 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_1538);
													mem_vec_1538 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_1539);
													mem_vec_1539 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_1540);
													mem_vec_1540 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_1541);
													mem_vec_1541 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_1542);
													mem_vec_1542 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_1543);
													mem_vec_1543 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_1544);
													mem_vec_1544 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_1545);
													mem_vec_1545 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_1546);
													mem_vec_1546 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_1547);
													mem_vec_1547 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1528);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1529);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1530);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1531);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1532);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1533);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1534);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1535);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1539);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1540);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1541);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1542);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1543);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1544);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_1545);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1546);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_1547);
									}
								}
							}
						}
					}
			}
		}
	}
}


}