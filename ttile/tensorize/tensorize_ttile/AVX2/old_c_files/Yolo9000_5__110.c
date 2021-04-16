#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, x, xp_0, x175_p_0, x176_p_0, x177_p_0, xp_1, x175_p_1, x176_p_1, xp_2, x175_p_2, xp_3, x175, x176, x177, y, yp_0, y140_p_0, y141_p_0, yp_1, y140_p_1, yp_2, y140, y141;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y142 = 0;
IND_TYPE x178 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c106 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y141 = y142, y141_p_0 = 0;
		y141 < y142 + 96;
		y141 += 32, y141_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x177 = x178, x177_p_0 = 0;
			x177 < x178 + 136;
			x177 += 136, x177_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y140 = y141, y140_p_1 = y141_p_0, y140_p_0 = 0;
				y140 < y141 + 32;
				y140 += 32, y140_p_1 += 32, y140_p_0 += 32){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x176 = x177, x176_p_1 = x177_p_0, x176_p_0 = 0;
					x176 < x177 + 136;
					x176 += 2, x176_p_1 += 2, x176_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f70, fp_0 = 0;
						f < f70 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y140, yp_2 = y140_p_1, yp_1 = y140_p_0, yp_0 = 0;
							y < y140 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x175 = x176, x175_p_2 = x176_p_1, x175_p_1 = x176_p_0, x175_p_0 = 0;
								x175 < x176 + 2;
								x175 += 1, x175_p_2 += 1, x175_p_1 += 1, x175_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c105 = c106, c105_p_0 = 0;
									c105 < c106 + 128;
									c105 += 128, c105_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x175, xp_3 = x175_p_2, xp_2 = x175_p_1, xp_1 = x175_p_0, xp_0 = 0;
										x < x175 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_860 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_861 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_862 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_863 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
													c < c105 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_860);
													mem_vec_860 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_861);
													mem_vec_861 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_862);
													mem_vec_862 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_863);
													mem_vec_863 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_864);
													mem_vec_864 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_865);
													mem_vec_865 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_866);
													mem_vec_866 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_867);
													mem_vec_867 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_868);
													mem_vec_868 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_869);
													mem_vec_869 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_870);
													mem_vec_870 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_871);
													mem_vec_871 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_872);
													mem_vec_872 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_873);
													mem_vec_873 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_874);
													mem_vec_874 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_875);
													mem_vec_875 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_860);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_861);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_862);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_863);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_864);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_865);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_866);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_867);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_868);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_869);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_870);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_871);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_872);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_873);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_874);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_875);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y141 = y142 + 96, y141_p_0 = 0;
		y141 < y142 + 96 + 40;
		y141 += 40, y141_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x177 = x178, x177_p_0 = 0;
			x177 < x178 + 136;
			x177 += 136, x177_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y140 = y141, y140_p_1 = y141_p_0, y140_p_0 = 0;
				y140 < y141 + 40;
				y140 += 40, y140_p_1 += 40, y140_p_0 += 40){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x176 = x177, x176_p_1 = x177_p_0, x176_p_0 = 0;
					x176 < x177 + 136;
					x176 += 2, x176_p_1 += 2, x176_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f70, fp_0 = 0;
						f < f70 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y140, yp_2 = y140_p_1, yp_1 = y140_p_0, yp_0 = 0;
							y < y140 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x175 = x176, x175_p_2 = x176_p_1, x175_p_1 = x176_p_0, x175_p_0 = 0;
								x175 < x176 + 2;
								x175 += 1, x175_p_2 += 1, x175_p_1 += 1, x175_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c105 = c106, c105_p_0 = 0;
									c105 < c106 + 128;
									c105 += 128, c105_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x175, xp_3 = x175_p_2, xp_2 = x175_p_1, xp_1 = x175_p_0, xp_0 = 0;
										x < x175 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_876 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_877 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_878 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_879 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
													c < c105 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_876);
													mem_vec_876 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_877);
													mem_vec_877 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_878);
													mem_vec_878 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_879);
													mem_vec_879 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_880);
													mem_vec_880 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_881);
													mem_vec_881 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_882);
													mem_vec_882 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_883);
													mem_vec_883 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_884);
													mem_vec_884 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_885);
													mem_vec_885 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_886);
													mem_vec_886 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_887);
													mem_vec_887 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_888);
													mem_vec_888 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_889);
													mem_vec_889 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_890);
													mem_vec_890 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_891);
													mem_vec_891 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_892);
													mem_vec_892 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_893);
													mem_vec_893 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_894);
													mem_vec_894 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_895);
													mem_vec_895 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_876);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_877);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_878);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_879);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_880);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_881);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_882);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_883);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_884);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_885);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_886);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_887);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_888);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_889);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_890);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_891);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_892);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_893);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_894);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_895);
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