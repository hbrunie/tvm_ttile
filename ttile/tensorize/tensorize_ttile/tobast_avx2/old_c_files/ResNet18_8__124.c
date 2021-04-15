#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (8, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (2, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1168_p_0, cp_1, c1168, f, fp_0, f1202_p_0, f1203_p_0, fp_1, f1202_p_1, fp_2, f1202, f1203, h, hp_0, x, xp_0, x1390_p_0, x1391_p_0, xp_1, x1390_p_1, xp_2, x1390, x1391, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y704 = 0;
IND_TYPE x1392 = 0;
IND_TYPE h516 = 0;
IND_TYPE w = 0;
IND_TYPE c1169 = 0;
IND_TYPE f1204 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,mem_vec_10066 ,mem_vec_10067 ,mem_vec_10068 ,mem_vec_10069 ,mem_vec_10070 ,mem_vec_10071 ,mem_vec_10072 ,mem_vec_10073 ,mem_vec_10074 ,mem_vec_10075 ,mem_vec_10076 ,mem_vec_10077 ,mem_vec_10078 ,mem_vec_10079 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1203 = f1204, f1203_p_0 = 0;
	f1203 < f1204 + 256;
	f1203 += 256, f1203_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
	// T (x, 2) (28 / 14)
	for (x1391 = x1392, x1391_p_0 = 0;
		x1391 < x1392 + 28;
		x1391 += 14, x1391_p_0 += 14){
		// y = 28, x = 14, h = 3, w = 3, c = 128, f = 256
		// T (c, 2) (128 / 64)
		for (c1168 = c1169, c1168_p_0 = 0;
			c1168 < c1169 + 128;
			c1168 += 64, c1168_p_0 += 64){
			// y = 28, x = 14, h = 3, w = 3, c = 64, f = 256
			// T (f, 1) (256 / 256)
			for (f1202 = f1203, f1202_p_1 = f1203_p_0, f1202_p_0 = 0;
				f1202 < f1203 + 256;
				f1202 += 256, f1202_p_1 += 256, f1202_p_0 += 256){
					for (y = y704, yp_0 = 0;
						y < y704 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 256
						// T (x, 2) (14 / 7)
						for (x1390 = x1391, x1390_p_1 = x1391_p_0, x1390_p_0 = 0;
							x1390 < x1391 + 14;
							x1390 += 7, x1390_p_1 += 7, x1390_p_0 += 7){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1202, fp_2 = f1202_p_1, fp_1 = f1202_p_0, fp_0 = 0;
								f < f1202 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h516, hp_0 = 0;
									h < h516 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1390, xp_2 = x1390_p_1, xp_1 = x1390_p_0, xp_0 = 0;
										x < x1390 + 7;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10036 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10037 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10038 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10039 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c1168, cp_1 = c1168_p_0, cp_0 = 0;
													c < c1168 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10036);
													mem_vec_10036 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10037);
													mem_vec_10037 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10038);
													mem_vec_10038 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10039);
													mem_vec_10039 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10040);
													mem_vec_10040 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10041);
													mem_vec_10041 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10042);
													mem_vec_10042 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10043);
													mem_vec_10043 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10044);
													mem_vec_10044 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10045);
													mem_vec_10045 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10046);
													mem_vec_10046 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10047);
													mem_vec_10047 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10048);
													mem_vec_10048 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10049);
													mem_vec_10049 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10050);
													mem_vec_10050 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10051);
													mem_vec_10051 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10052);
													mem_vec_10052 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10053);
													mem_vec_10053 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10054);
													mem_vec_10054 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10055);
													mem_vec_10055 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10036);
													mem_vec_10036 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10037);
													mem_vec_10037 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10038);
													mem_vec_10038 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10039);
													mem_vec_10039 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10040);
													mem_vec_10040 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10041);
													mem_vec_10041 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10042);
													mem_vec_10042 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10043);
													mem_vec_10043 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10044);
													mem_vec_10044 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10045);
													mem_vec_10045 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10046);
													mem_vec_10046 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10047);
													mem_vec_10047 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10048);
													mem_vec_10048 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10049);
													mem_vec_10049 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10050);
													mem_vec_10050 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10051);
													mem_vec_10051 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10052);
													mem_vec_10052 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10053);
													mem_vec_10053 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10054);
													mem_vec_10054 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10055);
													mem_vec_10055 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10036);
													mem_vec_10036 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10037);
													mem_vec_10037 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10038);
													mem_vec_10038 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10039);
													mem_vec_10039 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10040);
													mem_vec_10040 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10041);
													mem_vec_10041 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10042);
													mem_vec_10042 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10043);
													mem_vec_10043 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10044);
													mem_vec_10044 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10045);
													mem_vec_10045 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10046);
													mem_vec_10046 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10047);
													mem_vec_10047 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10048);
													mem_vec_10048 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10049);
													mem_vec_10049 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10050);
													mem_vec_10050 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10051);
													mem_vec_10051 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10052);
													mem_vec_10052 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10053);
													mem_vec_10053 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10054);
													mem_vec_10054 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10055);
													mem_vec_10055 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10036);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10037);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10038);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10039);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10040);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10041);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10042);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10043);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10044);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10045);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10046);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10047);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10048);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10049);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10050);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10051);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10052);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10053);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10054);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10055);
									}
								}
							}
						}
					}
					for (y = y704 + 10, yp_0 = 0;
						y < y704 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 256
						// T (x, 2) (14 / 7)
						for (x1390 = x1391, x1390_p_1 = x1391_p_0, x1390_p_0 = 0;
							x1390 < x1391 + 14;
							x1390 += 7, x1390_p_1 += 7, x1390_p_0 += 7){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1202, fp_2 = f1202_p_1, fp_1 = f1202_p_0, fp_0 = 0;
								f < f1202 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h516, hp_0 = 0;
									h < h516 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1390, xp_2 = x1390_p_1, xp_1 = x1390_p_0, xp_0 = 0;
										x < x1390 + 7;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10056 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10057 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10058 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10059 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c1168, cp_1 = c1168_p_0, cp_0 = 0;
													c < c1168 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10056);
													mem_vec_10056 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10057);
													mem_vec_10057 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10058);
													mem_vec_10058 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10059);
													mem_vec_10059 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10060);
													mem_vec_10060 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10061);
													mem_vec_10061 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10062);
													mem_vec_10062 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10063);
													mem_vec_10063 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10064);
													mem_vec_10064 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10065);
													mem_vec_10065 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10066);
													mem_vec_10066 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10067);
													mem_vec_10067 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10068);
													mem_vec_10068 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10069);
													mem_vec_10069 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10070);
													mem_vec_10070 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10071);
													mem_vec_10071 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10072);
													mem_vec_10072 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10073);
													mem_vec_10073 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10074);
													mem_vec_10074 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10075);
													mem_vec_10075 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10076);
													mem_vec_10076 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10077);
													mem_vec_10077 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10078);
													mem_vec_10078 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10079);
													mem_vec_10079 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10056);
													mem_vec_10056 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10057);
													mem_vec_10057 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10058);
													mem_vec_10058 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10059);
													mem_vec_10059 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10060);
													mem_vec_10060 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10061);
													mem_vec_10061 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10062);
													mem_vec_10062 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10063);
													mem_vec_10063 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10064);
													mem_vec_10064 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10065);
													mem_vec_10065 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10066);
													mem_vec_10066 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10067);
													mem_vec_10067 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10068);
													mem_vec_10068 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10069);
													mem_vec_10069 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10070);
													mem_vec_10070 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10071);
													mem_vec_10071 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10072);
													mem_vec_10072 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10073);
													mem_vec_10073 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10074);
													mem_vec_10074 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10075);
													mem_vec_10075 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10076);
													mem_vec_10076 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10077);
													mem_vec_10077 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10078);
													mem_vec_10078 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10079);
													mem_vec_10079 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10056);
													mem_vec_10056 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10057);
													mem_vec_10057 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10058);
													mem_vec_10058 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10059);
													mem_vec_10059 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10060);
													mem_vec_10060 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10061);
													mem_vec_10061 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10062);
													mem_vec_10062 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10063);
													mem_vec_10063 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10064);
													mem_vec_10064 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10065);
													mem_vec_10065 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10066);
													mem_vec_10066 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10067);
													mem_vec_10067 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10068);
													mem_vec_10068 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10069);
													mem_vec_10069 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10070);
													mem_vec_10070 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10071);
													mem_vec_10071 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10072);
													mem_vec_10072 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10073);
													mem_vec_10073 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10074);
													mem_vec_10074 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10075);
													mem_vec_10075 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10076);
													mem_vec_10076 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10077);
													mem_vec_10077 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10078);
													mem_vec_10078 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10079);
													mem_vec_10079 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10056);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10057);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10058);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10059);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10060);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10061);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10062);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10063);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10064);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10065);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10066);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10067);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10068);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10069);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10070);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10071);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10072);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10073);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10074);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10075);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10076);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10077);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10078);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10079);
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