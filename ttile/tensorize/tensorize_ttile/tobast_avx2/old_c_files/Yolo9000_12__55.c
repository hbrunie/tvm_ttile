#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (8, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (16, c);
  T (32, f); T (1, x); T (1, c)]
*/
IND_TYPE c, cp_0, c810_p_0, c811_p_0, c812_p_0, cp_1, c810_p_1, c811_p_1, cp_2, c810_p_2, cp_3, c810, c811, c812, f, fp_0, w, wp_0, x, xp_0, x648_p_0, x649_p_0, xp_1, x648_p_1, xp_2, x648, x649, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y324 = 0;
IND_TYPE x650 = 0;
IND_TYPE h = 0;
IND_TYPE w324 = 0;
IND_TYPE c813 = 0;
IND_TYPE f324 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6532 ,mem_vec_6533 ,mem_vec_6534 ,mem_vec_6535 ,mem_vec_6536 ,mem_vec_6537 ,mem_vec_6538 ,mem_vec_6539 ,mem_vec_6540 ,mem_vec_6541 ,mem_vec_6542 ,mem_vec_6543 ,mem_vec_6544 ,mem_vec_6545 ,mem_vec_6546 ,mem_vec_6547 ,mem_vec_6548 ,mem_vec_6549 ,mem_vec_6550 ,mem_vec_6551 ,mem_vec_6552 ,mem_vec_6553 ,mem_vec_6554 ,mem_vec_6555 ,mem_vec_6556 ,mem_vec_6557 ,mem_vec_6558 ,mem_vec_6559 ,mem_vec_6560 ,mem_vec_6561 ,mem_vec_6562 ,mem_vec_6563 ,mem_vec_6564 ,mem_vec_6565 ,mem_vec_6566 ,mem_vec_6567 ,mem_vec_6568 ,mem_vec_6569 ,mem_vec_6570 ,mem_vec_6571 ,mem_vec_6572 ,mem_vec_6573 ,mem_vec_6574 ,mem_vec_6575 ,mem_vec_6576 ,mem_vec_6577 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c812 = c813, c812_p_0 = 0;
	c812 < c813 + 256;
	c812 += 256, c812_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 1) (34 / 34)
	for (x649 = x650, x649_p_0 = 0;
		x649 < x650 + 34;
		x649 += 34, x649_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f324, fp_0 = 0;
			f < f324 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 34, h = 3, w = 3, c = 256, f = 16
			// T (c, 16) (256 / 16)
			for (c811 = c812, c811_p_1 = c812_p_0, c811_p_0 = 0;
				c811 < c812 + 256;
				c811 += 16, c811_p_1 += 16, c811_p_0 += 16){
					for (y = y324, yp_0 = 0;
						y < y324 + 22;
						y += 11, yp_0 += 11){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
						// T (x, 1) (34 / 34)
						for (x648 = x649, x648_p_1 = x649_p_0, x648_p_0 = 0;
							x648 < x649 + 34;
							x648 += 34, x648_p_1 += 34, x648_p_0 += 34){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
							// T (c, 8) (16 / 2)
							for (c810 = c811, c810_p_2 = c811_p_1, c810_p_1 = c811_p_0, c810_p_0 = 0;
								c810 < c811 + 16;
								c810 += 2, c810_p_2 += 2, c810_p_1 += 2, c810_p_0 += 2){
								// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 16
								// T (w, 3) (3 / 1)
								for (w = w324, wp_0 = 0;
									w < w324 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 3, w = 1, c = 2, f = 16
									// T (x, 34) (34 / 1)
									for (x = x648, xp_2 = x648_p_1, xp_1 = x648_p_0, xp_0 = 0;
										x < x648 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6532 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6533 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_6542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_6544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_6546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_6548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_6550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_6552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
												// T (c, 2) (2 / 1)
												for (c = c810, cp_3 = c810_p_2, cp_2 = c810_p_1, cp_1 = c810_p_0, cp_0 = 0;
													c < c810 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6532);
													mem_vec_6532 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6533);
													mem_vec_6533 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6534);
													mem_vec_6534 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6535);
													mem_vec_6535 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6536);
													mem_vec_6536 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6537);
													mem_vec_6537 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6538);
													mem_vec_6538 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6539);
													mem_vec_6539 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6540);
													mem_vec_6540 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6541);
													mem_vec_6541 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6542);
													mem_vec_6542 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6543);
													mem_vec_6543 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6544);
													mem_vec_6544 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6545);
													mem_vec_6545 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6546);
													mem_vec_6546 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6547);
													mem_vec_6547 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6548);
													mem_vec_6548 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6549);
													mem_vec_6549 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6550);
													mem_vec_6550 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6551);
													mem_vec_6551 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_6552);
													mem_vec_6552 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_6553);
													mem_vec_6553 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_36 = _mm256_set1_ps(scal_11);
													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_6532);
													mem_vec_6532 = vec_35;

													vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_6533);
													mem_vec_6533 = vec_38;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_6534);
													mem_vec_6534 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_6535);
													mem_vec_6535 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_6536);
													mem_vec_6536 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_6537);
													mem_vec_6537 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_6538);
													mem_vec_6538 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_6539);
													mem_vec_6539 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_6540);
													mem_vec_6540 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_6541);
													mem_vec_6541 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_6542);
													mem_vec_6542 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_6543);
													mem_vec_6543 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_6544);
													mem_vec_6544 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_6545);
													mem_vec_6545 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_6546);
													mem_vec_6546 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_6547);
													mem_vec_6547 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_6548);
													mem_vec_6548 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_6549);
													mem_vec_6549 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_6550);
													mem_vec_6550 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_6551);
													mem_vec_6551 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_6552);
													mem_vec_6552 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_6553);
													mem_vec_6553 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_71 = _mm256_set1_ps(scal_22);
													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_6532);
													mem_vec_6532 = vec_70;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_6533);
													mem_vec_6533 = vec_73;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_6534);
													mem_vec_6534 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_6535);
													mem_vec_6535 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_6536);
													mem_vec_6536 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_6537);
													mem_vec_6537 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_6538);
													mem_vec_6538 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_6539);
													mem_vec_6539 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_6540);
													mem_vec_6540 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_6541);
													mem_vec_6541 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6542);
													mem_vec_6542 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6543);
													mem_vec_6543 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_6544);
													mem_vec_6544 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_6545);
													mem_vec_6545 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_6546);
													mem_vec_6546 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_6547);
													mem_vec_6547 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_6548);
													mem_vec_6548 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_6549);
													mem_vec_6549 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_6550);
													mem_vec_6550 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_6551);
													mem_vec_6551 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_6552);
													mem_vec_6552 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_6553);
													mem_vec_6553 = vec_104;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6532);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6533);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6534);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6535);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6539);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6540);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6541);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6542);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6543);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6544);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6545);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6546);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6547);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6548);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6549);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6550);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_6551);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6552);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_6553);
									}
								}
							}
						}
					}
					for (y = y324 + 22, yp_0 = 0;
						y < y324 + 22 + 12;
						y += 12, yp_0 += 12){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
						// T (x, 1) (34 / 34)
						for (x648 = x649, x648_p_1 = x649_p_0, x648_p_0 = 0;
							x648 < x649 + 34;
							x648 += 34, x648_p_1 += 34, x648_p_0 += 34){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
							// T (c, 8) (16 / 2)
							for (c810 = c811, c810_p_2 = c811_p_1, c810_p_1 = c811_p_0, c810_p_0 = 0;
								c810 < c811 + 16;
								c810 += 2, c810_p_2 += 2, c810_p_1 += 2, c810_p_0 += 2){
								// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 16
								// T (w, 3) (3 / 1)
								for (w = w324, wp_0 = 0;
									w < w324 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 3, w = 1, c = 2, f = 16
									// T (x, 34) (34 / 1)
									for (x = x648, xp_2 = x648_p_1, xp_1 = x648_p_0, xp_0 = 0;
										x < x648 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6554 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6555 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_6564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_6566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_6568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_6570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_6572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_6574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												mem_vec_6576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
												// T (c, 2) (2 / 1)
												for (c = c810, cp_3 = c810_p_2, cp_2 = c810_p_1, cp_1 = c810_p_0, cp_0 = 0;
													c < c810 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6554);
													mem_vec_6554 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6555);
													mem_vec_6555 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6556);
													mem_vec_6556 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6557);
													mem_vec_6557 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6558);
													mem_vec_6558 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6559);
													mem_vec_6559 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6560);
													mem_vec_6560 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6561);
													mem_vec_6561 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6562);
													mem_vec_6562 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6563);
													mem_vec_6563 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6564);
													mem_vec_6564 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6565);
													mem_vec_6565 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6566);
													mem_vec_6566 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6567);
													mem_vec_6567 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6568);
													mem_vec_6568 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6569);
													mem_vec_6569 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6570);
													mem_vec_6570 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6571);
													mem_vec_6571 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6572);
													mem_vec_6572 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6573);
													mem_vec_6573 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_6574);
													mem_vec_6574 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_6575);
													mem_vec_6575 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm256_set1_ps(scal_11);


													vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_6576);
													mem_vec_6576 = vec_35;



													vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_6577);
													mem_vec_6577 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_12);
													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_6554);
													mem_vec_6554 = vec_38;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_6555);
													mem_vec_6555 = vec_41;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6556);
													mem_vec_6556 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6557);
													mem_vec_6557 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_6558);
													mem_vec_6558 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_6559);
													mem_vec_6559 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_6560);
													mem_vec_6560 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_6561);
													mem_vec_6561 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_6562);
													mem_vec_6562 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_6563);
													mem_vec_6563 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_6564);
													mem_vec_6564 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_6565);
													mem_vec_6565 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6566);
													mem_vec_6566 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6567);
													mem_vec_6567 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_6568);
													mem_vec_6568 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_6569);
													mem_vec_6569 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_6570);
													mem_vec_6570 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_6571);
													mem_vec_6571 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_6572);
													mem_vec_6572 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_6573);
													mem_vec_6573 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_71 = _mm256_set1_ps(scal_22);


													vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_6574);
													mem_vec_6574 = vec_70;



													vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_6575);
													mem_vec_6575 = vec_72;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_23);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_6576);
													mem_vec_6576 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_6577);
													mem_vec_6577 = vec_75;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_77 = _mm256_set1_ps(scal_24);
													vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_6554);
													mem_vec_6554 = vec_76;

													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_6555);
													mem_vec_6555 = vec_79;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_6556);
													mem_vec_6556 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_6557);
													mem_vec_6557 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_6558);
													mem_vec_6558 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_6559);
													mem_vec_6559 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_6560);
													mem_vec_6560 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6561);
													mem_vec_6561 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_6562);
													mem_vec_6562 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_6563);
													mem_vec_6563 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_6564);
													mem_vec_6564 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_6565);
													mem_vec_6565 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_6566);
													mem_vec_6566 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_6567);
													mem_vec_6567 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_6568);
													mem_vec_6568 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_6569);
													mem_vec_6569 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_6570);
													mem_vec_6570 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6571);
													mem_vec_6571 = vec_104;
													scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_106 = _mm256_set1_ps(scal_33);


													vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_6572);
													mem_vec_6572 = vec_105;



													vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_6573);
													mem_vec_6573 = vec_107;
													scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_109 = _mm256_set1_ps(scal_34);


													vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_6574);
													mem_vec_6574 = vec_108;



													vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_6575);
													mem_vec_6575 = vec_110;
													scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
													vec_112 = _mm256_set1_ps(scal_35);


													vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_6576);
													mem_vec_6576 = vec_111;



													vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_6577);
													mem_vec_6577 = vec_113;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6554);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6555);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6567);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_6573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_6575);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_6577);
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