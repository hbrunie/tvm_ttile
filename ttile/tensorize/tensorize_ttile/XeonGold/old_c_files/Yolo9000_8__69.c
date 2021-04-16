#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c297_p_0, cp_1, c297, f, fp_0, f396_p_0, f397_p_0, fp_1, f396_p_1, fp_2, f396, f397, h, hp_0, w, wp_0, x, xp_0, x297_p_0, xp_1, x297, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y198 = 0;
IND_TYPE x298 = 0;
IND_TYPE h198 = 0;
IND_TYPE w178 = 0;
IND_TYPE c298 = 0;
IND_TYPE f398 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3860 ,mem_vec_3861 ,mem_vec_3862 ,mem_vec_3863 ,mem_vec_3864 ,mem_vec_3865 ,mem_vec_3866 ,mem_vec_3867 ,mem_vec_3868 ,mem_vec_3869 ,mem_vec_3870 ,mem_vec_3871 ,mem_vec_3872 ,mem_vec_3873 ,mem_vec_3874 ,mem_vec_3875 ,mem_vec_3876 ,mem_vec_3877 ,mem_vec_3878 ,mem_vec_3879 ,mem_vec_3880 ,mem_vec_3881 ,mem_vec_3882 ,mem_vec_3883 ,mem_vec_3884 ,mem_vec_3885 ,mem_vec_3886 ,mem_vec_3887 ,mem_vec_3888 ,mem_vec_3889 ,mem_vec_3890 ,mem_vec_3891 ,mem_vec_3892 ,mem_vec_3893 ,mem_vec_3894 ,mem_vec_3895 ,mem_vec_3896 ,mem_vec_3897 ,mem_vec_3898 ,mem_vec_3899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f397 = f398, f397_p_0 = 0;
	f397 < f398 + 256;
	f397 += 128, f397_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 4) (128 / 32)
	for (f396 = f397, f396_p_1 = f397_p_0, f396_p_0 = 0;
		f396 < f397 + 128;
		f396 += 32, f396_p_1 += 32, f396_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x297 = x298, x297_p_0 = 0;
			x297 < x298 + 68;
			x297 += 17, x297_p_0 += 17){
				for (y = y198, yp_0 = 0;
					y < y198 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f396, fp_2 = f396_p_1, fp_1 = f396_p_0, fp_0 = 0;
						f < f396 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c297 = c298, c297_p_0 = 0;
							c297 < c298 + 128;
							c297 += 16, c297_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w178, wp_0 = 0;
								w < w178 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x297, xp_1 = x297_p_0, xp_0 = 0;
									x < x297 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h198, hp_0 = 0;
										h < h198 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c297, cp_1 = c297_p_0, cp_0 = 0;
													c < c297 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3860);
													mem_vec_3860 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3861);
													mem_vec_3861 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3862);
													mem_vec_3862 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3863);
													mem_vec_3863 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3864);
													mem_vec_3864 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3865);
													mem_vec_3865 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3866);
													mem_vec_3866 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3867);
													mem_vec_3867 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3868);
													mem_vec_3868 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3869);
													mem_vec_3869 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3870);
													mem_vec_3870 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3871);
													mem_vec_3871 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3872);
													mem_vec_3872 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3873);
													mem_vec_3873 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3874);
													mem_vec_3874 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3875);
													mem_vec_3875 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3860);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3861);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3862);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3863);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3867);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3868);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3869);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3870);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3871);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3872);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3873);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3874);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3875);
									}
								}
							}
						}
					}
				}
				for (y = y198 + 8, yp_0 = 0;
					y < y198 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f396, fp_2 = f396_p_1, fp_1 = f396_p_0, fp_0 = 0;
						f < f396 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c297 = c298, c297_p_0 = 0;
							c297 < c298 + 128;
							c297 += 16, c297_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w178, wp_0 = 0;
								w < w178 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x297, xp_1 = x297_p_0, xp_0 = 0;
									x < x297 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h198, hp_0 = 0;
										h < h198 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3876 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3877 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_3896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_3898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_3899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c297, cp_1 = c297_p_0, cp_0 = 0;
													c < c297 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3876);
													mem_vec_3876 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3877);
													mem_vec_3877 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3878);
													mem_vec_3878 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3879);
													mem_vec_3879 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3880);
													mem_vec_3880 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3881);
													mem_vec_3881 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3882);
													mem_vec_3882 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3883);
													mem_vec_3883 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3884);
													mem_vec_3884 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3885);
													mem_vec_3885 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3886);
													mem_vec_3886 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3887);
													mem_vec_3887 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3888);
													mem_vec_3888 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3889);
													mem_vec_3889 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3890);
													mem_vec_3890 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3891);
													mem_vec_3891 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3892);
													mem_vec_3892 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3893);
													mem_vec_3893 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3894);
													mem_vec_3894 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3895);
													mem_vec_3895 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3896);
													mem_vec_3896 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3897);
													mem_vec_3897 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3898);
													mem_vec_3898 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3899);
													mem_vec_3899 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3876);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3877);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3878);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3879);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3880);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3881);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3882);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3883);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3884);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3885);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3886);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3887);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3888);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3889);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3890);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3891);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3892);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3893);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3894);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3895);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3896);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3897);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3898);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3899);
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