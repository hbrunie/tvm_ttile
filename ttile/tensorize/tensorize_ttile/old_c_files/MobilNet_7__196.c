#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (16, c); T (8, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (16, c)]
*/
IND_TYPE c, cp_0, c1268_p_0, c1269_p_0, cp_1, c1268_p_1, cp_2, c1268, c1269, f, fp_0, h, hp_0, x, xp_0, x996_p_0, xp_1, x996, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y664 = 0;
IND_TYPE x997 = 0;
IND_TYPE h534 = 0;
IND_TYPE w = 0;
IND_TYPE c1270 = 0;
IND_TYPE f724 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8824 ,mem_vec_8825 ,mem_vec_8826 ,mem_vec_8827 ,mem_vec_8828 ,mem_vec_8829 ,mem_vec_8830 ,mem_vec_8831 ,mem_vec_8832 ,mem_vec_8833 ,mem_vec_8834 ,mem_vec_8835 ,mem_vec_8836 ,mem_vec_8837 ,mem_vec_8838 ,mem_vec_8839 ,mem_vec_8840 ,mem_vec_8841 ,mem_vec_8842 ,mem_vec_8843 ,mem_vec_8844 ,mem_vec_8845 ,mem_vec_8846 ,mem_vec_8847 ,mem_vec_8848 ,mem_vec_8849 ,mem_vec_8850 ,mem_vec_8851 ,mem_vec_8852 ,mem_vec_8853 ,mem_vec_8854 ,mem_vec_8855 ,mem_vec_8856 ,mem_vec_8857 ,mem_vec_8858 ,mem_vec_8859 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c1269 = c1270, c1269_p_0 = 0;
	c1269 < c1270 + 512;
	c1269 += 32, c1269_p_0 += 32){
		for (y = y664, yp_0 = 0;
			y < y664 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 512
			// T (x, 14) (14 / 1)
			for (x996 = x997, x996_p_0 = 0;
				x996 < x997 + 14;
				x996 += 1, x996_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 512
				// T (f, 8) (512 / 64)
				for (f = f724, fp_0 = 0;
					f < f724 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 16) (32 / 2)
					for (c1268 = c1269, c1268_p_1 = c1269_p_0, c1268_p_0 = 0;
						c1268 < c1269 + 32;
						c1268 += 2, c1268_p_1 += 2, c1268_p_0 += 2){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h534, hp_0 = 0;
							h < h534 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
								x < x996 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8824 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8825 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8826 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8827 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1268, cp_2 = c1268_p_1, cp_1 = c1268_p_0, cp_0 = 0;
											c < c1268 + 2;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8824);
											mem_vec_8824 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8825);
											mem_vec_8825 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8826);
											mem_vec_8826 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8827);
											mem_vec_8827 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8828);
											mem_vec_8828 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8829);
											mem_vec_8829 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8830);
											mem_vec_8830 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8831);
											mem_vec_8831 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8832);
											mem_vec_8832 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8833);
											mem_vec_8833 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8834);
											mem_vec_8834 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8835);
											mem_vec_8835 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8836);
											mem_vec_8836 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8837);
											mem_vec_8837 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8838);
											mem_vec_8838 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8839);
											mem_vec_8839 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_8824);
											mem_vec_8824 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_8825);
											mem_vec_8825 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_8826);
											mem_vec_8826 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_8827);
											mem_vec_8827 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_8828);
											mem_vec_8828 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_8829);
											mem_vec_8829 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_8830);
											mem_vec_8830 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_8831);
											mem_vec_8831 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_8832);
											mem_vec_8832 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_8833);
											mem_vec_8833 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_8834);
											mem_vec_8834 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_8835);
											mem_vec_8835 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_8836);
											mem_vec_8836 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_8837);
											mem_vec_8837 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_8838);
											mem_vec_8838 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_8839);
											mem_vec_8839 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_8824);
											mem_vec_8824 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_8825);
											mem_vec_8825 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_8826);
											mem_vec_8826 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_8827);
											mem_vec_8827 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_8828);
											mem_vec_8828 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_8829);
											mem_vec_8829 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_8830);
											mem_vec_8830 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8831);
											mem_vec_8831 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_8832);
											mem_vec_8832 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_8833);
											mem_vec_8833 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_8834);
											mem_vec_8834 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_8835);
											mem_vec_8835 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_8836);
											mem_vec_8836 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_8837);
											mem_vec_8837 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_8838);
											mem_vec_8838 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_8839);
											mem_vec_8839 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8835);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8839);
							}
						}
					}
				}
			}
		}
		for (y = y664 + 4, yp_0 = 0;
			y < y664 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 512
			// T (x, 14) (14 / 1)
			for (x996 = x997, x996_p_0 = 0;
				x996 < x997 + 14;
				x996 += 1, x996_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 512
				// T (f, 8) (512 / 64)
				for (f = f724, fp_0 = 0;
					f < f724 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 16) (32 / 2)
					for (c1268 = c1269, c1268_p_1 = c1269_p_0, c1268_p_0 = 0;
						c1268 < c1269 + 32;
						c1268 += 2, c1268_p_1 += 2, c1268_p_0 += 2){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h534, hp_0 = 0;
							h < h534 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
								x < x996 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_8856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_8859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1268, cp_2 = c1268_p_1, cp_1 = c1268_p_0, cp_0 = 0;
											c < c1268 + 2;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8840);
											mem_vec_8840 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8841);
											mem_vec_8841 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8842);
											mem_vec_8842 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8843);
											mem_vec_8843 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8844);
											mem_vec_8844 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8845);
											mem_vec_8845 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8846);
											mem_vec_8846 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8847);
											mem_vec_8847 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8848);
											mem_vec_8848 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8849);
											mem_vec_8849 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8850);
											mem_vec_8850 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8851);
											mem_vec_8851 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8852);
											mem_vec_8852 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8853);
											mem_vec_8853 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8854);
											mem_vec_8854 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8855);
											mem_vec_8855 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8856);
											mem_vec_8856 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8857);
											mem_vec_8857 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8858);
											mem_vec_8858 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8859);
											mem_vec_8859 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_8840);
											mem_vec_8840 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_8841);
											mem_vec_8841 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_8842);
											mem_vec_8842 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_8843);
											mem_vec_8843 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_8844);
											mem_vec_8844 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_8845);
											mem_vec_8845 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8846);
											mem_vec_8846 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_8847);
											mem_vec_8847 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_8848);
											mem_vec_8848 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_8849);
											mem_vec_8849 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_8850);
											mem_vec_8850 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_8851);
											mem_vec_8851 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_8852);
											mem_vec_8852 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_8853);
											mem_vec_8853 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_8854);
											mem_vec_8854 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_8855);
											mem_vec_8855 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_8856);
											mem_vec_8856 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_8857);
											mem_vec_8857 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_8858);
											mem_vec_8858 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_8859);
											mem_vec_8859 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_8840);
											mem_vec_8840 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_8841);
											mem_vec_8841 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_8842);
											mem_vec_8842 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_8843);
											mem_vec_8843 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_8844);
											mem_vec_8844 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_8845);
											mem_vec_8845 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_8846);
											mem_vec_8846 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_8847);
											mem_vec_8847 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_8848);
											mem_vec_8848 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_8849);
											mem_vec_8849 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_8850);
											mem_vec_8850 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_8851);
											mem_vec_8851 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_8852);
											mem_vec_8852 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_8853);
											mem_vec_8853 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_8854);
											mem_vec_8854 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_8855);
											mem_vec_8855 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_8856);
											mem_vec_8856 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_8857);
											mem_vec_8857 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_8858);
											mem_vec_8858 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_8859);
											mem_vec_8859 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8859);
							}
						}
					}
				}
			}
		}
}


}