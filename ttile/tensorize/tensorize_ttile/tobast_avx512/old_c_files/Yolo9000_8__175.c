#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))];
  T (2, f); T (16, c); T (1, f); T (17, x); T (4, f)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, f224_p_0, f225_p_0, fp_1, f224_p_1, fp_2, f224, f225, h, hp_0, w, wp_0, x, xp_0, x186_p_0, xp_1, x186, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y112 = 0;
IND_TYPE x187 = 0;
IND_TYPE h96 = 0;
IND_TYPE w86 = 0;
IND_TYPE c169 = 0;
IND_TYPE f226 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f225 = f226, f225_p_0 = 0;
	f225 < f226 + 256;
	f225 += 64, f225_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 17) (68 / 4)
	for (x186 = x187, x186_p_0 = 0;
		x186 < x187 + 68;
		x186 += 4, x186_p_0 += 4){
		// y = 68, x = 4, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f224 = f225, f224_p_1 = f225_p_0, f224_p_0 = 0;
			f224 < f225 + 64;
			f224 += 64, f224_p_1 += 64, f224_p_0 += 64){
			// y = 68, x = 4, h = 3, w = 3, c = 128, f = 64
			// T (c, 16) (128 / 8)
			for (c168 = c169, c168_p_0 = 0;
				c168 < c169 + 128;
				c168 += 8, c168_p_0 += 8){
				// y = 68, x = 4, h = 3, w = 3, c = 8, f = 64
				// T (f, 2) (64 / 32)
				for (f = f224, fp_2 = f224_p_1, fp_1 = f224_p_0, fp_0 = 0;
					f < f224 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y112, yp_0 = 0;
							y < y112 + 24;
							y += 8, yp_0 += 8){
							// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h96, hp_0 = 0;
								h < h96 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w86, wp_0 = 0;
									w < w86 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x186, xp_1 = x186_p_0, xp_0 = 0;
										x < x186 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
													c < c168 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_772);
													mem_vec_772 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_773);
													mem_vec_773 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_774);
													mem_vec_774 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_775);
													mem_vec_775 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_776);
													mem_vec_776 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_777);
													mem_vec_777 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_778);
													mem_vec_778 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_779);
													mem_vec_779 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_780);
													mem_vec_780 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_781);
													mem_vec_781 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_782);
													mem_vec_782 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_783);
													mem_vec_783 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_784);
													mem_vec_784 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_785);
													mem_vec_785 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_786);
													mem_vec_786 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_787);
													mem_vec_787 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_772);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_773);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_774);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_775);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_776);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_777);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_778);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_779);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_780);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_781);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_782);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_783);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_784);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_785);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_786);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_787);
									}
								}
							}
						}
						for (y = y112 + 24, yp_0 = 0;
							y < y112 + 24 + 44;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h96, hp_0 = 0;
								h < h96 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w86, wp_0 = 0;
									w < w86 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x186, xp_1 = x186_p_0, xp_0 = 0;
										x < x186 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
													c < c168 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_788);
													mem_vec_788 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_789);
													mem_vec_789 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_790);
													mem_vec_790 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_791);
													mem_vec_791 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_792);
													mem_vec_792 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_793);
													mem_vec_793 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_794);
													mem_vec_794 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_795);
													mem_vec_795 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_796);
													mem_vec_796 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_797);
													mem_vec_797 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_798);
													mem_vec_798 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_799);
													mem_vec_799 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_800);
													mem_vec_800 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_801);
													mem_vec_801 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_802);
													mem_vec_802 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_803);
													mem_vec_803 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_804);
													mem_vec_804 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_805);
													mem_vec_805 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_806);
													mem_vec_806 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_807);
													mem_vec_807 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_808);
													mem_vec_808 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_809);
													mem_vec_809 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_788);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_789);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_790);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_791);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_792);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_793);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_794);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_795);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_796);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_797);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_798);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_799);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_800);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_801);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_802);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_803);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_804);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_805);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_806);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_807);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_808);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_809);
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