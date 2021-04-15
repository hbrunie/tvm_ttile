#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (7, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (32, c);
  T (8, x)]
*/
IND_TYPE c, cp_0, c576_p_0, cp_1, c576, w, wp_0, x, xp_0, x768_p_0, x769_p_0, xp_1, x768_p_1, xp_2, x768, x769, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y384 = 0;
IND_TYPE x770 = 0;
IND_TYPE h = 0;
IND_TYPE w350 = 0;
IND_TYPE c577 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4880 ,mem_vec_4881 ,mem_vec_4882 ,mem_vec_4883 ,mem_vec_4884 ,mem_vec_4885 ,mem_vec_4886 ,mem_vec_4887 ,mem_vec_4888 ,mem_vec_4889 ,mem_vec_4890 ,mem_vec_4891 ,mem_vec_4892 ,mem_vec_4893 ,mem_vec_4894 ,mem_vec_4895 ,mem_vec_4896 ,mem_vec_4897 ,mem_vec_4898 ,mem_vec_4899 ,mem_vec_4900 ,mem_vec_4901 ,mem_vec_4902 ,mem_vec_4903 ,mem_vec_4904 ,mem_vec_4905 ,mem_vec_4906 ,mem_vec_4907 ,mem_vec_4908 ,mem_vec_4909 ,mem_vec_4910 ,mem_vec_4911 ,mem_vec_4912 ,mem_vec_4913 ,mem_vec_4914 ,mem_vec_4915 ,mem_vec_4916 ,mem_vec_4917 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 8) (112 / 14)
for (x769 = x770, x769_p_0 = 0;
	x769 < x770 + 112;
	x769 += 14, x769_p_0 += 14){
	// y = 112, x = 14, h = 3, w = 3, c = 32, f = 32
	// T (c, 32) (32 / 1)
	for (c576 = c577, c576_p_0 = 0;
		c576 < c577 + 32;
		c576 += 1, c576_p_0 += 1){
			for (y = y384, yp_0 = 0;
				y < y384 + 24;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
				// T (x, 7) (14 / 2)
				for (x768 = x769, x768_p_1 = x769_p_0, x768_p_0 = 0;
					x768 < x769 + 14;
					x768 += 2, x768_p_1 += 2, x768_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 32
					// T (w, 3) (3 / 1)
					for (w = w350, wp_0 = 0;
						w < w350 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 32
						// T (x, 2) (2 / 1)
						for (x = x768, xp_2 = x768_p_1, xp_1 = x768_p_0, xp_0 = 0;
							x < x768 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_4880 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4881 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_4889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_4890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_4891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_4892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_4893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_4894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_4895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
										c < c576 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4880);
										mem_vec_4880 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4881);
										mem_vec_4881 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4882);
										mem_vec_4882 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4883);
										mem_vec_4883 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4884);
										mem_vec_4884 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4885);
										mem_vec_4885 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4886);
										mem_vec_4886 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4887);
										mem_vec_4887 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4888);
										mem_vec_4888 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4889);
										mem_vec_4889 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4890);
										mem_vec_4890 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4891);
										mem_vec_4891 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4892);
										mem_vec_4892 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4893);
										mem_vec_4893 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4894);
										mem_vec_4894 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4895);
										mem_vec_4895 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_4880);
										mem_vec_4880 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_4881);
										mem_vec_4881 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_4882);
										mem_vec_4882 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_4883);
										mem_vec_4883 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_4884);
										mem_vec_4884 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_4885);
										mem_vec_4885 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_4886);
										mem_vec_4886 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4887);
										mem_vec_4887 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_4888);
										mem_vec_4888 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_4889);
										mem_vec_4889 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_4890);
										mem_vec_4890 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_4891);
										mem_vec_4891 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_4892);
										mem_vec_4892 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_4893);
										mem_vec_4893 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_4894);
										mem_vec_4894 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_4895);
										mem_vec_4895 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_4880);
										mem_vec_4880 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_4881);
										mem_vec_4881 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_4882);
										mem_vec_4882 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4883);
										mem_vec_4883 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_4884);
										mem_vec_4884 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_4885);
										mem_vec_4885 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_4886);
										mem_vec_4886 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_4887);
										mem_vec_4887 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_4888);
										mem_vec_4888 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_4889);
										mem_vec_4889 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_4890);
										mem_vec_4890 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_4891);
										mem_vec_4891 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_4892);
										mem_vec_4892 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_4893);
										mem_vec_4893 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_4894);
										mem_vec_4894 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_4895);
										mem_vec_4895 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4880);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4881);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4882);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4883);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4884);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4885);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4886);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4887);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4888);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4889);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4890);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4891);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4892);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4893);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4894);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4895);
						}
					}
				}
			}
			for (y = y384 + 24, yp_0 = 0;
				y < y384 + 24 + 88;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
				// T (x, 7) (14 / 2)
				for (x768 = x769, x768_p_1 = x769_p_0, x768_p_0 = 0;
					x768 < x769 + 14;
					x768 += 2, x768_p_1 += 2, x768_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 32
					// T (w, 3) (3 / 1)
					for (w = w350, wp_0 = 0;
						w < w350 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 32
						// T (x, 2) (2 / 1)
						for (x = x768, xp_2 = x768_p_1, xp_1 = x768_p_0, xp_0 = 0;
							x < x768 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_4896 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_4905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_4906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_4907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_4908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_4909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_4910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_4911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_4912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_4913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_4914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_4915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_4916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_4917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
										c < c576 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4896);
										mem_vec_4896 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4897);
										mem_vec_4897 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4898);
										mem_vec_4898 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4899);
										mem_vec_4899 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4900);
										mem_vec_4900 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4901);
										mem_vec_4901 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4902);
										mem_vec_4902 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4903);
										mem_vec_4903 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4904);
										mem_vec_4904 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4905);
										mem_vec_4905 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4906);
										mem_vec_4906 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4907);
										mem_vec_4907 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4908);
										mem_vec_4908 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4909);
										mem_vec_4909 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4910);
										mem_vec_4910 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4911);
										mem_vec_4911 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4912);
										mem_vec_4912 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4913);
										mem_vec_4913 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4914);
										mem_vec_4914 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4915);
										mem_vec_4915 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4916);
										mem_vec_4916 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4917);
										mem_vec_4917 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_4896);
										mem_vec_4896 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_4897);
										mem_vec_4897 = vec_38;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_4898);
										mem_vec_4898 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_4899);
										mem_vec_4899 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_4900);
										mem_vec_4900 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_4901);
										mem_vec_4901 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_4902);
										mem_vec_4902 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_4903);
										mem_vec_4903 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_4904);
										mem_vec_4904 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_4905);
										mem_vec_4905 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_4906);
										mem_vec_4906 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_4907);
										mem_vec_4907 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_4908);
										mem_vec_4908 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_4909);
										mem_vec_4909 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_4910);
										mem_vec_4910 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_4911);
										mem_vec_4911 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_4912);
										mem_vec_4912 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_4913);
										mem_vec_4913 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_4914);
										mem_vec_4914 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_4915);
										mem_vec_4915 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_4916);
										mem_vec_4916 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_4917);
										mem_vec_4917 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_71 = _mm512_set1_ps(scal_22);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_4896);
										mem_vec_4896 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_4897);
										mem_vec_4897 = vec_73;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_4898);
										mem_vec_4898 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_4899);
										mem_vec_4899 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_4900);
										mem_vec_4900 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_4901);
										mem_vec_4901 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_4902);
										mem_vec_4902 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_4903);
										mem_vec_4903 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_4904);
										mem_vec_4904 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_4905);
										mem_vec_4905 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_4906);
										mem_vec_4906 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_4907);
										mem_vec_4907 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_4908);
										mem_vec_4908 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_4909);
										mem_vec_4909 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_4910);
										mem_vec_4910 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_4911);
										mem_vec_4911 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_4912);
										mem_vec_4912 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_4913);
										mem_vec_4913 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_4914);
										mem_vec_4914 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_4915);
										mem_vec_4915 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_4916);
										mem_vec_4916 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_4917);
										mem_vec_4917 = vec_104;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4903);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4917);
						}
					}
				}
			}
	}
}


}