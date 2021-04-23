#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (14, y); U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (2, y); T (2, f); T (1, c); T (4, f)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, f102_p_0, fp_1, f102, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y68 = 0;
IND_TYPE x99 = 0;
IND_TYPE h = 0;
IND_TYPE w62 = 0;
IND_TYPE c103 = 0;
IND_TYPE f103 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f102 = f103, f102_p_0 = 0;
	f102 < f103 + 128;
	f102 += 32, f102_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
	// T (c, 1) (64 / 64)
	for (c102 = c103, c102_p_0 = 0;
		c102 < c103 + 64;
		c102 += 64, c102_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
		// T (f, 2) (32 / 16)
		for (f = f102, fp_1 = f102_p_0, fp_0 = 0;
			f < f102 + 32;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 28, x = 28, h = 3, w = 3, c = 64, f = 16
			// T (y, 2) (28 / 14)
			for (y = y68, yp_0 = 0;
				y < y68 + 28;
				y += 14, yp_0 += 14){
				// y = 14, x = 28, h = 3, w = 3, c = 64, f = 16
				// T (x, 28) (28 / 1)
				for (x = x99, xp_0 = 0;
					x < x99 + 28;
					x += 1, xp_0 += 1){
					// y = 14, x = 1, h = 3, w = 3, c = 64, f = 16
					// T (w, 3) (3 / 1)
					for (w = w62, wp_0 = 0;
						w < w62 + 3;
						w += 1, wp_0 += 1){
								mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								// y = 14, x = 1, h = 3, w = 1, c = 64, f = 16
								// T (c, 64) (64 / 1)
								for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
									c < c102 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_910);
									mem_vec_910 = vec_0;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);


									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_911);
									mem_vec_911 = vec_3;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_912);
									mem_vec_912 = vec_5;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);


									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_913);
									mem_vec_913 = vec_7;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_10 = _mm512_set1_ps(scal_4);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_914);
									mem_vec_914 = vec_9;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_12 = _mm512_set1_ps(scal_5);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_915);
									mem_vec_915 = vec_11;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_14 = _mm512_set1_ps(scal_6);


									vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_916);
									mem_vec_916 = vec_13;
									scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
									vec_16 = _mm512_set1_ps(scal_7);


									vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_917);
									mem_vec_917 = vec_15;
									scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
									vec_18 = _mm512_set1_ps(scal_8);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_918);
									mem_vec_918 = vec_17;
									scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
									vec_20 = _mm512_set1_ps(scal_9);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_919);
									mem_vec_919 = vec_19;
									scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
									vec_22 = _mm512_set1_ps(scal_10);


									vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_920);
									mem_vec_920 = vec_21;
									scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
									vec_24 = _mm512_set1_ps(scal_11);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_921);
									mem_vec_921 = vec_23;
									scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
									vec_26 = _mm512_set1_ps(scal_12);


									vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_922);
									mem_vec_922 = vec_25;
									scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
									vec_28 = _mm512_set1_ps(scal_13);


									vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_923);
									mem_vec_923 = vec_27;
									scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
									vec_30 = _mm512_set1_ps(scal_14);
									vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_910);
									mem_vec_910 = vec_29;
									scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
									vec_33 = _mm512_set1_ps(scal_15);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_31, mem_vec_911);
									mem_vec_911 = vec_32;
									scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_16);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_912);
									mem_vec_912 = vec_34;
									scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
									vec_37 = _mm512_set1_ps(scal_17);


									vec_36 = _mm512_fmadd_ps(vec_37, vec_31, mem_vec_913);
									mem_vec_913 = vec_36;
									scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
									vec_39 = _mm512_set1_ps(scal_18);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_914);
									mem_vec_914 = vec_38;
									scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_19);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_915);
									mem_vec_915 = vec_40;
									scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
									vec_43 = _mm512_set1_ps(scal_20);


									vec_42 = _mm512_fmadd_ps(vec_43, vec_31, mem_vec_916);
									mem_vec_916 = vec_42;
									scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
									vec_45 = _mm512_set1_ps(scal_21);


									vec_44 = _mm512_fmadd_ps(vec_45, vec_31, mem_vec_917);
									mem_vec_917 = vec_44;
									scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_22);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_918);
									mem_vec_918 = vec_46;
									scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
									vec_49 = _mm512_set1_ps(scal_23);


									vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_919);
									mem_vec_919 = vec_48;
									scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
									vec_51 = _mm512_set1_ps(scal_24);


									vec_50 = _mm512_fmadd_ps(vec_51, vec_31, mem_vec_920);
									mem_vec_920 = vec_50;
									scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_25);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_921);
									mem_vec_921 = vec_52;
									scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h + 1) + c];
									vec_55 = _mm512_set1_ps(scal_26);


									vec_54 = _mm512_fmadd_ps(vec_55, vec_31, mem_vec_922);
									mem_vec_922 = vec_54;
									scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h + 1) + c];
									vec_57 = _mm512_set1_ps(scal_27);


									vec_56 = _mm512_fmadd_ps(vec_57, vec_31, mem_vec_923);
									mem_vec_923 = vec_56;
									scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
									vec_59 = _mm512_set1_ps(scal_28);
									vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_910);
									mem_vec_910 = vec_58;
									scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
									vec_62 = _mm512_set1_ps(scal_29);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_60, mem_vec_911);
									mem_vec_911 = vec_61;
									scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_30);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_912);
									mem_vec_912 = vec_63;
									scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
									vec_66 = _mm512_set1_ps(scal_31);


									vec_65 = _mm512_fmadd_ps(vec_66, vec_60, mem_vec_913);
									mem_vec_913 = vec_65;
									scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
									vec_68 = _mm512_set1_ps(scal_32);


									vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_914);
									mem_vec_914 = vec_67;
									scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
									vec_70 = _mm512_set1_ps(scal_33);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_915);
									mem_vec_915 = vec_69;
									scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
									vec_72 = _mm512_set1_ps(scal_34);


									vec_71 = _mm512_fmadd_ps(vec_72, vec_60, mem_vec_916);
									mem_vec_916 = vec_71;
									scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
									vec_74 = _mm512_set1_ps(scal_35);


									vec_73 = _mm512_fmadd_ps(vec_74, vec_60, mem_vec_917);
									mem_vec_917 = vec_73;
									scal_36 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_36);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_918);
									mem_vec_918 = vec_75;
									scal_37 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
									vec_78 = _mm512_set1_ps(scal_37);


									vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_919);
									mem_vec_919 = vec_77;
									scal_38 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
									vec_80 = _mm512_set1_ps(scal_38);


									vec_79 = _mm512_fmadd_ps(vec_80, vec_60, mem_vec_920);
									mem_vec_920 = vec_79;
									scal_39 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 2) + c];
									vec_82 = _mm512_set1_ps(scal_39);


									vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_921);
									mem_vec_921 = vec_81;
									scal_40 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h + 2) + c];
									vec_84 = _mm512_set1_ps(scal_40);


									vec_83 = _mm512_fmadd_ps(vec_84, vec_60, mem_vec_922);
									mem_vec_922 = vec_83;
									scal_41 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h + 2) + c];
									vec_86 = _mm512_set1_ps(scal_41);


									vec_85 = _mm512_fmadd_ps(vec_86, vec_60, mem_vec_923);
									mem_vec_923 = vec_85;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_910);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_911);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_912);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_913);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_914);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_915);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_916);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_917);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_918);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_919);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_920);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_921);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_922);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_923);
					}
				}
			}
		}
	}
}


}