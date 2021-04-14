#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (1, f); T (16, c); T (1, f); T (34, x); T (8, f)]
*/
IND_TYPE c, cp_0, c984_p_0, cp_1, c984, f, fp_0, f1312_p_0, f1313_p_0, fp_1, f1312_p_1, fp_2, f1312, f1313, h, hp_0, w, wp_0, x, xp_0, x1036_p_0, xp_1, x1036, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y656 = 0;
IND_TYPE x1037 = 0;
IND_TYPE h656 = 0;
IND_TYPE w604 = 0;
IND_TYPE c985 = 0;
IND_TYPE f1314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13004 ,mem_vec_13005 ,mem_vec_13006 ,mem_vec_13007 ,mem_vec_13008 ,mem_vec_13009 ,mem_vec_13010 ,mem_vec_13011 ,mem_vec_13012 ,mem_vec_13013 ,mem_vec_13014 ,mem_vec_13015 ,mem_vec_13016 ,mem_vec_13017 ,mem_vec_13018 ,mem_vec_13019 ,mem_vec_13020 ,mem_vec_13021 ,mem_vec_13022 ,mem_vec_13023 ,mem_vec_13024 ,mem_vec_13025 ,mem_vec_13026 ,mem_vec_13027 ,mem_vec_13028 ,mem_vec_13029 ,mem_vec_13030 ,mem_vec_13031 ,mem_vec_13032 ,mem_vec_13033 ,mem_vec_13034 ,mem_vec_13035 ,mem_vec_13036 ,mem_vec_13037 ,mem_vec_13038 ,mem_vec_13039 ,mem_vec_13040 ,mem_vec_13041 ,mem_vec_13042 ,mem_vec_13043 ,mem_vec_13044 ,mem_vec_13045 ,mem_vec_13046 ,mem_vec_13047 ,mem_vec_13048 ,mem_vec_13049 ,mem_vec_13050 ,mem_vec_13051 ,mem_vec_13052 ,mem_vec_13053 ,mem_vec_13054 ,mem_vec_13055 ,mem_vec_13056 ,mem_vec_13057 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f1313 = f1314, f1313_p_0 = 0;
	f1313 < f1314 + 256;
	f1313 += 32, f1313_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 34) (68 / 2)
	for (x1036 = x1037, x1036_p_0 = 0;
		x1036 < x1037 + 68;
		x1036 += 2, x1036_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f1312 = f1313, f1312_p_1 = f1313_p_0, f1312_p_0 = 0;
			f1312 < f1313 + 32;
			f1312 += 32, f1312_p_1 += 32, f1312_p_0 += 32){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
			// T (c, 16) (128 / 8)
			for (c984 = c985, c984_p_0 = 0;
				c984 < c985 + 128;
				c984 += 8, c984_p_0 += 8){
				// y = 68, x = 2, h = 3, w = 3, c = 8, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
					f < f1312 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y656, yp_0 = 0;
							y < y656 + 26;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h656, hp_0 = 0;
								h < h656 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w604, wp_0 = 0;
									w < w604 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1036, xp_1 = x1036_p_0, xp_0 = 0;
										x < x1036 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13004 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13005 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_13017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_13018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_13019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_13020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_13021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_13022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_13023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_13024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_13025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_13026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_13027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_13028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_13029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
													c < c984 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13004);
													mem_vec_13004 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13005);
													mem_vec_13005 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13006);
													mem_vec_13006 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13007);
													mem_vec_13007 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13008);
													mem_vec_13008 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13009);
													mem_vec_13009 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13010);
													mem_vec_13010 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13011);
													mem_vec_13011 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13012);
													mem_vec_13012 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13013);
													mem_vec_13013 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13014);
													mem_vec_13014 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13015);
													mem_vec_13015 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13016);
													mem_vec_13016 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13017);
													mem_vec_13017 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13018);
													mem_vec_13018 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13019);
													mem_vec_13019 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13020);
													mem_vec_13020 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13021);
													mem_vec_13021 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13022);
													mem_vec_13022 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13023);
													mem_vec_13023 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13024);
													mem_vec_13024 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13025);
													mem_vec_13025 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13026);
													mem_vec_13026 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13027);
													mem_vec_13027 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13028);
													mem_vec_13028 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13029);
													mem_vec_13029 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13004);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13005);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13006);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13007);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13008);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13016);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13023);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13025);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13026);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13027);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13028);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13029);
									}
								}
							}
						}
						for (y = y656 + 26, yp_0 = 0;
							y < y656 + 26 + 42;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h656, hp_0 = 0;
								h < h656 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w604, wp_0 = 0;
									w < w604 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1036, xp_1 = x1036_p_0, xp_0 = 0;
										x < x1036 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13030 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13031 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_13043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_13044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_13045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_13046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_13047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_13048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_13049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_13050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_13051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_13052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_13053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_13054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_13055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_13056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_13057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
													c < c984 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13030);
													mem_vec_13030 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13031);
													mem_vec_13031 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13032);
													mem_vec_13032 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13033);
													mem_vec_13033 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13034);
													mem_vec_13034 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13035);
													mem_vec_13035 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13036);
													mem_vec_13036 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13037);
													mem_vec_13037 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13038);
													mem_vec_13038 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13039);
													mem_vec_13039 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13040);
													mem_vec_13040 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13041);
													mem_vec_13041 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13042);
													mem_vec_13042 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13043);
													mem_vec_13043 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13044);
													mem_vec_13044 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13045);
													mem_vec_13045 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13046);
													mem_vec_13046 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13047);
													mem_vec_13047 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13048);
													mem_vec_13048 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13049);
													mem_vec_13049 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13050);
													mem_vec_13050 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13051);
													mem_vec_13051 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13052);
													mem_vec_13052 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13053);
													mem_vec_13053 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13054);
													mem_vec_13054 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13055);
													mem_vec_13055 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_13056);
													mem_vec_13056 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_13057);
													mem_vec_13057 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13030);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13031);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13032);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13033);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13034);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13035);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13036);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13037);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13038);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13039);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13040);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13041);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13042);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13043);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13044);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13045);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13046);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13047);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13048);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13049);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13050);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13051);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13052);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13053);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13054);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13055);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_13056);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_13057);
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