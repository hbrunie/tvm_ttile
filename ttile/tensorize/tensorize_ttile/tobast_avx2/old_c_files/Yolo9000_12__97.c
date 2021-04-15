#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (256, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1286_p_0, cp_1, c1286, f, fp_0, f744_p_0, f745_p_0, fp_1, f744_p_1, fp_2, f744, f745, w, wp_0, x, xp_0, x1160_p_0, x1161_p_0, xp_1, x1160_p_1, xp_2, x1160, x1161, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y580 = 0;
IND_TYPE x1162 = 0;
IND_TYPE h = 0;
IND_TYPE w580 = 0;
IND_TYPE c1287 = 0;
IND_TYPE f746 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12200 ,mem_vec_12201 ,mem_vec_12202 ,mem_vec_12203 ,mem_vec_12204 ,mem_vec_12205 ,mem_vec_12206 ,mem_vec_12207 ,mem_vec_12208 ,mem_vec_12209 ,mem_vec_12210 ,mem_vec_12211 ,mem_vec_12212 ,mem_vec_12213 ,mem_vec_12214 ,mem_vec_12215 ,mem_vec_12216 ,mem_vec_12217 ,mem_vec_12218 ,mem_vec_12219 ,mem_vec_12220 ,mem_vec_12221 ,mem_vec_12222 ,mem_vec_12223 ,mem_vec_12224 ,mem_vec_12225 ,mem_vec_12226 ,mem_vec_12227 ,mem_vec_12228 ,mem_vec_12229 ,mem_vec_12230 ,mem_vec_12231 ,mem_vec_12232 ,mem_vec_12233 ,mem_vec_12234 ,mem_vec_12235 ,mem_vec_12236 ,mem_vec_12237 ,mem_vec_12238 ,mem_vec_12239 ,mem_vec_12240 ,mem_vec_12241 ,mem_vec_12242 ,mem_vec_12243 ,mem_vec_12244 ,mem_vec_12245 ,mem_vec_12246 ,mem_vec_12247 ,mem_vec_12248 ,mem_vec_12249 ,mem_vec_12250 ,mem_vec_12251 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f745 = f746, f745_p_0 = 0;
	f745 < f746 + 512;
	f745 += 128, f745_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (x, 1) (34 / 34)
	for (x1161 = x1162, x1161_p_0 = 0;
		x1161 < x1162 + 34;
		x1161 += 34, x1161_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (c, 256) (256 / 1)
		for (c1286 = c1287, c1286_p_0 = 0;
			c1286 < c1287 + 256;
			c1286 += 1, c1286_p_0 += 1){
			// y = 34, x = 34, h = 3, w = 3, c = 1, f = 128
			// T (f, 2) (128 / 64)
			for (f744 = f745, f744_p_1 = f745_p_0, f744_p_0 = 0;
				f744 < f745 + 128;
				f744 += 64, f744_p_1 += 64, f744_p_0 += 64){
					for (y = y580, yp_0 = 0;
						y < y580 + 6;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
						// T (x, 34) (34 / 1)
						for (x1160 = x1161, x1160_p_1 = x1161_p_0, x1160_p_0 = 0;
							x1160 < x1161 + 34;
							x1160 += 1, x1160_p_1 += 1, x1160_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f744, fp_2 = f744_p_1, fp_1 = f744_p_0, fp_0 = 0;
								f < f744 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w580, wp_0 = 0;
									w < w580 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1160, xp_2 = x1160_p_1, xp_1 = x1160_p_0, xp_0 = 0;
										x < x1160 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12200 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12201 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12202 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12203 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12210 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12211 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_12220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_12222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1286, cp_1 = c1286_p_0, cp_0 = 0;
													c < c1286 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12200);
													mem_vec_12200 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12201);
													mem_vec_12201 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12202);
													mem_vec_12202 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12203);
													mem_vec_12203 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12204);
													mem_vec_12204 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12205);
													mem_vec_12205 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12206);
													mem_vec_12206 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12207);
													mem_vec_12207 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12208);
													mem_vec_12208 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12209);
													mem_vec_12209 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12210);
													mem_vec_12210 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12211);
													mem_vec_12211 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12212);
													mem_vec_12212 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12213);
													mem_vec_12213 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12214);
													mem_vec_12214 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12215);
													mem_vec_12215 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12216);
													mem_vec_12216 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12217);
													mem_vec_12217 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12218);
													mem_vec_12218 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12219);
													mem_vec_12219 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12220);
													mem_vec_12220 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12221);
													mem_vec_12221 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12222);
													mem_vec_12222 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12223);
													mem_vec_12223 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_12200);
													mem_vec_12200 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_12201);
													mem_vec_12201 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_12202);
													mem_vec_12202 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_12203);
													mem_vec_12203 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_12204);
													mem_vec_12204 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_12205);
													mem_vec_12205 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_12206);
													mem_vec_12206 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_12207);
													mem_vec_12207 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_12208);
													mem_vec_12208 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_12209);
													mem_vec_12209 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_12210);
													mem_vec_12210 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_12211);
													mem_vec_12211 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_12212);
													mem_vec_12212 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_12213);
													mem_vec_12213 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_12214);
													mem_vec_12214 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_12215);
													mem_vec_12215 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_12216);
													mem_vec_12216 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_12217);
													mem_vec_12217 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_12218);
													mem_vec_12218 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_12219);
													mem_vec_12219 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_12220);
													mem_vec_12220 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_12221);
													mem_vec_12221 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_12222);
													mem_vec_12222 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_12223);
													mem_vec_12223 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_12200);
													mem_vec_12200 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_12201);
													mem_vec_12201 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_12202);
													mem_vec_12202 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_12203);
													mem_vec_12203 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_12204);
													mem_vec_12204 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_12205);
													mem_vec_12205 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_12206);
													mem_vec_12206 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_12207);
													mem_vec_12207 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_12208);
													mem_vec_12208 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_12209);
													mem_vec_12209 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_12210);
													mem_vec_12210 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_12211);
													mem_vec_12211 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_12212);
													mem_vec_12212 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_12213);
													mem_vec_12213 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_12214);
													mem_vec_12214 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_12215);
													mem_vec_12215 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_12216);
													mem_vec_12216 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_12217);
													mem_vec_12217 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_12218);
													mem_vec_12218 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_12219);
													mem_vec_12219 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_12220);
													mem_vec_12220 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_12221);
													mem_vec_12221 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_12222);
													mem_vec_12222 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_12223);
													mem_vec_12223 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12200);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12201);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12202);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12203);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12204);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12205);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12206);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12207);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12208);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12209);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12210);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12211);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12212);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12213);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12214);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12215);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12216);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12217);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12218);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12219);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12220);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12221);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12222);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12223);
									}
								}
							}
						}
					}
					for (y = y580 + 6, yp_0 = 0;
						y < y580 + 6 + 28;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
						// T (x, 34) (34 / 1)
						for (x1160 = x1161, x1160_p_1 = x1161_p_0, x1160_p_0 = 0;
							x1160 < x1161 + 34;
							x1160 += 1, x1160_p_1 += 1, x1160_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f744, fp_2 = f744_p_1, fp_1 = f744_p_0, fp_0 = 0;
								f < f744 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w580, wp_0 = 0;
									w < w580 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1160, xp_2 = x1160_p_1, xp_1 = x1160_p_0, xp_0 = 0;
										x < x1160 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_12244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_12246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_12248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_12250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1286, cp_1 = c1286_p_0, cp_0 = 0;
													c < c1286 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12224);
													mem_vec_12224 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12225);
													mem_vec_12225 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12226);
													mem_vec_12226 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12227);
													mem_vec_12227 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12228);
													mem_vec_12228 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12229);
													mem_vec_12229 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12230);
													mem_vec_12230 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12231);
													mem_vec_12231 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12232);
													mem_vec_12232 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12233);
													mem_vec_12233 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12234);
													mem_vec_12234 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12235);
													mem_vec_12235 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12236);
													mem_vec_12236 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12237);
													mem_vec_12237 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12238);
													mem_vec_12238 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12239);
													mem_vec_12239 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12240);
													mem_vec_12240 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12241);
													mem_vec_12241 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12242);
													mem_vec_12242 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12243);
													mem_vec_12243 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12244);
													mem_vec_12244 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12245);
													mem_vec_12245 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12246);
													mem_vec_12246 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12247);
													mem_vec_12247 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_12248);
													mem_vec_12248 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_12249);
													mem_vec_12249 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_12250);
													mem_vec_12250 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_12251);
													mem_vec_12251 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_12224);
													mem_vec_12224 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_12225);
													mem_vec_12225 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_12226);
													mem_vec_12226 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_12227);
													mem_vec_12227 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_12228);
													mem_vec_12228 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_12229);
													mem_vec_12229 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_12230);
													mem_vec_12230 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_12231);
													mem_vec_12231 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_12232);
													mem_vec_12232 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_12233);
													mem_vec_12233 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_12234);
													mem_vec_12234 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_12235);
													mem_vec_12235 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_12236);
													mem_vec_12236 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_12237);
													mem_vec_12237 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_12238);
													mem_vec_12238 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_12239);
													mem_vec_12239 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_12240);
													mem_vec_12240 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_12241);
													mem_vec_12241 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_12242);
													mem_vec_12242 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_12243);
													mem_vec_12243 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_12244);
													mem_vec_12244 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_12245);
													mem_vec_12245 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_12246);
													mem_vec_12246 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_12247);
													mem_vec_12247 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_12248);
													mem_vec_12248 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_12249);
													mem_vec_12249 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_12250);
													mem_vec_12250 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_12251);
													mem_vec_12251 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_12224);
													mem_vec_12224 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_12225);
													mem_vec_12225 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_12226);
													mem_vec_12226 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_12227);
													mem_vec_12227 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_12228);
													mem_vec_12228 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_12229);
													mem_vec_12229 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_12230);
													mem_vec_12230 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_12231);
													mem_vec_12231 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_12232);
													mem_vec_12232 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_12233);
													mem_vec_12233 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_12234);
													mem_vec_12234 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_12235);
													mem_vec_12235 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_12236);
													mem_vec_12236 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_12237);
													mem_vec_12237 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_12238);
													mem_vec_12238 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_12239);
													mem_vec_12239 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_12240);
													mem_vec_12240 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_12241);
													mem_vec_12241 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_12242);
													mem_vec_12242 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_12243);
													mem_vec_12243 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_12244);
													mem_vec_12244 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_12245);
													mem_vec_12245 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_12246);
													mem_vec_12246 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_12247);
													mem_vec_12247 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_12248);
													mem_vec_12248 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_12249);
													mem_vec_12249 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_12250);
													mem_vec_12250 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_12251);
													mem_vec_12251 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12224);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12225);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12226);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12227);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12228);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12229);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12230);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12231);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12232);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12233);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12234);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12235);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12236);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12237);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12238);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12239);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12240);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12241);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12242);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12243);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12244);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12245);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12246);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12247);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12248);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_12249);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12250);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_12251);
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