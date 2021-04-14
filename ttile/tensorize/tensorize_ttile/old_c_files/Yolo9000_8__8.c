#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))];
  T (1, f); T (16, c); T (4, f); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c798_p_0, cp_1, c798, f, fp_0, f1064_p_0, f1065_p_0, fp_1, f1064_p_1, fp_2, f1064, f1065, h, hp_0, w, wp_0, x, xp_0, x850_p_0, xp_1, x850, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y532 = 0;
IND_TYPE x851 = 0;
IND_TYPE h532 = 0;
IND_TYPE w480 = 0;
IND_TYPE c799 = 0;
IND_TYPE f1066 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9852 ,mem_vec_9853 ,mem_vec_9854 ,mem_vec_9855 ,mem_vec_9856 ,mem_vec_9857 ,mem_vec_9858 ,mem_vec_9859 ,mem_vec_9860 ,mem_vec_9861 ,mem_vec_9862 ,mem_vec_9863 ,mem_vec_9864 ,mem_vec_9865 ,mem_vec_9866 ,mem_vec_9867 ,mem_vec_9868 ,mem_vec_9869 ,mem_vec_9870 ,mem_vec_9871 ,mem_vec_9872 ,mem_vec_9873 ,mem_vec_9874 ,mem_vec_9875 ,mem_vec_9876 ,mem_vec_9877 ,mem_vec_9878 ,mem_vec_9879 ,mem_vec_9880 ,mem_vec_9881 ,mem_vec_9882 ,mem_vec_9883 ,mem_vec_9884 ,mem_vec_9885 ,mem_vec_9886 ,mem_vec_9887 ,mem_vec_9888 ,mem_vec_9889 ,mem_vec_9890 ,mem_vec_9891 ,mem_vec_9892 ,mem_vec_9893 ,mem_vec_9894 ,mem_vec_9895 ,mem_vec_9896 ,mem_vec_9897 ,mem_vec_9898 ,mem_vec_9899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1065 = f1066, f1065_p_0 = 0;
	f1065 < f1066 + 256;
	f1065 += 128, f1065_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 1) (68 / 68)
	for (x850 = x851, x850_p_0 = 0;
		x850 < x851 + 68;
		x850 += 68, x850_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (f, 4) (128 / 32)
		for (f1064 = f1065, f1064_p_1 = f1065_p_0, f1064_p_0 = 0;
			f1064 < f1065 + 128;
			f1064 += 32, f1064_p_1 += 32, f1064_p_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (c, 16) (128 / 8)
			for (c798 = c799, c798_p_0 = 0;
				c798 < c799 + 128;
				c798 += 8, c798_p_0 += 8){
				// y = 68, x = 68, h = 3, w = 3, c = 8, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1064, fp_2 = f1064_p_1, fp_1 = f1064_p_0, fp_0 = 0;
					f < f1064 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y532, yp_0 = 0;
							y < y532 + 55;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h532, hp_0 = 0;
								h < h532 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w480, wp_0 = 0;
									w < w480 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 8, f = 32
									// T (x, 68) (68 / 1)
									for (x = x850, xp_1 = x850_p_0, xp_0 = 0;
										x < x850 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c798, cp_1 = c798_p_0, cp_0 = 0;
													c < c798 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9852);
													mem_vec_9852 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9853);
													mem_vec_9853 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9854);
													mem_vec_9854 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9855);
													mem_vec_9855 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9856);
													mem_vec_9856 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9857);
													mem_vec_9857 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9858);
													mem_vec_9858 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9859);
													mem_vec_9859 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9860);
													mem_vec_9860 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9861);
													mem_vec_9861 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9862);
													mem_vec_9862 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9863);
													mem_vec_9863 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9864);
													mem_vec_9864 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9865);
													mem_vec_9865 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9866);
													mem_vec_9866 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9867);
													mem_vec_9867 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9868);
													mem_vec_9868 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9869);
													mem_vec_9869 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9870);
													mem_vec_9870 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9871);
													mem_vec_9871 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9872);
													mem_vec_9872 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9873);
													mem_vec_9873 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9855);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9856);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9857);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9858);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9859);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9860);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9861);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9862);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9863);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9867);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9868);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9869);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9870);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9871);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9872);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9873);
									}
								}
							}
						}
						for (y = y532 + 55, yp_0 = 0;
							y < y532 + 55 + 13;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h532, hp_0 = 0;
								h < h532 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w480, wp_0 = 0;
									w < w480 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 8, f = 32
									// T (x, 68) (68 / 1)
									for (x = x850, xp_1 = x850_p_0, xp_0 = 0;
										x < x850 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9874 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9875 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c798, cp_1 = c798_p_0, cp_0 = 0;
													c < c798 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9874);
													mem_vec_9874 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9875);
													mem_vec_9875 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9876);
													mem_vec_9876 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9877);
													mem_vec_9877 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9878);
													mem_vec_9878 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9879);
													mem_vec_9879 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9880);
													mem_vec_9880 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9881);
													mem_vec_9881 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9882);
													mem_vec_9882 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9883);
													mem_vec_9883 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9884);
													mem_vec_9884 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9885);
													mem_vec_9885 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9886);
													mem_vec_9886 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9887);
													mem_vec_9887 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9888);
													mem_vec_9888 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9889);
													mem_vec_9889 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9890);
													mem_vec_9890 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9891);
													mem_vec_9891 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9892);
													mem_vec_9892 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9893);
													mem_vec_9893 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9894);
													mem_vec_9894 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9895);
													mem_vec_9895 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9896);
													mem_vec_9896 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9897);
													mem_vec_9897 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9898);
													mem_vec_9898 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9899);
													mem_vec_9899 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9874);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9875);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9876);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9877);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9878);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9879);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9880);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9881);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9882);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9883);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9884);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9885);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9886);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9887);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9888);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9889);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9890);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9891);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9892);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9893);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9894);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9895);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9896);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9897);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9898);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9899);
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