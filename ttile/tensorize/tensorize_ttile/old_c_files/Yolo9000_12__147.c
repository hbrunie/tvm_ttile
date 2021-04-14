#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (1, f);
  T (256, c); T (16, f)]
*/
IND_TYPE c, cp_0, c414_p_0, cp_1, c414, f, fp_0, f552_p_0, f553_p_0, fp_1, f552_p_1, fp_2, f552, f553, h, hp_0, w, wp_0, x, xp_0, x414_p_0, xp_1, x414, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y276 = 0;
IND_TYPE x415 = 0;
IND_TYPE h276 = 0;
IND_TYPE w276 = 0;
IND_TYPE c415 = 0;
IND_TYPE f554 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5964 ,mem_vec_5965 ,mem_vec_5966 ,mem_vec_5967 ,mem_vec_5968 ,mem_vec_5969 ,mem_vec_5970 ,mem_vec_5971 ,mem_vec_5972 ,mem_vec_5973 ,mem_vec_5974 ,mem_vec_5975 ,mem_vec_5976 ,mem_vec_5977 ,mem_vec_5978 ,mem_vec_5979 ,mem_vec_5980 ,mem_vec_5981 ,mem_vec_5982 ,mem_vec_5983 ,mem_vec_5984 ,mem_vec_5985 ,mem_vec_5986 ,mem_vec_5987 ,mem_vec_5988 ,mem_vec_5989 ,mem_vec_5990 ,mem_vec_5991 ,mem_vec_5992 ,mem_vec_5993 ,mem_vec_5994 ,mem_vec_5995 ,mem_vec_5996 ,mem_vec_5997 ,mem_vec_5998 ,mem_vec_5999 ,mem_vec_6000 ,mem_vec_6001 ,mem_vec_6002 ,mem_vec_6003 ,mem_vec_6004 ,mem_vec_6005 ,mem_vec_6006 ,mem_vec_6007 ,mem_vec_6008 ,mem_vec_6009 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 16) (512 / 32)
for (f553 = f554, f553_p_0 = 0;
	f553 < f554 + 512;
	f553 += 32, f553_p_0 += 32){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 32
	// T (c, 256) (256 / 1)
	for (c414 = c415, c414_p_0 = 0;
		c414 < c415 + 256;
		c414 += 1, c414_p_0 += 1){
		// y = 34, x = 34, h = 3, w = 3, c = 1, f = 32
		// T (f, 1) (32 / 32)
		for (f552 = f553, f552_p_1 = f553_p_0, f552_p_0 = 0;
			f552 < f553 + 32;
			f552 += 32, f552_p_1 += 32, f552_p_0 += 32){
				for (y = y276, yp_0 = 0;
					y < y276 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (34 / 34)
					for (x414 = x415, x414_p_0 = 0;
						x414 < x415 + 34;
						x414 += 34, x414_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f552, fp_2 = f552_p_1, fp_1 = f552_p_0, fp_0 = 0;
							f < f552 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h276, hp_0 = 0;
								h < h276 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w276, wp_0 = 0;
									w < w276 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 1, f = 32
									// T (x, 34) (34 / 1)
									for (x = x414, xp_1 = x414_p_0, xp_0 = 0;
										x < x414 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5964 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5965 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_5984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_5985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
													c < c414 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5964);
													mem_vec_5964 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5965);
													mem_vec_5965 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5966);
													mem_vec_5966 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5967);
													mem_vec_5967 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5968);
													mem_vec_5968 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5969);
													mem_vec_5969 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5970);
													mem_vec_5970 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5971);
													mem_vec_5971 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5972);
													mem_vec_5972 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5973);
													mem_vec_5973 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5974);
													mem_vec_5974 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5975);
													mem_vec_5975 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5976);
													mem_vec_5976 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5977);
													mem_vec_5977 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5978);
													mem_vec_5978 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5979);
													mem_vec_5979 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5980);
													mem_vec_5980 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5981);
													mem_vec_5981 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5982);
													mem_vec_5982 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5983);
													mem_vec_5983 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5984);
													mem_vec_5984 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5985);
													mem_vec_5985 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5964);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5965);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5966);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5967);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5968);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5969);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5970);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5971);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5972);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5973);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5974);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5975);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5976);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5977);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5978);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5979);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5980);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5981);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5982);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5983);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5984);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5985);
									}
								}
							}
						}
					}
				}
				for (y = y276 + 22, yp_0 = 0;
					y < y276 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (34 / 34)
					for (x414 = x415, x414_p_0 = 0;
						x414 < x415 + 34;
						x414 += 34, x414_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f552, fp_2 = f552_p_1, fp_1 = f552_p_0, fp_0 = 0;
							f < f552 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h276, hp_0 = 0;
								h < h276 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w276, wp_0 = 0;
									w < w276 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 1, f = 32
									// T (x, 34) (34 / 1)
									for (x = x414, xp_1 = x414_p_0, xp_0 = 0;
										x < x414 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5986 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5987 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
													c < c414 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5986);
													mem_vec_5986 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5987);
													mem_vec_5987 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5988);
													mem_vec_5988 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5989);
													mem_vec_5989 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5990);
													mem_vec_5990 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5991);
													mem_vec_5991 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5992);
													mem_vec_5992 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5993);
													mem_vec_5993 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5994);
													mem_vec_5994 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5995);
													mem_vec_5995 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5996);
													mem_vec_5996 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5997);
													mem_vec_5997 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5998);
													mem_vec_5998 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5999);
													mem_vec_5999 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6000);
													mem_vec_6000 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6001);
													mem_vec_6001 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6002);
													mem_vec_6002 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6003);
													mem_vec_6003 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6004);
													mem_vec_6004 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6005);
													mem_vec_6005 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6006);
													mem_vec_6006 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6007);
													mem_vec_6007 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6008);
													mem_vec_6008 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6009);
													mem_vec_6009 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5986);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5987);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5988);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5989);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5990);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5991);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5992);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5993);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5994);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5995);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5996);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5997);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5998);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5999);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6000);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6001);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6002);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6003);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6004);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6005);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6006);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6007);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6009);
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