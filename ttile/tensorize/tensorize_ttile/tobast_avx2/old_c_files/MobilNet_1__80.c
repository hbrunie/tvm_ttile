#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (8, x);
  T (3, w); Lambda_apply y [((Iter 9), (Arg 10)); ((Iter 2), (Arg 11))];
  T (2, f); T (2, c); T (14, x)]
*/
IND_TYPE c, cp_0, c1050_p_0, cp_1, c1050, f, fp_0, w, wp_0, x, xp_0, x1296_p_0, xp_1, x1296, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y700 = 0;
IND_TYPE x1297 = 0;
IND_TYPE h = 0;
IND_TYPE w586 = 0;
IND_TYPE c1051 = 0;
IND_TYPE f442 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8940 ,mem_vec_8941 ,mem_vec_8942 ,mem_vec_8943 ,mem_vec_8944 ,mem_vec_8945 ,mem_vec_8946 ,mem_vec_8947 ,mem_vec_8948 ,mem_vec_8949 ,mem_vec_8950 ,mem_vec_8951 ,mem_vec_8952 ,mem_vec_8953 ,mem_vec_8954 ,mem_vec_8955 ,mem_vec_8956 ,mem_vec_8957 ,mem_vec_8958 ,mem_vec_8959 ,mem_vec_8960 ,mem_vec_8961 ,mem_vec_8962 ,mem_vec_8963 ,mem_vec_8964 ,mem_vec_8965 ,mem_vec_8966 ,mem_vec_8967 ,mem_vec_8968 ,mem_vec_8969 ,mem_vec_8970 ,mem_vec_8971 ,mem_vec_8972 ,mem_vec_8973 ,mem_vec_8974 ,mem_vec_8975 ,mem_vec_8976 ,mem_vec_8977 ,mem_vec_8978 ,mem_vec_8979 ,mem_vec_8980 ,mem_vec_8981 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 14) (112 / 8)
for (x1296 = x1297, x1296_p_0 = 0;
	x1296 < x1297 + 112;
	x1296 += 8, x1296_p_0 += 8){
	// y = 112, x = 8, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c1050 = c1051, c1050_p_0 = 0;
		c1050 < c1051 + 32;
		c1050 += 16, c1050_p_0 += 16){
		// y = 112, x = 8, h = 3, w = 3, c = 16, f = 32
		// T (f, 2) (32 / 16)
		for (f = f442, fp_0 = 0;
			f < f442 + 32;
			f += 16, fp_0 += 16){
				for (y = y700, yp_0 = 0;
					y < y700 + 90;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 16
					// T (w, 3) (3 / 1)
					for (w = w586, wp_0 = 0;
						w < w586 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 16
						// T (x, 8) (8 / 1)
						for (x = x1296, xp_1 = x1296_p_0, xp_0 = 0;
							x < x1296 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8940 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8941 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_8942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_8944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_8946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_8948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_8950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_8952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_8954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									mem_vec_8956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
									mem_vec_8958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
										c < c1050 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8940);
										mem_vec_8940 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8941);
										mem_vec_8941 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm256_set1_ps(scal_1);


										vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8942);
										mem_vec_8942 = vec_5;



										vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8943);
										mem_vec_8943 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm256_set1_ps(scal_2);


										vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8944);
										mem_vec_8944 = vec_8;



										vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8945);
										mem_vec_8945 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm256_set1_ps(scal_3);


										vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8946);
										mem_vec_8946 = vec_11;



										vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8947);
										mem_vec_8947 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm256_set1_ps(scal_4);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8948);
										mem_vec_8948 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8949);
										mem_vec_8949 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm256_set1_ps(scal_5);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8950);
										mem_vec_8950 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8951);
										mem_vec_8951 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm256_set1_ps(scal_6);


										vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8952);
										mem_vec_8952 = vec_20;



										vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8953);
										mem_vec_8953 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm256_set1_ps(scal_7);


										vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8954);
										mem_vec_8954 = vec_23;



										vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8955);
										mem_vec_8955 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm256_set1_ps(scal_8);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8956);
										mem_vec_8956 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8957);
										mem_vec_8957 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm256_set1_ps(scal_9);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8958);
										mem_vec_8958 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8959);
										mem_vec_8959 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_33 = _mm256_set1_ps(scal_10);
										vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_8940);
										mem_vec_8940 = vec_32;

										vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_8941);
										mem_vec_8941 = vec_35;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_38 = _mm256_set1_ps(scal_11);


										vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_8942);
										mem_vec_8942 = vec_37;



										vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_8943);
										mem_vec_8943 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_41 = _mm256_set1_ps(scal_12);


										vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_8944);
										mem_vec_8944 = vec_40;



										vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_8945);
										mem_vec_8945 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_13);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_8946);
										mem_vec_8946 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8947);
										mem_vec_8947 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_47 = _mm256_set1_ps(scal_14);


										vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_8948);
										mem_vec_8948 = vec_46;



										vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_8949);
										mem_vec_8949 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_50 = _mm256_set1_ps(scal_15);


										vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_8950);
										mem_vec_8950 = vec_49;



										vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_8951);
										mem_vec_8951 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_53 = _mm256_set1_ps(scal_16);


										vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_8952);
										mem_vec_8952 = vec_52;



										vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_8953);
										mem_vec_8953 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_56 = _mm256_set1_ps(scal_17);


										vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_8954);
										mem_vec_8954 = vec_55;



										vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_8955);
										mem_vec_8955 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_59 = _mm256_set1_ps(scal_18);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_8956);
										mem_vec_8956 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8957);
										mem_vec_8957 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_62 = _mm256_set1_ps(scal_19);


										vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_8958);
										mem_vec_8958 = vec_61;



										vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_8959);
										mem_vec_8959 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_65 = _mm256_set1_ps(scal_20);
										vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_8940);
										mem_vec_8940 = vec_64;

										vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_8941);
										mem_vec_8941 = vec_67;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_70 = _mm256_set1_ps(scal_21);


										vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_8942);
										mem_vec_8942 = vec_69;



										vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_8943);
										mem_vec_8943 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_73 = _mm256_set1_ps(scal_22);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8944);
										mem_vec_8944 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_8945);
										mem_vec_8945 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_76 = _mm256_set1_ps(scal_23);


										vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_8946);
										mem_vec_8946 = vec_75;



										vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_8947);
										mem_vec_8947 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_79 = _mm256_set1_ps(scal_24);


										vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_8948);
										mem_vec_8948 = vec_78;



										vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_8949);
										mem_vec_8949 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_82 = _mm256_set1_ps(scal_25);


										vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_8950);
										mem_vec_8950 = vec_81;



										vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_8951);
										mem_vec_8951 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_85 = _mm256_set1_ps(scal_26);


										vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_8952);
										mem_vec_8952 = vec_84;



										vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_8953);
										mem_vec_8953 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_88 = _mm256_set1_ps(scal_27);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_8954);
										mem_vec_8954 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_8955);
										mem_vec_8955 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_91 = _mm256_set1_ps(scal_28);


										vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_8956);
										mem_vec_8956 = vec_90;



										vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_8957);
										mem_vec_8957 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_94 = _mm256_set1_ps(scal_29);


										vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_8958);
										mem_vec_8958 = vec_93;



										vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_8959);
										mem_vec_8959 = vec_95;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8940);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8941);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8942);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8943);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8944);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8945);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8946);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8947);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8948);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8949);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8950);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8951);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8952);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8953);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8954);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8955);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8956);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8957);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8958);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8959);
						}
					}
				}
				for (y = y700 + 90, yp_0 = 0;
					y < y700 + 90 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 16
					// T (w, 3) (3 / 1)
					for (w = w586, wp_0 = 0;
						w < w586 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 16
						// T (x, 8) (8 / 1)
						for (x = x1296, xp_1 = x1296_p_0, xp_0 = 0;
							x < x1296 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8960 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8961 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_8962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_8964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_8966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_8968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_8970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_8972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_8974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									mem_vec_8976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
									mem_vec_8978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
									mem_vec_8980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_8981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
										c < c1050 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8960);
										mem_vec_8960 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8961);
										mem_vec_8961 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm256_set1_ps(scal_1);


										vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8962);
										mem_vec_8962 = vec_5;



										vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8963);
										mem_vec_8963 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm256_set1_ps(scal_2);


										vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8964);
										mem_vec_8964 = vec_8;



										vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8965);
										mem_vec_8965 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm256_set1_ps(scal_3);


										vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8966);
										mem_vec_8966 = vec_11;



										vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8967);
										mem_vec_8967 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm256_set1_ps(scal_4);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8968);
										mem_vec_8968 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8969);
										mem_vec_8969 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm256_set1_ps(scal_5);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8970);
										mem_vec_8970 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8971);
										mem_vec_8971 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm256_set1_ps(scal_6);


										vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8972);
										mem_vec_8972 = vec_20;



										vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8973);
										mem_vec_8973 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm256_set1_ps(scal_7);


										vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8974);
										mem_vec_8974 = vec_23;



										vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8975);
										mem_vec_8975 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm256_set1_ps(scal_8);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8976);
										mem_vec_8976 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8977);
										mem_vec_8977 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm256_set1_ps(scal_9);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8978);
										mem_vec_8978 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8979);
										mem_vec_8979 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm256_set1_ps(scal_10);


										vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8980);
										mem_vec_8980 = vec_32;



										vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8981);
										mem_vec_8981 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_36 = _mm256_set1_ps(scal_11);
										vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_8960);
										mem_vec_8960 = vec_35;

										vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_8961);
										mem_vec_8961 = vec_38;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_41 = _mm256_set1_ps(scal_12);


										vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_8962);
										mem_vec_8962 = vec_40;



										vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_8963);
										mem_vec_8963 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_13);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8964);
										mem_vec_8964 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_8965);
										mem_vec_8965 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_47 = _mm256_set1_ps(scal_14);


										vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_8966);
										mem_vec_8966 = vec_46;



										vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_8967);
										mem_vec_8967 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_50 = _mm256_set1_ps(scal_15);


										vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_8968);
										mem_vec_8968 = vec_49;



										vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_8969);
										mem_vec_8969 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_53 = _mm256_set1_ps(scal_16);


										vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_8970);
										mem_vec_8970 = vec_52;



										vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_8971);
										mem_vec_8971 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_56 = _mm256_set1_ps(scal_17);


										vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_8972);
										mem_vec_8972 = vec_55;



										vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_8973);
										mem_vec_8973 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_59 = _mm256_set1_ps(scal_18);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_8974);
										mem_vec_8974 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_8975);
										mem_vec_8975 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_62 = _mm256_set1_ps(scal_19);


										vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_8976);
										mem_vec_8976 = vec_61;



										vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_8977);
										mem_vec_8977 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_65 = _mm256_set1_ps(scal_20);


										vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_8978);
										mem_vec_8978 = vec_64;



										vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_8979);
										mem_vec_8979 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_68 = _mm256_set1_ps(scal_21);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_8980);
										mem_vec_8980 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_8981);
										mem_vec_8981 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_71 = _mm256_set1_ps(scal_22);
										vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_8960);
										mem_vec_8960 = vec_70;

										vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_8961);
										mem_vec_8961 = vec_73;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_76 = _mm256_set1_ps(scal_23);


										vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_8962);
										mem_vec_8962 = vec_75;



										vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_8963);
										mem_vec_8963 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_79 = _mm256_set1_ps(scal_24);


										vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_8964);
										mem_vec_8964 = vec_78;



										vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_8965);
										mem_vec_8965 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_82 = _mm256_set1_ps(scal_25);


										vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_8966);
										mem_vec_8966 = vec_81;



										vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_8967);
										mem_vec_8967 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_85 = _mm256_set1_ps(scal_26);


										vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_8968);
										mem_vec_8968 = vec_84;



										vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_8969);
										mem_vec_8969 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_88 = _mm256_set1_ps(scal_27);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8970);
										mem_vec_8970 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8971);
										mem_vec_8971 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_91 = _mm256_set1_ps(scal_28);


										vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_8972);
										mem_vec_8972 = vec_90;



										vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_8973);
										mem_vec_8973 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_94 = _mm256_set1_ps(scal_29);


										vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_8974);
										mem_vec_8974 = vec_93;



										vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_8975);
										mem_vec_8975 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_97 = _mm256_set1_ps(scal_30);


										vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_8976);
										mem_vec_8976 = vec_96;



										vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_8977);
										mem_vec_8977 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_100 = _mm256_set1_ps(scal_31);


										vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_8978);
										mem_vec_8978 = vec_99;



										vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_8979);
										mem_vec_8979 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_103 = _mm256_set1_ps(scal_32);


										vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_8980);
										mem_vec_8980 = vec_102;



										vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_8981);
										mem_vec_8981 = vec_104;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8960);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8961);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8962);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8963);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8964);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8965);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8966);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8967);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8968);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8969);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8970);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8971);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8972);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8973);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8974);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8975);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8976);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8977);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8978);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8979);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8980);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8981);
						}
					}
				}
		}
	}
}


}