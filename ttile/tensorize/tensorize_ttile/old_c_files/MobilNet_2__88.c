#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (16, c); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c684_p_0, c685_p_0, cp_1, c684_p_1, cp_2, c684, c685, h, hp_0, w, wp_0, x, xp_0, x758_p_0, xp_1, x758, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y412 = 0;
IND_TYPE x759 = 0;
IND_TYPE h376 = 0;
IND_TYPE w388 = 0;
IND_TYPE c686 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_6836 ,mem_vec_6837 ,mem_vec_6838 ,mem_vec_6839 ,mem_vec_6840 ,mem_vec_6841 ,mem_vec_6842 ,mem_vec_6843 ,mem_vec_6844 ,mem_vec_6845 ,mem_vec_6846 ,mem_vec_6847 ,mem_vec_6848 ,mem_vec_6849 ,mem_vec_6850 ,mem_vec_6851 ,mem_vec_6852 ,mem_vec_6853 ,mem_vec_6854 ,mem_vec_6855 ,mem_vec_6856 ,mem_vec_6857 ,mem_vec_6858 ,mem_vec_6859 ,mem_vec_6860 ,mem_vec_6861 ,mem_vec_6862 ,mem_vec_6863 ,mem_vec_6864 ,mem_vec_6865 ,mem_vec_6866 ,mem_vec_6867 ,mem_vec_6868 ,mem_vec_6869 ,mem_vec_6870 ,mem_vec_6871 ,mem_vec_6872 ,mem_vec_6873 ,mem_vec_6874 ,mem_vec_6875 ,mem_vec_6876 ,mem_vec_6877 ,mem_vec_6878 ,mem_vec_6879 ,mem_vec_6880 ,mem_vec_6881 ,mem_vec_6882 ,mem_vec_6883 ,mem_vec_6884 ,mem_vec_6885 ,mem_vec_6886 ,mem_vec_6887 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c685 = c686, c685_p_0 = 0;
	c685 < c686 + 64;
	c685 += 64, c685_p_0 += 64){
		for (y = y412, yp_0 = 0;
			y < y412 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 7) (56 / 8)
			for (x758 = x759, x758_p_0 = 0;
				x758 < x759 + 56;
				x758 += 8, x758_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 64
				// T (c, 16) (64 / 4)
				for (c684 = c685, c684_p_1 = c685_p_0, c684_p_0 = 0;
					c684 < c685 + 64;
					c684 += 4, c684_p_1 += 4, c684_p_0 += 4){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h376, hp_0 = 0;
						h < h376 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w388, wp_0 = 0;
							w < w388 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 64
							// T (x, 8) (8 / 1)
							for (x = x758, xp_1 = x758_p_0, xp_0 = 0;
								x < x758 + 8;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6838 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6839 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c684, cp_2 = c684_p_1, cp_1 = c684_p_0, cp_0 = 0;
											c < c684 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6836);
											mem_vec_6836 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6837);
											mem_vec_6837 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6838);
											mem_vec_6838 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6839);
											mem_vec_6839 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6840);
											mem_vec_6840 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6841);
											mem_vec_6841 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6842);
											mem_vec_6842 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6843);
											mem_vec_6843 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6844);
											mem_vec_6844 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6845);
											mem_vec_6845 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6846);
											mem_vec_6846 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6847);
											mem_vec_6847 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6848);
											mem_vec_6848 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6849);
											mem_vec_6849 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6850);
											mem_vec_6850 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6851);
											mem_vec_6851 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6852);
											mem_vec_6852 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6853);
											mem_vec_6853 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6854);
											mem_vec_6854 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6855);
											mem_vec_6855 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6856);
											mem_vec_6856 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6857);
											mem_vec_6857 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6858);
											mem_vec_6858 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6859);
											mem_vec_6859 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6859);
							}
						}
					}
				}
			}
		}
		for (y = y412 + 42, yp_0 = 0;
			y < y412 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 7) (56 / 8)
			for (x758 = x759, x758_p_0 = 0;
				x758 < x759 + 56;
				x758 += 8, x758_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 64
				// T (c, 16) (64 / 4)
				for (c684 = c685, c684_p_1 = c685_p_0, c684_p_0 = 0;
					c684 < c685 + 64;
					c684 += 4, c684_p_1 += 4, c684_p_0 += 4){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h376, hp_0 = 0;
						h < h376 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w388, wp_0 = 0;
							w < w388 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 64
							// T (x, 8) (8 / 1)
							for (x = x758, xp_1 = x758_p_0, xp_0 = 0;
								x < x758 + 8;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6862 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6863 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_6884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_6887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c684, cp_2 = c684_p_1, cp_1 = c684_p_0, cp_0 = 0;
											c < c684 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6860);
											mem_vec_6860 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6861);
											mem_vec_6861 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6862);
											mem_vec_6862 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6863);
											mem_vec_6863 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6864);
											mem_vec_6864 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6865);
											mem_vec_6865 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6866);
											mem_vec_6866 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6867);
											mem_vec_6867 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6868);
											mem_vec_6868 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6869);
											mem_vec_6869 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6870);
											mem_vec_6870 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6871);
											mem_vec_6871 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6872);
											mem_vec_6872 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6873);
											mem_vec_6873 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6874);
											mem_vec_6874 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6875);
											mem_vec_6875 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6876);
											mem_vec_6876 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6877);
											mem_vec_6877 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6878);
											mem_vec_6878 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6879);
											mem_vec_6879 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6880);
											mem_vec_6880 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6881);
											mem_vec_6881 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6882);
											mem_vec_6882 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6883);
											mem_vec_6883 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_6884);
											mem_vec_6884 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_6885);
											mem_vec_6885 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_6886);
											mem_vec_6886 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_6887);
											mem_vec_6887 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6879);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6880);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6881);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6882);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6883);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_6886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_6887);
							}
						}
					}
				}
			}
		}
}


}