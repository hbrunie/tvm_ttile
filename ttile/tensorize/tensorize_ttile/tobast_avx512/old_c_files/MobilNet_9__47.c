#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, h); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c); T (16, f); T (1, y); T (4, c); T (1, f); T (8, c)]
*/
IND_TYPE c, cp_0, c538_p_0, c539_p_0, c540_p_0, cp_1, c538_p_1, c539_p_1, cp_2, c538_p_2, cp_3, c538, c539, c540, f, fp_0, f358_p_0, fp_1, f358, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y148 = 0;
IND_TYPE x224 = 0;
IND_TYPE h = 0;
IND_TYPE w224 = 0;
IND_TYPE c541 = 0;
IND_TYPE f359 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1918 ,mem_vec_1919 ,mem_vec_1920 ,mem_vec_1921 ,mem_vec_1922 ,mem_vec_1923 ,mem_vec_1924 ,mem_vec_1925 ,mem_vec_1926 ,mem_vec_1927 ,mem_vec_1928 ,mem_vec_1929 ,mem_vec_1930 ,mem_vec_1931 ,mem_vec_1932 ,mem_vec_1933 ,mem_vec_1934 ,mem_vec_1935 ,mem_vec_1936 ,mem_vec_1937 ,mem_vec_1938 ,mem_vec_1939 ,mem_vec_1940 ,mem_vec_1941 ,mem_vec_1942 ,mem_vec_1943 ,mem_vec_1944 ,mem_vec_1945 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c540 = c541, c540_p_0 = 0;
	c540 < c541 + 1024;
	c540 += 128, c540_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 1) (1024 / 1024)
	for (f358 = f359, f358_p_0 = 0;
		f358 < f359 + 1024;
		f358 += 1024, f358_p_0 += 1024){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
		// T (c, 4) (128 / 32)
		for (c539 = c540, c539_p_1 = c540_p_0, c539_p_0 = 0;
			c539 < c540 + 128;
			c539 += 32, c539_p_1 += 32, c539_p_0 += 32){
			// y = 7, x = 7, h = 3, w = 3, c = 32, f = 1024
			// T (y, 1) (7 / 7)
			for (y = y148, yp_0 = 0;
				y < y148 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 32, f = 1024
				// T (f, 16) (1024 / 64)
				for (f = f358, fp_1 = f358_p_0, fp_0 = 0;
					f < f358 + 1024;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 7, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c538 = c539, c538_p_2 = c539_p_1, c538_p_1 = c539_p_0, c538_p_0 = 0;
						c538 < c539 + 32;
						c538 += 16, c538_p_2 += 16, c538_p_1 += 16, c538_p_0 += 16){
						// y = 7, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w224, wp_0 = 0;
							w < w224 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 3, w = 1, c = 16, f = 64
							// T (x, 7) (7 / 1)
							for (x = x224, xp_0 = 0;
								x < x224 + 7;
								x += 1, xp_0 += 1){
										mem_vec_1918 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1919 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1920 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1921 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_1934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_1937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_1938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_1941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_1942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_1945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c538, cp_3 = c538_p_2, cp_2 = c538_p_1, cp_1 = c538_p_0, cp_0 = 0;
											c < c538 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1918);
											mem_vec_1918 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1919);
											mem_vec_1919 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1920);
											mem_vec_1920 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1921);
											mem_vec_1921 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1922);
											mem_vec_1922 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1923);
											mem_vec_1923 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1924);
											mem_vec_1924 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1925);
											mem_vec_1925 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1926);
											mem_vec_1926 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1927);
											mem_vec_1927 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1928);
											mem_vec_1928 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1929);
											mem_vec_1929 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1930);
											mem_vec_1930 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1931);
											mem_vec_1931 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1932);
											mem_vec_1932 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1933);
											mem_vec_1933 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1934);
											mem_vec_1934 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1935);
											mem_vec_1935 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1936);
											mem_vec_1936 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1937);
											mem_vec_1937 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1938);
											mem_vec_1938 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1939);
											mem_vec_1939 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1940);
											mem_vec_1940 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1941);
											mem_vec_1941 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1942);
											mem_vec_1942 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1943);
											mem_vec_1943 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1944);
											mem_vec_1944 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1945);
											mem_vec_1945 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_1918);
											mem_vec_1918 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_1919);
											mem_vec_1919 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_1920);
											mem_vec_1920 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_1921);
											mem_vec_1921 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_1922);
											mem_vec_1922 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_1923);
											mem_vec_1923 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_1924);
											mem_vec_1924 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_1925);
											mem_vec_1925 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_1926);
											mem_vec_1926 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_1927);
											mem_vec_1927 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_1928);
											mem_vec_1928 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_1929);
											mem_vec_1929 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_1930);
											mem_vec_1930 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_1931);
											mem_vec_1931 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_1932);
											mem_vec_1932 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_1933);
											mem_vec_1933 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_1934);
											mem_vec_1934 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_1935);
											mem_vec_1935 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_1936);
											mem_vec_1936 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_1937);
											mem_vec_1937 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_1938);
											mem_vec_1938 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_1939);
											mem_vec_1939 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_1940);
											mem_vec_1940 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_1941);
											mem_vec_1941 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_1942);
											mem_vec_1942 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_1943);
											mem_vec_1943 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_1944);
											mem_vec_1944 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_1945);
											mem_vec_1945 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_1918);
											mem_vec_1918 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_1919);
											mem_vec_1919 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_1920);
											mem_vec_1920 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_1921);
											mem_vec_1921 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_1922);
											mem_vec_1922 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_1923);
											mem_vec_1923 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_1924);
											mem_vec_1924 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_1925);
											mem_vec_1925 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_1926);
											mem_vec_1926 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_1927);
											mem_vec_1927 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_1928);
											mem_vec_1928 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_1929);
											mem_vec_1929 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_1930);
											mem_vec_1930 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_1931);
											mem_vec_1931 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_1932);
											mem_vec_1932 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_1933);
											mem_vec_1933 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_1934);
											mem_vec_1934 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_1935);
											mem_vec_1935 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_1936);
											mem_vec_1936 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_1937);
											mem_vec_1937 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_1938);
											mem_vec_1938 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_1939);
											mem_vec_1939 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_1940);
											mem_vec_1940 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_1941);
											mem_vec_1941 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_1942);
											mem_vec_1942 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_1943);
											mem_vec_1943 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_1944);
											mem_vec_1944 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_1945);
											mem_vec_1945 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1918);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1919);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1920);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1921);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1931);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1934);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1935);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1939);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1945);
							}
						}
					}
				}
			}
		}
	}
}


}