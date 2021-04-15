#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, f76_p_0, f77_p_0, fp_1, f76_p_1, fp_2, f76, f77, h, hp_0, w, wp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y38 = 0;
IND_TYPE x58 = 0;
IND_TYPE h38 = 0;
IND_TYPE w38 = 0;
IND_TYPE c58 = 0;
IND_TYPE f78 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f77 = f78, f77_p_0 = 0;
	f77 < f78 + 256;
	f77 += 128, f77_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 4) (128 / 32)
	for (f76 = f77, f76_p_1 = f77_p_0, f76_p_0 = 0;
		f76 < f77 + 128;
		f76 += 32, f76_p_1 += 32, f76_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 2) (68 / 34)
		for (x57 = x58, x57_p_0 = 0;
			x57 < x58 + 68;
			x57 += 34, x57_p_0 += 34){
				for (y = y38, yp_0 = 0;
					y < y38 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f76, fp_2 = f76_p_1, fp_1 = f76_p_0, fp_0 = 0;
						f < f76 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c57 = c58, c57_p_0 = 0;
							c57 < c58 + 128;
							c57 += 16, c57_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w38, wp_0 = 0;
								w < w38 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
									x < x57 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h38, hp_0 = 0;
										h < h38 + 3;
										h += 1, hp_0 += 1){
												mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
													c < c57 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_740);
													mem_vec_740 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_741);
													mem_vec_741 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_742);
													mem_vec_742 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_743);
													mem_vec_743 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_744);
													mem_vec_744 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_745);
													mem_vec_745 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_746);
													mem_vec_746 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_747);
													mem_vec_747 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_748);
													mem_vec_748 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_749);
													mem_vec_749 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_750);
													mem_vec_750 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_751);
													mem_vec_751 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_752);
													mem_vec_752 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_753);
													mem_vec_753 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_754);
													mem_vec_754 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_755);
													mem_vec_755 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_740);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_741);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_742);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_743);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_744);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_745);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_746);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_747);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_748);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_749);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_750);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_751);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_752);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_753);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_754);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_755);
									}
								}
							}
						}
					}
				}
				for (y = y38 + 8, yp_0 = 0;
					y < y38 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f76, fp_2 = f76_p_1, fp_1 = f76_p_0, fp_0 = 0;
						f < f76 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c57 = c58, c57_p_0 = 0;
							c57 < c58 + 128;
							c57 += 16, c57_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w38, wp_0 = 0;
								w < w38 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
									x < x57 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h38, hp_0 = 0;
										h < h38 + 3;
										h += 1, hp_0 += 1){
												mem_vec_756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
													c < c57 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_756);
													mem_vec_756 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_757);
													mem_vec_757 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_758);
													mem_vec_758 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_759);
													mem_vec_759 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_760);
													mem_vec_760 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_761);
													mem_vec_761 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_762);
													mem_vec_762 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_763);
													mem_vec_763 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_764);
													mem_vec_764 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_765);
													mem_vec_765 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_766);
													mem_vec_766 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_767);
													mem_vec_767 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_768);
													mem_vec_768 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_769);
													mem_vec_769 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_770);
													mem_vec_770 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_771);
													mem_vec_771 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_772);
													mem_vec_772 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_773);
													mem_vec_773 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_774);
													mem_vec_774 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_775);
													mem_vec_775 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_776);
													mem_vec_776 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_777);
													mem_vec_777 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_778);
													mem_vec_778 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_779);
													mem_vec_779 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_756);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_757);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_758);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_759);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_760);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_761);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_762);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_763);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_764);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_765);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_766);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_767);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_768);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_769);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_770);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_771);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_772);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_773);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_774);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_775);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_776);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_777);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_778);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_779);
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