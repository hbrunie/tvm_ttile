#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (2, y); T (1, f); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (8, f)]
*/
IND_TYPE c, cp_0, c712_p_0, cp_1, c712, f, fp_0, f702_p_0, f703_p_0, fp_1, f702_p_1, fp_2, f702, f703, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y368_p_0, yp_1, y368;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y369 = 0;
IND_TYPE x360 = 0;
IND_TYPE h271 = 0;
IND_TYPE w277 = 0;
IND_TYPE c713 = 0;
IND_TYPE f704 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,mem_vec_4812 ,mem_vec_4813 ,mem_vec_4814 ,mem_vec_4815 ,mem_vec_4816 ,mem_vec_4817 ,mem_vec_4818 ,mem_vec_4819 ,mem_vec_4820 ,mem_vec_4821 ,mem_vec_4822 ,mem_vec_4823 ,mem_vec_4824 ,mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f703 = f704, f703_p_0 = 0;
	f703 < f704 + 256;
	f703 += 32, f703_p_0 += 32){
		for (y368 = y369, y368_p_0 = 0;
			y368 < y369 + 8;
			y368 += 8, y368_p_0 += 8){
			// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f702 = f703, f702_p_1 = f703_p_0, f702_p_0 = 0;
				f702 < f703 + 32;
				f702 += 32, f702_p_1 += 32, f702_p_0 += 32){
				// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c712 = c713, c712_p_0 = 0;
					c712 < c713 + 256;
					c712 += 32, c712_p_0 += 32){
					// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f702, fp_2 = f702_p_1, fp_1 = f702_p_0, fp_0 = 0;
						f < f702 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y368, yp_1 = y368_p_0, yp_0 = 0;
							y < y368 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x360, xp_0 = 0;
								x < x360 + 28;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h271, hp_0 = 0;
									h < h271 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w277, wp_0 = 0;
										w < w277 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4808 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4809 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4810 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4811 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c712, cp_1 = c712_p_0, cp_0 = 0;
													c < c712 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4808);
													mem_vec_4808 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4809);
													mem_vec_4809 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4810);
													mem_vec_4810 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4811);
													mem_vec_4811 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4812);
													mem_vec_4812 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4813);
													mem_vec_4813 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4814);
													mem_vec_4814 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4815);
													mem_vec_4815 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4816);
													mem_vec_4816 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4817);
													mem_vec_4817 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4818);
													mem_vec_4818 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4819);
													mem_vec_4819 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4820);
													mem_vec_4820 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4821);
													mem_vec_4821 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4822);
													mem_vec_4822 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4823);
													mem_vec_4823 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4808);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4809);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4810);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4811);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4812);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4813);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4814);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4815);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4816);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4817);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4818);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4819);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4820);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4821);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4822);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4823);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y368 = y369 + 8, y368_p_0 = 0;
			y368 < y369 + 8 + 20;
			y368 += 10, y368_p_0 += 10){
			// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f702 = f703, f702_p_1 = f703_p_0, f702_p_0 = 0;
				f702 < f703 + 32;
				f702 += 32, f702_p_1 += 32, f702_p_0 += 32){
				// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c712 = c713, c712_p_0 = 0;
					c712 < c713 + 256;
					c712 += 32, c712_p_0 += 32){
					// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f702, fp_2 = f702_p_1, fp_1 = f702_p_0, fp_0 = 0;
						f < f702 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y368, yp_1 = y368_p_0, yp_0 = 0;
							y < y368 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x360, xp_0 = 0;
								x < x360 + 28;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h271, hp_0 = 0;
									h < h271 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w277, wp_0 = 0;
										w < w277 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4824 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4825 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4826 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4827 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_4840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_4842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c712, cp_1 = c712_p_0, cp_0 = 0;
													c < c712 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4824);
													mem_vec_4824 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4825);
													mem_vec_4825 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4826);
													mem_vec_4826 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4827);
													mem_vec_4827 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4828);
													mem_vec_4828 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4829);
													mem_vec_4829 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4830);
													mem_vec_4830 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4831);
													mem_vec_4831 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4832);
													mem_vec_4832 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4833);
													mem_vec_4833 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4834);
													mem_vec_4834 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4835);
													mem_vec_4835 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4836);
													mem_vec_4836 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4837);
													mem_vec_4837 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4838);
													mem_vec_4838 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4839);
													mem_vec_4839 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4840);
													mem_vec_4840 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4841);
													mem_vec_4841 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4842);
													mem_vec_4842 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4843);
													mem_vec_4843 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4824);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4825);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4826);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4827);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4828);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4829);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4830);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4831);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4832);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4833);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4834);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4835);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4836);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4837);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4838);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4839);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4840);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4841);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4842);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4843);
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