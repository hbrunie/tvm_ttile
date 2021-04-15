#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (8, f);
  T (4, c); T (4, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1240_p_0, cp_1, c1240, f, fp_0, f1298_p_0, f1299_p_0, fp_1, f1298_p_1, fp_2, f1298, f1299, h, hp_0, x, xp_0, x1486_p_0, x1487_p_0, xp_1, x1486_p_1, xp_2, x1486, x1487, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y752 = 0;
IND_TYPE x1488 = 0;
IND_TYPE h564 = 0;
IND_TYPE w = 0;
IND_TYPE c1241 = 0;
IND_TYPE f1300 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11092 ,mem_vec_11093 ,mem_vec_11094 ,mem_vec_11095 ,mem_vec_11096 ,mem_vec_11097 ,mem_vec_11098 ,mem_vec_11099 ,mem_vec_11100 ,mem_vec_11101 ,mem_vec_11102 ,mem_vec_11103 ,mem_vec_11104 ,mem_vec_11105 ,mem_vec_11106 ,mem_vec_11107 ,mem_vec_11108 ,mem_vec_11109 ,mem_vec_11110 ,mem_vec_11111 ,mem_vec_11112 ,mem_vec_11113 ,mem_vec_11114 ,mem_vec_11115 ,mem_vec_11116 ,mem_vec_11117 ,mem_vec_11118 ,mem_vec_11119 ,mem_vec_11120 ,mem_vec_11121 ,mem_vec_11122 ,mem_vec_11123 ,mem_vec_11124 ,mem_vec_11125 ,mem_vec_11126 ,mem_vec_11127 ,mem_vec_11128 ,mem_vec_11129 ,mem_vec_11130 ,mem_vec_11131 ,mem_vec_11132 ,mem_vec_11133 ,mem_vec_11134 ,mem_vec_11135 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1299 = f1300, f1299_p_0 = 0;
	f1299 < f1300 + 256;
	f1299 += 256, f1299_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
	// T (x, 4) (28 / 7)
	for (x1487 = x1488, x1487_p_0 = 0;
		x1487 < x1488 + 28;
		x1487 += 7, x1487_p_0 += 7){
		// y = 28, x = 7, h = 3, w = 3, c = 128, f = 256
		// T (c, 4) (128 / 32)
		for (c1240 = c1241, c1240_p_0 = 0;
			c1240 < c1241 + 128;
			c1240 += 32, c1240_p_0 += 32){
			// y = 28, x = 7, h = 3, w = 3, c = 32, f = 256
			// T (f, 8) (256 / 32)
			for (f1298 = f1299, f1298_p_1 = f1299_p_0, f1298_p_0 = 0;
				f1298 < f1299 + 256;
				f1298 += 32, f1298_p_1 += 32, f1298_p_0 += 32){
					for (y = y752, yp_0 = 0;
						y < y752 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (x, 7) (7 / 1)
						for (x1486 = x1487, x1486_p_1 = x1487_p_0, x1486_p_0 = 0;
							x1486 < x1487 + 7;
							x1486 += 1, x1486_p_1 += 1, x1486_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1298, fp_2 = f1298_p_1, fp_1 = f1298_p_0, fp_0 = 0;
								f < f1298 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h564, hp_0 = 0;
									h < h564 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1486, xp_2 = x1486_p_1, xp_1 = x1486_p_0, xp_0 = 0;
										x < x1486 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11092 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11093 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11094 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11095 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c1240, cp_1 = c1240_p_0, cp_0 = 0;
													c < c1240 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11092);
													mem_vec_11092 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11093);
													mem_vec_11093 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11094);
													mem_vec_11094 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11095);
													mem_vec_11095 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11096);
													mem_vec_11096 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11097);
													mem_vec_11097 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11098);
													mem_vec_11098 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11099);
													mem_vec_11099 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11100);
													mem_vec_11100 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11101);
													mem_vec_11101 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11102);
													mem_vec_11102 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11103);
													mem_vec_11103 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11104);
													mem_vec_11104 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11105);
													mem_vec_11105 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11106);
													mem_vec_11106 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11107);
													mem_vec_11107 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11108);
													mem_vec_11108 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11109);
													mem_vec_11109 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11110);
													mem_vec_11110 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11111);
													mem_vec_11111 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11092);
													mem_vec_11092 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11093);
													mem_vec_11093 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11094);
													mem_vec_11094 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11095);
													mem_vec_11095 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11096);
													mem_vec_11096 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11097);
													mem_vec_11097 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11098);
													mem_vec_11098 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11099);
													mem_vec_11099 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11100);
													mem_vec_11100 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11101);
													mem_vec_11101 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11102);
													mem_vec_11102 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11103);
													mem_vec_11103 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11104);
													mem_vec_11104 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11105);
													mem_vec_11105 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11106);
													mem_vec_11106 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11107);
													mem_vec_11107 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11108);
													mem_vec_11108 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11109);
													mem_vec_11109 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11110);
													mem_vec_11110 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11111);
													mem_vec_11111 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11092);
													mem_vec_11092 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11093);
													mem_vec_11093 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11094);
													mem_vec_11094 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11095);
													mem_vec_11095 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11096);
													mem_vec_11096 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11097);
													mem_vec_11097 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11098);
													mem_vec_11098 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11099);
													mem_vec_11099 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11100);
													mem_vec_11100 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11101);
													mem_vec_11101 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11102);
													mem_vec_11102 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11103);
													mem_vec_11103 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11104);
													mem_vec_11104 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11105);
													mem_vec_11105 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11106);
													mem_vec_11106 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11107);
													mem_vec_11107 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11108);
													mem_vec_11108 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11109);
													mem_vec_11109 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11110);
													mem_vec_11110 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11111);
													mem_vec_11111 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11092);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11093);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11094);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11095);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11096);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11097);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11098);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11099);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11100);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11101);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11102);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11103);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11104);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11105);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11106);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11107);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11108);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11109);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11110);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11111);
									}
								}
							}
						}
					}
					for (y = y752 + 10, yp_0 = 0;
						y < y752 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (x, 7) (7 / 1)
						for (x1486 = x1487, x1486_p_1 = x1487_p_0, x1486_p_0 = 0;
							x1486 < x1487 + 7;
							x1486 += 1, x1486_p_1 += 1, x1486_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1298, fp_2 = f1298_p_1, fp_1 = f1298_p_0, fp_0 = 0;
								f < f1298 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h564, hp_0 = 0;
									h < h564 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1486, xp_2 = x1486_p_1, xp_1 = x1486_p_0, xp_0 = 0;
										x < x1486 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c1240, cp_1 = c1240_p_0, cp_0 = 0;
													c < c1240 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11112);
													mem_vec_11112 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11113);
													mem_vec_11113 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11114);
													mem_vec_11114 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11115);
													mem_vec_11115 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11116);
													mem_vec_11116 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11117);
													mem_vec_11117 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11118);
													mem_vec_11118 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11119);
													mem_vec_11119 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11120);
													mem_vec_11120 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11121);
													mem_vec_11121 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11122);
													mem_vec_11122 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11123);
													mem_vec_11123 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11124);
													mem_vec_11124 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11125);
													mem_vec_11125 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11126);
													mem_vec_11126 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11127);
													mem_vec_11127 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11128);
													mem_vec_11128 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11129);
													mem_vec_11129 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11130);
													mem_vec_11130 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11131);
													mem_vec_11131 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11132);
													mem_vec_11132 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11133);
													mem_vec_11133 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11134);
													mem_vec_11134 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11135);
													mem_vec_11135 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11112);
													mem_vec_11112 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11113);
													mem_vec_11113 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11114);
													mem_vec_11114 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11115);
													mem_vec_11115 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11116);
													mem_vec_11116 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11117);
													mem_vec_11117 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11118);
													mem_vec_11118 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11119);
													mem_vec_11119 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11120);
													mem_vec_11120 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11121);
													mem_vec_11121 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11122);
													mem_vec_11122 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11123);
													mem_vec_11123 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11124);
													mem_vec_11124 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11125);
													mem_vec_11125 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11126);
													mem_vec_11126 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11127);
													mem_vec_11127 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11128);
													mem_vec_11128 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11129);
													mem_vec_11129 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11130);
													mem_vec_11130 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11131);
													mem_vec_11131 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11132);
													mem_vec_11132 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11133);
													mem_vec_11133 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11134);
													mem_vec_11134 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11135);
													mem_vec_11135 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11112);
													mem_vec_11112 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11113);
													mem_vec_11113 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11114);
													mem_vec_11114 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11115);
													mem_vec_11115 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11116);
													mem_vec_11116 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11117);
													mem_vec_11117 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11118);
													mem_vec_11118 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11119);
													mem_vec_11119 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11120);
													mem_vec_11120 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11121);
													mem_vec_11121 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11122);
													mem_vec_11122 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11123);
													mem_vec_11123 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11124);
													mem_vec_11124 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11125);
													mem_vec_11125 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11126);
													mem_vec_11126 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11127);
													mem_vec_11127 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11128);
													mem_vec_11128 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11129);
													mem_vec_11129 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11130);
													mem_vec_11130 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11131);
													mem_vec_11131 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11132);
													mem_vec_11132 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11133);
													mem_vec_11133 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11134);
													mem_vec_11134 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11135);
													mem_vec_11135 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11112);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11113);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11114);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11115);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11116);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11117);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11118);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11119);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11120);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11121);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11122);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11123);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11124);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11125);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11126);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11127);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11128);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11129);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11130);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11131);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11135);
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