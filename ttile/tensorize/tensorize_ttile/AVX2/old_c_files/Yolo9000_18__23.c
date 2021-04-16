#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (4, f); T (8, c); T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c147_p_0, cp_1, c147, f, fp_0, f196_p_0, f197_p_0, fp_1, f196_p_1, fp_2, f196, f197, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y98 = 0;
IND_TYPE x98 = 0;
IND_TYPE h = 0;
IND_TYPE w87 = 0;
IND_TYPE c148 = 0;
IND_TYPE f198 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1920 ,mem_vec_1921 ,mem_vec_1922 ,mem_vec_1923 ,mem_vec_1924 ,mem_vec_1925 ,mem_vec_1926 ,mem_vec_1927 ,mem_vec_1928 ,mem_vec_1929 ,mem_vec_1930 ,mem_vec_1931 ,mem_vec_1932 ,mem_vec_1933 ,mem_vec_1934 ,mem_vec_1935 ,mem_vec_1936 ,mem_vec_1937 ,mem_vec_1938 ,mem_vec_1939 ,mem_vec_1940 ,mem_vec_1941 ,mem_vec_1942 ,mem_vec_1943 ,mem_vec_1944 ,mem_vec_1945 ,mem_vec_1946 ,mem_vec_1947 ,mem_vec_1948 ,mem_vec_1949 ,mem_vec_1950 ,mem_vec_1951 ,mem_vec_1952 ,mem_vec_1953 ,mem_vec_1954 ,mem_vec_1955 ,mem_vec_1956 ,mem_vec_1957 ,mem_vec_1958 ,mem_vec_1959 ,mem_vec_1960 ,mem_vec_1961 ,mem_vec_1962 ,mem_vec_1963 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f197 = f198, f197_p_0 = 0;
	f197 < f198 + 1024;
	f197 += 512, f197_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 4) (512 / 128)
	for (f196 = f197, f196_p_1 = f197_p_0, f196_p_0 = 0;
		f196 < f197 + 512;
		f196 += 128, f196_p_1 += 128, f196_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
		// T (c, 8) (512 / 64)
		for (c147 = c148, c147_p_0 = 0;
			c147 < c148 + 512;
			c147 += 64, c147_p_0 += 64){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
			// T (f, 4) (128 / 32)
			for (f = f196, fp_2 = f196_p_1, fp_1 = f196_p_0, fp_0 = 0;
				f < f196 + 128;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y98, yp_0 = 0;
						y < y98 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x98, xp_0 = 0;
							x < x98 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w87, wp_0 = 0;
								w < w87 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1920 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1921 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1922 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1923 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c147, cp_1 = c147_p_0, cp_0 = 0;
											c < c147 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1920);
											mem_vec_1920 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1921);
											mem_vec_1921 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1922);
											mem_vec_1922 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1923);
											mem_vec_1923 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1924);
											mem_vec_1924 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1925);
											mem_vec_1925 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1926);
											mem_vec_1926 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1927);
											mem_vec_1927 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1928);
											mem_vec_1928 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1929);
											mem_vec_1929 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1930);
											mem_vec_1930 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1931);
											mem_vec_1931 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1932);
											mem_vec_1932 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1933);
											mem_vec_1933 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1934);
											mem_vec_1934 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1935);
											mem_vec_1935 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1936);
											mem_vec_1936 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1937);
											mem_vec_1937 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1938);
											mem_vec_1938 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1939);
											mem_vec_1939 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1920);
											mem_vec_1920 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1921);
											mem_vec_1921 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1922);
											mem_vec_1922 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1923);
											mem_vec_1923 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1924);
											mem_vec_1924 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1925);
											mem_vec_1925 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1926);
											mem_vec_1926 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1927);
											mem_vec_1927 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1928);
											mem_vec_1928 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1929);
											mem_vec_1929 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1930);
											mem_vec_1930 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1931);
											mem_vec_1931 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1932);
											mem_vec_1932 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1933);
											mem_vec_1933 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1934);
											mem_vec_1934 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1935);
											mem_vec_1935 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1936);
											mem_vec_1936 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1937);
											mem_vec_1937 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1938);
											mem_vec_1938 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1939);
											mem_vec_1939 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1920);
											mem_vec_1920 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1921);
											mem_vec_1921 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1922);
											mem_vec_1922 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1923);
											mem_vec_1923 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1924);
											mem_vec_1924 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1925);
											mem_vec_1925 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1926);
											mem_vec_1926 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1927);
											mem_vec_1927 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1928);
											mem_vec_1928 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1929);
											mem_vec_1929 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1930);
											mem_vec_1930 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1931);
											mem_vec_1931 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1932);
											mem_vec_1932 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1933);
											mem_vec_1933 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1934);
											mem_vec_1934 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1935);
											mem_vec_1935 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1936);
											mem_vec_1936 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1937);
											mem_vec_1937 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1938);
											mem_vec_1938 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1939);
											mem_vec_1939 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1920);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1921);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1922);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1923);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1924);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1925);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1926);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1927);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1928);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1929);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1930);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1931);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1932);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1933);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1934);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1935);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1936);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1937);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1938);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1939);
							}
						}
					}
					for (y = y98 + 5, yp_0 = 0;
						y < y98 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x98, xp_0 = 0;
							x < x98 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w87, wp_0 = 0;
								w < w87 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1940 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1941 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1942 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1943 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_1960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_1962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c147, cp_1 = c147_p_0, cp_0 = 0;
											c < c147 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1940);
											mem_vec_1940 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1941);
											mem_vec_1941 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1942);
											mem_vec_1942 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1943);
											mem_vec_1943 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1944);
											mem_vec_1944 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1945);
											mem_vec_1945 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1946);
											mem_vec_1946 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1947);
											mem_vec_1947 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1948);
											mem_vec_1948 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1949);
											mem_vec_1949 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1950);
											mem_vec_1950 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1951);
											mem_vec_1951 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1952);
											mem_vec_1952 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1953);
											mem_vec_1953 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1954);
											mem_vec_1954 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1955);
											mem_vec_1955 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1956);
											mem_vec_1956 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1957);
											mem_vec_1957 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1958);
											mem_vec_1958 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1959);
											mem_vec_1959 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1960);
											mem_vec_1960 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1961);
											mem_vec_1961 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1962);
											mem_vec_1962 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1963);
											mem_vec_1963 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1940);
											mem_vec_1940 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1941);
											mem_vec_1941 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1942);
											mem_vec_1942 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1943);
											mem_vec_1943 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1944);
											mem_vec_1944 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1945);
											mem_vec_1945 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1946);
											mem_vec_1946 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1947);
											mem_vec_1947 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1948);
											mem_vec_1948 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1949);
											mem_vec_1949 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1950);
											mem_vec_1950 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1951);
											mem_vec_1951 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1952);
											mem_vec_1952 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1953);
											mem_vec_1953 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1954);
											mem_vec_1954 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1955);
											mem_vec_1955 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1956);
											mem_vec_1956 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1957);
											mem_vec_1957 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1958);
											mem_vec_1958 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1959);
											mem_vec_1959 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1960);
											mem_vec_1960 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1961);
											mem_vec_1961 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1962);
											mem_vec_1962 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1963);
											mem_vec_1963 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1940);
											mem_vec_1940 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1941);
											mem_vec_1941 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1942);
											mem_vec_1942 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1943);
											mem_vec_1943 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1944);
											mem_vec_1944 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1945);
											mem_vec_1945 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1946);
											mem_vec_1946 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1947);
											mem_vec_1947 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1948);
											mem_vec_1948 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1949);
											mem_vec_1949 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1950);
											mem_vec_1950 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1951);
											mem_vec_1951 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1952);
											mem_vec_1952 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1953);
											mem_vec_1953 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1954);
											mem_vec_1954 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1955);
											mem_vec_1955 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1956);
											mem_vec_1956 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1957);
											mem_vec_1957 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1958);
											mem_vec_1958 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1959);
											mem_vec_1959 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1960);
											mem_vec_1960 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1961);
											mem_vec_1961 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1962);
											mem_vec_1962 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1963);
											mem_vec_1963 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1940);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1941);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1942);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1943);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1944);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1945);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1946);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1947);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1948);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1949);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1950);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1951);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1952);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1953);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1954);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1955);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1956);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1957);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1958);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1959);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1960);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1961);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1962);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1963);
							}
						}
					}
			}
		}
	}
}


}