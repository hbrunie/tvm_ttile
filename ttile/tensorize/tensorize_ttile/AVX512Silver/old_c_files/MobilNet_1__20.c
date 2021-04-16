#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (112, x); Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))];
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c561_p_0, cp_1, c561, w, wp_0, x, xp_0, y, yp_0, y522_p_0, yp_1, y522;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y523 = 0;
IND_TYPE x452 = 0;
IND_TYPE h = 0;
IND_TYPE w273 = 0;
IND_TYPE c562 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5807 ,mem_vec_5808 ,mem_vec_5809 ,mem_vec_5810 ,mem_vec_5811 ,mem_vec_5812 ,mem_vec_5813 ,mem_vec_5814 ,mem_vec_5815 ,mem_vec_5816 ,mem_vec_5817 ,mem_vec_5818 ,mem_vec_5819 ,mem_vec_5820 ,mem_vec_5821 ,mem_vec_5822 ,mem_vec_5823 ,mem_vec_5824 ,mem_vec_5825 ,mem_vec_5826 ,mem_vec_5827 ,mem_vec_5828 ,mem_vec_5829 ,mem_vec_5830 ,mem_vec_5831 ,mem_vec_5832 ,mem_vec_5833 ,mem_vec_5834 ,mem_vec_5835 ,mem_vec_5836 ,mem_vec_5837 ,mem_vec_5838 ,mem_vec_5839 ,mem_vec_5840 ,mem_vec_5841 ,mem_vec_5842 ,mem_vec_5843 ,mem_vec_5844 ,mem_vec_5845 ,mem_vec_5846 ,mem_vec_5847 ,mem_vec_5848 ,mem_vec_5849 ,mem_vec_5850 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 1) (112 / 112)
for (y522 = y523, y522_p_0 = 0;
	y522 < y523 + 112;
	y522 += 112, y522_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c561 = c562, c561_p_0 = 0;
		c561 < c562 + 32;
		c561 += 32, c561_p_0 += 32){
			for (y = y522, yp_1 = y522_p_0, yp_0 = 0;
				y < y522 + 56;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x452, xp_0 = 0;
					x < x452 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w273, wp_0 = 0;
						w < w273 + 3;
						w += 1, wp_0 += 1){
								mem_vec_5807 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5808 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_5822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c561, cp_1 = c561_p_0, cp_0 = 0;
									c < c561 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5807);
									mem_vec_5807 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5808);
									mem_vec_5808 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5809);
									mem_vec_5809 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5810);
									mem_vec_5810 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5811);
									mem_vec_5811 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5812);
									mem_vec_5812 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5813);
									mem_vec_5813 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5814);
									mem_vec_5814 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5815);
									mem_vec_5815 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5816);
									mem_vec_5816 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5817);
									mem_vec_5817 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5818);
									mem_vec_5818 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5819);
									mem_vec_5819 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5820);
									mem_vec_5820 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5821);
									mem_vec_5821 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5822);
									mem_vec_5822 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_5807);
									mem_vec_5807 = vec_26;

									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_5808);
									mem_vec_5808 = vec_29;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_32 = _mm512_set1_ps(scal_9);


									vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_5809);
									mem_vec_5809 = vec_31;



									vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_5810);
									mem_vec_5810 = vec_33;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_10);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_5811);
									mem_vec_5811 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_5812);
									mem_vec_5812 = vec_36;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_5813);
									mem_vec_5813 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_5814);
									mem_vec_5814 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_5815);
									mem_vec_5815 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_5816);
									mem_vec_5816 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5817);
									mem_vec_5817 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5818);
									mem_vec_5818 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_47 = _mm512_set1_ps(scal_14);


									vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_5819);
									mem_vec_5819 = vec_46;



									vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_5820);
									mem_vec_5820 = vec_48;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_5821);
									mem_vec_5821 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_5822);
									mem_vec_5822 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_53 = _mm512_set1_ps(scal_16);
									vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_5807);
									mem_vec_5807 = vec_52;

									vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_5808);
									mem_vec_5808 = vec_55;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_58 = _mm512_set1_ps(scal_17);


									vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5809);
									mem_vec_5809 = vec_57;



									vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5810);
									mem_vec_5810 = vec_59;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_61 = _mm512_set1_ps(scal_18);


									vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_5811);
									mem_vec_5811 = vec_60;



									vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_5812);
									mem_vec_5812 = vec_62;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_19);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_5813);
									mem_vec_5813 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_5814);
									mem_vec_5814 = vec_65;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_67 = _mm512_set1_ps(scal_20);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_5815);
									mem_vec_5815 = vec_66;



									vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_5816);
									mem_vec_5816 = vec_68;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_70 = _mm512_set1_ps(scal_21);


									vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_5817);
									mem_vec_5817 = vec_69;



									vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_5818);
									mem_vec_5818 = vec_71;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_73 = _mm512_set1_ps(scal_22);


									vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_5819);
									mem_vec_5819 = vec_72;



									vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_5820);
									mem_vec_5820 = vec_74;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_23);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_5821);
									mem_vec_5821 = vec_75;



									vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_5822);
									mem_vec_5822 = vec_77;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5807);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5808);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5809);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5810);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5811);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5812);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5813);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5814);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5815);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5816);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5817);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5818);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5819);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5820);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5821);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5822);
					}
				}
			}
			for (y = y522 + 56, yp_1 = y522_p_0, yp_0 = 0;
				y < y522 + 56 + 56;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x452, xp_0 = 0;
					x < x452 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w273, wp_0 = 0;
						w < w273 + 3;
						w += 1, wp_0 += 1){
								mem_vec_5823 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5824 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_5838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_5839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_5840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_5841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_5842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_5843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_5844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_5845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_5846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_5847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_5848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								mem_vec_5849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								mem_vec_5850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c561, cp_1 = c561_p_0, cp_0 = 0;
									c < c561 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5823);
									mem_vec_5823 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5824);
									mem_vec_5824 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5825);
									mem_vec_5825 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5826);
									mem_vec_5826 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5827);
									mem_vec_5827 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5828);
									mem_vec_5828 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5829);
									mem_vec_5829 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5830);
									mem_vec_5830 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5831);
									mem_vec_5831 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5832);
									mem_vec_5832 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5833);
									mem_vec_5833 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5834);
									mem_vec_5834 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5835);
									mem_vec_5835 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5836);
									mem_vec_5836 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5837);
									mem_vec_5837 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5838);
									mem_vec_5838 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5839);
									mem_vec_5839 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5840);
									mem_vec_5840 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5841);
									mem_vec_5841 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5842);
									mem_vec_5842 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5843);
									mem_vec_5843 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5844);
									mem_vec_5844 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5845);
									mem_vec_5845 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5846);
									mem_vec_5846 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5847);
									mem_vec_5847 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5848);
									mem_vec_5848 = vec_40;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5849);
									mem_vec_5849 = vec_41;



									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5850);
									mem_vec_5850 = vec_43;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_45 = _mm512_set1_ps(scal_14);
									vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_5823);
									mem_vec_5823 = vec_44;

									vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_47 = _mm512_fmadd_ps(vec_45, vec_48, mem_vec_5824);
									mem_vec_5824 = vec_47;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_50 = _mm512_set1_ps(scal_15);


									vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_5825);
									mem_vec_5825 = vec_49;



									vec_51 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_5826);
									mem_vec_5826 = vec_51;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_53 = _mm512_set1_ps(scal_16);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_5827);
									mem_vec_5827 = vec_52;



									vec_54 = _mm512_fmadd_ps(vec_53, vec_48, mem_vec_5828);
									mem_vec_5828 = vec_54;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_56 = _mm512_set1_ps(scal_17);


									vec_55 = _mm512_fmadd_ps(vec_56, vec_46, mem_vec_5829);
									mem_vec_5829 = vec_55;



									vec_57 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_5830);
									mem_vec_5830 = vec_57;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_59 = _mm512_set1_ps(scal_18);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_46, mem_vec_5831);
									mem_vec_5831 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_48, mem_vec_5832);
									mem_vec_5832 = vec_60;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_62 = _mm512_set1_ps(scal_19);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_46, mem_vec_5833);
									mem_vec_5833 = vec_61;



									vec_63 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_5834);
									mem_vec_5834 = vec_63;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_65 = _mm512_set1_ps(scal_20);


									vec_64 = _mm512_fmadd_ps(vec_65, vec_46, mem_vec_5835);
									mem_vec_5835 = vec_64;



									vec_66 = _mm512_fmadd_ps(vec_65, vec_48, mem_vec_5836);
									mem_vec_5836 = vec_66;
									scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
									vec_68 = _mm512_set1_ps(scal_21);


									vec_67 = _mm512_fmadd_ps(vec_68, vec_46, mem_vec_5837);
									mem_vec_5837 = vec_67;



									vec_69 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_5838);
									mem_vec_5838 = vec_69;
									scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
									vec_71 = _mm512_set1_ps(scal_22);


									vec_70 = _mm512_fmadd_ps(vec_71, vec_46, mem_vec_5839);
									mem_vec_5839 = vec_70;



									vec_72 = _mm512_fmadd_ps(vec_71, vec_48, mem_vec_5840);
									mem_vec_5840 = vec_72;
									scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
									vec_74 = _mm512_set1_ps(scal_23);


									vec_73 = _mm512_fmadd_ps(vec_74, vec_46, mem_vec_5841);
									mem_vec_5841 = vec_73;



									vec_75 = _mm512_fmadd_ps(vec_74, vec_48, mem_vec_5842);
									mem_vec_5842 = vec_75;
									scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
									vec_77 = _mm512_set1_ps(scal_24);


									vec_76 = _mm512_fmadd_ps(vec_77, vec_46, mem_vec_5843);
									mem_vec_5843 = vec_76;



									vec_78 = _mm512_fmadd_ps(vec_77, vec_48, mem_vec_5844);
									mem_vec_5844 = vec_78;
									scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
									vec_80 = _mm512_set1_ps(scal_25);


									vec_79 = _mm512_fmadd_ps(vec_80, vec_46, mem_vec_5845);
									mem_vec_5845 = vec_79;



									vec_81 = _mm512_fmadd_ps(vec_80, vec_48, mem_vec_5846);
									mem_vec_5846 = vec_81;
									scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
									vec_83 = _mm512_set1_ps(scal_26);


									vec_82 = _mm512_fmadd_ps(vec_83, vec_46, mem_vec_5847);
									mem_vec_5847 = vec_82;



									vec_84 = _mm512_fmadd_ps(vec_83, vec_48, mem_vec_5848);
									mem_vec_5848 = vec_84;
									scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
									vec_86 = _mm512_set1_ps(scal_27);


									vec_85 = _mm512_fmadd_ps(vec_86, vec_46, mem_vec_5849);
									mem_vec_5849 = vec_85;



									vec_87 = _mm512_fmadd_ps(vec_86, vec_48, mem_vec_5850);
									mem_vec_5850 = vec_87;
									scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_89 = _mm512_set1_ps(scal_28);
									vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_5823);
									mem_vec_5823 = vec_88;

									vec_92 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_91 = _mm512_fmadd_ps(vec_89, vec_92, mem_vec_5824);
									mem_vec_5824 = vec_91;
									scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_94 = _mm512_set1_ps(scal_29);


									vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_5825);
									mem_vec_5825 = vec_93;



									vec_95 = _mm512_fmadd_ps(vec_94, vec_92, mem_vec_5826);
									mem_vec_5826 = vec_95;
									scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_97 = _mm512_set1_ps(scal_30);


									vec_96 = _mm512_fmadd_ps(vec_97, vec_90, mem_vec_5827);
									mem_vec_5827 = vec_96;



									vec_98 = _mm512_fmadd_ps(vec_97, vec_92, mem_vec_5828);
									mem_vec_5828 = vec_98;
									scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_100 = _mm512_set1_ps(scal_31);


									vec_99 = _mm512_fmadd_ps(vec_100, vec_90, mem_vec_5829);
									mem_vec_5829 = vec_99;



									vec_101 = _mm512_fmadd_ps(vec_100, vec_92, mem_vec_5830);
									mem_vec_5830 = vec_101;
									scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_103 = _mm512_set1_ps(scal_32);


									vec_102 = _mm512_fmadd_ps(vec_103, vec_90, mem_vec_5831);
									mem_vec_5831 = vec_102;



									vec_104 = _mm512_fmadd_ps(vec_103, vec_92, mem_vec_5832);
									mem_vec_5832 = vec_104;
									scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_106 = _mm512_set1_ps(scal_33);


									vec_105 = _mm512_fmadd_ps(vec_106, vec_90, mem_vec_5833);
									mem_vec_5833 = vec_105;



									vec_107 = _mm512_fmadd_ps(vec_106, vec_92, mem_vec_5834);
									mem_vec_5834 = vec_107;
									scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_109 = _mm512_set1_ps(scal_34);


									vec_108 = _mm512_fmadd_ps(vec_109, vec_90, mem_vec_5835);
									mem_vec_5835 = vec_108;



									vec_110 = _mm512_fmadd_ps(vec_109, vec_92, mem_vec_5836);
									mem_vec_5836 = vec_110;
									scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
									vec_112 = _mm512_set1_ps(scal_35);


									vec_111 = _mm512_fmadd_ps(vec_112, vec_90, mem_vec_5837);
									mem_vec_5837 = vec_111;



									vec_113 = _mm512_fmadd_ps(vec_112, vec_92, mem_vec_5838);
									mem_vec_5838 = vec_113;
									scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
									vec_115 = _mm512_set1_ps(scal_36);


									vec_114 = _mm512_fmadd_ps(vec_115, vec_90, mem_vec_5839);
									mem_vec_5839 = vec_114;



									vec_116 = _mm512_fmadd_ps(vec_115, vec_92, mem_vec_5840);
									mem_vec_5840 = vec_116;
									scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
									vec_118 = _mm512_set1_ps(scal_37);


									vec_117 = _mm512_fmadd_ps(vec_118, vec_90, mem_vec_5841);
									mem_vec_5841 = vec_117;



									vec_119 = _mm512_fmadd_ps(vec_118, vec_92, mem_vec_5842);
									mem_vec_5842 = vec_119;
									scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
									vec_121 = _mm512_set1_ps(scal_38);


									vec_120 = _mm512_fmadd_ps(vec_121, vec_90, mem_vec_5843);
									mem_vec_5843 = vec_120;



									vec_122 = _mm512_fmadd_ps(vec_121, vec_92, mem_vec_5844);
									mem_vec_5844 = vec_122;
									scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
									vec_124 = _mm512_set1_ps(scal_39);


									vec_123 = _mm512_fmadd_ps(vec_124, vec_90, mem_vec_5845);
									mem_vec_5845 = vec_123;



									vec_125 = _mm512_fmadd_ps(vec_124, vec_92, mem_vec_5846);
									mem_vec_5846 = vec_125;
									scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
									vec_127 = _mm512_set1_ps(scal_40);


									vec_126 = _mm512_fmadd_ps(vec_127, vec_90, mem_vec_5847);
									mem_vec_5847 = vec_126;



									vec_128 = _mm512_fmadd_ps(vec_127, vec_92, mem_vec_5848);
									mem_vec_5848 = vec_128;
									scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
									vec_130 = _mm512_set1_ps(scal_41);


									vec_129 = _mm512_fmadd_ps(vec_130, vec_90, mem_vec_5849);
									mem_vec_5849 = vec_129;



									vec_131 = _mm512_fmadd_ps(vec_130, vec_92, mem_vec_5850);
									mem_vec_5850 = vec_131;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5823);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5824);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5825);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5826);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5827);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5828);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5829);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5830);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5831);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5832);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5833);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5834);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5835);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5836);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5837);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5838);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5839);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5840);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5841);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5842);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5843);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5844);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5845);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5846);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5847);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5848);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5849);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5850);
					}
				}
			}
	}
}


}