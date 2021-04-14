#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (32, c); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, f1194_p_0, fp_1, f1194, h, hp_0, x, xp_0, x1194_p_0, xp_1, x1194, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y796 = 0;
IND_TYPE x1195 = 0;
IND_TYPE h634 = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f1195 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12940 ,mem_vec_12941 ,mem_vec_12942 ,mem_vec_12943 ,mem_vec_12944 ,mem_vec_12945 ,mem_vec_12946 ,mem_vec_12947 ,mem_vec_12948 ,mem_vec_12949 ,mem_vec_12950 ,mem_vec_12951 ,mem_vec_12952 ,mem_vec_12953 ,mem_vec_12954 ,mem_vec_12955 ,mem_vec_12956 ,mem_vec_12957 ,mem_vec_12958 ,mem_vec_12959 ,mem_vec_12960 ,mem_vec_12961 ,mem_vec_12962 ,mem_vec_12963 ,mem_vec_12964 ,mem_vec_12965 ,mem_vec_12966 ,mem_vec_12967 ,mem_vec_12968 ,mem_vec_12969 ,mem_vec_12970 ,mem_vec_12971 ,mem_vec_12972 ,mem_vec_12973 ,mem_vec_12974 ,mem_vec_12975 ,mem_vec_12976 ,mem_vec_12977 ,mem_vec_12978 ,mem_vec_12979 ,mem_vec_12980 ,mem_vec_12981 ,mem_vec_12982 ,mem_vec_12983 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1194 = f1195, f1194_p_0 = 0;
	f1194 < f1195 + 128;
	f1194 += 64, f1194_p_0 += 64){
		for (y = y796, yp_0 = 0;
			y < y796 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x1194 = x1195, x1194_p_0 = 0;
				x1194 < x1195 + 28;
				x1194 += 1, x1194_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 32) (128 / 4)
				for (c1194 = c1195, c1194_p_0 = 0;
					c1194 < c1195 + 128;
					c1194 += 4, c1194_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1194, fp_1 = f1194_p_0, fp_0 = 0;
						f < f1194 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h634, hp_0 = 0;
							h < h634 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
								x < x1194 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12940 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12941 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12942 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12943 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_12955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_12956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_12959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
											c < c1194 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12940);
											mem_vec_12940 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12941);
											mem_vec_12941 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12942);
											mem_vec_12942 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12943);
											mem_vec_12943 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12944);
											mem_vec_12944 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12945);
											mem_vec_12945 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12946);
											mem_vec_12946 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12947);
											mem_vec_12947 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12948);
											mem_vec_12948 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12949);
											mem_vec_12949 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12950);
											mem_vec_12950 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12951);
											mem_vec_12951 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12952);
											mem_vec_12952 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12953);
											mem_vec_12953 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12954);
											mem_vec_12954 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12955);
											mem_vec_12955 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12956);
											mem_vec_12956 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12957);
											mem_vec_12957 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12958);
											mem_vec_12958 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12959);
											mem_vec_12959 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_12940);
											mem_vec_12940 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_12941);
											mem_vec_12941 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_12942);
											mem_vec_12942 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_12943);
											mem_vec_12943 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_12944);
											mem_vec_12944 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_12945);
											mem_vec_12945 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_12946);
											mem_vec_12946 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_12947);
											mem_vec_12947 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_12948);
											mem_vec_12948 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_12949);
											mem_vec_12949 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_12950);
											mem_vec_12950 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_12951);
											mem_vec_12951 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_12952);
											mem_vec_12952 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_12953);
											mem_vec_12953 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_12954);
											mem_vec_12954 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_12955);
											mem_vec_12955 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_12956);
											mem_vec_12956 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_12957);
											mem_vec_12957 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_12958);
											mem_vec_12958 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_12959);
											mem_vec_12959 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_12940);
											mem_vec_12940 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_12941);
											mem_vec_12941 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_12942);
											mem_vec_12942 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_12943);
											mem_vec_12943 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_12944);
											mem_vec_12944 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_12945);
											mem_vec_12945 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_12946);
											mem_vec_12946 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_12947);
											mem_vec_12947 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_12948);
											mem_vec_12948 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_12949);
											mem_vec_12949 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_12950);
											mem_vec_12950 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_12951);
											mem_vec_12951 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_12952);
											mem_vec_12952 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_12953);
											mem_vec_12953 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_12954);
											mem_vec_12954 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_12955);
											mem_vec_12955 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_12956);
											mem_vec_12956 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_12957);
											mem_vec_12957 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_12958);
											mem_vec_12958 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_12959);
											mem_vec_12959 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12945);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12946);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12947);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12948);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12949);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12951);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12952);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12953);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12954);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12955);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12956);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12957);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12959);
							}
						}
					}
				}
			}
		}
		for (y = y796 + 10, yp_0 = 0;
			y < y796 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 28) (28 / 1)
			for (x1194 = x1195, x1194_p_0 = 0;
				x1194 < x1195 + 28;
				x1194 += 1, x1194_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 64
				// T (c, 32) (128 / 4)
				for (c1194 = c1195, c1194_p_0 = 0;
					c1194 < c1195 + 128;
					c1194 += 4, c1194_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1194, fp_1 = f1194_p_0, fp_0 = 0;
						f < f1194 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h634, hp_0 = 0;
							h < h634 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
								x < x1194 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12960 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12961 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12963 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_12975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_12976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_12979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_12980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_12981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_12982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_12983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
											c < c1194 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12960);
											mem_vec_12960 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12961);
											mem_vec_12961 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12962);
											mem_vec_12962 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12963);
											mem_vec_12963 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12964);
											mem_vec_12964 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12965);
											mem_vec_12965 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12966);
											mem_vec_12966 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12967);
											mem_vec_12967 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12968);
											mem_vec_12968 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12969);
											mem_vec_12969 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12970);
											mem_vec_12970 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12971);
											mem_vec_12971 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12972);
											mem_vec_12972 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12973);
											mem_vec_12973 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12974);
											mem_vec_12974 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12975);
											mem_vec_12975 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12976);
											mem_vec_12976 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12977);
											mem_vec_12977 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12978);
											mem_vec_12978 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12979);
											mem_vec_12979 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12980);
											mem_vec_12980 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12981);
											mem_vec_12981 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_12982);
											mem_vec_12982 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_12983);
											mem_vec_12983 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_12960);
											mem_vec_12960 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_12961);
											mem_vec_12961 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_12962);
											mem_vec_12962 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_12963);
											mem_vec_12963 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_12964);
											mem_vec_12964 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_12965);
											mem_vec_12965 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_12966);
											mem_vec_12966 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_12967);
											mem_vec_12967 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_12968);
											mem_vec_12968 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_12969);
											mem_vec_12969 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_12970);
											mem_vec_12970 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_12971);
											mem_vec_12971 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_12972);
											mem_vec_12972 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_12973);
											mem_vec_12973 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_12974);
											mem_vec_12974 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_12975);
											mem_vec_12975 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_12976);
											mem_vec_12976 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_12977);
											mem_vec_12977 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_12978);
											mem_vec_12978 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_12979);
											mem_vec_12979 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_12980);
											mem_vec_12980 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_12981);
											mem_vec_12981 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_12982);
											mem_vec_12982 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_12983);
											mem_vec_12983 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_12960);
											mem_vec_12960 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_12961);
											mem_vec_12961 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_12962);
											mem_vec_12962 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_12963);
											mem_vec_12963 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_12964);
											mem_vec_12964 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_12965);
											mem_vec_12965 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_12966);
											mem_vec_12966 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_12967);
											mem_vec_12967 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_12968);
											mem_vec_12968 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_12969);
											mem_vec_12969 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_12970);
											mem_vec_12970 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_12971);
											mem_vec_12971 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_12972);
											mem_vec_12972 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_12973);
											mem_vec_12973 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_12974);
											mem_vec_12974 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_12975);
											mem_vec_12975 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_12976);
											mem_vec_12976 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_12977);
											mem_vec_12977 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_12978);
											mem_vec_12978 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_12979);
											mem_vec_12979 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_12980);
											mem_vec_12980 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_12981);
											mem_vec_12981 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_12982);
											mem_vec_12982 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_12983);
											mem_vec_12983 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_12982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_12983);
							}
						}
					}
				}
			}
		}
}


}