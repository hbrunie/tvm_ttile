#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, f); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (128, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1042_p_0, cp_1, c1042, f, fp_0, f1034_p_0, f1035_p_0, fp_1, f1034_p_1, fp_2, f1034, f1035, w, wp_0, x, xp_0, x1222_p_0, x1223_p_0, xp_1, x1222_p_1, xp_2, x1222, x1223, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y620 = 0;
IND_TYPE x1224 = 0;
IND_TYPE h = 0;
IND_TYPE w506 = 0;
IND_TYPE c1043 = 0;
IND_TYPE f1036 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8188 ,mem_vec_8189 ,mem_vec_8190 ,mem_vec_8191 ,mem_vec_8192 ,mem_vec_8193 ,mem_vec_8194 ,mem_vec_8195 ,mem_vec_8196 ,mem_vec_8197 ,mem_vec_8198 ,mem_vec_8199 ,mem_vec_8200 ,mem_vec_8201 ,mem_vec_8202 ,mem_vec_8203 ,mem_vec_8204 ,mem_vec_8205 ,mem_vec_8206 ,mem_vec_8207 ,mem_vec_8208 ,mem_vec_8209 ,mem_vec_8210 ,mem_vec_8211 ,mem_vec_8212 ,mem_vec_8213 ,mem_vec_8214 ,mem_vec_8215 ,mem_vec_8216 ,mem_vec_8217 ,mem_vec_8218 ,mem_vec_8219 ,mem_vec_8220 ,mem_vec_8221 ,mem_vec_8222 ,mem_vec_8223 ,mem_vec_8224 ,mem_vec_8225 ,mem_vec_8226 ,mem_vec_8227 ,mem_vec_8228 ,mem_vec_8229 ,mem_vec_8230 ,mem_vec_8231 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1035 = f1036, f1035_p_0 = 0;
	f1035 < f1036 + 256;
	f1035 += 128, f1035_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (x, 1) (28 / 28)
	for (x1223 = x1224, x1223_p_0 = 0;
		x1223 < x1224 + 28;
		x1223 += 28, x1223_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (c, 128) (128 / 1)
		for (c1042 = c1043, c1042_p_0 = 0;
			c1042 < c1043 + 128;
			c1042 += 1, c1042_p_0 += 1){
			// y = 28, x = 28, h = 3, w = 3, c = 1, f = 128
			// T (f, 4) (128 / 32)
			for (f1034 = f1035, f1034_p_1 = f1035_p_0, f1034_p_0 = 0;
				f1034 < f1035 + 128;
				f1034 += 32, f1034_p_1 += 32, f1034_p_0 += 32){
					for (y = y620, yp_0 = 0;
						y < y620 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (x, 28) (28 / 1)
						for (x1222 = x1223, x1222_p_1 = x1223_p_0, x1222_p_0 = 0;
							x1222 < x1223 + 28;
							x1222 += 1, x1222_p_1 += 1, x1222_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1034, fp_2 = f1034_p_1, fp_1 = f1034_p_0, fp_0 = 0;
								f < f1034 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w506, wp_0 = 0;
									w < w506 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1222, xp_2 = x1222_p_1, xp_1 = x1222_p_0, xp_0 = 0;
										x < x1222 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8188 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8189 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8190 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8191 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1042, cp_1 = c1042_p_0, cp_0 = 0;
													c < c1042 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8188);
													mem_vec_8188 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8189);
													mem_vec_8189 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8190);
													mem_vec_8190 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8191);
													mem_vec_8191 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8192);
													mem_vec_8192 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8193);
													mem_vec_8193 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8194);
													mem_vec_8194 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8195);
													mem_vec_8195 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8196);
													mem_vec_8196 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8197);
													mem_vec_8197 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8198);
													mem_vec_8198 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8199);
													mem_vec_8199 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8200);
													mem_vec_8200 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8201);
													mem_vec_8201 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8202);
													mem_vec_8202 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8203);
													mem_vec_8203 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8204);
													mem_vec_8204 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8205);
													mem_vec_8205 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8206);
													mem_vec_8206 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8207);
													mem_vec_8207 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8188);
													mem_vec_8188 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8189);
													mem_vec_8189 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_8190);
													mem_vec_8190 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_8191);
													mem_vec_8191 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_8192);
													mem_vec_8192 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_8193);
													mem_vec_8193 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_8194);
													mem_vec_8194 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_8195);
													mem_vec_8195 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8196);
													mem_vec_8196 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8197);
													mem_vec_8197 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_8198);
													mem_vec_8198 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8199);
													mem_vec_8199 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_8200);
													mem_vec_8200 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_8201);
													mem_vec_8201 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_8202);
													mem_vec_8202 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_8203);
													mem_vec_8203 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_8204);
													mem_vec_8204 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_8205);
													mem_vec_8205 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_8206);
													mem_vec_8206 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_8207);
													mem_vec_8207 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8188);
													mem_vec_8188 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8189);
													mem_vec_8189 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_8190);
													mem_vec_8190 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_8191);
													mem_vec_8191 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_8192);
													mem_vec_8192 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_8193);
													mem_vec_8193 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_8194);
													mem_vec_8194 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_8195);
													mem_vec_8195 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8196);
													mem_vec_8196 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8197);
													mem_vec_8197 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_8198);
													mem_vec_8198 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8199);
													mem_vec_8199 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_8200);
													mem_vec_8200 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_8201);
													mem_vec_8201 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_8202);
													mem_vec_8202 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_8203);
													mem_vec_8203 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_8204);
													mem_vec_8204 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_8205);
													mem_vec_8205 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_8206);
													mem_vec_8206 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_8207);
													mem_vec_8207 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8188);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8189);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8190);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8191);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8192);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8193);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8194);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8195);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8196);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8197);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8198);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8199);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8200);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8201);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8202);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8203);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8204);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8205);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8206);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8207);
									}
								}
							}
						}
					}
					for (y = y620 + 10, yp_0 = 0;
						y < y620 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 32
						// T (x, 28) (28 / 1)
						for (x1222 = x1223, x1222_p_1 = x1223_p_0, x1222_p_0 = 0;
							x1222 < x1223 + 28;
							x1222 += 1, x1222_p_1 += 1, x1222_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1034, fp_2 = f1034_p_1, fp_1 = f1034_p_0, fp_0 = 0;
								f < f1034 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w506, wp_0 = 0;
									w < w506 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1222, xp_2 = x1222_p_1, xp_1 = x1222_p_0, xp_0 = 0;
										x < x1222 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8208 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8209 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8210 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8211 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_8228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1042, cp_1 = c1042_p_0, cp_0 = 0;
													c < c1042 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8208);
													mem_vec_8208 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8209);
													mem_vec_8209 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8210);
													mem_vec_8210 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8211);
													mem_vec_8211 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8212);
													mem_vec_8212 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8213);
													mem_vec_8213 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8214);
													mem_vec_8214 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8215);
													mem_vec_8215 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8216);
													mem_vec_8216 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8217);
													mem_vec_8217 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8218);
													mem_vec_8218 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8219);
													mem_vec_8219 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8220);
													mem_vec_8220 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8221);
													mem_vec_8221 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8222);
													mem_vec_8222 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8223);
													mem_vec_8223 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8224);
													mem_vec_8224 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8225);
													mem_vec_8225 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8226);
													mem_vec_8226 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8227);
													mem_vec_8227 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8228);
													mem_vec_8228 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8229);
													mem_vec_8229 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8230);
													mem_vec_8230 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8231);
													mem_vec_8231 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_8208);
													mem_vec_8208 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_8209);
													mem_vec_8209 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_8210);
													mem_vec_8210 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_8211);
													mem_vec_8211 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8212);
													mem_vec_8212 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_8213);
													mem_vec_8213 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8214);
													mem_vec_8214 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8215);
													mem_vec_8215 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_8216);
													mem_vec_8216 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_8217);
													mem_vec_8217 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_8218);
													mem_vec_8218 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_8219);
													mem_vec_8219 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_8220);
													mem_vec_8220 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_8221);
													mem_vec_8221 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_8222);
													mem_vec_8222 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_8223);
													mem_vec_8223 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8224);
													mem_vec_8224 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_8225);
													mem_vec_8225 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8226);
													mem_vec_8226 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8227);
													mem_vec_8227 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_8228);
													mem_vec_8228 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_8229);
													mem_vec_8229 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_8230);
													mem_vec_8230 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_8231);
													mem_vec_8231 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_8208);
													mem_vec_8208 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_8209);
													mem_vec_8209 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_8210);
													mem_vec_8210 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_8211);
													mem_vec_8211 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_8212);
													mem_vec_8212 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_8213);
													mem_vec_8213 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_8214);
													mem_vec_8214 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_8215);
													mem_vec_8215 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_8216);
													mem_vec_8216 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_8217);
													mem_vec_8217 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_8218);
													mem_vec_8218 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_8219);
													mem_vec_8219 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_8220);
													mem_vec_8220 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8221);
													mem_vec_8221 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8222);
													mem_vec_8222 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8223);
													mem_vec_8223 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_8224);
													mem_vec_8224 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_8225);
													mem_vec_8225 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_8226);
													mem_vec_8226 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_8227);
													mem_vec_8227 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_8228);
													mem_vec_8228 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_8229);
													mem_vec_8229 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_8230);
													mem_vec_8230 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_8231);
													mem_vec_8231 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8208);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8209);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8210);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8211);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8212);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8213);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8214);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8215);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8216);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8217);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8218);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8219);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8220);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8221);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8222);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8223);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8224);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8225);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8226);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8227);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8228);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8229);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8230);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8231);
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