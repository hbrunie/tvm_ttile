#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f);
  T (128, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1170_p_0, cp_1, c1170, f, fp_0, f1164_p_0, f1165_p_0, fp_1, f1164_p_1, fp_2, f1164, f1165, h, hp_0, x, xp_0, x1452_p_0, x1453_p_0, xp_1, x1452_p_1, xp_2, x1452, x1453, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y708 = 0;
IND_TYPE x1454 = 0;
IND_TYPE h498 = 0;
IND_TYPE w = 0;
IND_TYPE c1171 = 0;
IND_TYPE f1166 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10120 ,mem_vec_10121 ,mem_vec_10122 ,mem_vec_10123 ,mem_vec_10124 ,mem_vec_10125 ,mem_vec_10126 ,mem_vec_10127 ,mem_vec_10128 ,mem_vec_10129 ,mem_vec_10130 ,mem_vec_10131 ,mem_vec_10132 ,mem_vec_10133 ,mem_vec_10134 ,mem_vec_10135 ,mem_vec_10136 ,mem_vec_10137 ,mem_vec_10138 ,mem_vec_10139 ,mem_vec_10140 ,mem_vec_10141 ,mem_vec_10142 ,mem_vec_10143 ,mem_vec_10144 ,mem_vec_10145 ,mem_vec_10146 ,mem_vec_10147 ,mem_vec_10148 ,mem_vec_10149 ,mem_vec_10150 ,mem_vec_10151 ,mem_vec_10152 ,mem_vec_10153 ,mem_vec_10154 ,mem_vec_10155 ,mem_vec_10156 ,mem_vec_10157 ,mem_vec_10158 ,mem_vec_10159 ,mem_vec_10160 ,mem_vec_10161 ,mem_vec_10162 ,mem_vec_10163 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1165 = f1166, f1165_p_0 = 0;
	f1165 < f1166 + 128;
	f1165 += 64, f1165_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (x, 1) (28 / 28)
	for (x1453 = x1454, x1453_p_0 = 0;
		x1453 < x1454 + 28;
		x1453 += 28, x1453_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (c, 128) (128 / 1)
		for (c1170 = c1171, c1170_p_0 = 0;
			c1170 < c1171 + 128;
			c1170 += 1, c1170_p_0 += 1){
			// y = 28, x = 28, h = 3, w = 3, c = 1, f = 64
			// T (f, 2) (64 / 32)
			for (f1164 = f1165, f1164_p_1 = f1165_p_0, f1164_p_0 = 0;
				f1164 < f1165 + 64;
				f1164 += 32, f1164_p_1 += 32, f1164_p_0 += 32){
					for (y = y708, yp_0 = 0;
						y < y708 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (x, 2) (28 / 14)
						for (x1452 = x1453, x1452_p_1 = x1453_p_0, x1452_p_0 = 0;
							x1452 < x1453 + 28;
							x1452 += 14, x1452_p_1 += 14, x1452_p_0 += 14){
							// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1164, fp_2 = f1164_p_1, fp_1 = f1164_p_0, fp_0 = 0;
								f < f1164 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h498, hp_0 = 0;
									h < h498 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1452, xp_2 = x1452_p_1, xp_1 = x1452_p_0, xp_0 = 0;
										x < x1452 + 14;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10120 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10121 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10122 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10123 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
													c < c1170 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10120);
													mem_vec_10120 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10121);
													mem_vec_10121 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10122);
													mem_vec_10122 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10123);
													mem_vec_10123 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10124);
													mem_vec_10124 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10125);
													mem_vec_10125 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10126);
													mem_vec_10126 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10127);
													mem_vec_10127 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10128);
													mem_vec_10128 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10129);
													mem_vec_10129 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10130);
													mem_vec_10130 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10131);
													mem_vec_10131 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10132);
													mem_vec_10132 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10133);
													mem_vec_10133 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10134);
													mem_vec_10134 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10135);
													mem_vec_10135 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10136);
													mem_vec_10136 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10137);
													mem_vec_10137 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10138);
													mem_vec_10138 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10139);
													mem_vec_10139 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10120);
													mem_vec_10120 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10121);
													mem_vec_10121 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10122);
													mem_vec_10122 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10123);
													mem_vec_10123 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10124);
													mem_vec_10124 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10125);
													mem_vec_10125 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10126);
													mem_vec_10126 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10127);
													mem_vec_10127 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10128);
													mem_vec_10128 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10129);
													mem_vec_10129 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10130);
													mem_vec_10130 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10131);
													mem_vec_10131 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10132);
													mem_vec_10132 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10133);
													mem_vec_10133 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10134);
													mem_vec_10134 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10135);
													mem_vec_10135 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10136);
													mem_vec_10136 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10137);
													mem_vec_10137 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10138);
													mem_vec_10138 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10139);
													mem_vec_10139 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10120);
													mem_vec_10120 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10121);
													mem_vec_10121 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10122);
													mem_vec_10122 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10123);
													mem_vec_10123 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10124);
													mem_vec_10124 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10125);
													mem_vec_10125 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10126);
													mem_vec_10126 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10127);
													mem_vec_10127 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10128);
													mem_vec_10128 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10129);
													mem_vec_10129 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10130);
													mem_vec_10130 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10131);
													mem_vec_10131 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10132);
													mem_vec_10132 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10133);
													mem_vec_10133 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10134);
													mem_vec_10134 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10135);
													mem_vec_10135 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10136);
													mem_vec_10136 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10137);
													mem_vec_10137 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10138);
													mem_vec_10138 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10139);
													mem_vec_10139 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10120);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10121);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10122);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10123);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10124);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10125);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10126);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10127);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10128);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10129);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10130);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10131);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10135);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10139);
									}
								}
							}
						}
					}
					for (y = y708 + 10, yp_0 = 0;
						y < y708 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (x, 2) (28 / 14)
						for (x1452 = x1453, x1452_p_1 = x1453_p_0, x1452_p_0 = 0;
							x1452 < x1453 + 28;
							x1452 += 14, x1452_p_1 += 14, x1452_p_0 += 14){
							// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1164, fp_2 = f1164_p_1, fp_1 = f1164_p_0, fp_0 = 0;
								f < f1164 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h498, hp_0 = 0;
									h < h498 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1452, xp_2 = x1452_p_1, xp_1 = x1452_p_0, xp_0 = 0;
										x < x1452 + 14;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10140 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10141 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10142 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10143 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
													c < c1170 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10140);
													mem_vec_10140 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10141);
													mem_vec_10141 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10142);
													mem_vec_10142 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10143);
													mem_vec_10143 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10144);
													mem_vec_10144 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10145);
													mem_vec_10145 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10146);
													mem_vec_10146 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10147);
													mem_vec_10147 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10148);
													mem_vec_10148 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10149);
													mem_vec_10149 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10150);
													mem_vec_10150 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10151);
													mem_vec_10151 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10152);
													mem_vec_10152 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10153);
													mem_vec_10153 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10154);
													mem_vec_10154 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10155);
													mem_vec_10155 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10156);
													mem_vec_10156 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10157);
													mem_vec_10157 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10158);
													mem_vec_10158 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10159);
													mem_vec_10159 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10160);
													mem_vec_10160 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10161);
													mem_vec_10161 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10162);
													mem_vec_10162 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10163);
													mem_vec_10163 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10140);
													mem_vec_10140 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10141);
													mem_vec_10141 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10142);
													mem_vec_10142 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10143);
													mem_vec_10143 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10144);
													mem_vec_10144 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10145);
													mem_vec_10145 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10146);
													mem_vec_10146 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10147);
													mem_vec_10147 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10148);
													mem_vec_10148 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10149);
													mem_vec_10149 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10150);
													mem_vec_10150 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10151);
													mem_vec_10151 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10152);
													mem_vec_10152 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10153);
													mem_vec_10153 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10154);
													mem_vec_10154 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10155);
													mem_vec_10155 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10156);
													mem_vec_10156 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10157);
													mem_vec_10157 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10158);
													mem_vec_10158 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10159);
													mem_vec_10159 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10160);
													mem_vec_10160 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10161);
													mem_vec_10161 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10162);
													mem_vec_10162 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10163);
													mem_vec_10163 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10140);
													mem_vec_10140 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10141);
													mem_vec_10141 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10142);
													mem_vec_10142 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10143);
													mem_vec_10143 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10144);
													mem_vec_10144 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10145);
													mem_vec_10145 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10146);
													mem_vec_10146 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10147);
													mem_vec_10147 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10148);
													mem_vec_10148 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10149);
													mem_vec_10149 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10150);
													mem_vec_10150 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10151);
													mem_vec_10151 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10152);
													mem_vec_10152 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10153);
													mem_vec_10153 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10154);
													mem_vec_10154 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10155);
													mem_vec_10155 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10156);
													mem_vec_10156 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10157);
													mem_vec_10157 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10158);
													mem_vec_10158 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10159);
													mem_vec_10159 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10160);
													mem_vec_10160 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10161);
													mem_vec_10161 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10162);
													mem_vec_10162 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10163);
													mem_vec_10163 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10143);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10144);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10145);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10146);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10147);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10148);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10149);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10150);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10151);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10152);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10153);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10154);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10155);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10156);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10157);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10158);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10159);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10163);
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