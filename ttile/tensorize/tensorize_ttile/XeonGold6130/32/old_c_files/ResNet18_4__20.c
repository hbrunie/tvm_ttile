#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, c); T (1, f); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c450_p_0, cp_1, c450, f, fp_0, f450_p_0, fp_1, f450, w, wp_0, x, xp_0, x435_p_0, xp_1, x435, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y300 = 0;
IND_TYPE x436 = 0;
IND_TYPE h = 0;
IND_TYPE w282 = 0;
IND_TYPE c451 = 0;
IND_TYPE f451 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4977 ,mem_vec_4978 ,mem_vec_4979 ,mem_vec_4980 ,mem_vec_4981 ,mem_vec_4982 ,mem_vec_4983 ,mem_vec_4984 ,mem_vec_4985 ,mem_vec_4986 ,mem_vec_4987 ,mem_vec_4988 ,mem_vec_4989 ,mem_vec_4990 ,mem_vec_4991 ,mem_vec_4992 ,mem_vec_4993 ,mem_vec_4994 ,mem_vec_4995 ,mem_vec_4996 ,mem_vec_4997 ,mem_vec_4998 ,mem_vec_4999 ,mem_vec_5000 ,mem_vec_5001 ,mem_vec_5002 ,mem_vec_5003 ,mem_vec_5004 ,mem_vec_5005 ,mem_vec_5006 ,mem_vec_5007 ,mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f450 = f451, f450_p_0 = 0;
	f450 < f451 + 128;
	f450 += 32, f450_p_0 += 32){
		for (y = y300, yp_0 = 0;
			y < y300 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (x, 28) (28 / 1)
			for (x435 = x436, x435_p_0 = 0;
				x435 < x436 + 28;
				x435 += 1, x435_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f450, fp_1 = f450_p_0, fp_0 = 0;
					f < f450 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c450 = c451, c450_p_0 = 0;
						c450 < c451 + 64;
						c450 += 64, c450_p_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w282, wp_0 = 0;
							w < w282 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x435, xp_1 = x435_p_0, xp_0 = 0;
								x < x435 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4977 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4978 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c450, cp_1 = c450_p_0, cp_0 = 0;
											c < c450 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4977);
											mem_vec_4977 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4978);
											mem_vec_4978 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4979);
											mem_vec_4979 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4980);
											mem_vec_4980 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4981);
											mem_vec_4981 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4982);
											mem_vec_4982 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4983);
											mem_vec_4983 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4984);
											mem_vec_4984 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4985);
											mem_vec_4985 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4986);
											mem_vec_4986 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4987);
											mem_vec_4987 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4988);
											mem_vec_4988 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4989);
											mem_vec_4989 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4990);
											mem_vec_4990 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4991);
											mem_vec_4991 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4992);
											mem_vec_4992 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4993);
											mem_vec_4993 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4994);
											mem_vec_4994 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_4977);
											mem_vec_4977 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_4978);
											mem_vec_4978 = vec_32;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_4979);
											mem_vec_4979 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_4980);
											mem_vec_4980 = vec_36;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_4981);
											mem_vec_4981 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_4982);
											mem_vec_4982 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_4983);
											mem_vec_4983 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_4984);
											mem_vec_4984 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_4985);
											mem_vec_4985 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_4986);
											mem_vec_4986 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_4987);
											mem_vec_4987 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_4988);
											mem_vec_4988 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_4989);
											mem_vec_4989 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_4990);
											mem_vec_4990 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_4991);
											mem_vec_4991 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_4992);
											mem_vec_4992 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_4993);
											mem_vec_4993 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_4994);
											mem_vec_4994 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_4977);
											mem_vec_4977 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_4978);
											mem_vec_4978 = vec_61;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_4979);
											mem_vec_4979 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_4980);
											mem_vec_4980 = vec_65;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_4981);
											mem_vec_4981 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_4982);
											mem_vec_4982 = vec_68;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_4983);
											mem_vec_4983 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_4984);
											mem_vec_4984 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_4985);
											mem_vec_4985 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_4986);
											mem_vec_4986 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_4987);
											mem_vec_4987 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_4988);
											mem_vec_4988 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_4989);
											mem_vec_4989 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_4990);
											mem_vec_4990 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_4991);
											mem_vec_4991 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_4992);
											mem_vec_4992 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_4993);
											mem_vec_4993 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_4994);
											mem_vec_4994 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4979);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4994);
							}
						}
					}
				}
			}
		}
		for (y = y300 + 18, yp_0 = 0;
			y < y300 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (x, 28) (28 / 1)
			for (x435 = x436, x435_p_0 = 0;
				x435 < x436 + 28;
				x435 += 1, x435_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f450, fp_1 = f450_p_0, fp_0 = 0;
					f < f450 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c450 = c451, c450_p_0 = 0;
						c450 < c451 + 64;
						c450 += 64, c450_p_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w282, wp_0 = 0;
							w < w282 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x435, xp_1 = x435_p_0, xp_0 = 0;
								x < x435 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4995 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4996 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c450, cp_1 = c450_p_0, cp_0 = 0;
											c < c450 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4995);
											mem_vec_4995 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4996);
											mem_vec_4996 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4997);
											mem_vec_4997 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4998);
											mem_vec_4998 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4999);
											mem_vec_4999 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5000);
											mem_vec_5000 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5001);
											mem_vec_5001 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5002);
											mem_vec_5002 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5003);
											mem_vec_5003 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5004);
											mem_vec_5004 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5005);
											mem_vec_5005 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5006);
											mem_vec_5006 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5007);
											mem_vec_5007 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5008);
											mem_vec_5008 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5009);
											mem_vec_5009 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5010);
											mem_vec_5010 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5011);
											mem_vec_5011 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5012);
											mem_vec_5012 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5013);
											mem_vec_5013 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5014);
											mem_vec_5014 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_4995);
											mem_vec_4995 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_4996);
											mem_vec_4996 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4997);
											mem_vec_4997 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4998);
											mem_vec_4998 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_4999);
											mem_vec_4999 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_5000);
											mem_vec_5000 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_5001);
											mem_vec_5001 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5002);
											mem_vec_5002 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_5003);
											mem_vec_5003 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_5004);
											mem_vec_5004 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_5005);
											mem_vec_5005 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_5006);
											mem_vec_5006 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_5007);
											mem_vec_5007 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_5008);
											mem_vec_5008 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_5009);
											mem_vec_5009 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_5010);
											mem_vec_5010 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_5011);
											mem_vec_5011 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5012);
											mem_vec_5012 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_5013);
											mem_vec_5013 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_5014);
											mem_vec_5014 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_4995);
											mem_vec_4995 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_4996);
											mem_vec_4996 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_4997);
											mem_vec_4997 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_4998);
											mem_vec_4998 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4999);
											mem_vec_4999 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_5000);
											mem_vec_5000 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_5001);
											mem_vec_5001 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_5002);
											mem_vec_5002 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_5003);
											mem_vec_5003 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_5004);
											mem_vec_5004 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_5005);
											mem_vec_5005 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_5006);
											mem_vec_5006 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_5007);
											mem_vec_5007 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_5008);
											mem_vec_5008 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_5009);
											mem_vec_5009 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_5010);
											mem_vec_5010 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_5011);
											mem_vec_5011 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_5012);
											mem_vec_5012 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_5013);
											mem_vec_5013 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_5014);
											mem_vec_5014 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4995);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4996);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4997);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4998);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4999);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5000);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5001);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5002);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5003);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5004);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5005);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5006);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5007);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5011);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5012);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5013);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5014);
							}
						}
					}
				}
			}
		}
}


}