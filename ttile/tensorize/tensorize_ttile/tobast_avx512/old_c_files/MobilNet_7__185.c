#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (7, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 1), (Arg 10))];
  T (2, f); T (4, c); T (8, f); T (16, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c956_p_0, c957_p_0, cp_1, c956_p_1, cp_2, c956, c957, f, fp_0, f816_p_0, f817_p_0, fp_1, f816_p_1, fp_2, f816, f817, h, hp_0, x, xp_0, x734_p_0, xp_1, x734, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y492 = 0;
IND_TYPE x735 = 0;
IND_TYPE h432 = 0;
IND_TYPE w = 0;
IND_TYPE c958 = 0;
IND_TYPE f818 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,mem_vec_4856 ,mem_vec_4857 ,mem_vec_4858 ,mem_vec_4859 ,mem_vec_4860 ,mem_vec_4861 ,mem_vec_4862 ,mem_vec_4863 ,mem_vec_4864 ,mem_vec_4865 ,mem_vec_4866 ,mem_vec_4867 ,mem_vec_4868 ,mem_vec_4869 ,mem_vec_4870 ,mem_vec_4871 ,mem_vec_4872 ,mem_vec_4873 ,mem_vec_4874 ,mem_vec_4875 ,mem_vec_4876 ,mem_vec_4877 ,mem_vec_4878 ,mem_vec_4879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f817 = f818, f817_p_0 = 0;
	f817 < f818 + 512;
	f817 += 512, f817_p_0 += 512){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
	// T (x, 2) (14 / 7)
	for (x734 = x735, x734_p_0 = 0;
		x734 < x735 + 14;
		x734 += 7, x734_p_0 += 7){
		// y = 14, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (c, 16) (512 / 32)
		for (c957 = c958, c957_p_0 = 0;
			c957 < c958 + 512;
			c957 += 32, c957_p_0 += 32){
			// y = 14, x = 7, h = 3, w = 3, c = 32, f = 512
			// T (f, 8) (512 / 64)
			for (f816 = f817, f816_p_1 = f817_p_0, f816_p_0 = 0;
				f816 < f817 + 512;
				f816 += 64, f816_p_1 += 64, f816_p_0 += 64){
				// y = 14, x = 7, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c956 = c957, c956_p_1 = c957_p_0, c956_p_0 = 0;
					c956 < c957 + 32;
					c956 += 8, c956_p_1 += 8, c956_p_0 += 8){
					// y = 14, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f816, fp_2 = f816_p_1, fp_1 = f816_p_0, fp_0 = 0;
						f < f816 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y492, yp_0 = 0;
								y < y492 + 4;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h432, hp_0 = 0;
									h < h432 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 32
									// T (x, 7) (7 / 1)
									for (x = x734, xp_1 = x734_p_0, xp_0 = 0;
										x < x734 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c956, cp_2 = c956_p_1, cp_1 = c956_p_0, cp_0 = 0;
													c < c956 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4852);
													mem_vec_4852 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4853);
													mem_vec_4853 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4854);
													mem_vec_4854 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4855);
													mem_vec_4855 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4856);
													mem_vec_4856 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4857);
													mem_vec_4857 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4858);
													mem_vec_4858 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4859);
													mem_vec_4859 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4852);
													mem_vec_4852 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4853);
													mem_vec_4853 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_4854);
													mem_vec_4854 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_4855);
													mem_vec_4855 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_4856);
													mem_vec_4856 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_4857);
													mem_vec_4857 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_4858);
													mem_vec_4858 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_4859);
													mem_vec_4859 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4852);
													mem_vec_4852 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4853);
													mem_vec_4853 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4854);
													mem_vec_4854 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4855);
													mem_vec_4855 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_4856);
													mem_vec_4856 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_4857);
													mem_vec_4857 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_4858);
													mem_vec_4858 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_4859);
													mem_vec_4859 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4855);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4856);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4857);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4858);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4859);
									}
								}
							}
							for (y = y492 + 4, yp_0 = 0;
								y < y492 + 4 + 10;
								y += 10, yp_0 += 10){
								// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h432, hp_0 = 0;
									h < h432 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 32
									// T (x, 7) (7 / 1)
									for (x = x734, xp_1 = x734_p_0, xp_0 = 0;
										x < x734 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_4876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_4877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_4878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_4879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c956, cp_2 = c956_p_1, cp_1 = c956_p_0, cp_0 = 0;
													c < c956 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4860);
													mem_vec_4860 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4861);
													mem_vec_4861 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4862);
													mem_vec_4862 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4863);
													mem_vec_4863 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4864);
													mem_vec_4864 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4865);
													mem_vec_4865 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4866);
													mem_vec_4866 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4867);
													mem_vec_4867 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4868);
													mem_vec_4868 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4869);
													mem_vec_4869 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4870);
													mem_vec_4870 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4871);
													mem_vec_4871 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4872);
													mem_vec_4872 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4873);
													mem_vec_4873 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4874);
													mem_vec_4874 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4875);
													mem_vec_4875 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4876);
													mem_vec_4876 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4877);
													mem_vec_4877 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4878);
													mem_vec_4878 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4879);
													mem_vec_4879 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_4860);
													mem_vec_4860 = vec_32;

													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_4861);
													mem_vec_4861 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4862);
													mem_vec_4862 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4863);
													mem_vec_4863 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);


													vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_4864);
													mem_vec_4864 = vec_40;



													vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_4865);
													mem_vec_4865 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm512_set1_ps(scal_13);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_4866);
													mem_vec_4866 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_4867);
													mem_vec_4867 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_47 = _mm512_set1_ps(scal_14);


													vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_4868);
													mem_vec_4868 = vec_46;



													vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_4869);
													mem_vec_4869 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_50 = _mm512_set1_ps(scal_15);


													vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_4870);
													mem_vec_4870 = vec_49;



													vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_4871);
													mem_vec_4871 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_53 = _mm512_set1_ps(scal_16);


													vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_4872);
													mem_vec_4872 = vec_52;



													vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_4873);
													mem_vec_4873 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
													vec_56 = _mm512_set1_ps(scal_17);


													vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_4874);
													mem_vec_4874 = vec_55;



													vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_4875);
													mem_vec_4875 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
													vec_59 = _mm512_set1_ps(scal_18);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_4876);
													mem_vec_4876 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_4877);
													mem_vec_4877 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
													vec_62 = _mm512_set1_ps(scal_19);


													vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_4878);
													mem_vec_4878 = vec_61;



													vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_4879);
													mem_vec_4879 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_65 = _mm512_set1_ps(scal_20);
													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_4860);
													mem_vec_4860 = vec_64;

													vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_4861);
													mem_vec_4861 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_70 = _mm512_set1_ps(scal_21);


													vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_4862);
													mem_vec_4862 = vec_69;



													vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_4863);
													mem_vec_4863 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm512_set1_ps(scal_22);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4864);
													mem_vec_4864 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_4865);
													mem_vec_4865 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_76 = _mm512_set1_ps(scal_23);


													vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_4866);
													mem_vec_4866 = vec_75;



													vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_4867);
													mem_vec_4867 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_79 = _mm512_set1_ps(scal_24);


													vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_4868);
													mem_vec_4868 = vec_78;



													vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_4869);
													mem_vec_4869 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_82 = _mm512_set1_ps(scal_25);


													vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_4870);
													mem_vec_4870 = vec_81;



													vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_4871);
													mem_vec_4871 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_85 = _mm512_set1_ps(scal_26);


													vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_4872);
													mem_vec_4872 = vec_84;



													vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_4873);
													mem_vec_4873 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
													vec_88 = _mm512_set1_ps(scal_27);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_4874);
													mem_vec_4874 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_4875);
													mem_vec_4875 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
													vec_91 = _mm512_set1_ps(scal_28);


													vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_4876);
													mem_vec_4876 = vec_90;



													vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_4877);
													mem_vec_4877 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
													vec_94 = _mm512_set1_ps(scal_29);


													vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_4878);
													mem_vec_4878 = vec_93;



													vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_4879);
													mem_vec_4879 = vec_95;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4860);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4861);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4862);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4863);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4867);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4868);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4869);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4870);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4871);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4872);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4873);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4874);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4875);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4876);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4877);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4878);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4879);
									}
								}
							}
					}
				}
			}
		}
	}
}


}