#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (2, f); T (8, c); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f)]
*/
IND_TYPE c, cp_0, c966_p_0, cp_1, c966, f, fp_0, f966_p_0, fp_1, f966, h, hp_0, x, xp_0, x966_p_0, xp_1, x966, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y644 = 0;
IND_TYPE x967 = 0;
IND_TYPE h506 = 0;
IND_TYPE w = 0;
IND_TYPE c967 = 0;
IND_TYPE f967 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7960 ,mem_vec_7961 ,mem_vec_7962 ,mem_vec_7963 ,mem_vec_7964 ,mem_vec_7965 ,mem_vec_7966 ,mem_vec_7967 ,mem_vec_7968 ,mem_vec_7969 ,mem_vec_7970 ,mem_vec_7971 ,mem_vec_7972 ,mem_vec_7973 ,mem_vec_7974 ,mem_vec_7975 ,mem_vec_7976 ,mem_vec_7977 ,mem_vec_7978 ,mem_vec_7979 ,mem_vec_7980 ,mem_vec_7981 ,mem_vec_7982 ,mem_vec_7983 ,mem_vec_7984 ,mem_vec_7985 ,mem_vec_7986 ,mem_vec_7987 ,mem_vec_7988 ,mem_vec_7989 ,mem_vec_7990 ,mem_vec_7991 ,mem_vec_7992 ,mem_vec_7993 ,mem_vec_7994 ,mem_vec_7995 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f966 = f967, f966_p_0 = 0;
	f966 < f967 + 256;
	f966 += 128, f966_p_0 += 128){
		for (y = y644, yp_0 = 0;
			y < y644 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 7) (14 / 2)
			for (x966 = x967, x966_p_0 = 0;
				x966 < x967 + 14;
				x966 += 2, x966_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 128
				// T (c, 8) (256 / 32)
				for (c966 = c967, c966_p_0 = 0;
					c966 < c967 + 256;
					c966 += 32, c966_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 128
					// T (f, 2) (128 / 64)
					for (f = f966, fp_1 = f966_p_0, fp_0 = 0;
						f < f966 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h506, hp_0 = 0;
							h < h506 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 64
							// T (x, 2) (2 / 1)
							for (x = x966, xp_1 = x966_p_0, xp_0 = 0;
								x < x966 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7960 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7961 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7963 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c966, cp_1 = c966_p_0, cp_0 = 0;
											c < c966 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7960);
											mem_vec_7960 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7961);
											mem_vec_7961 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7962);
											mem_vec_7962 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7963);
											mem_vec_7963 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7964);
											mem_vec_7964 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7965);
											mem_vec_7965 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7966);
											mem_vec_7966 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7967);
											mem_vec_7967 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7968);
											mem_vec_7968 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7969);
											mem_vec_7969 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7970);
											mem_vec_7970 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7971);
											mem_vec_7971 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7972);
											mem_vec_7972 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7973);
											mem_vec_7973 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7974);
											mem_vec_7974 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7975);
											mem_vec_7975 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7960);
											mem_vec_7960 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7961);
											mem_vec_7961 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7962);
											mem_vec_7962 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7963);
											mem_vec_7963 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7964);
											mem_vec_7964 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7965);
											mem_vec_7965 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7966);
											mem_vec_7966 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7967);
											mem_vec_7967 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7968);
											mem_vec_7968 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7969);
											mem_vec_7969 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7970);
											mem_vec_7970 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7971);
											mem_vec_7971 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7972);
											mem_vec_7972 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7973);
											mem_vec_7973 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7974);
											mem_vec_7974 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7975);
											mem_vec_7975 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7960);
											mem_vec_7960 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7961);
											mem_vec_7961 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7962);
											mem_vec_7962 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7963);
											mem_vec_7963 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7964);
											mem_vec_7964 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7965);
											mem_vec_7965 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7966);
											mem_vec_7966 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7967);
											mem_vec_7967 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7968);
											mem_vec_7968 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7969);
											mem_vec_7969 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7970);
											mem_vec_7970 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7971);
											mem_vec_7971 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7972);
											mem_vec_7972 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7973);
											mem_vec_7973 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7974);
											mem_vec_7974 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7975);
											mem_vec_7975 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7967);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7975);
							}
						}
					}
				}
			}
		}
		for (y = y644 + 4, yp_0 = 0;
			y < y644 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 7) (14 / 2)
			for (x966 = x967, x966_p_0 = 0;
				x966 < x967 + 14;
				x966 += 2, x966_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 128
				// T (c, 8) (256 / 32)
				for (c966 = c967, c966_p_0 = 0;
					c966 < c967 + 256;
					c966 += 32, c966_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 128
					// T (f, 2) (128 / 64)
					for (f = f966, fp_1 = f966_p_0, fp_0 = 0;
						f < f966 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h506, hp_0 = 0;
							h < h506 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 64
							// T (x, 2) (2 / 1)
							for (x = x966, xp_1 = x966_p_0, xp_0 = 0;
								x < x966 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7976 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7977 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7978 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7979 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c966, cp_1 = c966_p_0, cp_0 = 0;
											c < c966 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7976);
											mem_vec_7976 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7977);
											mem_vec_7977 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7978);
											mem_vec_7978 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7979);
											mem_vec_7979 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7980);
											mem_vec_7980 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7981);
											mem_vec_7981 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7982);
											mem_vec_7982 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7983);
											mem_vec_7983 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7984);
											mem_vec_7984 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7985);
											mem_vec_7985 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7986);
											mem_vec_7986 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7987);
											mem_vec_7987 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7988);
											mem_vec_7988 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7989);
											mem_vec_7989 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7990);
											mem_vec_7990 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7991);
											mem_vec_7991 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7992);
											mem_vec_7992 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7993);
											mem_vec_7993 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7994);
											mem_vec_7994 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7995);
											mem_vec_7995 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7976);
											mem_vec_7976 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7977);
											mem_vec_7977 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_7978);
											mem_vec_7978 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_7979);
											mem_vec_7979 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_7980);
											mem_vec_7980 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_7981);
											mem_vec_7981 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_7982);
											mem_vec_7982 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_7983);
											mem_vec_7983 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7984);
											mem_vec_7984 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7985);
											mem_vec_7985 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_7986);
											mem_vec_7986 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_7987);
											mem_vec_7987 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_7988);
											mem_vec_7988 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_7989);
											mem_vec_7989 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_7990);
											mem_vec_7990 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_7991);
											mem_vec_7991 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_7992);
											mem_vec_7992 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_7993);
											mem_vec_7993 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_7994);
											mem_vec_7994 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_7995);
											mem_vec_7995 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7976);
											mem_vec_7976 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7977);
											mem_vec_7977 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_7978);
											mem_vec_7978 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_7979);
											mem_vec_7979 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_7980);
											mem_vec_7980 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_7981);
											mem_vec_7981 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_7982);
											mem_vec_7982 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_7983);
											mem_vec_7983 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7984);
											mem_vec_7984 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7985);
											mem_vec_7985 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_7986);
											mem_vec_7986 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_7987);
											mem_vec_7987 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_7988);
											mem_vec_7988 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_7989);
											mem_vec_7989 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_7990);
											mem_vec_7990 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_7991);
											mem_vec_7991 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_7992);
											mem_vec_7992 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_7993);
											mem_vec_7993 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_7994);
											mem_vec_7994 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_7995);
											mem_vec_7995 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7994);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7995);
							}
						}
					}
				}
			}
		}
}


}