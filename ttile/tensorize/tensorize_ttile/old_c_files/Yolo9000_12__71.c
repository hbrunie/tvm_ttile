#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, f); T (34, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, f);
  T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, f96_p_0, f97_p_0, fp_1, f96_p_1, fp_2, f96, f97, h, hp_0, w, wp_0, x, xp_0, x72_p_0, xp_1, x72, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y48 = 0;
IND_TYPE x73 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c73 = 0;
IND_TYPE f98 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f97 = f98, f97_p_0 = 0;
	f97 < f98 + 512;
	f97 += 128, f97_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 8) (256 / 32)
	for (c72 = c73, c72_p_0 = 0;
		c72 < c73 + 256;
		c72 += 32, c72_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 128
		// T (f, 2) (128 / 64)
		for (f96 = f97, f96_p_1 = f97_p_0, f96_p_0 = 0;
			f96 < f97 + 128;
			f96 += 64, f96_p_1 += 64, f96_p_0 += 64){
				for (y = y48, yp_0 = 0;
					y < y48 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 64
					// T (x, 34) (34 / 1)
					for (x72 = x73, x72_p_0 = 0;
						x72 < x73 + 34;
						x72 += 1, x72_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f96, fp_2 = f96_p_1, fp_1 = f96_p_0, fp_0 = 0;
							f < f96 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h48, hp_0 = 0;
								h < h48 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w48, wp_0 = 0;
									w < w48 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
										x < x72 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
													c < c72 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_864);
													mem_vec_864 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_865);
													mem_vec_865 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_866);
													mem_vec_866 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_867);
													mem_vec_867 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_868);
													mem_vec_868 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_869);
													mem_vec_869 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_870);
													mem_vec_870 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_871);
													mem_vec_871 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_872);
													mem_vec_872 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_873);
													mem_vec_873 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_874);
													mem_vec_874 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_875);
													mem_vec_875 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_876);
													mem_vec_876 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_877);
													mem_vec_877 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_878);
													mem_vec_878 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_879);
													mem_vec_879 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_867);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_868);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_869);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_870);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_871);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_872);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_873);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_874);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_875);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_876);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_877);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_878);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_879);
									}
								}
							}
						}
					}
				}
				for (y = y48 + 24, yp_0 = 0;
					y < y48 + 24 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 64
					// T (x, 34) (34 / 1)
					for (x72 = x73, x72_p_0 = 0;
						x72 < x73 + 34;
						x72 += 1, x72_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f96, fp_2 = f96_p_1, fp_1 = f96_p_0, fp_0 = 0;
							f < f96 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h48, hp_0 = 0;
								h < h48 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w48, wp_0 = 0;
									w < w48 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
										x < x72 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
													c < c72 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_880);
													mem_vec_880 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_881);
													mem_vec_881 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_882);
													mem_vec_882 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_883);
													mem_vec_883 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_884);
													mem_vec_884 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_885);
													mem_vec_885 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_886);
													mem_vec_886 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_887);
													mem_vec_887 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_888);
													mem_vec_888 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_889);
													mem_vec_889 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_890);
													mem_vec_890 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_891);
													mem_vec_891 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_892);
													mem_vec_892 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_893);
													mem_vec_893 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_894);
													mem_vec_894 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_895);
													mem_vec_895 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_896);
													mem_vec_896 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_897);
													mem_vec_897 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_898);
													mem_vec_898 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_899);
													mem_vec_899 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_880);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_881);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_882);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_883);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_884);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_885);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_886);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_887);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_888);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_889);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_890);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_891);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_892);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_893);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_894);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_895);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_896);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_897);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_898);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_899);
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